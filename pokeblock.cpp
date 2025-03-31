#include "../include/pokeblock.h"
#include <iomanip>

Pokeblock::Pokeblock(int id, std::string color, std::string attribute,
                   std::string recommendedBerries, std::string levelRange,
                   std::string specialEffects, std::string requiredContestStats)
    : id(id), color(std::move(color)), attribute(std::move(attribute)),
      recommendedBerries(std::move(recommendedBerries)), levelRange(std::move(levelRange)),
      specialEffects(std::move(specialEffects)), requiredContestStats(std::move(requiredContestStats)) {}

void Pokeblock::display() const {
    std::cout << "  #" << id << " " << std::setw(10) << std::left << color 
              << " Attribute: " << std::setw(10) << attribute 
              << " Level: " << levelRange << "\n";
    std::cout << "  Berries: " << recommendedBerries << "\n";
    if (!specialEffects.empty())
        std::cout << "  Special: " << specialEffects << "\n";
    if (!requiredContestStats.empty())
        std::cout << "  Requires: " << requiredContestStats << "\n";
}