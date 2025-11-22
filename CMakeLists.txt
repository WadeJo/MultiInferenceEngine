cmake_minimum_required(VERSION 3.10)
project(MultiInferenceEngine VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------------------------------------------------------
# Options to enable backends
# -----------------------------------------------------------------------------
option(ENABLE_NCNN "Build with NCNN backend" ON)
option(ENABLE_ONNX "Build with ONNX Runtime backend" OFF)
option(ENABLE_TFLITE "Build with TensorFlow Lite backend" OFF)

message(STATUS "ENABLE_NCNN = ${ENABLE_NCNN}")
message(STATUS "ENABLE_ONNX = ${ENABLE_ONNX}")
message(STATUS "ENABLE_TFLITE = ${ENABLE_TFLITE}")

# -----------------------------------------------------------------------------
# Project structure
# -----------------------------------------------------------------------------
set(ROOT_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Inc)

add_subdirectory(Impl)

# -----------------------------------------------------------------------------
# Help message about where to put third-party libs
# -----------------------------------------------------------------------------
message(STATUS "Put third-party libs under ${CMAKE_SOURCE_DIR}/third_party/<name> (optional).")