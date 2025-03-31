#pragma once
#include "pokedex.h"
#include "command.h"
#include <memory>

class PokedexUI {
public:
    explicit PokedexUI(Pokedex& pokedex);
    void run();
    
    // Command methods
    void searchById();
    void searchByName();
    void searchByType();
    void viewFavorites();
    void pokeblockMakerMenu();
    void runContest(int pokemonId);
    void comparePokemon(int firstPokemonId = -1);
    void viewAllPokemon();
    
private:
    Pokedex& pokedex;
    std::unique_ptr<Menu> mainMenu;
    
    void initializeCommands();
    void displayPokemonWithOptions(std::shared_ptr<Pokemon> pokemon);
    void displayPokemonList(const std::vector<std::shared_ptr<Pokemon>>& list, 
                          const std::string& title) const;
    void addToHistory(int pokemonId);
};