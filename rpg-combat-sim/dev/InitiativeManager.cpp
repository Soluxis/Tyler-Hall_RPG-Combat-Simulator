#include "InitiativeManager.h"
#include "DisplayManager.h"


#include <algorithm>
#include <sstream>
#include <iomanip>


// ========================================
// CONSTRUCTOR
// ========================================

InitiativeManager::InitiativeManager(
    std::vector<Character>& characters
)
    : mCharacters(characters)
{
}

// ========================================
// GET NEXT ATTACKER
// ========================================
Character* InitiativeManager::GetNextAttacker()
{
    Character* nextAttacker = nullptr;

    for (Character& character : mCharacters)
    {
        if (!character.IsAlive()) { continue; }

        // If mActedThisRound contains character, skip
        if (std::find(
            mActedThisRound.begin(),
            mActedThisRound.end(),
            &character
        ) != mActedThisRound.end()) {
            continue;
        }

        // Once we reach a valid character, store them then move on
        if (nextAttacker == nullptr)
        {
            nextAttacker = &character;
            continue;
        }

        // Compare the stored character to this one
        // If this one's speed is higher, it becomes the new stored character
        if (character.GetActionSpeed() > nextAttacker->GetActionSpeed())
        {
            nextAttacker = &character;
        }
        else if (character.GetActionSpeed() == nextAttacker->GetActionSpeed())
        {
            // In a speed tie, player gets priority over enemies
            if (character.IsAlly() && !nextAttacker->IsAlly())
            {
                nextAttacker = &character;
            }
        }
    }

    return nextAttacker;
}

// ========================================
// MANAGE WHO ACTED THIS ROUND
// ========================================

void InitiativeManager::MarkAsActed(Character& character)
{
    mActedThisRound.push_back(&character);
}

void InitiativeManager::StartNewRound()
{
    mActedThisRound.clear();
}

// ========================================
// GET CURRENT TURN ORDER
// ========================================

std::string InitiativeManager::GetCurrentTurnOrder()
{
    std::vector<Character> battleCharacters;

    for (Character& character : mCharacters) 
    { 
        if (std::find(
            mActedThisRound.begin(),
            mActedThisRound.end(),
            &character
        ) != mActedThisRound.end() || !character.IsAlive()) {
            continue;
        }
        battleCharacters.push_back(character); 
    }

    std::sort(
        mActedThisRound.begin(),
        mActedThisRound.end(),
        [](const Character* a, const Character* b)
        {
            if (a->GetActionSpeed() == b->GetActionSpeed())
            {
                return a->IsAlly() && !b->IsAlly();
            }
            return a->GetActionSpeed() > b->GetActionSpeed();
        }
    );

    std::sort(
        battleCharacters.begin(),
        battleCharacters.end(),
        [](const Character& a, const Character& b)
        {
            if (a.GetActionSpeed() == b.GetActionSpeed())
            {
                return a.IsAlly() && !b.IsAlly();
            }
            return a.GetActionSpeed() > b.GetActionSpeed();
        }
    ); 

    std::ostringstream order;

    DisplayManager::DisplaySectionHeader("Timeline");

    order << std::fixed << std::setprecision(2);

    bool firstChar = true;

    for (Character* character : mActedThisRound)
    {
        DisplayManager::SetGray();

        if (firstChar) { order << "    "; }
        else { order << " -> "; }

        order << character->GetName();

        order << "(" << character->GetActionSpeed() << ")";

        order << "  -> ";

        DisplayManager::SetDefaultColor();


        firstChar = false;
    }

    firstChar = true;

    for (const Character& character : battleCharacters)
    {
        if (firstChar) { 
            order << " ||"; }
        else { 
            order << "  ->  "; }

        order << character.GetName();

        order << "(" << character.GetActionSpeed() << ")";

        if (firstChar) { order << "||"; }

        firstChar = false;
    }

    return order.str();
}
