#include "../include/favorites_manager.h"
#include <filesystem>
#include <fstream>
#include <algorithm>

FavoritesManager::FavoritesManager(const std::string& filePath) 
    : filePath(filePath) {
    load();
}

void FavoritesManager::addFavorite(int pokemonId) {
    std::lock_guard<std::mutex> lock(mutex);
    if (!isFavorite(pokemonId)) {
        favorites.push_back(pokemonId);
        save();
    }
}

void FavoritesManager::removeFavorite(int pokemonId) {
    std::lock_guard<std::mutex> lock(mutex);
    auto it = std::find(favorites.begin(), favorites.end(), pokemonId);
    if (it != favorites.end()) {
        favorites.erase(it);
        save();
    }
}

bool FavoritesManager::isFavorite(int pokemonId) const {
    std::lock_guard<std::mutex> lock(mutex);
    return std::find(favorites.begin(), favorites.end(), pokemonId) != favorites.end();
}

std::vector<int> FavoritesManager::getFavorites() const {
    std::lock_guard<std::mutex> lock(mutex);
    return favorites;
}

void FavoritesManager::load() {
    std::lock_guard<std::mutex> lock(mutex);
    ensureFileExists();
    
    std::ifstream file(filePath);
    if (file.is_open()) {
        try {
            nlohmann::json j;
            file >> j;
            favorites = j.get<std::vector<int>>();
        } catch (const nlohmann::json::exception&) {
            favorites.clear();
        }
    }
}

void FavoritesManager::save() const {
    std::lock_guard<std::mutex> lock(mutex);
    ensureFileExists();
    
    std::ofstream file(filePath);
    if (file.is_open()) {
        nlohmann::json j = favorites;
        file << j.dump(4);
    }
}

void FavoritesManager::ensureFileExists() const {
    namespace fs = std::filesystem;
    fs::path path(filePath);
    
    if (!fs::exists(path.parent_path())) {
        fs::create_directories(path.parent_path());
    }
    
    if (!fs::exists(path)) {
        std::ofstream file(filePath);
        if (file.is_open()) {
            file << nlohmann::json::array().dump();
        }
    }
}