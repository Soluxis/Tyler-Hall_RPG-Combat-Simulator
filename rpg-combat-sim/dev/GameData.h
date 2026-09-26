#pragma once

#include <string>
#include <vector>


// ========================================
// BATTLE STATES
// ========================================

enum class BattleState
{
    Ongoing,
    PlayerWon,
    EnemyWon,
    Draw
};


// ========================================
// CHARACTER ARCHETYPES
// ========================================

enum class ArchetypeType
{
    Tank,
    Fighter,
    Rogue
};

struct ArchetypeData
{
    ArchetypeType type;
    std::string name;

    float baseHP;
    float attackModifier;
    float baseSpeed;
    float baseDefense;
};


// ========================================
// WEAPON CLASSES
// ========================================

enum class WeaponClassType
{
    Ranged,
    Light,
    Medium,
    Heavy
};

struct WeaponClassData
{
    WeaponClassType type;
    std::string name;

    float damage;

    // Fixed amount subtracted from the user's
    // Base Speed when determining Action Speed.
    float wieldSpeedCost;

    // Percentage of Base Speed a target loses
    // after being successfully hit.
    float impactSlow;
};


// ========================================
// ELEMENTS / AFFINITIES
// ========================================

enum class ElementType
{
    Fire,
    Water,
    Ice,
    Lightning,
    Rock,
    Air
};

struct AffinityModifier
{
    // Attack is stored as a whole percentage.
    // Example: 5.0f represents +5% Attack.
    float attack;

    // Defense and Speed are stored as flat points.
    float defense;
    float speed;
};

struct AffinityData
{
    ElementType element1;
    ElementType element2;

    // Modifier applied to element1 when
    // both elements are active in battle.
    AffinityModifier element1Modifier;

    // Modifier applied to element2 when
    // both elements are active in battle.
    AffinityModifier element2Modifier;
};


// ========================================
// GAME DATA
// ========================================

// Preset character archetypes.
extern const std::vector<ArchetypeData> ARCHETYPES;

// Preset weapon classes.
extern const std::vector<WeaponClassData> WEAPON_CLASSES;

// Preset elemental affinity interactions.
extern const std::vector<AffinityData> AFFINITIES;