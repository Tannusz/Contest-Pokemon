#include "../include/move.h"
#include <iomanip>

Move::Move(std::string pokemonName, std::string moveName, std::string category,
         int appealPoints, int jamPoints, std::string effect)
    : pokemonName(std::move(pokemonName)), moveName(std::move(moveName)),
      category(std::move(category)), appealPoints(appealPoints),
      jamPoints(jamPoints), effect(std::move(effect)) {}

void Move::display() const {
    std::cout << "  " << std::setw(20) << std::left << moveName 
              << " [" << std::setw(8) << category << "] "
              << "AP: " << std::setw(2) << appealPoints
              << " JP: " << std::setw(2) << jamPoints << "\n";
    std::cout << "  Effect: " << effect << "\n";
}