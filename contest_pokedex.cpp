#include "contest_pokedex.h"
#include <algorithm>

void ContestPokedex::addContestRecord(int pokemonId, const std::string& category, int score, bool won) {
    auto& record = _contestRecords[pokemonId];
    record.participations++;
    if (won) record.wins++;
    
    // Atualiza a pontuação mais alta na categoria
    if (score > record.highestScores[category]) {
        record.highestScores[category] = score;
    }
}

ContestPokedex::ContestRecord ContestPokedex::getContestRecord(int pokemonId) const {
    auto it = _contestRecords.find(pokemonId);
    return (it != _contestRecords.end()) ? it->second : ContestRecord();
}

std::vector<std::string> ContestPokedex::suggestPokeblocks(const Pokemon& pokemon) const {
    std::vector<std::string> suggestions;
    auto types = pokemon.getTypes();

    // Sugere Pokéblocks baseado no tipo primário do Pokémon
    if (_pokeblockSuggestions.count(types.first)) {
        suggestions = _pokeblockSuggestions.at(types.first);
    }
    return suggestions;
}

std::vector<std::string> ContestPokedex::suggestMoves(const Pokemon& pokemon, const std::string& category) const {
    // (Implemente uma lógica baseada nos movimentos disponíveis do Pokémon)
    return {"Move1", "Move2"}; // Exemplo simplificado
}
