#include "Character.h"

#include <algorithm>
#include <cmath>


// ========================================
// CONSTRUCTORS
// ========================================

Character::Character()
{
    mName = "Unnamed";

    mArchetype = ArchetypeType::Tank;
    mWeaponClass = WeaponClassType::Light;
    mElement = ElementType::Fire;

    mIsAlly = true;

    Reset();
}


Character::Character(
    const std::string& name,
    ArchetypeType archetype,
    WeaponClassType weaponClass,
    ElementType element,
    bool isAlly
)
{
    mName = name;

    mArchetype = archetype;
    mWeaponClass = weaponClass;
    mElement = element;

    mIsAlly = isAlly;

    Reset();
}


// ========================================
// HELPER METHODS
// ========================================

const ArchetypeData& Character::GetArchetypeData() const
{
    for (const ArchetypeData& archetype : ARCHETYPES)
    {
        if (archetype.type == mArchetype)
        {
            return archetype;
        }
    }

    return ARCHETYPES[0];
}


const WeaponClassData& Character::GetWeaponData() const
{
    for (const WeaponClassData& weapon : WEAPON_CLASSES)
    {
        if (weapon.type == mWeaponClass)
        {
            return weapon;
        }
    }

    return WEAPON_CLASSES[0];
}


// ========================================
// BASIC GETTERS
// ========================================

const std::string& Character::GetName() const
{
    return mName;
}


ArchetypeType Character::GetArchetype() const
{
    return mArchetype;
}


WeaponClassType Character::GetWeaponClass() const
{
    return mWeaponClass;
}


ElementType Character::GetElement() const
{
    return mElement;
}


bool Character::IsAlly() const
{
    return mIsAlly;
}


// ========================================
// HP GETTERS
// ========================================

float Character::GetBaseHP() const
{
    return GetArchetypeData().baseHP;
}


float Character::GetMaxHP() const
{
    return mCurrentMaxHP;
}


float Character::GetCurrentHP() const
{
    return mCurrentHP;
}


// ========================================
// ATTACK GETTERS
// ========================================

float Character::GetBaseAttackModifier() const
{
    return GetArchetypeData().attackModifier;
}


float Character::GetCurrentAttackModifier() const
{
    return mCurrentAttackModifier
        + (mAffinityAttackModifier / 100.0f);
}


// ========================================
// SPEED GETTERS
// ========================================

float Character::GetBaseSpeed() const
{
    return GetArchetypeData().baseSpeed;
}


float Character::GetCurrentBaseSpeed() const
{
    float speed =
        mCurrentBaseSpeed + mAffinitySpeedModifier;

    return speed * mImpactSpeedMultiplier;
}


// ========================================
// DEFENSE GETTERS
// ========================================

float Character::GetBaseDefense() const
{
    return GetArchetypeData().baseDefense;
}


float Character::GetCurrentDefense() const
{
    return mCurrentDefense
        + mAffinityDefenseModifier;
}


// ========================================
// WEAPON / COMBAT STAT GETTERS
// ========================================

float Character::GetDamage() const
{
    float weaponDamage =
        GetWeaponData().damage;

    float damage =
        weaponDamage * GetCurrentAttackModifier();

    return std::round(damage);
}


float Character::GetWieldSpeedCost() const
{
    return GetWeaponData().wieldSpeedCost;
}


float Character::GetImpactSlow() const
{
    return GetWeaponData().impactSlow;
}


float Character::GetActionSpeed() const
{
    float actionSpeed =
        GetCurrentBaseSpeed() - GetWieldSpeedCost();

    return std::max(1.0f, actionSpeed);
}


// ========================================
// AFFINITY METHODS
// ========================================

void Character::ResetAffinityModifiers()
{
    mAffinityAttackModifier = 0.0f;
    mAffinityDefenseModifier = 0.0f;
    mAffinitySpeedModifier = 0.0f;
}


void Character::ApplyAffinityModifiers(
    float attack,
    float defense,
    float speed
)
{
    mAffinityAttackModifier += attack;
    mAffinityDefenseModifier += defense;
    mAffinitySpeedModifier += speed;
}

// ========================================
// AFFINITY GETTERS
// ========================================

float Character::GetAffinityAttackModifier() const
{
    return mAffinityAttackModifier;
}

float Character::GetAffinityDefenseModifier() const
{
    return mAffinityDefenseModifier;
}

float Character::GetAffinitySpeedModifier() const
{
    return mAffinitySpeedModifier;
}


// ========================================
// COMBAT METHODS
// ========================================

bool Character::IsAlive() const
{
    return mCurrentHP > 0.0f;
}

float Character::PreviewDamageTaken(float damage) const
{
    float defense =
        std::max(0.0f, GetCurrentDefense());

    float damageTaken =
        damage * (100.0f / (100.0f + defense));

    return std::round(damageTaken);
}

float Character::PreviewRemainingHP(float damage) const
{
    float defense =
        std::max(0.0f, GetCurrentDefense());

    float tempHp = mCurrentHP;

    return tempHp -= std::round(damage * (100.0f / (100.0f + defense)));
}


void Character::TakeDamage(float damage)
{
    float damageTaken = PreviewDamageTaken(damage);

    mCurrentHP -= std::round(damageTaken);

    if (mCurrentHP < 0.0f)
    {
        mCurrentHP = 0.0f;
    }
}

float Character::PreviewImpactSlow(float slowPercent) const
{
    float newImpactSpeedMultiplier =
        mImpactSpeedMultiplier * (1.0f - slowPercent);

    float speed =
        mCurrentBaseSpeed + mAffinitySpeedModifier;

    float newBaseSpeed =
        speed * newImpactSpeedMultiplier;

    float newActionSpeed =
        newBaseSpeed - GetWieldSpeedCost();

    return std::max(1.0f, std::round(newActionSpeed));
}


void Character::ApplyImpactSlow(float slowPercent)
{
    mImpactSpeedMultiplier *= (1.0f - slowPercent);

    if (mImpactSpeedMultiplier < 0.0f)
    {
        mImpactSpeedMultiplier = 0.0f;
    }
}


// ========================================
// RESET
// ========================================

void Character::Reset()
{
    mCurrentMaxHP = GetBaseHP();
    mCurrentHP = mCurrentMaxHP;

    mCurrentAttackModifier = GetBaseAttackModifier();

    mCurrentBaseSpeed = GetBaseSpeed();
    mImpactSpeedMultiplier = 1.0f;

    mCurrentDefense = GetBaseDefense();

    ResetAffinityModifiers();
}