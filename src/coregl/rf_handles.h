#pragma once

// Hides the type of a HDC by allowing forward declaration

// platform specific defines
#include "base/platform.h"

#ifdef FT_OS_WINDOWS
    #include "base/windows_include.h"
#else
    #error Unsupported platform
#endif

