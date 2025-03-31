#pragma once
#include <string>

class Item {
public:
    Item(int id, std::string name, std::string type, 
         std::string category, std::string description, 
         std::string effect);
    
    int getId() const { return id; }
    const std::string& getName() const { return name; }
    const std::string& getType() const { return type; }
    const std::string& getCategory() const { return category; }
    const std::string& getDescription() const { return description; }
    const std::string& getEffect() const { return effect; }
    
    void display() const;

private:
    int id;
    std::string name;
    std::string type;
    std::string category;
    std::string description;
    std::string effect;
};