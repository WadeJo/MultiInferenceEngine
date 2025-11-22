#include "ModelBase.h"
#include <ncnn/net.h>

MULENGINE_NCNN_NAMESPACE_BEGIN
bool ModelBase::loadModel(std::string modelFile, std::string paramFile){

}

const TensorShape& ModelBase::getInputDim() const{
    return m_inputDim;
}

const TensorShape& ModelBase::getOutDim() const{
    return m_outputDim;
} 

MULENGINE_NCNN_NAMESPACE_END