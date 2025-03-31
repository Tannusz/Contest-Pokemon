#include "../include/pokemon.h"
#include <iomanip>
#include <algorithm>

Pokemon::Pokemon(IdType id, std::string name, std::string type1, std::string type2,
               StatType hp, StatType attack, StatType defense, StatType spAttack,
               StatType spDefense, StatType speed, StatType cool, StatType beauty,
               StatType cute, StatType smart, StatType tough, StatType stamina,
               StatType charisma, StatType accuracy, std::string description)
    : id(id), name(std::move(name)), type1(std::move(type1)), type2(std::move(type2)),
      hp(hp), attack(attack), defense(defense), spAttack(spAttack),
      spDefense(spDefense), speed(speed), cool(cool), beauty(beauty),
      cute(cute), smart(smart), tough(tough), stamina(stamina),
      charisma(charisma), accuracy(accuracy), description(std::move(description)) {}

void Pokemon::displayBasic() const {
    std::cout << "┌────────────────────────────────────────────────────┐\n";
    std::cout << "│ #" << std::setw(3) << id << " " << std::setw(30) << std::left << name << std::right << "          │\n";
    std::cout << "├────────────────────────────────────────────────────┤\n";
    std::cout << "│ Types: " << std::setw(10) << std::left << type1;
    if (!type2.empty()) std::cout << "/" << type2;
    std::cout << std::right << std::string(36 - (10 + type1.length() + (type2.empty() ? 0 : type2.length() + 1)), ' ') << "│\n";
}

void Pokemon::displayFull() const {
    displayBasic();
    std::cout << "│                                                    │\n";
    displayStats();
    std::cout << "│                                                    │\n";
    displayContestStats();
    std::cout << "│                                                    │\n";
    displayDescription();
    std::cout << "└────────────────────────────────────────────────────┘\n";
}

void Pokemon::displayStats() const {
    std::cout << "│ Stats:                                             │\n";
    std::cout << "│   HP: " << std::setw(3) << hp << "   Attack: " << std::setw(3) << attack 
              << "   Defense: " << std::setw(3) << defense << "        │\n";
    std::cout << "│ Sp.Atk: " << std::setw(3) << spAttack << " Sp.Def: " << std::setw(3) << spDefense 
              << " Speed: " << std::setw(3) << speed << "         │\n";
}

void Pokemon::displayContestStats() const {
    std::cout << "│ Contest Stats:                                     │\n";
    std::cout << "│   Cool: " << std::setw(3) << cool << " Beauty: " << std::setw(3) << beauty 
              << "  Cute: " << std::setw(3) << cute << "          │\n";
    std::cout << "│ Smart: " << std::setw(3) << smart << " Tough: " << std::setw(3) << tough 
              << " Stamina: " << std::setw(3) << stamina << "       │\n";
}

void Pokemon::displayDescription() const {
    std::cout << "│ Description:                                       │\n";
    size_t pos = 0;
    while (pos < description.length()) {
        size_t end = std::min(pos + 50, description.length());
        std::string line = description.substr(pos, end - pos);
        std::cout << "│ " << std::setw(49) << std::left << line << std::right << " │\n";
        pos = end;
    }
}

void Pokemon::displayComparison(const Pokemon& other) const {
    std::cout << "┌──────────────────────────┬──────────────────────────┐\n";
    std::cout << "│ " << std::setw(24) << std::left << name << " │ " 
              << std::setw(24) << std::left << other.name << " │\n";
    std::cout << "├──────────────────────────┼──────────────────────────┤\n";
    
    std::cout << "│ Types: " << std::setw(15) << std::left << (type1 + (type2.empty() ? "" : "/" + type2))
              << " │ Types: " << std::setw(15) << std::left << (other.type1 + (other.type2.empty() ? "" : "/" + other.type2)) << " │\n";
    
    auto compareStat = [](int a, int b, const std::string& statName) {
        std::cout << "│ " << statName << ": " << std::setw(4) << a;
        if (a > b) std::cout << " (+" << (a - b) << ")";
        else if (a < b) std::cout << " (-" << (b - a) << ")";
        else std::cout << " (=)";
    };
    
    std::cout << "├──────────────────────────┼──────────────────────────┤\n";
    std::cout << "│ Stats:                  │ Stats:                  │\n";
    
    std::cout << "│ ";
    compareStat(hp, other.hp, "HP");
    std::cout << "         │ ";
    compareStat(other.hp, hp, "HP");
    std::cout << "         │\n";
    
    // Continue para outros stats...
    
    std::cout << "└──────────────────────────┴──────────────────────────┘\n";
}