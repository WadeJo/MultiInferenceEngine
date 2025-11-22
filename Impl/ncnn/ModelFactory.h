#pragma once
#include <IModelFactory.h>
#include "ncnn.h"

MULENGINE_NCNN_NAMESPACE_BEGIN

class ModelFactory: public IModelFactory{
public:
    IU2NetModel* createU2Net() override;

};


MULENGINE_NCNN_NAMESPACE_END