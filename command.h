#pragma once
#include <functional>
#include <memory>
#include <vector>
#include <string>

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual std::string getName() const = 0;
    virtual std::string getDescription() const = 0;
};

class Menu {
public:
    Menu(std::string title, std::vector<std::unique_ptr<Command>> commands);
    
    void show();
    void addCommand(std::unique_ptr<Command> command);
    
private:
    std::string title;
    std::vector<std::unique_ptr<Command>> commands;
};