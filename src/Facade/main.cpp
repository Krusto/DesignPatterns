#include <iostream>

class Renderer
{
public:
    Renderer() = default;
    ~Renderer() = default;

    void Init() { std::cout << "Renderer Init\n"; }

    void Destroy() { std::cout << "Renderer Destroy\n"; }
};

class AssetManager
{
public:
    AssetManager() = default;
    ~AssetManager() = default;

    void Init() { std::cout << "AssetManager Init\n"; }

    void Destroy() { std::cout << "AssetManager Destroy\n"; }
};

class GameEngine
{
public:
    GameEngine() = default;
    ~GameEngine() = default;

    void StartEngine()
    {
        mRenderer.Init();
        mAssetManager.Init();
    }

    void StopEngine()
    {
        mAssetManager.Destroy();
        mRenderer.Destroy();
    }

private:
    AssetManager mAssetManager;
    Renderer mRenderer;
};

int main()
{
    GameEngine engine;
    engine.StartEngine();
    engine.StopEngine();
    return 0;
}
