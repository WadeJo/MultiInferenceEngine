#pragma once
#include "IModelBase.h"
#include "export.h"

MULENGINE_NAMESPACE_BEGIN


class MULINFERENCE_API U2NetModel: virtual public IModelBase{
public:


protected:
    virtual ~U2NetModel() = 0;
};

MULENGINE_NAMESPACE_END
