#pragma once

#include <string>
#include "typedef.h"
#include "export.h"

MULENGINE_NAMESPACE_BEGIN

class MULINFERENCE_API IModelBase{
public:
    virtual bool loadModel(std::string modelFile, std::string paramFile = "") = 0;

    virtual const TensorShape& getInputDim() const = 0;

    virtual const TensorShape& getOutDim() const = 0;

};

MULENGINE_NAMESPACE_END