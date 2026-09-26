#include "GameData.h"

// ========================================
// CHARACTER ARCHETYPES
// ========================================

const std::vector<ArchetypeData> ARCHETYPES =
{
    {
        ArchetypeType::Tank,
        "Tank",
        110.0f,     // Base HP
        0.90f,      // Attack Modifier
        90.0f,      // Base Speed
        25.0f       // Base Defense
    },

    {
        ArchetypeType::Fighter,
        "Fighter",
        90.0f,      // Base HP
        1.10f,      // Attack Modifier
        110.0f,     // Base Speed
        15.0f       // Base Defense
    },

    {
        ArchetypeType::Rogue,
        "Rogue",
        90.0f,      // Base HP
        0.90f,      // Attack Modifier
        110.0f,     // Base Speed
        25.0f       // Base Defense
    }
};


// ========================================
// WEAPON CLASSES
// ========================================

const std::vector<WeaponClassData> WEAPON_CLASSES =
{
    {
        WeaponClassType::Ranged,
        "Ranged",
        20.0f,      // Damage
        10.0f,      // Wield Speed Cost
        0.05f       // Impact Slow - 5%
    },

    {
        WeaponClassType::Light,
        "Light",
        24.0f,      // Damage
        15.0f,      // Wield Speed Cost
        0.075f      // Impact Slow - 7.5%
    },

    {
        WeaponClassType::Medium,
        "Medium",
        30.0f,      // Damage
        25.0f,      // Wield Speed Cost
        0.10f       // Impact Slow - 10%
    },

    {
        WeaponClassType::Heavy,
        "Heavy",
        40.0f,      // Damage
        35.0f,      // Wield Speed Cost
        0.15f       // Impact Slow - 15%
    }
};


// ========================================
// ELEMENTAL AFFINITIES
// ========================================

const std::vector<AffinityData> AFFINITIES =
{
    // Fire x Water
    // Both become more aggressive but lose defense.
    {
        ElementType::Fire,
        ElementType::Water,
        { 5.0f, -10.0f, 0.0f },     // Fire:  +5% ATK, -10 DEF
        { 5.0f, -10.0f, 0.0f }      // Water: +5% ATK, -10 DEF
    },

    // Fire x Ice
    // Fire gains attack while Ice gains speed,
    // but both lose defense.
    {
        ElementType::Fire,
        ElementType::Ice,
        { 5.0f, -10.0f, 0.0f },     // Fire: +5% ATK, -10 DEF
        { 0.0f, -10.0f, 5.0f }      // Ice:  +5 SPD, -10 DEF
    },

    // Fire x Lightning
    {
        ElementType::Fire,
        ElementType::Lightning,
        { 10.0f, 0.0f, 0.0f },      // Fire:      +10% ATK
        { 0.0f, 0.0f, 10.0f }       // Lightning: +10 SPD
    },

    // Fire x Rock
    {
        ElementType::Fire,
        ElementType::Rock,
        { -5.0f, 0.0f, -5.0f },     // Fire: -5% ATK, -5 SPD
        { 0.0f, 10.0f, 0.0f }       // Rock: +10 DEF
    },

    // Fire x Air
    {
        ElementType::Fire,
        ElementType::Air,
        { 10.0f, 0.0f, 0.0f },      // Fire: +10% ATK
        { 0.0f, 0.0f, 10.0f }       // Air:  +10 SPD
    },

    // Water x Ice
    {
        ElementType::Water,
        ElementType::Ice,
        { 0.0f, 10.0f, 0.0f },      // Water: +10 DEF
        { 0.0f, 0.0f, 10.0f }       // Ice:   +10 SPD
    },

    // Water x Lightning
    // Both gain an offensive advantage but lose defense.
    {
        ElementType::Water,
        ElementType::Lightning,
        { 0.0f, -10.0f, 5.0f },     // Water:     +5 SPD, -10 DEF
        { 5.0f, -10.0f, 0.0f }      // Lightning: +5% ATK, -10 DEF
    },

    // Water x Rock
    {
        ElementType::Water,
        ElementType::Rock,
        { 10.0f, 0.0f, 0.0f },      // Water: +10% ATK
        { 0.0f, -5.0f, 10.0f }      // Rock:  +10 SPD, -5 DEF
    },

    // Water x Air
    {
        ElementType::Water,
        ElementType::Air,
        { 0.0f, 5.0f, 5.0f },       // Water: +5 DEF, +5 SPD
        { -10.0f, 0.0f, 0.0f }      // Air:   -10% ATK
    },

    // Ice x Lightning
    {
        ElementType::Ice,
        ElementType::Lightning,
        { 0.0f, 10.0f, 0.0f },      // Ice:       +10 DEF
        { -10.0f, 0.0f, 5.0f }      // Lightning: -10% ATK, +5 SPD
    },

    // Ice x Rock
    {
        ElementType::Ice,
        ElementType::Rock,
        { 0.0f, 10.0f, 0.0f },      // Ice:  +10 DEF
        { 0.0f, 10.0f, 0.0f }       // Rock: +10 DEF
    },

    // Ice x Air
    {
        ElementType::Ice,
        ElementType::Air,
        { 10.0f, 0.0f, 0.0f },      // Ice: +10% ATK
        { 0.0f, -10.0f, 5.0f }      // Air: +5 SPD, -10 DEF
    },

    // Lightning x Rock
    {
        ElementType::Lightning,
        ElementType::Rock,
        { -10.0f, 0.0f, 0.0f },     // Lightning: -10% ATK
        { -10.0f, 0.0f, 0.0f }      // Rock:      -10% ATK
    },

    // Lightning x Air
    {
        ElementType::Lightning,
        ElementType::Air,
        { 0.0f, 0.0f, 10.0f },      // Lightning: +10 SPD
        { 0.0f, -10.0f, 0.0f }      // Air:       -10 DEF
    },

    // Rock x Air
    {
        ElementType::Rock,
        ElementType::Air,
        { 5.0f, -10.0f, 0.0f },     // Rock: +5% ATK, -10 DEF
        { -10.0f, 0.0f, 5.0f }      // Air:  -10% ATK, +5 SPD
    }
};