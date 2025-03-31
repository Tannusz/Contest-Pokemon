#include "../include/evolution.h"
#include <iostream>

Evolution::Evolution(int pokemonId, std::string pokemonName, int baseLevel,
                   std::string evolutionCondition, std::string evolutionItem,
                   int beautyAttributeGrowth, std::string specialAbilities,
                   std::string evolutionBonus)
    : pokemon_id(pokemonId), pokemon_name(std::move(pokemonName)),
      base_level(baseLevel), evolution_condition(std::move(evolutionCondition)),
      evolution_item(std::move(evolutionItem)), 
      beauty_attribute_growth(beautyAttributeGrowth),
      special_abilities(std::move(specialAbilities)),
      evolution_bonus(std::move(evolutionBonus)) {}

void Evolution::display() const {
    std::cout << "  From: " << pokemon_name << " (Lv. " << base_level << ")\n";
    std::cout << "  Condition: " << evolution_condition;
    if (!evolution_item.empty()) std::cout << " with " << evolution_item;
    std::cout << "\n";
    if (beauty_attribute_growth > 0)
        std::cout << "  Beauty requirement: " << beauty_attribute_growth << "\n";
    if (!special_abilities.empty())
        std::cout << "  Gains: " << special_abilities << "\n";
    if (!evolution_bonus.empty())
        std::cout << "  Bonus: " << evolution_bonus << "\n";
}