#pragma once
#include <string>

class Berry {
public:
    Berry(int id, std::string name, std::string color,
          std::string flavor, int smoothness, int size,
          int firmness, std::string description);
    
    int getId() const { return id; }
    const std::string& getName() const { return name; }
    const std::string& getColor() const { return color; }
    const std::string& getFlavor() const { return flavor; }
    int getSmoothness() const { return smoothness; }
    int getSize() const { return size; }
    int getFirmness() const { return firmness; }
    const std::string& getDescription() const { return description; }
    
    void display() const;

private:
    int id;
    std::string name;
    std::string color;
    std::string flavor;
    int smoothness;
    int size;
    int firmness;
    std::string description;
};