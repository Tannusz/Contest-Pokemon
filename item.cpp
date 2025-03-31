#include "../include/item.h"
#include <iomanip>

Item::Item(int id, std::string name, std::string type, std::string category,
         std::string description, std::string effect)
    : id(id), name(std::move(name)), type(std::move(type)),
      category(std::move(category)), description(std::move(description)),
      effect(std::move(effect)) {}

void Item::display() const {
    std::cout << "  #" << id << " " << std::setw(20) << std::left << name 
              << " Type: " << std::setw(10) << type 
              << " Category: " << category << "\n";
    std::cout << "  Effect: " << effect << "\n";
    if (!description.empty())
        std::cout << "  Desc: " << description << "\n";
}