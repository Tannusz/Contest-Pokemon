#pragma once
#include <string>
#include <utility>
#include <vector>
#include <memory>

class Pokemon {
public:
    using StatType = int;
    using IdType = int;
    
    Pokemon(IdType id, std::string name, 
           std::string type1, std::string type2,
           StatType hp, StatType attack, StatType defense,
           StatType spAttack, StatType spDefense, StatType speed,
           StatType cool, StatType beauty, StatType cute,
           StatType smart, StatType tough, StatType stamina,
           StatType charisma, StatType accuracy,
           std::string description);
    
    // Getters
    IdType getId() const { return id; }
    const std::string& getName() const { return name; }
    std::pair<std::string, std::string> getTypes() const { return {type1, type2}; }
    StatType getHp() const { return hp; }
    StatType getAttack() const { return attack; }
    StatType getDefense() const { return defense; }
    StatType getSpAttack() const { return spAttack; }
    StatType getSpDefense() const { return spDefense; }
    StatType getSpeed() const { return speed; }
    StatType getCool() const { return cool; }
    StatType getBeauty() const { return beauty; }
    StatType getCute() const { return cute; }
    StatType getSmart() const { return smart; }
    StatType getTough() const { return tough; }
    StatType getStamina() const { return stamina; }
    StatType getCharisma() const { return charisma; }
    StatType getAccuracy() const { return accuracy; }
    const std::string& getDescription() const { return description; }
    
    // Display methods
    void displayBasic() const;
    void displayFull() const;
    void displayComparison(const Pokemon& other) const;
    
    // Operators
    bool operator==(const Pokemon& other) const { return id == other.id; }
    bool operator<(const Pokemon& other) const { return id < other.id; }

private:
    IdType id;
    std::string name;
    std::string type1;
    std::string type2;
    StatType hp;
    StatType attack;
    StatType defense;
    StatType spAttack;
    StatType spDefense;
    StatType speed;
    StatType cool;
    StatType beauty;
    StatType cute;
    StatType smart;
    StatType tough;
    StatType stamina;
    StatType charisma;
    StatType accuracy;
    std::string description;
    
    void displayStats() const;
    void displayContestStats() const;
    void displayDescription() const;
};