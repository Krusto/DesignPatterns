#include <iostream>

class Image
{
public:
    virtual void Bind() = 0;
};

class OpenGLImage: public Image
{
public:
    OpenGLImage(std::string_view name) : mName(name) {}

public:
    virtual void Bind() override { std::cout << "Bound Image " << mName << '\n'; }

private:
    std::string mName;
};

class ImageProxy: public Image
{
public:
    ImageProxy(std::string_view name) : mName(name) {}

    ~ImageProxy()
    {
        if (mImage) { delete mImage; }
    }

public:
    virtual void Bind() override
    {
        if (nullptr == mImage) { mImage = new OpenGLImage(mName); }

        mImage->Bind();
    }

private:
    Image* mImage{};
    std::string_view mName;
};

int main()
{
    ImageProxy* imageProxy = new ImageProxy("example image");

    imageProxy->Bind();
    imageProxy->Bind();
    imageProxy->Bind();

    delete imageProxy;

    return 0;
}
