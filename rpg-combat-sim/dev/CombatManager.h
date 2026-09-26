#pragma once

#include <vector>
#include <string>
#include "Character.h"

struct AttackResult
{
    std::string attackerName;
    std::string targetName;

    float damageTaken;

    float oldHP;
    float newHP;

    float oldSpeed;
    float newSpeed;

    bool defeated;
};

class CombatManager
{
private:
    std::vector<Character>& mCharacters;
    std::vector<Character*> mActedThisRound;

public:

    // Constructor
    CombatManager(std::vector<Character>& characters);

    // Check what elements are present
    void RecalculateAffinities();

    // Perform a basic attack
    AttackResult Attack(Character& attacker, Character& target);

    // Check whether one team has been defeated
    BattleState GetBattleResult() const;
};