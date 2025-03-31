#include "../include/berry.h"
#include <iomanip>

Berry::Berry(int id, std::string name, std::string color, std::string flavor,
           int smoothness, int size, int firmness, std::string description)
    : id(id), name(std::move(name)), color(std::move(color)),
      flavor(std::move(flavor)), smoothness(smoothness), size(size),
      firmness(firmness), description(std::move(description)) {}

void Berry::display() const {
    std::cout << "  " << std::setw(15) << std::left << name 
              << " Color: " << std::setw(10) << color 
              << " Flavor: " << std::setw(10) << flavor << "\n";
    std::cout << "  Smoothness: " << smoothness 
              << " | Size: " << size 
              << " | Firmness: " << firmness << "\n";
    std::cout << "  " << description << "\n";
}