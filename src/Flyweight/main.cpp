#include <iostream>
#include <unordered_map>

struct Vector3 {
    uint32_t x, y, z;
};

namespace Hasher
{
    template <typename T>
    size_t hash(T x, T y, T z)
    {
        std::hash<T> hasher;
        auto h1 = hasher(x);
        auto h2 = hasher(y);
        auto h3 = hasher(z);

        return std::hash<T>{}(h1 ^ (h2 << h3) ^ h3);
    }

}// namespace Hasher

namespace std
{
    template <>
    struct hash<Vector3> {
        size_t operator()(const Vector3& pos) const { return Hasher::hash(pos.x, pos.y, pos.z); }
    };

    template <>
    struct equal_to<Vector3> {
        bool operator()(const Vector3& vec1, const Vector3& vec2) const
        {
            return (vec1.x == vec2.x) && (vec1.y == vec2.y) && (vec1.z == vec2.z);
        }
    };
}// namespace std

class Particle
{
private:
    Vector3 mLocation;

public:
    Particle(Vector3 location) : mLocation(location) {}

public:
    void Render() { std::cout << "Rendering {" << mLocation.x << "," << mLocation.y << "," << mLocation.z << "}\n"; }
};

class ParticleSystem
{
public:
    ParticleSystem() = default;

public:
    Particle* GetParticle(Vector3 location)
    {

        if (mParticles.find(location) == mParticles.end()) { mParticles.emplace(location, new Particle(location)); }

        return mParticles[location];
    }

    void Destroy()
    {
        for (auto& [position, particle]: mParticles) { delete particle; }
    }

private:
    std::unordered_map<Vector3, Particle*, std::hash<Vector3>> mParticles;
};

int main()
{
    ParticleSystem system;

    auto particle1 = system.GetParticle({0, 1, 2});
    auto particle2 = system.GetParticle({3, 1, 2});
    auto particle3 = system.GetParticle({0, 1, 2});

    particle1->Render();
    particle2->Render();
    particle3->Render();

    system.Destroy();

    return 0;
}