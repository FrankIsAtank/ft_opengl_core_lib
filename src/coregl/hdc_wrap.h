#pragma once

// Hides the type of a HDC by allowing forward declaration

// platform headers
#include "rf_handles.h"

namespace ft {
namespace gl {
namespace coregl {

struct hdc_wrap
{
    HDC value;
}; // class hdc_wrap

}   // namespace coregl
}   // namespace gl
}   // namespace ft
