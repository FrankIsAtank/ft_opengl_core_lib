// Implementation for the platform agnostic component of renderframe

// Project headers
#include "renderframe.h"
#include "renderframe_impl.h"

// Constructor
ft::gl::rf::render_frame::render_frame(t_render_frame_params p_params) :
    m_params{std::move(p_params)},
    m_impl{ new render_frame_impl(m_params), [](render_frame_impl * p_ptr) {delete p_ptr; } }
{ }


// Get the window's initial parameters
const ft::gl::rf::t_render_frame_params &
ft::gl::rf::render_frame::get_params() const
{
    return m_params;
}


// Get the opengl context assigned to this render frame
ft::gl::context::opengl_context &
ft::gl::rf::render_frame::get_opengl_context()
{
    return m_impl->get_opengl_context();
}


// Get the opengl context assigned to this render frame
const ft::gl::context::opengl_context & 
ft::gl::rf::render_frame::get_opengl_context() const
{
    return m_impl->get_opengl_context();
}


// Clear the current frame and prepare to start drawing to it
void ft::gl::rf::render_frame::start_frame()
{
    const auto & background = get_params().background;
    m_impl->get_opengl_context().clear_frame(background);
}


// Finish the current frame and display it
// If double buffering is used, display it
void ft::gl::rf::render_frame::end_frame()
{
    m_impl->display_frame();
}


// Show or hide the render frame
void ft::gl::rf::render_frame::set_visible(const bool p_visible)
{
    return m_impl->set_visible(p_visible);
}


// Is the render frame shown?
bool ft::gl::rf::render_frame::is_visible() const
{
    return m_impl->is_visible();
}
