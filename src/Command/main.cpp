#include <iostream>
#include <vector>

class Command
{
public:
    virtual void Execute() = 0;
};

class AddCommand: public Command
{

public:
    AddCommand(int32_t A, int32_t B) : mA(A), mB(B) {}

    ~AddCommand() = default;

    virtual void Execute() override { std::cout << mA + mB << '\n'; }

private:
    int32_t mA{}, mB{};
};

class SubCommand: public Command
{

public:
    SubCommand(int32_t A, int32_t B) : mA(A), mB(B) {}

    ~SubCommand() = default;

    virtual void Execute() override { std::cout << mA - mB << '\n'; }

private:
    int32_t mA{}, mB{};
};

class CommandQueue
{
public:
    CommandQueue() = default;

public:
    void PushCommand(Command* command) { mCommands.push_back(command); }

    void Flush()
    {
        for (auto& command: mCommands) { command->Execute(); }
    }

private:
    std::vector<Command*> mCommands;
};

int main()
{

    int32_t a = 5, b = 10;

    Command* add = new AddCommand(a, b);
    Command* sub = new SubCommand(a, b);

    CommandQueue myQueue;
    myQueue.PushCommand(add);
    myQueue.PushCommand(sub);
    myQueue.Flush();

    return 0;
}