#include <iostream>

class OldTerminal
{
public:
    OldTerminal() = default;
    ~OldTerminal() = default;

    void Print(const std::string_view message) const { std::cout << message; }
};

class Computer
{
public:
    Computer() = default;
    ~Computer() = default;

    void SendToConsole(const std::string_view message) const { std::cout << message; }
};

class TerminalAdapter
{
public:
    TerminalAdapter() = default;
    ~TerminalAdapter() = default;

    void SendToConsole(const std::string_view message) const { m_Terminal.Print(message); }

private:
    OldTerminal m_Terminal;
};

int main()
{
    TerminalAdapter terminal;
    Computer computer;

    terminal.SendToConsole("Using old terminal to print!\n");
    computer.SendToConsole("Using computer to print!\n");

    return 0;
}