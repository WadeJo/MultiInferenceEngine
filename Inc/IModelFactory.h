#pragma once
#include "typedef.h"
#include "export.h"

MULENGINE_NAMESPACE_BEGIN

class IModelBase;
class IU2NetModel;

class MULINFERENCE_API IModelFactory{
public:
    static IModelFactory* createFactory(BackendType backend);
    static void releaseFactory(IModelFactory* factory);

    virtual IU2NetModel* createU2Net() = 0;

protected:
    virtual void destory(IModelBase* model) = 0;
};

MULENGINE_NAMESPACE_END