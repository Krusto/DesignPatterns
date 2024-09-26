#include <iostream>

class Application
{
public:
    ~Application() = default;

    const std::string GetName() const { return m_Name; }

    static void Create() { Application::s_Application = new Application(); }

    static void Destroy()
    {
        if (!Application::s_Application) { delete Application::s_Application; }
    }

    static Application* GetInstance() { return Application::s_Application; }

private:
    const std::string m_Name = "Example Application";

    inline static Application* s_Application{};
};

int main()
{

    Application::Create();
    Application* appInstance = Application::GetInstance();

    std::cout << "Application Name: " << appInstance->GetName() << "\n";

    Application::Destroy();

    return 0;
}