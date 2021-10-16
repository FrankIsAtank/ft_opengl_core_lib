#pragma once

// struct to define a pixel format

// standard headers
#include <cstdint>

namespace ft {
namespace gl {

struct t_pixel_format
{
    using t_integer = int;

    t_integer color_depth = 32;     // RGBA color depth
    t_integer alpha_depth = 8;      // Alpha channel depth
    t_integer z_buffer_depth = 24;  // Depth buffer resolution
    t_integer stencil_depth = 8;    // Stencil buffer bits per pixel
    bool double_buffer = true;      // Supports double buffering
    t_integer multisample = 0;      // Antialiasing

}; // class t_pixel_format

}   // namespace gl
}   // namespace ft
