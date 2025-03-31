#pragma once
#include "pokemon.h"
#include "move.h"
#include "evolution.h"
#include "item.h"
#include "pokeblock.h"
#include "berry.h"
#include "contest_judge.h"
#include "pokemon_repository.h"
#include "favorites_manager.h"
#include "contest_pokedex.h" // Nova inclusão
#include <memory>
#include <vector>
#include <unordered_map>

class Pokedex {
public:
    Pokedex(std::unique_ptr<IPokemonRepository> pokemonRepo,
            std::unique_ptr<IPokemonRepository> moveRepo,
            std::unique_ptr<IPokemonRepository> evolutionRepo,
            std::unique_ptr<IPokemonRepository> itemRepo,
            std::unique_ptr<IPokemonRepository> pokeblockRepo,
            std::unique_ptr<IPokemonRepository> berryRepo,
            std::unique_ptr<IPokemonRepository> judgeRepo,
            std::unique_ptr<FavoritesManager> favoritesManager);
    
    // ---- Operações com Pokémon ----
    std::shared_ptr<Pokemon> findPokemonById(int id) const;
    std::vector<std::shared_ptr<Pokemon>> findPokemonByName(const std::string& name) const;
    std::vector<std::shared_ptr<Pokemon>> findPokemonByType(const std::string& type) const;
    
    // ---- Operações com Moves ----
    std::vector<std::shared_ptr<Move>> getMovesForPokemon(const std::string& pokemonName) const;
    
    // ---- Operações com Evoluções ----
    std::vector<std::shared_ptr<Evolution>> getEvolutionsForPokemon(int pokemonId) const;
    
    // ---- Gerenciamento de Favoritos ----
    void addFavorite(int pokemonId);
    void removeFavorite(int pokemonId);
    bool isFavorite(int pokemonId) const;
    std::vector<std::shared_ptr<Pokemon>> getFavorites() const;
    
    // ---- Pokédex de Concurso (Nova funcionalidade) ----
    ContestPokedex& getContestPokedex() { return _contestPokedex; }
    const ContestPokedex& getContestPokedex() const { return _contestPokedex; }
    
    // ---- Recarregar Dados ----
    void reloadAllData();

private:
    std::unique_ptr<IPokemonRepository> pokemonRepo;
    std::unique_ptr<IPokemonRepository> moveRepo;
    std::unique_ptr<IPokemonRepository> evolutionRepo;
    std::unique_ptr<IPokemonRepository> itemRepo;
    std::unique_ptr<IPokemonRepository> pokeblockRepo;
    std::unique_ptr<IPokemonRepository> berryRepo;
    std::unique_ptr<IPokemonRepository> judgeRepo;
    std::unique_ptr<FavoritesManager> favoritesManager;
    ContestPokedex _contestPokedex; // Nova membro
    
    void initializeRepositories();
};
