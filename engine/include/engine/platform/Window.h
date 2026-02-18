#pragma once
#include <string>

namespace Engine
{
    struct WindowProps
    {
        std::string title = "Valkyrie Engine";
        int width = 1280;
        int height = 720;
    };

    class Window
    {
    public:
        virtual ~Window() = default;

        virtual void PollEvents() = 0;
        virtual bool ShouldClose() = 0;

        static Window* Create(WindowProps const& props = WindowProps());
    };
}