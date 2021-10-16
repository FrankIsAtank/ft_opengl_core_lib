#pragma once

// Stores members that require OpenGL headers
#include "coregl/opengl_headers.h"

namespace ft {
namespace gl {
namespace context {

struct opengl_context_members
{
    HDC device_context;
    HGLRC render_context;

};  // struct opengl_context_members

}   // namespace context
}   // namespace gl
}   // namespace ft
