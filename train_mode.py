import joblib
import numpy as np
from skl2onnx import convert_sklearn
from skl2onnx.common.data_types import FloatTensorType

model = joblib.load("Simple_model.pkl")

initial_type = [('float_input', FloatTensorType([None, 1]))]

onx = convert_sklearn(model, initial_types=initial_type)

with open("Simple_model.onnx", "wb") as f:
    f.write(onx.SerializeToString())

print("Success! 'Simple_model.onnx' is ready for C++.")