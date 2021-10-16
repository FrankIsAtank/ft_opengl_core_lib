#pragma once

// Platform agnostic interface for a window or other render context
#include "renderframeparams.h"

// standard headers
#include <memory>

namespace ft {
namespace gl {

namespace context {
    // Forward declaration
    class opengl_context;
}

namespace rf {

// Platform-dependent component of this class
class render_frame_impl;

class render_frame
{
public:
    // Constructor
    explicit render_frame(t_render_frame_params p_params);

    // Get the window's initial parameters
    const t_render_frame_params& get_params() const;

    // Get the opengl context assigned to this render frame
    context::opengl_context& get_opengl_context();
    const context::opengl_context& get_opengl_context() const;

    // Clear the current frame and prepare to start drawing to it
    void start_frame();

    // Finish the current frame and display it
    // If double buffering is used, display it
    void end_frame();

    // Show or hide the render frame
    void set_visible(const bool p_visible);
    bool is_visible() const;

private:
    // The frame's parameters
    t_render_frame_params m_params;

    // Actual implementation
    std::unique_ptr<render_frame_impl, void(*)(render_frame_impl*)> m_impl;

};  // class render_frame

}   // namespace rf
}   // namespace gl
}   // namespace ft
