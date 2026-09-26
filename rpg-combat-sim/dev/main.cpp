#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

#include "Character.h"
#include "GameData.h"
#include "CombatManager.h"
#include "InitiativeManager.h"
#include "DisplayManager.h"


// ========================================
// FUNCTION DECLARATIONS
// ========================================

void DisplayMainMenu();

void AddCharacter(std::vector<Character>& characters);

void ViewCharacters(const std::vector<Character>& characters);

void RemoveCharacter(std::vector<Character>& characters);

void SimulateBattle(const std::vector<Character>& characters);

void LogAttack(
    const AttackResult& result,
    std::vector<std::string>& battleLog,
    std::vector<std::string>& recentEvents
);

bool BattleMenu(
    const std::vector<Character>& battleCharacters,
    const std::vector<std::string>& battleLog
);

bool CheckBattleConditions(const std::vector<Character>& characters);


int GetMenuChoice(int min, int max);

ArchetypeType SelectArchetype();

WeaponClassType SelectWeaponClass();

ElementType SelectElement();

std::string GetElementName(ElementType type);

std::string GetArchetypeName(ArchetypeType type);

std::string GetWeaponClassName(WeaponClassType type);





// ========================================
// MAIN
// ========================================

int main()
{
    std::vector<Character> characters;

    bool running = true;

    while (running)
    {
        DisplayMainMenu();

        int choice = GetMenuChoice(0, 4);

        switch (choice)
        {
        case 1:
            AddCharacter(characters);
            break;

        case 2:
            ViewCharacters(characters);
            break;

        case 3:
            RemoveCharacter(characters);
            break;

        case 4:
            SimulateBattle(characters);
            break;

        case 0:
            std::cout << "\nExiting Combat Simulator...\n";
            running = false;
            break;
        }
    }

    return 0;
}


// ========================================
// MAIN MENU
// ========================================

void DisplayMainMenu()
{
    std::cout << "\n";
    std::cout << "========================================\n";
    std::cout << "        COMBAT SIMULATOR\n";
    std::cout << "========================================\n";
    std::cout << "1. Add Character\n";
    std::cout << "2. View Characters\n";
    std::cout << "3. Remove Character\n";
    std::cout << "4. Simulate Battle\n";
    std::cout << "0. Exit\n";
    std::cout << "========================================\n";
    std::cout << "Choice: ";
}


// ========================================
// CREATE CHARACTER
// ========================================

void AddCharacter(std::vector<Character>& characters)
{
    std::cout << "\n========================================\n";
    std::cout << "          CREATE CHARACTER\n";
    std::cout << "========================================\n";

    std::string name;

    std::cout << "Enter character name: ";
    getline(std::cin >> std::ws, name);

    ArchetypeType archetype = SelectArchetype();

    WeaponClassType weaponClass = SelectWeaponClass();

    ElementType element = SelectElement();

    std::cout << "\nChoose Team:\n";
    std::cout << "1. Ally\n";
    std::cout << "2. Enemy\n";
    std::cout << "Choice: ";

    int teamChoice = GetMenuChoice(1, 2);

    bool isAlly = teamChoice == 1;

    Character newCharacter(
        name,
        archetype,
        weaponClass,
        element,
        isAlly
    );

    characters.push_back(newCharacter);

    std::cout << "\nCharacter created successfully!\n";

    std::cout << "\n";
    std::cout << newCharacter.GetName() << "\n";
    std::cout << "Archetype: "
        << GetArchetypeName(newCharacter.GetArchetype())
        << "\n";

    std::cout << "Weapon: "
        << GetWeaponClassName(newCharacter.GetWeaponClass())
        << "\n";

    std::cout << "Element: "
        << GetElementName(newCharacter.GetElement())
        << "\n";

    std::cout << "Team: "
        << (newCharacter.IsAlly() ? "Ally" : "Enemy")
        << "\n";
}


// ========================================
// SELECT ARCHETYPE
// ========================================

ArchetypeType SelectArchetype()
{
    std::cout << "\nChoose Archetype:\n";

    std::cout << "1. Tank\n";
    std::cout << "   HP: 110 | Attack: 90% | Speed: 90 | Defense: 25\n\n";

    std::cout << "2. Fighter\n";
    std::cout << "   HP: 90 | Attack: 110% | Speed: 110 | Defense: 15\n\n";

    std::cout << "3. Rogue\n";
    std::cout << "   HP: 90 | Attack: 90% | Speed: 110 | Defense: 25\n\n";

    std::cout << "Choice: ";

    int choice = GetMenuChoice(1, 3);

    switch (choice)
    {
    case 1:
        return ArchetypeType::Tank;

    case 2:
        return ArchetypeType::Fighter;

    case 3:
        return ArchetypeType::Rogue;
    }

    return ArchetypeType::Tank;
}


// ========================================
// SELECT WEAPON
// ========================================

WeaponClassType SelectWeaponClass()
{
    std::cout << "\nChoose Weapon Class:\n";

    std::cout << "1. Ranged\n";
    std::cout << "   Damage: 20 | Wield Speed Cost: 10 | Impact Slow: 5%\n\n";

    std::cout << "2. Light\n";
    std::cout << "   Damage: 24 | Wield Speed Cost: 15 | Impact Slow: 7.5%\n\n";

    std::cout << "3. Medium\n";
    std::cout << "   Damage: 30 | Wield Speed Cost: 25 | Impact Slow: 10%\n\n";

    std::cout << "4. Heavy\n";
    std::cout << "   Damage: 40 | Wield Speed Cost: 35 | Impact Slow: 15%\n\n";

    std::cout << "Choice: ";

    int choice = GetMenuChoice(1, 4);

    switch (choice)
    {
    case 1:
        return WeaponClassType::Ranged;

    case 2:
        return WeaponClassType::Light;

    case 3:
        return WeaponClassType::Medium;

    case 4:
        return WeaponClassType::Heavy;
    }

    return WeaponClassType::Light;
}

// ========================================
// SELECT ELEMENT
// ========================================

ElementType SelectElement()
{
    while (true)
    {
        DisplayManager::ClearScreen();

        DisplayManager::DisplayHeader("SELECT ELEMENT");

        std::cout << "\n";

        DisplayManager::SetRed();
        std::cout << "1. Fire\n";

        DisplayManager::SetBlue();
        std::cout << "2. Water\n";

        DisplayManager::SetCyan();
        std::cout << "3. Ice\n";

        DisplayManager::SetYellow();
        std::cout << "4. Lightning\n";

        DisplayManager::SetGray();
        std::cout << "5. Rock\n";

        DisplayManager::SetGreen();
        std::cout << "6. Air\n";

        DisplayManager::SetDefaultColor();

        std::cout << "\n";
        std::cout << "0. View Element Interactions\n";

        std::cout << "\nChoice: ";

        int choice = GetMenuChoice(0, 6);

        switch (choice)
        {
        case 1:
            return ElementType::Fire;

        case 2:
            return ElementType::Water;

        case 3:
            return ElementType::Ice;

        case 4:
            return ElementType::Lightning;

        case 5:
            return ElementType::Rock;

        case 6:
            return ElementType::Air;
        case 0:
            DisplayManager::DisplayElementInteractions();

            std::cout << "\nChoice: ";
            GetMenuChoice(0, 0);
            break;
        }
    }
}



// ========================================
// CHARACTER ROSTER
// ========================================

void ViewCharacters(const std::vector<Character>& characters)
{
    std::cout << "\n========================================\n";
    std::cout << "          CHARACTER ROSTER\n";
    std::cout << "========================================\n";

    if (characters.empty())
    {
        std::cout << "No characters have been created yet.\n";
        return;
    }

    for (std::size_t i = 0; i < characters.size(); i++)
    {
        const Character& character = characters[i];

        std::cout << "\n";
        std::cout << "Character #" << i + 1 << "\n";
        std::cout << "----------------------------------------\n";

        std::cout << "Name: "
            << character.GetName()
            << "\n";

        std::cout << "Team: "
            << (character.IsAlly() ? "Ally" : "Enemy")
            << "\n";

        std::cout << "Archetype: "
            << GetArchetypeName(character.GetArchetype())
            << "\n";

        std::cout << "Weapon Class: "
            << GetWeaponClassName(character.GetWeaponClass())
            << "\n";

        std::cout << "Element: "
            << GetElementName(character.GetElement())
            << "\n";

        std::cout << "\nBase Stats\n";
        std::cout << "HP: "
            << character.GetMaxHP()
            << "\n";

        std::cout << "Attack Modifier: "
            << character.GetCurrentAttackModifier() * 100
            << "%\n";

        std::cout << "Base Speed: "
            << character.GetBaseSpeed()
            << "\n";

        std::cout << "\nWeapon Stats\n";

        std::cout << "Damage: "
            << character.GetDamage()
            << "\n";

        std::cout << "Wield Speed Cost: "
            << character.GetWieldSpeedCost()
            << "\n";

        std::cout << "Impact Slow: "
            << character.GetImpactSlow() * 100
            << "%\n";

        std::cout << "Starting Action Speed: "
            << character.GetActionSpeed()
            << "\n";
    }

    std::cout << "\n";
}


// ========================================
// REMOVE CHARACTER
// ========================================

void RemoveCharacter(std::vector<Character>& characters)
{
    if (characters.empty())
    {
        std::cout << "\nThere are no characters to remove.\n";
        return;
    }

    std::cout << "\n========================================\n";
    std::cout << "          REMOVE CHARACTER\n";
    std::cout << "========================================\n";

    for (std::size_t i = 0; i < characters.size(); i++)
    {
        std::cout << i + 1
            << ". "
            << characters[i].GetName()
            << " ("
            << GetArchetypeName(characters[i].GetArchetype())
            << ")\n";
    }

    std::cout << "0. Cancel\n";

    std::cout << "\nChoose a character to remove: ";

    int choice =
        GetMenuChoice(0, static_cast<int>(characters.size()));

    if (choice == 0)
    {
        std::cout << "Removal cancelled.\n";
        return;
    }

    std::string removedName = characters[choice - 1].GetName();

    characters.erase(characters.begin() + (choice - 1));

    std::cout << removedName
        << " was removed from the roster.\n";
}

// ========================================
// SIMULATE BATTLE
// ========================================

bool CheckBattleConditions(const std::vector<Character>& characters)
{
    bool allyExist = false;
    bool enemyExist = false;

    for (const Character& character : characters)
    {
        if (character.IsAlly())
        {
            allyExist = true;
        }
        else
        {
            enemyExist = true;
        }

        if (allyExist && enemyExist) { return true; }
    }
    return allyExist && enemyExist;
}

// ========================================
// SIMULATE BATTLE
// ========================================

void SimulateBattle(const std::vector<Character>& characters)
{
    if (!CheckBattleConditions(characters))
    {
        std::cout
            << "Please make sure there is at least one Ally and Enemy.\n";

        return;
    }

    std::vector<Character> battleCharacters = characters;

    CombatManager combatManager(battleCharacters);
    InitiativeManager initiativeManager(battleCharacters);

    combatManager.RecalculateAffinities();

    int round = 1;

    std::vector<std::string> battleLog;
    std::vector<std::string> recentEvents;

    battleLog.push_back(
        "==================== ROUND 1 ===================="
    );

    while (combatManager.GetBattleResult() == BattleState::Ongoing)
    {
        Character* attacker =
            initiativeManager.GetNextAttacker();

        // ========================================
        // START NEW ROUND
        // ========================================

        if (attacker == nullptr)
        {
            initiativeManager.StartNewRound();

            round++;

            battleLog.push_back("");
            battleLog.push_back(
                "==================== ROUND "
                + std::to_string(round)
                + " ===================="
            );

            continue;
        }

        std::vector<Character*> targets;


        // ========================================
        // ENEMY TURN
        // ========================================

        if (!attacker->IsAlly())
        {
            for (Character& defender : battleCharacters)
            {
                if (!defender.IsAlly() || !defender.IsAlive())
                {
                    continue;
                }

                targets.push_back(&defender);
            }

            Character* target =
                targets[rand() % targets.size()];

            battleLog.push_back("");
            battleLog.push_back(
                "--- " + attacker->GetName() + "'s Turn ---"
            );

            AttackResult result =
                combatManager.Attack(
                    *attacker,
                    *target
                );

            LogAttack(
                result,
                battleLog,
                recentEvents
            );
        }


        // ========================================
        // PLAYER TURN
        // ========================================

        else
        {
            DisplayManager::DisplayBattleScene(
                battleCharacters,
                *attacker,
                round
            );

            DisplayManager::DisplaySectionHeader(
                "RECENT EVENTS"
            );

            if (recentEvents.empty())
            {
                std::cout << "No recent events.\n";
            }
            else
            {
                for (const std::string& event : recentEvents)
                {
                    std::cout
                        << event
                        << "\n";
                }
            }

            for (Character& defender : battleCharacters)
            {
                if (defender.IsAlly() || !defender.IsAlive())
                {
                    continue;
                }

                targets.push_back(&defender);
            }

            std::cout
                << initiativeManager.GetCurrentTurnOrder()
                << "\n";

            DisplayManager::DisplayDivider();

            std::cout
                << "\nSelect target for "
                << attacker->GetName()
                << " to attack:\n";

            for (size_t i = 0; i < targets.size(); i++)
            {
                std::cout
                    << "\t"
                    << i + 1
                    << ": "
                    << targets[i]->GetName()
                    << "\n";
            }

            std::cout << "\t0: Menu/Help";

            std::cout << "\n\nChoice: ";

            int choice =
                GetMenuChoice(
                    0,
                    static_cast<int>(targets.size())
                );

            // ========================================
            // BATTLE MENU
            // ========================================

            if (choice == 0)
            {
                bool continueBattle =
                    BattleMenu(
                        battleCharacters,
                        battleLog
                    );

                if (!continueBattle)
                {
                    return;
                }

                // Return to the same character's turn.
                continue;
            }


            // ========================================
            // ATTACK
            // ========================================

            int attackTarget = choice - 1;

            battleLog.push_back("");
            battleLog.push_back(
                "--- " + attacker->GetName() + "'s Turn ---"
            );

            AttackResult result =
                combatManager.Attack(
                    *attacker,
                    *targets[attackTarget]
                );

            recentEvents.clear();

            LogAttack(
                result,
                battleLog,
                recentEvents
            );
        }


        // ========================================
        // END TURN
        // ========================================

        initiativeManager.MarkAsActed(*attacker);
    }

    // ========================================
// BATTLE RESULT
// ========================================

    BattleState result =
        combatManager.GetBattleResult();

    DisplayManager::ClearScreen();

    DisplayManager::DisplayHeader("BATTLE RESULT");

    std::cout << "\n";

    switch (result)
    {
    case BattleState::PlayerWon:
        DisplayManager::SetGreen();

        std::cout
            << "          ALLIES WIN!\n";

        break;


    case BattleState::EnemyWon:
        DisplayManager::SetRed();

        std::cout
            << "          ENEMIES WIN!\n";

        break;


    case BattleState::Draw:
        DisplayManager::SetYellow();

        std::cout
            << "             DRAW!\n";

        break;


    case BattleState::Ongoing:
        break;
    }

    DisplayManager::SetDefaultColor();

    std::cout << "\n";

    DisplayManager::DisplayDivider();


    // ========================================
    // SURVIVING CHARACTERS
    // ========================================

    std::cout << "\nSurvivors:\n\n";

    for (const Character& character : battleCharacters)
    {
        if (!character.IsAlive())
        {
            continue;
        }

        if (character.IsAlly())
        {
            DisplayManager::SetGreen();
        }
        else
        {
            DisplayManager::SetRed();
        }

        std::cout
            << "  "
            << character.GetName();

        DisplayManager::SetDefaultColor();

        std::cout
            << " - "
            << character.GetCurrentHP()
            << " / "
            << character.GetMaxHP()
            << " HP\n";
    }


    // ========================================
    // RETURN TO MAIN MENU
    // ========================================

    std::cout
        << "\n0. Return to Main Menu"
        << "\n\nChoice: ";

    GetMenuChoice(0, 0);
}



// ========================================
// BATTLE LOGGING
// ========================================

void LogAttack(
    const AttackResult& result,
    std::vector<std::string>& battleLog,
    std::vector<std::string>& recentEvents
)
{
    std::string attackMessage =
        result.attackerName
        + " attacked "
        + result.targetName
        + ".";

    std::string damageMessage =
        result.targetName
        + " took "
        + std::to_string(
            static_cast<int>(result.damageTaken)
        )
        + " damage.";


    battleLog.push_back(attackMessage);
    battleLog.push_back(damageMessage);

    recentEvents.push_back(attackMessage);
    recentEvents.push_back(damageMessage);


    // ========================================
    // DEFEATED
    // ========================================

    if (result.defeated)
    {
        std::string defeatedMessage =
            result.targetName
            + " was defeated!";

        battleLog.push_back(
            defeatedMessage
        );

        recentEvents.push_back(
            defeatedMessage
        );

        return;
    }


    // ========================================
    // SPEED CHANGE
    // ========================================

    if (result.newSpeed != result.oldSpeed)
    {
        std::string speedMessage =
            result.targetName
            + "'s Speed changed from "
            + std::to_string(
                static_cast<int>(result.oldSpeed)
            )
            + " -> "
            + std::to_string(
                static_cast<int>(result.newSpeed)
            )
            + ".";

        battleLog.push_back(
            speedMessage
        );

        recentEvents.push_back(
            speedMessage
        );
    }
}

// ========================================
// BATTLE MENU
// ========================================

bool BattleMenu(
    const std::vector<Character>& battleCharacters,
    const std::vector<std::string>& battleLog
)
{
    while (true)
    {
        DisplayManager::ClearScreen();

        DisplayManager::DisplayHeader("BATTLE MENU");

        std::cout
            << "\n\t1: View Element Chart"
            << "\n\t2: View Active Affinities"
            << "\n\t3: View Battle Log"
            << "\n\t4: Return To Battle"
            << "\n\n\t0: Main Menu"
            << "\n\nChoice: ";

        int choice = GetMenuChoice(0, 4);

        switch (choice)
        {
            // ========================================
            // ELEMENT CHART
            // ========================================

        case 1:
            DisplayManager::DisplayElementInteractions();

            std::cout << "\nChoice: ";
            GetMenuChoice(0, 0);

            break;


            // ========================================
            // ACTIVE AFFINITIES
            // ========================================

        case 2:
            DisplayManager::DisplayActiveElements(
                battleCharacters
            );

            std::cout << "\nChoice: ";
            GetMenuChoice(0, 0);

            break;


            // ========================================
            // BATTLE LOG
            // ========================================

        case 3:
            DisplayManager::ClearScreen();

            DisplayManager::DisplayHeader("BATTLE LOG");

            std::cout << "\n";

            for (const std::string& event : battleLog)
            {
                std::cout
                    << event
                    << "\n";
            }

            std::cout << "\n0. Return to Battle Menu";
            std::cout << "\n\nChoice: ";

            GetMenuChoice(0, 0);

            break;


            // ========================================
            // RETURN TO BATTLE
            // ========================================

        case 4:
            return true;


            // ========================================
            // RETURN TO MAIN MENU
            // ========================================

        case 0:
            return false;
        }
    }
}

// ========================================
// INPUT VALIDATION
// ========================================

int GetMenuChoice(int min, int max)
{
    while (true)
    {
        std::string input;
        std::getline(std::cin, input);

        try
        {
            int choice = std::stoi(input);

            if (choice < min || choice > max)
            {
                std::cout << "Please enter a number from "
                    << min << " to " << max << ": ";
            }
            else
            {
                return choice;
            }
        }
        catch (...)
        {
            std::cout << "Invalid input. Please enter a number: ";
        }
    }
}

// ========================================
// DISPLAY HELPERS
// ========================================

std::string GetArchetypeName(ArchetypeType type)
{
    switch (type)
    {
    case ArchetypeType::Tank:
        return "Tank";

    case ArchetypeType::Fighter:
        return "Fighter";

    case ArchetypeType::Rogue:
        return "Rogue";
    }

    return "Unknown";
}


std::string GetWeaponClassName(WeaponClassType type)
{
    switch (type)
    {
    case WeaponClassType::Ranged:
        return "Ranged";

    case WeaponClassType::Light:
        return "Light";

    case WeaponClassType::Medium:
        return "Medium";

    case WeaponClassType::Heavy:
        return "Heavy";
    }

    return "Unknown";
}

std::string GetElementName(ElementType type)
{
    switch (type)
    {
    case ElementType::Fire:
        return "Fire";

    case ElementType::Water:
        return "Water";

    case ElementType::Ice:
        return "Ice";

    case ElementType::Lightning:
        return "Lightning";

    case ElementType::Rock:
        return "Rock";

    case ElementType::Air:
        return "Air";
    }

    return "Unknown";
}