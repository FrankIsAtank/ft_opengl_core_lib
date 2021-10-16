#pragma once

// Type information to abstract opengl headers

#include "container/type_list.h"

namespace ft {
namespace gl {
namespace coregl {

using t_opengl_uint = unsigned int;
using t_opengl_int = int;
using t_opengl_enum = t_opengl_uint;


// Get the OpenGL enum value associated with this type
template<class T>
struct type_to_opengl_enum
{
    static const t_opengl_enum value;
};

// List of fundamental types that can be written to or read from OpenGL buffers
using opengl_type_list = base::container::type_list<
    std::int8_t,
    std::uint8_t,
    std::int16_t,
    std::uint16_t,
    std::int32_t,
    std::uint32_t,
    float,
    double
>;

}   // namespace coregl
}   // namespace gl
}   // namespace ft
