#pragma once
#include <string>

class Move {
public:
    Move(std::string pokemonName, std::string moveName, 
         std::string category, int appealPoints, 
         int jamPoints, std::string effect);
    
    const std::string& getPokemonName() const { return pokemonName; }
    const std::string& getMoveName() const { return moveName; }
    const std::string& getCategory() const { return category; }
    int getAppealPoints() const { return appealPoints; }
    int getJamPoints() const { return jamPoints; }
    const std::string& getEffect() const { return effect; }
    
    void display() const;

private:
    std::string pokemonName;
    std::string moveName;
    std::string category;
    int appealPoints;
    int jamPoints;
    std::string effect;
};