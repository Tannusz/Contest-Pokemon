#pragma once
#include <string>

class ContestJudge {
public:
    ContestJudge(std::string game, std::string contestCategory,
                std::string judgeAppearance, std::string judgePersonality,
                std::string preferredMoveTypes, std::string dislikedMoveTypes,
                std::string specialNotes);
    
    const std::string& getGame() const { return game; }
    const std::string& getContestCategory() const { return contest_category; }
    const std::string& getJudgeAppearance() const { return judge_appearance; }
    const std::string& getJudgePersonality() const { return judge_personality; }
    const std::string& getPreferredMoveTypes() const { return preferred_move_types; }
    const std::string& getDislikedMoveTypes() const { return disliked_move_types; }
    const std::string& getSpecialNotes() const { return special_notes; }
    
    void display() const;

private:
    std::string game;
    std::string contest_category;
    std::string judge_appearance;
    std::string judge_personality;
    std::string preferred_move_types;
    std::string disliked_move_types;
    std::string special_notes;
};