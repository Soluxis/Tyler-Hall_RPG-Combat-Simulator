#pragma once

#include <string>
#include "GameData.h"

class Character
{
private:
    std::string mName;

    ArchetypeType mArchetype;
    WeaponClassType mWeaponClass;
    ElementType mElement;

    bool mIsAlly;


    // ========================================
    // CURRENT COMBAT STATS
    // ========================================

    float mCurrentMaxHP;
    float mCurrentHP;

    float mCurrentAttackModifier;
    float mCurrentBaseSpeed;
    float mCurrentDefense;

    // Stored separately so temporary Speed changes
    // do not erase accumulated Impact Slow.
    float mImpactSpeedMultiplier;


    // ========================================
    // AFFINITY MODIFIERS
    // ========================================

    // Attack is stored as a whole percentage.
    // Defense and Speed are stored as flat points.
    float mAffinityAttackModifier;
    float mAffinityDefenseModifier;
    float mAffinitySpeedModifier;


    // ========================================
    // HELPER METHODS
    // ========================================

    const ArchetypeData& GetArchetypeData() const;
    const WeaponClassData& GetWeaponData() const;


public:

    // ========================================
    // CONSTRUCTORS
    // ========================================

    Character();

    Character(
        const std::string& name,
        ArchetypeType archetype,
        WeaponClassType weaponClass,
        ElementType element,
        bool isAlly
    );


    // ========================================
    // BASIC GETTERS
    // ========================================

    const std::string& GetName() const;

    ArchetypeType GetArchetype() const;
    WeaponClassType GetWeaponClass() const;
    ElementType GetElement() const;

    bool IsAlly() const;


    // ========================================
    // STAT GETTERS
    // ========================================

    float GetBaseHP() const;
    float GetMaxHP() const;
    float GetCurrentHP() const;

    float GetBaseAttackModifier() const;
    float GetCurrentAttackModifier() const;

    float GetBaseSpeed() const;
    float GetCurrentBaseSpeed() const;

    float GetBaseDefense() const;
    float GetCurrentDefense() const;

    float GetDamage() const;

    float GetWieldSpeedCost() const;
    float GetImpactSlow() const;

    float GetActionSpeed() const;

    float PreviewDamageTaken(float damage) const;
    float PreviewRemainingHP(float damage) const;
    float PreviewImpactSlow(float slowPercent) const;


    // ========================================
    // AFFINITY METHODS
    // ========================================

    void ResetAffinityModifiers();

    void ApplyAffinityModifiers(
        float attack,
        float defense,
        float speed
    );

    // ========================================
    // AFFINITY GETTERS
    // ========================================

        float GetAffinityAttackModifier() const;
        float GetAffinityDefenseModifier() const;
        float GetAffinitySpeedModifier() const;


    // ========================================
    // COMBAT METHODS
    // ========================================

    bool IsAlive() const;

    void TakeDamage(float damage);
    void ApplyImpactSlow(float slowPercent);

    void Reset();
};