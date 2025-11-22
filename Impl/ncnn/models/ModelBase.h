#pragma once
#include <IModelBase.h>
#include "../ncnn.h"

MULENGINE_NCNN_NAMESPACE_BEGIN

class ModelBase: public IModelBase{
public:
    bool loadModel(std::string modelFile, std::string paramFile) override;

    const TensorShape& getInputDim() const override;

    const TensorShape& getOutDim() const override;    

protected:
    TensorShape m_inputDim;
    TensorShape m_outputDim;
};

MULENGINE_NCNN_NAMESPACE_END