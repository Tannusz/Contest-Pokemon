#pragma once
#include <string>

class Evolution {
public:
    Evolution(int pokemonId, std::string pokemonName, 
             int baseLevel, std::string evolutionCondition,
             std::string evolutionItem, int beautyAttributeGrowth,
             std::string specialAbilities, std::string evolutionBonus);
    
    int getPokemonId() const { return pokemon_id; }
    const std::string& getPokemonName() const { return pokemon_name; }
    int getBaseLevel() const { return base_level; }
    const std::string& getEvolutionCondition() const { return evolution_condition; }
    const std::string& getEvolutionItem() const { return evolution_item; }
    int getBeautyAttributeGrowth() const { return beauty_attribute_growth; }
    const std::string& getSpecialAbilities() const { return special_abilities; }
    const std::string& getEvolutionBonus() const { return evolution_bonus; }
    
    void display() const;

private:
    int pokemon_id;
    std::string pokemon_name;
    int base_level;
    std::string evolution_condition;
    std::string evolution_item;
    int beauty_attribute_growth;
    std::string special_abilities;
    std::string evolution_bonus;
};