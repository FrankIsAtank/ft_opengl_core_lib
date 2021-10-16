#include "opengl_headers.h"
#include "opengl_types.h"


// standard headers
#include <cstdint>
#include <type_traits>

// When this file compiles it verifies that the type abstraction
//  matches the OpenGL types
static_assert(std::is_same<ft::gl::coregl::t_opengl_int, int>{});
static_assert(std::is_same<ft::gl::coregl::t_opengl_uint, unsigned int>{});
static_assert(std::is_same<ft::gl::coregl::t_opengl_enum, GLenum>{});



namespace
{
template<class T>
struct t_gl_type_enum {};

template<GLenum value>
using t_gl_enum = std::integral_constant<GLenum, value>;

template<> struct t_gl_type_enum<std::int8_t> : t_gl_enum<GL_BYTE> {};
template<> struct t_gl_type_enum<std::uint8_t> : t_gl_enum<GL_UNSIGNED_BYTE> {};
template<> struct t_gl_type_enum<std::int16_t> : t_gl_enum<GL_SHORT> {};
template<> struct t_gl_type_enum<std::uint16_t> : t_gl_enum<GL_UNSIGNED_SHORT> {};
template<> struct t_gl_type_enum<std::int32_t> : t_gl_enum<GL_INT> {};
template<> struct t_gl_type_enum<std::uint32_t> : t_gl_enum<GL_UNSIGNED_INT> {};
template<> struct t_gl_type_enum<float> : t_gl_enum<GL_FLOAT> {};
template<> struct t_gl_type_enum<double> : t_gl_enum<GL_DOUBLE> {};

}   // anonymous namespace

// Static member initialization
template<class T>
const ft::gl::coregl::t_opengl_enum 
ft::gl::coregl::type_to_opengl_enum<T>::value = ::t_gl_type_enum<T>::value;

// Explicit instantiation
template ft::gl::coregl::type_to_opengl_enum<std::int8_t>;
template ft::gl::coregl::type_to_opengl_enum<std::uint8_t>;
template ft::gl::coregl::type_to_opengl_enum<std::int16_t>;
template ft::gl::coregl::type_to_opengl_enum<std::uint16_t>;
template ft::gl::coregl::type_to_opengl_enum<std::int32_t>;
template ft::gl::coregl::type_to_opengl_enum<std::uint32_t>;
template ft::gl::coregl::type_to_opengl_enum<double>;
template ft::gl::coregl::type_to_opengl_enum<float>;
