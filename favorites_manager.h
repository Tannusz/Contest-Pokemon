#pragma once
#include <vector>
#include <string>
#include <mutex>
#include <nlohmann/json.hpp>

class FavoritesManager {
public:
    explicit FavoritesManager(const std::string& filePath);
    
    void addFavorite(int pokemonId);
    void removeFavorite(int pokemonId);
    bool isFavorite(int pokemonId) const;
    std::vector<int> getFavorites() const;
    
    void load();
    void save() const;
    
private:
    std::string filePath;
    std::vector<int> favorites;
    mutable std::mutex mutex;
    
    void ensureFileExists() const;
};