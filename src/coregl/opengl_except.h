#pragma once

// ft_base_lib headers
#include "error/except_impl.h"

namespace ft {
namespace gl {
namespace err {

enum class except_types {

    base = 0,

    context_base,

    context_init,
    context_bad_pixel_format,
    context_edit_error,
    context_activate_error,
    context_opengl_function_not_found,
    context_failed_to_clear_frame,

    enum_counter

};  // enum class net_except_types

// Base type for opengl exceptions
using base_except = base::error::except_impl<base::error::except_base, except_types::base>;


// Base type for errors related to opengl contexts
using base_context = base::error::except_impl<base_except, except_types::context_base>;
template<except_types E> using except_context_impl = base::error::except_impl<base_context, E>;

// Exception when failing to construct an opengl context
using context_init = except_context_impl<except_types::context_init>;

// Exception when failing to configure an opengl's pixel format
//  May indicate that the pixel format is not supported
using context_bad_pixel_format = except_context_impl<except_types::context_bad_pixel_format>;

// Exception when changing a context property fails
using context_edit_error = except_context_impl<except_types::context_edit_error>;

// Exception when failing to activate an opengl context
using context_activate_error = except_context_impl<except_types::context_activate_error>;

// Exception when failing to find a requested OpenGL function
using context_opengl_function_not_found = except_context_impl<except_types::context_opengl_function_not_found>;

// Exception when failing to clear the frame buffer
using context_failed_to_clear_frame = except_context_impl<except_types::context_failed_to_clear_frame>;


}   // namespace err
}   // namespace gl
}   // namespace ft
