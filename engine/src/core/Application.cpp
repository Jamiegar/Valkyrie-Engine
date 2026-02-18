#include <engine/Application.h>
#include <chrono>
#include <thread>
#include <iostream>

namespace Engine
{
    void Application::Run()
    {
        Initialize();

        using clock = std::chrono::high_resolution_clock;
        auto lastTime = clock::now();

        while (m_Running && !m_Window->ShouldClose())
        {
            auto startTime = clock::now();
            std::chrono::duration<double> delta = startTime - lastTime;
            lastTime = startTime;

            m_Window->PollEvents();

            ProcessInput();
            Update(delta.count());
            Render();
        }

        Shutdown();
    }

    void Application::Initialize()
    {
        m_Window.reset(Window::Create());
    }

    void Application::Shutdown()
    {
        std::cout << "Engine Shutdown\n";
    }

    void Application::ProcessInput()
    {
        
    }

    void Application::Update(float dt)
    {
    }

    void Application::Render()
    {
    }
}