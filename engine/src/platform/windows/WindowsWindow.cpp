#include <engine/platform/Window.h>
#include <windows.h>

namespace Engine
{
    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(WindowProps const& props)
        {
            WNDCLASS wc = { };
            wc.lpfnWndProc = WindowProc;
            wc.hInstance = GetModuleHandle(nullptr);
            wc.lpszClassName = "ValkyrieWindowClass";

            RegisterClass(&wc);

            m_Handle = CreateWindowEx(
                0,
                wc.lpszClassName,
                "Valkyrie Engine",
                WS_OVERLAPPEDWINDOW,
                CW_USEDEFAULT, CW_USEDEFAULT, 
                props.width, props.height,
                nullptr,
                nullptr,
                wc.hInstance,
                nullptr
            );

            ShowWindow(m_Handle, SW_SHOW);
        }

        ~WindowsWindow() override
        {
            DestroyWindow(m_Handle);
        }

        void PollEvents() override
        {
            MSG msg;

            while(PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);

                if (msg.message == WM_QUIT)
                {
                    m_ShouldClose = true;
                }
            }
        }

        bool ShouldClose() override
        {
            return m_ShouldClose;
        }
    private:
        HWND m_Handle = nullptr;
        bool m_ShouldClose = false;

        static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
        {
            switch (msg)
            {
                case WM_DESTROY:
                {
                    PostQuitMessage(0);
                    return 0;
                }
                default:
                {
                    return DefWindowProc(hwnd, msg, wParam, lParam);
                }
            }
        }
    };

    Window* Window::Create(WindowProps const& props)
    {
        return new WindowsWindow(props);
    }
}

