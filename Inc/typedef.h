#pragma once

#include <vector>
#include <string>
#include <sstream>

#include "macroConfig.h"
#include "export.h"

MULENGINE_NAMESPACE_BEGIN


enum class BackendType{
    NCNN = 0,
    TFLITE,
    ONNX,
    TENSORRT
};

struct MULINFERENCE_API TensorShape {

    // 使用 int 表示维度大小，-1 代表动态维度
    std::vector<int> dims;

    TensorShape() = default;

    TensorShape(std::initializer_list<int> list)
        : dims(list) {}

    TensorShape(const std::vector<int>& v)
        : dims(v) {}

    int rank() const {
        return (int)dims.size();
    }

    // 是否包含动态维度
    bool hasDynamic() const {
        for (int d : dims)
            if (d < 0) return true;
        return false;
    }

    // 获取某一维度（带越界保护）
    int operator[](size_t idx) const {
        if (idx >= dims.size()) return -1;
        return dims[idx];
    }

    // 写入某一维
    int& operator[](size_t idx) {
        return dims[idx];
    }

    // 字符串表示，如 "1x3x224x224"
    std::string str() const {
        std::ostringstream oss;
        for (size_t i = 0; i < dims.size(); i++) {
            oss << dims[i];
            if (i + 1 < dims.size()) oss << "x";
        }
        return oss.str();
    }

    bool operator==(const TensorShape& other) const {
        return dims == other.dims;
    }

    bool operator!=(const TensorShape& other) const {
        return !(*this == other);
    }
};

MULENGINE_NAMESPACE_END