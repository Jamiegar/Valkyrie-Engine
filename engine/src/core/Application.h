#pragma once

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

        bool m_Running = true;
    };
}