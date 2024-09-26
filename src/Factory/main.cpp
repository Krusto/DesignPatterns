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

class OpenGLContext: public API
{
public:
    virtual void Log(std::string_view message) const override
    {
        std::cout << "OpenGLAPI LOG: " << std::string(message) << "\n";
    }
};

class VulkanContext: public API
{
public:
    virtual void Log(std::string_view message) const override
    {
        std::cout << "VulkanAPI LOG: " << std::string(message) << "\n";
    }
};

class Renderer
{
public:
    static API* CreateContext(API_Types type)
    {
        API* renderingContext{nullptr};
        switch (type)
        {
            case API_OPENGL:
                renderingContext = new OpenGLContext();
                break;
            case API_VULKAN:
                renderingContext = new VulkanContext();
                break;
            default:
                std::cout << "Unknown API!";
                break;
        }
        return renderingContext;
    }

private:
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

    API* renderer = Renderer::CreateContext(selectedType);

    if (nullptr == renderer) return -1;

    renderer->Log("Created context");

    delete renderer;
    return 0;
}