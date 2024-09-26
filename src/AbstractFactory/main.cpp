#include <functional>
#include <iostream>

enum API_Types
{
    API_NONE = 0,
    API_OPENGL,
    API_VULKAN
};

class API
{
public:
    virtual void Log(std::string_view message) const = 0;
};

class OpenGLAPI: public API
{
public:
    virtual void Log(std::string_view message) const override
    {
        std::cout << "OpenGLAPI LOG: " << std::string(message) << "\n";
    }
};

class VulkanAPI: public API
{
public:
    virtual void Log(std::string_view message) const override
    {
        std::cout << "VulkanAPI LOG: " << std::string(message) << "\n";
    }
};

class RenderingContext
{
public:
    virtual API* Create() = 0;
};

class OpenGLRenderingContext: public RenderingContext
{
public:
    ~OpenGLRenderingContext() = default;

    virtual API* Create() override { return new OpenGLAPI(); }
};

class VulkanRenderingContext: public RenderingContext
{
public:
    ~VulkanRenderingContext() = default;

    virtual API* Create() override { return new VulkanAPI(); }
};

class GameEngine
{
public:
    static RenderingContext* CreateContext(API_Types type)
    {
        RenderingContext* RenderingContext{nullptr};
        switch (type)
        {
            case API_OPENGL:
                RenderingContext = new OpenGLRenderingContext();
                break;
            case API_VULKAN:
                RenderingContext = new VulkanRenderingContext();
                break;
            default:
                std::cout << "Unknown API!";
                break;
        }
        return RenderingContext;
    }
};

int main()
{
    std::cout << "Select API: 0(OpenGL),1(Vulkan)\n";

    std::string type;
    std::cin >> type;

    uint32_t typeID = (std::isdigit(type[0])) ? (type[0] - '0') : 2;
    API_Types selectedType = API_NONE;
    switch (typeID)
    {
        case 0:
            selectedType = API_OPENGL;
            break;
        case 1:
            selectedType = API_VULKAN;
            break;
    }

    RenderingContext* context = GameEngine::CreateContext(selectedType);

    if (nullptr == context) return -1;

    API* renderer = context->Create();
    renderer->Log("Created context");

    delete renderer;
    delete context;
    return 0;
}