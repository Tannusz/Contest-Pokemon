#pragma once
#include "pokemon.h"
#include <vector>
#include <unordered_map>

class ContestPokedex {
public:
    struct ContestRecord {
        int wins = 0;
        int participations = 0;
        std::unordered_map<std::string, int> highestScores; // Categorias: "Beauty", "Cool", etc.
    };

    // Adiciona um registro de concurso para um Pokémon
    void addContestRecord(int pokemonId, const std::string& category, int score, bool won);

    // Obtém estatísticas de concurso de um Pokémon
    ContestRecord getContestRecord(int pokemonId) const;

    // Sugere Pokéblocks baseados nos atributos do Pokémon
    std::vector<std::string> suggestPokeblocks(const Pokemon& pokemon) const;

    // Sugere movimentos para uma categoria de concurso
    std::vector<std::string> suggestMoves(const Pokemon& pokemon, const std::string& category) const;

private:
    std::unordered_map<int, ContestRecord> _contestRecords; // Mapeia ID do Pokémon -> dados de concurso

    // Dados internos para sugestões (podem ser carregados de um arquivo JSON)
    const std::unordered_map<std::string, std::vector<std::string>> _pokeblockSuggestions = {
        {"Beauty", {"Blue Pokéblock", "Rainbow Pokéblock"}},
        {"Cool", {"Red Pokéblock", "Black Pokéblock"}}
    };
};
