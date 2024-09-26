#include <iostream>

class Entity
{
public:
    ~Entity() = default;

    virtual Entity* Clone() const = 0;

    virtual std::string GetSound() const = 0;
};

class Cow: public Entity
{
public:
    Cow(std::string sound) : Sound(sound) {}

    std::string Sound;

    virtual Entity* Clone() const override { return new Cow(*this); }

    virtual std::string GetSound() const override { return Sound; }
};

class Pig: public Entity
{
public:
    Pig(std::string sound) : Sound(sound) {}

    std::string Sound;

    virtual Entity* Clone() const override { return new Pig(*this); }

    virtual std::string GetSound() const override { return Sound; }
};

int main()
{
    Pig pepe("Oink!");
    Cow koko("Moo!");

    Entity* fakePepe = pepe.Clone();
    Entity* fakeKoko = koko.Clone();

    std::cout << "fakePepe Says " << fakePepe->GetSound() << '\n';
    std::cout << "fakeKoko Says " << fakeKoko->GetSound() << '\n';

    delete fakePepe;
    delete fakeKoko;
    return 0;
}