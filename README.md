# ONNX C++ Inference Pipeline

A simple C++ project demonstrating how to run inference using the **ONNX Runtime**.  
This repo integrates compiled C++ code with machine learning models (`.onnx`, `.pkl`) and provides an interactive CLI for predictions.

---

##  Features
- Loads ONNX models with **ONNX Runtime C++ API**
- Accepts user input via command line
- Runs inference and outputs predicted class
- Error handling for ONNX exceptions
- Cross‑language workflow (Python training → C++ inference)

---

##  Project Structure
pipelineCpp/ ┣ 📂 .vscode          # VSCode settings 
┣ hush.cpp / hush.exe # Example source & binary 
┣ main.cpp / main.exe # Entry point for inference 
┣ onnxruntime.dll     # ONNX Runtime library
┣ Simple_model.onnx   # Trained model (ONNX format)
┣ Simple_model.pkl    # Model checkpoint (Python pickle)
┗ train_mode.py       # Python script for training


---

## ⚙️ Requirements
- C++17 or later
- ONNX Runtime (C++ API)
- Python (for training scripts, optional)

---

## 🛠 Build & Run
1. Clone the repo:
   ```bash
2. git clone https://github.com/YourUsername/onnx-cpp-inference.git
  cd onnx-cpp-inference

3. Compile
  g++ main.cpp -o main.exe -I/path/to/onnxruntime/include -L/path/to/onnxruntime/lib -lonnxruntime

4. Run
  ./main.exe


---


## Usage- Enter a number when prompted.
- The model will classify the input and return the predicted class.
- Type -1 to exit.

---

Feel Free to fork thi s repo and intorduce your innovationn and include your own code. Happy codingg!!
