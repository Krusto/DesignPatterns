#include <iostream>

enum class CarEngineType
{
    None,
    Regular,
    Sports
};
enum class CarWheelType
{
    None,
    Steel,
    Alloy
};
enum class CarSuspensionType
{
    None,
    Regular,
    Sports
};

class Car
{
public:
    Car() = default;
    ~Car() = default;

public:
    void PrintSpecs()
    {
        std::cout << "Specs: \n";
        switch (pEngineType)
        {
            case CarEngineType::Regular:
                std::cout << "Regular Engine\n";
                break;
            case CarEngineType::Sports:
                std::cout << "Sports Engine\n";
                break;
            default:
                std::cout << "Unknown Engine\n";
        }
        switch (pWheelType)
        {
            case CarWheelType::Steel:
                std::cout << "Steel Wheels\n";
                break;
            case CarWheelType::Alloy:
                std::cout << "Alloy Wheels\n";
                break;
            default:
                std::cout << "Unknown wheels type";
                break;
        }
        switch (pSuspensionType)
        {
            case CarSuspensionType::Regular:
                std::cout << "Regular Suspension\n";
                break;
            case CarSuspensionType::Sports:
                std::cout << "Sports suspension\n";
                break;
            default:
                std::cout << "Unknown suspension\n";
                break;
        }
        if (pHasMuffler) { std::cout << "Included Muffler\n"; }
        else { std::cout << "Without Muffler\n"; }
    }

protected:
    CarEngineType pEngineType;
    CarWheelType pWheelType;
    CarSuspensionType pSuspensionType;
    bool pHasMuffler;

    friend class CarBuilder;
};

class CarBuilder
{
public:
    CarBuilder() { mResult = new Car(); }

public:
    void AddEngine() { mResult->pEngineType = CarEngineType::Regular; }

    void AddSportsEngine() { mResult->pEngineType = CarEngineType::Sports; }

    void AddWheels() { mResult->pWheelType = CarWheelType::Steel; }

    void AddAlloyWheels() { mResult->pWheelType = CarWheelType::Alloy; }

    void AddMuffler() { mResult->pHasMuffler = true; }

    void AddSuspension() { mResult->pSuspensionType = CarSuspensionType::Regular; }

    void AddSportsSuspension() { mResult->pSuspensionType = CarSuspensionType::Sports; }

    void Reset() { mResult = new Car(); }

    Car* GetResult() { return mResult; }

private:
    Car* mResult;
};

class CarDirector
{
public:
    CarDirector(CarBuilder* builder) { mBuilder = builder; }

    ~CarDirector() = default;

    void MakeCoolCar()
    {
        mBuilder->Reset();
        mBuilder->AddSportsEngine();
        mBuilder->AddAlloyWheels();
        mBuilder->AddSportsSuspension();
        mBuilder->AddMuffler();
    }

    void MakeBoringCar()
    {
        mBuilder->Reset();
        mBuilder->AddEngine();
        mBuilder->AddWheels();
        mBuilder->AddSuspension();
    }

private:
    CarBuilder* mBuilder;
};

int main()
{
    CarBuilder builder;
    CarDirector director(&builder);

    director.MakeCoolCar();
    Car* coolCar = builder.GetResult();

    director.MakeBoringCar();
    Car* boringCar = builder.GetResult();

    std::cout << "=================================\n";
    std::cout << "Cool Car:\n";
    coolCar->PrintSpecs();

    std::cout << "=================================\n";
    std::cout << "Boring Car:\n";
    boringCar->PrintSpecs();

    delete coolCar;
    delete boringCar;

    return 0;
}