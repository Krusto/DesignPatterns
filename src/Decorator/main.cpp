#include <iostream>
#include <string>

class IceCream
{
public:
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
};

class VanillaIceCream: public IceCream
{
public:
    std::string getDescription() const override { return "Vanilla Ice Cream"; }

    double cost() const override { return 160.0; }
};

class IceCreamDecorator: public IceCream
{
public:
    IceCreamDecorator(IceCream* ic) : iceCream(ic) {}

    std::string getDescription() const override { return iceCream->getDescription(); }

    double cost() const override { return iceCream->cost(); }

protected:
    IceCream* iceCream;
};

class ChocolateDecorator: public IceCreamDecorator
{
public:
    ChocolateDecorator(IceCream* ic) : IceCreamDecorator(ic) {}

    std::string getDescription() const override { return iceCream->getDescription() + " with Chocolate"; }

    double cost() const override { return iceCream->cost() + 100.0; }
};

int main()
{
    IceCream* vanillaIceCream = new VanillaIceCream();
    std::cout << "Order: " << vanillaIceCream->getDescription() << ", Cost: Rs." << vanillaIceCream->cost()
              << std::endl;

    IceCream* chocolateIceCream = new ChocolateDecorator(vanillaIceCream);
    std::cout << "Order: " << chocolateIceCream->getDescription() << ", Cost: Rs." << chocolateIceCream->cost()
              << std::endl;

    delete vanillaIceCream;
    delete chocolateIceCream;

    return 0;
}
