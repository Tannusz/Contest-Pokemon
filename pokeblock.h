#pragma once
#include <string>

class Pokeblock {
public:
    Pokeblock(int id, std::string color, std::string attribute,
              std::string recommendedBerries, std::string levelRange,
              std::string specialEffects, std::string requiredContestStats);
    
    int getId() const { return id; }
    const std::string& getColor() const { return color; }
    const std::string& getAttribute() const { return attribute; }
    const std::string& getRecommendedBerries() const { return recommendedBerries; }
    const std::string& getLevelRange() const { return levelRange; }
    const std::string& getSpecialEffects() const { return specialEffects; }
    const std::string& getRequiredContestStats() const { return requiredContestStats; }
    
    void display() const;

private:
    int id;
    std::string color;
    std::string attribute;
    std::string recommendedBerries;
    std::string levelRange;
    std::string specialEffects;
    std::string requiredContestStats;
};