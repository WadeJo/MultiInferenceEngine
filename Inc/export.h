#pragma once

// 平台判断
#if defined(_WIN32) || defined(_WIN64)
    #if defined(MULINFERENCE_EXPORTS) // 在编译 DLL 时定义
        #define MULINFERENCE_API __declspec(dllexport)
    #else
        #define MULINFERENCE_API __declspec(dllimport)
    #endif
#else
    // 非 Windows 平台不用 dllexport/dllimport
    #define MULINFERENCE_API
#endif