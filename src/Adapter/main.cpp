#include <iostream>
#include <vector>

struct Vec3 {
    uint32_t x, y, z;

    void Move(const Vec3& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
    }
};

class Object
{
public:
    ~Object() = default;

    virtual void Move(Vec3 velocity)
    {
        pPosition.Move(velocity);
        for (auto& child: mChildren) { child->Move(velocity); }
    }

    virtual void Print()
    {
        std::cout << GetType() << " {" << pPosition.x << "," << pPosition.y << "," << pPosition.z << "}\n";
        for (auto& child: mChildren) { child->Print(); }
    }

    virtual void SetPosition(Vec3 position) { pPosition = position; }

    virtual Vec3 GetPosition() { return pPosition; }

    virtual std::string_view GetType() { return "Object"; }

public:
    std::string_view GetName() const { return pName; }

    void AddChild(Object* object) { mChildren.push_back(object); }

    Object* Get(uint32_t index) { return mChildren[index]; }

    std::vector<Object*>& GetChildren() { return mChildren; }

protected:
    Object(std::string_view Name, Vec3 Position) : pName(Name), pPosition(Position) {}

    Vec3 pPosition;
    std::string_view pName;

private:
    std::vector<Object*> mChildren;
};

class Player: public Object
{
public:
    Player(std::string_view Name, Vec3 Position) : Object(Name, Position) {}

    ~Player() = default;

public:
    virtual std::string_view GetType() { return "Player"; }
};

class Cube: public Object
{
public:
    Cube(std::string_view Name, Vec3 Position) : Object(Name, Position) {}

    ~Cube() = default;

public:
    virtual std::string_view GetType() { return "Cube"; }
};

int main()
{
    Cube* cube = new Cube("Cube1", Vec3{0, 1, 2});
    Cube* cube2 = new Cube("Cube2", Vec3{1, 2, 1});
    Player* player = new Player("player", Vec3{3, 2, 1});

    player->AddChild(cube);
    player->AddChild(cube2);

    player->Print();

    player->Move(Vec3{1, 0, 0});
    std::cout << "\n\n";
    player->Print();

    delete player;
    delete cube;
    delete cube2;
    return 0;
}