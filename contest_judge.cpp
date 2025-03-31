#include "../include/contest_judge.h"
#include <iostream>

ContestJudge::ContestJudge(std::string game, std::string contestCategory,
                         std::string judgeAppearance, std::string judgePersonality,
                         std::string preferredMoveTypes, std::string dislikedMoveTypes,
                         std::string specialNotes)
    : game(std::move(game)), contest_category(std::move(contestCategory)),
      judge_appearance(std::move(judgeAppearance)), judge_personality(std::move(judgePersonality)),
      preferred_move_types(std::move(preferredMoveTypes)), disliked_move_types(std::move(dislikedMoveTypes)),
      special_notes(std::move(specialNotes)) {}

void ContestJudge::display() const {
    std::cout << "  Game: " << game << " | Category: " << contest_category << "\n";
    std::cout << "  Judge: " << judge_appearance << " (" << judge_personality << ")\n";
    std::cout << "  Likes: " << preferred_move_types << "\n";
    std::cout << "  Dislikes: " << disliked_move_types << "\n";
    if (!special_notes.empty())
        std::cout << "  Notes: " << special_notes << "\n";
}