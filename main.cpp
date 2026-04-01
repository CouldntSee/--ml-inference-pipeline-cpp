#include <onnxruntime_cxx_api.h>
#include <iostream>
#include <vector>

int main() {
    try {
        Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "TEST");
        Ort::SessionOptions session_options;
        const wchar_t* model_path = L"Simple_model.onnx";
        Ort::Session session(env, model_path, session_options);

        Ort::AllocatorWithDefaultOptions allocator;
        auto memory_info = Ort::MemoryInfo::CreateCpu(OrtDeviceAllocator, OrtMemTypeCPU);

        float user_input;
        while (true) {
            std::cout << "\n---> Enter a number to predict (or type -1 to exit): ";
            std::cin >> user_input;

            if (user_input == -1) break;

           
            std::vector<float> input_data = {user_input};
            std::vector<int64_t> input_shape = {1, 1};

            Ort::Value input_tensor = Ort::Value::CreateTensor<float>(
                memory_info, input_data.data(), input_data.size(), 
                input_shape.data(), input_shape.size());

            auto input_name_ptr = session.GetInputNameAllocated(0, allocator);
            auto output_name_ptr = session.GetOutputNameAllocated(0, allocator);
            const char* input_names[] = { input_name_ptr.get() };
            const char* output_names[] = { output_name_ptr.get() };

            auto output_tensors = session.Run(Ort::RunOptions{nullptr}, input_names, &input_tensor, 1, output_names, 1);

            int64_t* label = output_tensors.front().GetTensorMutableData<int64_t>();
            std::cout << "Result: The model classifies " << user_input << " as Class [" << label[0] << "]" << std::endl;
        }

    } catch (const Ort::Exception& e) {
        std::cerr << "ONNX Error: " << e.what() << std::endl;
    }
    return 0;
}