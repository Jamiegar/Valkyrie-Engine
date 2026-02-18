#pragma once
#include <engine/platform/Window.h>
#include <memory>

namespace Engine
{
    class Application
    {
    public:
        void Run();

    private:
        void Initialize();
        void Shutdown();

        void ProcessInput();
        void Update(float dt);
        void Render();

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };
}