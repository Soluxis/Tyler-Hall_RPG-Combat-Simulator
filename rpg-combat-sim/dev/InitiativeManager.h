#pragma once

#include <vector>

#include "Character.h"


class InitiativeManager
{
private:

    std::vector<Character>& mCharacters;
    std::vector<Character*> mActedThisRound;


public:

    InitiativeManager(std::vector<Character>& characters);

    Character* GetNextAttacker();

    void MarkAsActed(Character& character);

    void StartNewRound();

    std::string GetCurrentTurnOrder();
};