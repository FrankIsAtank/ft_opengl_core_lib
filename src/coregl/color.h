#pragma once

// Basic structure for representing a color
// The values should be normalized (0.0 to 1.0)

namespace ft {
namespace gl {

template<class T = float>
struct color
{
    T red, green, blue;
    T alpha = 1.0;
};

}   // namespace gl
}   // namespace ft
