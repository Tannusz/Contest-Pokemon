#pragma once
#include "pokemon.h"
#include <memory>
#include <vector>
#include <unordered_map>
#include <mutex>

class IPokemonRepository {
public:
    virtual ~IPokemonRepository() = default;
    
    virtual std::shared_ptr<Pokemon> findById(int id) const = 0;
    virtual std::vector<std::shared_ptr<Pokemon>> findByName(const std::string& name) const = 0;
    virtual std::vector<std::shared_ptr<Pokemon>> findByType(const std::string& type) const = 0;
    virtual std::vector<std::shared_ptr<Pokemon>> getAll() const = 0;
    
    virtual void reload() = 0;
};

class CachedPokemonRepository : public IPokemonRepository {
public:
    explicit CachedPokemonRepository(std::unique_ptr<IPokemonRepository> baseRepository);
    
    std::shared_ptr<Pokemon> findById(int id) const override;
    std::vector<std::shared_ptr<Pokemon>> findByName(const std::string& name) const override;
    std::vector<std::shared_ptr<Pokemon>> findByType(const std::string& type) const override;
    std::vector<std::shared_ptr<Pokemon>> getAll() const override;
    
    void reload() override;

private:
    std::unique_ptr<IPokemonRepository> baseRepository;
    mutable std::unordered_map<int, std::shared_ptr<Pokemon>> idCache;
    mutable std::unordered_multimap<std::string, std::shared_ptr<Pokemon>> nameCache;
    mutable std::unordered_multimap<std::string, std::shared_ptr<Pokemon>> typeCache;
    mutable std::vector<std::shared_ptr<Pokemon>> allCache;
    mutable std::mutex cacheMutex;
    
    void rebuildCache() const;
};