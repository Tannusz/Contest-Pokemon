#include "../include/command.h"
#include <iostream>

Menu::Menu(std::string title, std::vector<std::unique_ptr<Command>> commands)
    : title(std::move(title)), commands(std::move(commands)) {}

void Menu::show() {
    while (true) {
        std::cout << "\n" << title << "\n";
        std::cout << std::string(title.length(), '=') << "\n";
        
        for (const auto& cmd : commands) {
            std::cout << cmd->getName() << ". " << cmd->getDescription() << "\n";
        }
        std::cout << "0. Exit\n";
        
        std::cout << "Select an option: ";
        std::string input;
        std::cin >> input;
        
        if (input == "0") {
            break;
        }
        
        auto it = std::find_if(commands.begin(), commands.end(),
            [&input](const std::unique_ptr<Command>& cmd) {
                return cmd->getName() == input;
            });
        
        if (it != commands.end()) {
            (*it)->execute();
        } else {
            std::cout << "Invalid option!\n";
        }
    }
}

void Menu::addCommand(std::unique_ptr<Command> command) {
    commands.push_back(std::move(command));
}