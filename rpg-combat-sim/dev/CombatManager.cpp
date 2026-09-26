#include "CombatManager.h"
#include "GameData.h"

#include <iostream>
#include <algorithm>


// ========================================
// CONSTRUCTOR
// ========================================

CombatManager::CombatManager(std::vector<Character>& characters)
    : mCharacters(characters)
{
}


// ========================================
// AFFINITY CALCULATION
// ========================================

void CombatManager::RecalculateAffinities()
{
    std::vector<ElementType> activeElements;


    // ========================================
    // RESET AFFINITY MODIFIERS
    // ========================================

    for (Character& character : mCharacters)
    {
        character.ResetAffinityModifiers();
    }


    // ========================================
    // FIND ACTIVE ELEMENTS
    // ========================================

    for (const Character& character : mCharacters)
    {
        if (!character.IsAlive())
        {
            continue;
        }

        ElementType element = character.GetElement();

        // Only add the element if it is not
        // already in the active element list.
        if (std::find(
            activeElements.begin(),
            activeElements.end(),
            element
        ) == activeElements.end())
        {
            activeElements.push_back(element);
        }
    }


    // ========================================
    // APPLY AFFINITIES
    // ========================================

    for (Character& character : mCharacters)
    {
        if (!character.IsAlive())
        {
            continue;
        }

        ElementType characterElement =
            character.GetElement();

        for (ElementType activeElement : activeElements)
        {
            // An element does not interact with itself.
            if (activeElement == characterElement)
            {
                continue;
            }

            // Search the affinity table for the
            // interaction between these two elements.
            for (const AffinityData& affinity : AFFINITIES)
            {
                // Character is element1 in this interaction.
                if (
                    affinity.element1 == characterElement &&
                    affinity.element2 == activeElement
                    )
                {
                    character.ApplyAffinityModifiers(
                        affinity.element1Modifier.attack,
                        affinity.element1Modifier.defense,
                        affinity.element1Modifier.speed
                    );

                    break;
                }

                // Character is element2 in this interaction.
                if (
                    affinity.element2 == characterElement &&
                    affinity.element1 == activeElement
                    )
                {
                    character.ApplyAffinityModifiers(
                        affinity.element2Modifier.attack,
                        affinity.element2Modifier.defense,
                        affinity.element2Modifier.speed
                    );

                    break;
                }
            }
        }
    }
}


// ========================================
// ATTACK
// ========================================

AttackResult CombatManager::Attack(
    Character& attacker,
    Character& target
)
{
    AttackResult result;

    // ========================================
    // RECORD STARTING VALUES
    // ========================================

    result.attackerName =
        attacker.GetName();

    result.targetName =
        target.GetName();

    result.oldHP =
        target.GetCurrentHP();

    result.oldSpeed =
        target.GetActionSpeed();


    // ========================================
    // ATTACK
    // ========================================

    float damage =
        attacker.GetDamage();

    target.TakeDamage(damage);

    result.newHP =
        target.GetCurrentHP();

    result.damageTaken =
        result.oldHP - result.newHP;


    // ========================================
    // CHECK FOR DEFEAT
    // ========================================

    result.defeated =
        !target.IsAlive();

    if (result.defeated)
    {
        result.newSpeed =
            result.oldSpeed;

        RecalculateAffinities();

        return result;
    }


    // ========================================
    // APPLY IMPACT SLOW
    // ========================================

    target.ApplyImpactSlow(
        attacker.GetImpactSlow()
    );

    result.newSpeed =
        target.GetActionSpeed();

    return result;
}

// ========================================
// BATTLE OVER CHECK
// ========================================

BattleState CombatManager::GetBattleResult() const
{
    bool allyAlive = false;
    bool enemyAlive = false;

    for (const Character& character : mCharacters)
    {
        if (!character.IsAlive())
        {
            continue;
        }

        if (character.IsAlly())
        {
            allyAlive = true;
        }
        else
        {
            enemyAlive = true;
        }

        if (allyAlive && enemyAlive)
        {
            return BattleState::Ongoing;
        }
    }

    if (allyAlive && !enemyAlive)
    {
        return BattleState::PlayerWon;
    }
    else if (!allyAlive && enemyAlive)
    {
        return BattleState::EnemyWon;
    }
    else
    {
        return BattleState::Draw;
    }
}