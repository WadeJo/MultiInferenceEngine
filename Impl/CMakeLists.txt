# src/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)


include_directories(${ROOT_INC_DIR})

# source files
file(GLOB NCNN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ncnn/*.cpp)

add_executable(MultiInferenceEngine ${NCNN_SRC})

# platform-specific defines
if(ANDROID)
    target_compile_definitions(MultiInferenceEngine PRIVATE PLATFORM_ANDROID)
elseif(APPLE)
    target_compile_definitions(MultiInferenceEngine PRIVATE PLATFORM_APPLE)
elseif(WIN32)
    target_compile_definitions(MultiInferenceEngine PRIVATE PLATFORM_WINDOWS)
else()
    target_compile_definitions(MultiInferenceEngine PRIVATE PLATFORM_LINUX)
endif()

# ---------------------------------------------------------------------
# Link NCNN
# ---------------------------------------------------------------------
if(ENABLE_NCNN)
    set(NCNN_ROOT ${CMAKE_SOURCE_DIR}/third_party/ncnn)
    if(EXISTS "${NCNN_ROOT}")
        message(STATUS "Using NCNN from ${NCNN_ROOT}")
        target_include_directories(MultiInferenceEngine PRIVATE ${NCNN_ROOT}/include)
        # pick library path by platform
        if(ANDROID)
            set(NCNN_LIB ${NCNN_ROOT}/libs/android/${ANDROID_ABI}/libncnn.a)
        elseif(WIN32)
            set(NCNN_LIB ${NCNN_ROOT}/libs/windows32/ncnn.lib)
        elseif(APPLE)
            set(NCNN_LIB ${NCNN_ROOT}/libs/macos/libncnn.a)
        else()
            set(NCNN_LIB ${NCNN_ROOT}/libs/linux/libncnn.a)
        endif()
        if(EXISTS ${NCNN_LIB})
            target_link_libraries(MultiInferenceEngine PRIVATE ${NCNN_LIB})
            target_compile_definitions(MultiInferenceEngine PRIVATE ENABLE_NCNN)
        else()
            message(WARNING "NCNN library not found at ${NCNN_LIB}. Set correct path or disable ENABLE_NCNN.")
        endif()
    else()
        message(WARNING "third_party/ncnn not found. disable ENABLE_NCNN or provide NCNN_ROOT.")
    endif()
endif()

# ---------------------------------------------------------------------
# Link ONNX Runtime
# ---------------------------------------------------------------------
if(ENABLE_ONNX)
    set(ORT_ROOT ${CMAKE_SOURCE_DIR}/third_party/onnxruntime)
    if(EXISTS "${ORT_ROOT}")
        message(STATUS "Using ONNX Runtime from ${ORT_ROOT}")
        target_include_directories(MultiBackendDemo PRIVATE ${ORT_ROOT}/include)
        if(WIN32)
            set(ORT_LIB ${ORT_ROOT}/lib/onnxruntime.lib)
        else()
            set(ORT_LIB ${ORT_ROOT}/lib/libonnxruntime.so)
        endif()
        if(EXISTS ${ORT_LIB})
            target_link_libraries(MultiBackendDemo PRIVATE ${ORT_LIB})
            target_compile_definitions(MultiBackendDemo PRIVATE ENABLE_ONNX)
        else()
            message(WARNING "ONNX Runtime lib not found at ${ORT_LIB}.")
        endif()
    else()
        message(WARNING "third_party/onnxruntime not found. disable ENABLE_ONNX or provide ORT_ROOT.")
    endif()
endif()

# ---------------------------------------------------------------------
# Link TFLite
# ---------------------------------------------------------------------
if(ENABLE_TFLITE)
    set(TFLITE_ROOT ${CMAKE_SOURCE_DIR}/third_party/tflite)
    if(EXISTS "${TFLITE_ROOT}")
        message(STATUS "Using TFLite from ${TFLITE_ROOT}")
        target_include_directories(MultiBackendDemo PRIVATE ${TFLITE_ROOT}/include)
        if(WIN32)
            set(TFLITE_LIB ${TFLITE_ROOT}/lib/tensorflowlite.lib)
        else()
            set(TFLITE_LIB ${TFLITE_ROOT}/lib/libtensorflowlite.so)
        endif()
        if(EXISTS ${TFLITE_LIB})
            target_link_libraries(MultiBackendDemo PRIVATE ${TFLITE_LIB})
            target_compile_definitions(MultiBackendDemo PRIVATE ENABLE_TFLITE)
        else()
            message(WARNING "TFLite lib not found at ${TFLITE_LIB}.")
        endif()
    else()
        message(WARNING "third_party/tflite not found. disable ENABLE_TFLITE or provide TFLITE_ROOT.")
    endif()
endif()

# ---------------------------------------------------------------------
# Optional dependencies
# ---------------------------------------------------------------------
find_package(Threads REQUIRED)
target_link_libraries(MultiInferenceEngine PRIVATE Threads::Threads)