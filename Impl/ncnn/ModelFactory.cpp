#include "ModelFactory.h"
#include "./models/U2NetModel.h"

MULENGINE_NCNN_NAMESPACE_BEGIN

IU2NetModel* ModelFactory::createU2Net(){
    return new U2Net
}

MULENGINE_NCNN_NAMESPACE_END