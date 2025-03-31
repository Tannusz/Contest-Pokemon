#include "../include/pokemon_repository.h"
#include <algorithm>

CachedPokemonRepository::CachedPokemonRepository(std::unique_ptr<IPokemonRepository> baseRepository) 
    : baseRepository(std::move(baseRepository)) {
    rebuildCache();
}

std::shared_ptr<Pokemon> CachedPokemonRepository::findById(int id) const {
    std::lock_guard<std::mutex> lock(cacheMutex);
    auto it = idCache.find(id);
    return it != idCache.end() ? it->second : nullptr;
}

std::vector<std::shared_ptr<Pokemon>> CachedPokemonRepository::findByName(const std::string& name) const {
    std::lock_guard<std::mutex> lock(cacheMutex);
    std::vector<std::shared_ptr<Pokemon>> result;
    std::string lowerName = toLower(name);
    
    auto range = nameCache.equal_range(lowerName);
    for (auto it = range.first; it != range.second; ++it) {
        result.push_back(it->second);
    }
    
    return result;
}

std::vector<std::shared_ptr<Pokemon>> CachedPokemonRepository::findByType(const std::string& type) const {
    std::lock_guard<std::mutex> lock(cacheMutex);
    std::vector<std::shared_ptr<Pokemon>> result;
    std::string lowerType = toLower(type);
    
    auto range = typeCache.equal_range(lowerType);
    for (auto it = range.first; it != range.second; ++it) {
        result.push_back(it->second);
    }
    
    return result;
}

std::vector<std::shared_ptr<Pokemon>> CachedPokemonRepository::getAll() const {
    std::lock_guard<std::mutex> lock(cacheMutex);
    return allCache;
}

void CachedPokemonRepository::reload() {
    std::lock_guard<std::mutex> lock(cacheMutex);
    baseRepository->reload();
    rebuildCache();
}

void CachedPokemonRepository::rebuildCache() const {
    idCache.clear();
    nameCache.clear();
    typeCache.clear();
    allCache = baseRepository->getAll();
    
    for (const auto& pokemon : allCache) {
        idCache[pokemon->getId()] = pokemon;
        
        std::string lowerName = toLower(pokemon->getName());
        nameCache.emplace(lowerName, pokemon);
        
        auto types = pokemon->getTypes();
        std::string lowerType1 = toLower(types.first);
        typeCache.emplace(lowerType1, pokemon);
        
        if (!types.second.empty()) {
            std::string lowerType2 = toLower(types.second);
            typeCache.emplace(lowerType2, pokemon);
        }
    }
}

std::string CachedPokemonRepository::toLower(const std::string& str) const {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
                  [](unsigned char c) { return std::tolower(c); });
    return lowerStr;
}