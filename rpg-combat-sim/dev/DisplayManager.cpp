#include "DisplayManager.h"

#include <iostream>
#include <windows.h>


// ========================================
// SCREEN MANAGEMENT
// ========================================

void DisplayManager::ClearScreen()
{
    HANDLE console =
        GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screenInfo;

    GetConsoleScreenBufferInfo(
        console,
        &screenInfo
    );

    DWORD consoleSize =
        screenInfo.dwSize.X * screenInfo.dwSize.Y;

    DWORD written;

    COORD topLeft =
    {
        0,
        0
    };

    FillConsoleOutputCharacter(
        console,
        ' ',
        consoleSize,
        topLeft,
        &written
    );

    FillConsoleOutputAttribute(
        console,
        screenInfo.wAttributes,
        consoleSize,
        topLeft,
        &written
    );

    SetConsoleCursorPosition(
        console,
        topLeft
    );
}


// ========================================
// BASIC LAYOUT
// ========================================

void DisplayManager::DisplayHeader(
    const std::string& title
)
{
    std::cout
        << "============================================================\n";

    std::cout
        << "                       "
        << title
        << "\n";

    std::cout
        << "============================================================\n";
}


void DisplayManager::DisplaySectionHeader(
    const std::string& title
)
{
    std::cout << "\n";

    std::cout
        << "-------------------- "
        << title
        << " --------------------\n";
}


void DisplayManager::DisplayDivider()
{
    std::cout
        << "------------------------------------------------------------\n";
}


// ========================================
// COLORS
// ========================================

void DisplayManager::SetDefaultColor()
{
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        7
    );
}


void DisplayManager::SetRed()
{
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        12
    );
}


void DisplayManager::SetGreen()
{
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        10
    );
}


void DisplayManager::SetYellow()
{
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        14
    );
}


void DisplayManager::SetBlue()
{
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        9
    );
}


void DisplayManager::SetCyan()
{
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        11
    );
}


void DisplayManager::SetGray()
{
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        8
    );
}

void DisplayManager::SetPurple()
{
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        5
    );
}


// ========================================
// BARS
// ========================================

std::string DisplayManager::CreateBar(
    float currentValue,
    float maxValue,
    int width
)
{
    if (maxValue <= 0.0f)
    {
        return "";
    }

    float percentage =
        currentValue / maxValue;

    if (percentage < 0.0f) { percentage = 0.0f; }

    if (percentage > 1.0f) { percentage = 1.0f; }

    int filled =
        static_cast<int>(percentage * width);

    std::string bar = "[";

    for (int i = 0; i < width; i++)
    {
        if (i < filled)
        {
            bar += "#";
        }
        else
        {
            bar += "-";
        }
    }

    bar += "]";

    return bar;
}

// ========================================
// ELEMENT DISPLAY
// ========================================


void DisplayManager::DisplayElementInteractions()
{
    ClearScreen();

    DisplayHeader("ELEMENT INTERACTIONS");

    std::cout << "\n";
    std::cout << "Element interactions activate when both elements\n";
    std::cout << "are present in battle.\n\n";

    // FIRE

    SetRed();
    std::cout << "FIRE\n";
    SetDefaultColor();

    //
    std::cout << "  vs ";
    SetBlue();
    std::cout << "Water";
    SetDefaultColor();
    std::cout << "      ";

    SetRed();
    std::cout << "Fire";
    SetDefaultColor();
    std::cout << ": +5 % ATK, -10 DEF"
        << " | ";
    SetBlue();
    std::cout << "Water";
    SetDefaultColor();
    std::cout << ": +5% ATK, -10 DEF\n";

    //
    std::cout << "  vs ";

    SetCyan();
    std::cout << "Ice";
    SetDefaultColor();
    std::cout << "        ";

    SetRed();
    std::cout << "Fire";
    SetDefaultColor();
    std::cout << ": +5% ATK, -10 DEF"
        << "  | ";
    SetCyan();
    std::cout << "Ice";
    SetDefaultColor();
    std::cout << ": +5 SPD, -10 DEF\n";

    //
    std::cout << "  vs ";

    SetYellow();
    std::cout << "Lightning";
    SetDefaultColor();
    std::cout << "  ";

    SetRed();
    std::cout << "Fire";
    SetDefaultColor();
    std::cout << ": +10% ATK"
        << "          | ";
    SetYellow();
    std::cout << "Lightning";
    SetDefaultColor();
    std::cout << ": +10 SPD\n";

    //
    std::cout << "  vs ";

    SetGray();
    std::cout << "Rock";
    SetDefaultColor();
    std::cout << "       ";

    SetRed();
    std::cout << "Fire";
    SetDefaultColor();
    std::cout << ": -5% ATK, -5 SPD"
        << "   | ";
    SetGray();
    std::cout << "Rock";
    SetDefaultColor();
    std::cout << ": +10 DEF\n";

    //
    std::cout << "  vs ";
    SetGreen();
    std::cout << "Air";
    SetDefaultColor();
    std::cout << "        ";

    SetRed();
    std::cout << "Fire";
    SetDefaultColor();
    std::cout << ": +10% ATK"
        << "          | ";
    SetGreen();
    std::cout << "Air";
    SetDefaultColor();
    std::cout << ": +10 SPD\n";

    DisplayDivider();


    // WATER

    SetBlue();
    std::cout << "WATER\n";
    SetDefaultColor();

    //
    std::cout << "  vs ";
    SetCyan();
    std::cout << "Ice";
    SetDefaultColor();
    std::cout << "        ";

    SetBlue();
    std::cout << "Water";
    SetDefaultColor();
    std::cout << ": +10 DEF"
        << "          | ";
    SetCyan();
    std::cout << "Ice";
    SetDefaultColor();
    std::cout << ": +10 SPD\n";

    //
    std::cout << "  vs ";
    SetYellow();
    std::cout << "Lightning";
    SetDefaultColor();
    std::cout << "  ";

    SetBlue();
    std::cout << "Water";
    SetDefaultColor();
    std::cout << ": +5 SPD, -10 DEF"
        << "  | ";
    SetYellow();
    std::cout << "Lightning";
    SetDefaultColor();
    std::cout << ": +5% ATK, -10 DEF\n";

    //
    std::cout << "  vs ";
    SetGray();
    std::cout << "Rock";
    SetDefaultColor();
    std::cout << "       ";

    SetBlue();
    std::cout << "Water";
    SetDefaultColor();
    std::cout << ": +10% ATK"
        << "         | ";
    SetGray();
    std::cout << "Rock";
    SetDefaultColor();
    std::cout << ": +10 SPD, -5 DEF\n";

    //
    std::cout << "  vs ";
    SetGreen();
    std::cout << "Air";
    SetDefaultColor();
    std::cout << "        ";

    SetBlue();
    std::cout << "Water";
    SetDefaultColor();
    std::cout << ": +5 SPD, +5 DEF"
        << "   | ";
    SetGreen();
    std::cout << "Air";
    SetDefaultColor();
    std::cout << ": -10% ATK\n";

    DisplayDivider();


    // ICE

    SetCyan();
    std::cout << "ICE\n";
    SetDefaultColor();

    //
    std::cout << "  vs ";
    SetYellow();
    std::cout << "Lightning";
    SetDefaultColor();
    std::cout << "  ";

    SetCyan();
    std::cout << "Ice";
    SetDefaultColor();
    std::cout << ": +10 DEF"
        << "            | ";
    SetYellow();
    std::cout << "Lightning";
    SetDefaultColor();
    std::cout << ": +5 SPD, -10% ATK\n";

    std::cout << "  vs ";
    SetGray();
    std::cout << "Rock";
    SetDefaultColor();
    std::cout << "       ";

    SetCyan();
    std::cout << "Ice";
    SetDefaultColor();
    std::cout << ": +10 DEF"
        << "            | ";
    SetGray();
    std::cout << "Rock";
    SetDefaultColor();
    std::cout << ": +10 DEF\n";

    //
    std::cout << "  vs ";
    SetGreen();
    std::cout << "Air";
    SetDefaultColor();
    std::cout << "        ";

    SetCyan();
    std::cout << "Ice";
    SetDefaultColor();
    std::cout << ": +10% ATK"
        << "           | ";
    SetGreen();
    std::cout << "Air";
    SetDefaultColor();
    std::cout << ": +5 SPD, -10 DEF\n";

    DisplayDivider();


    // LIGHTNING

    SetYellow();
    std::cout << "LIGHTNING\n";
    SetDefaultColor();

    //
    std::cout << "  vs ";
    SetGray();
    std::cout << "Rock";
    SetDefaultColor();
    std::cout << "       ";
    SetYellow();
    std::cout << "Lightning";
    SetDefaultColor();
    std::cout << ": -10% ATK"
        << "     | ";
    SetGray();
    std::cout << "Rock";
    SetDefaultColor();
    std::cout << ": -10% ATK\n";

    //
    std::cout << "  vs ";
    SetGreen();
    std::cout << "Air";
    SetDefaultColor();
    std::cout << "        ";

    SetYellow();
    std::cout << "Lightning";
    SetDefaultColor();
    std::cout << ": +10 SPD"
        << "      | ";
    SetGreen();
    std::cout << "Air";
    SetDefaultColor();
    std::cout << ": -10 DEF\n";

    DisplayDivider();


    // ROCK

    SetGray();
    std::cout << "ROCK\n";
    SetDefaultColor();

    //
    std::cout << "  vs ";
    SetGreen();
    std::cout << "Air";
    SetDefaultColor();
    std::cout << "        ";

    SetGray();
    std::cout << "Rock";
    SetDefaultColor();
    std::cout << ": +5% ATK, -10 DEF"
        << "  | ";
    SetGreen();
    std::cout << "Air";
    SetDefaultColor();
    std::cout << ": +5 SPD, -10% ATK\n";

    DisplayDivider();

    std::cout << "\n0. Return to Element Selection";
}

// ========================================
// AFFINITY MODIFIER DISPLAY
// ========================================

void DisplayManager::DisplayAffinityModifier(
    const AffinityModifier& modifier
)
{
    if (modifier.attack != 0.0f)
    {
        if (modifier.attack > 0.0f)
        {
            SetGreen();
            std::cout << "+";
        }
        else
        {
            SetRed();
        }

        std::cout
            << modifier.attack
            << "% ATK  ";

        SetDefaultColor();
    }


    if (modifier.defense != 0.0f)
    {
        if (modifier.defense > 0.0f)
        {
            SetGreen();
            std::cout << "+";
        }
        else
        {
            SetRed();
        }

        std::cout
            << modifier.defense
            << " DEF  ";

        SetDefaultColor();
    }


    if (modifier.speed != 0.0f)
    {
        if (modifier.speed > 0.0f)
        {
            SetGreen();
            std::cout << "+";
        }
        else
        {
            SetRed();
        }

        std::cout
            << modifier.speed
            << " SPD";

        SetDefaultColor();
    }
}

// ========================================
// DISPLAY ACTIVE AFFINITIES
// ========================================

void DisplayManager::DisplayActiveElements(
    const std::vector<Character>& characters
)
{
    ClearScreen();

    DisplayHeader("ACTIVE AFFINITIES");

    std::vector<ElementType> activeElements;


    // ========================================
    // FIND ACTIVE ELEMENTS
    // ========================================

    for (const Character& character : characters)
    {
        if (!character.IsAlive())
        {
            continue;
        }

        ElementType element =
            character.GetElement();

        bool alreadyActive = false;

        for (ElementType activeElement : activeElements)
        {
            if (activeElement == element)
            {
                alreadyActive = true;
                break;
            }
        }

        if (!alreadyActive)
        {
            activeElements.push_back(element);
        }
    }


    // ========================================
    // DISPLAY ACTIVE ELEMENTS
    // ========================================

    DisplaySectionHeader("ACTIVE ELEMENTS");

    for (ElementType element : activeElements)
    {
        SetElementColor(element);

        std::cout
            << GetElementName(element)
            << "   ";

        SetDefaultColor();
    }

    std::cout << "\n";


    // ========================================
    // DISPLAY ACTIVE INTERACTIONS
    // ========================================

    DisplaySectionHeader("ACTIVE INTERACTIONS");

    bool interactionFound = false;

    for (const AffinityData& affinity : AFFINITIES)
    {
        bool element1Active = false;
        bool element2Active = false;

        for (ElementType element : activeElements)
        {
            if (element == affinity.element1)
            {
                element1Active = true;
            }

            if (element == affinity.element2)
            {
                element2Active = true;
            }
        }


        if (!element1Active || !element2Active)
        {
            continue;
        }

        interactionFound = true;


        // ========================================
        // INTERACTION HEADER
        // ========================================

        std::cout << "\n";

        SetElementColor(affinity.element1);

        std::cout
            << GetElementName(affinity.element1);

        SetDefaultColor();

        std::cout << " x ";

        SetElementColor(affinity.element2);

        std::cout
            << GetElementName(affinity.element2);

        SetDefaultColor();

        std::cout << "\n";


        // ========================================
        // ELEMENT 1 MODIFIERS
        // ========================================

        std::cout << "  ";

        SetElementColor(affinity.element1);

        std::cout
            << GetElementName(affinity.element1)
            << ": ";

        SetDefaultColor();

        DisplayAffinityModifier(
            affinity.element1Modifier
        );

        std::cout << "\n";


        // ========================================
        // ELEMENT 2 MODIFIERS
        // ========================================

        std::cout << "  ";

        SetElementColor(affinity.element2);

        std::cout
            << GetElementName(affinity.element2)
            << ": ";

        SetDefaultColor();

        DisplayAffinityModifier(
            affinity.element2Modifier
        );

        std::cout << "\n";
    }


    if (!interactionFound)
    {
        std::cout
            << "\nNo elemental interactions are currently active.\n";
    }


    // ========================================
    // CHARACTER TOTALS
    // ========================================

    DisplaySectionHeader("CHARACTER TOTALS");

    for (const Character& character : characters)
    {
        if (!character.IsAlive())
        {
            continue;
        }

        std::cout
            << "\n"
            << character.GetName()
            << " (";

        SetElementColor(character.GetElement());

        std::cout
            << GetElementName(character.GetElement());

        SetDefaultColor();

        std::cout << ")\n";


        // ========================================
        // ATTACK
        // ========================================

        float attack =
            character.GetAffinityAttackModifier();

        std::cout << "  ATK: ";

        if (attack > 0.0f)
        {
            SetGreen();
            std::cout << "+";
        }
        else if (attack < 0.0f)
        {
            SetRed();
        }

        std::cout
            << attack
            << "%";

        SetDefaultColor();


        // ========================================
        // DEFENSE
        // ========================================

        float defense =
            character.GetAffinityDefenseModifier();

        std::cout << "   DEF: ";

        if (defense > 0.0f)
        {
            SetGreen();
            std::cout << "+";
        }
        else if (defense < 0.0f)
        {
            SetRed();
        }

        std::cout << defense;

        SetDefaultColor();


        // ========================================
        // SPEED
        // ========================================

        float speed =
            character.GetAffinitySpeedModifier();

        std::cout << "   SPD: ";

        if (speed > 0.0f)
        {
            SetGreen();
            std::cout << "+";
        }
        else if (speed < 0.0f)
        {
            SetRed();
        }

        std::cout << speed;

        SetDefaultColor();

        std::cout << "\n";
    }


    // ========================================
    // RETURN
    // ========================================

    std::cout << "\n";

    DisplayDivider();

    std::cout
        << "\n0. Return to Battle Menu\n";
}

// ========================================
// DISPLAY CHARACTER
// ========================================

void DisplayManager::DisplayCharacter(
    const Character& character,
    const Character* attacker = nullptr
)
{
    std::cout << character.GetName();

    if (!character.IsAlive())
    {
        SetRed();
        std::cout << " [DEFEATED]";
        SetDefaultColor();
    }

    std::cout << "\n";

    // ========================================
    // HEALTH
    // ========================================

    float healthPercent =
        character.GetCurrentHP() / character.GetMaxHP();

    if (healthPercent > 0.50f)
    {
        SetGreen();
    }
    else if (healthPercent > 0.25f)
    {
        SetYellow();
    }
    else
    {
        SetRed();
    }

    std::cout
        << "HP  "
        << CreateBar(
            character.GetCurrentHP(),
            character.GetMaxHP(),
            15
        );

    SetDefaultColor();

    std::cout
        << " "
        << character.GetCurrentHP()
        << " / "
        << character.GetMaxHP();

    if (attacker)
    {
        SetPurple();
        std::cout << " ---> ";

        float healthPercent =
            character.PreviewRemainingHP(attacker->GetDamage()) / character.GetMaxHP();

        if (healthPercent > 0.50f)
        {
            SetGreen();
        }
        else if (healthPercent > 0.25f)
        {
            SetYellow();
        }
        else
        {
            SetRed();
        }

        std::cout
            << "HP  "
            << CreateBar(
                character.PreviewRemainingHP(attacker->GetDamage()),
                character.GetMaxHP(),
                15
            );

        SetDefaultColor();

        std::cout
            << " "
            << character.PreviewRemainingHP(attacker->GetDamage())
            << " / "
            << character.GetMaxHP();
    }
        std::cout << "\n";
    


    // ========================================
    // COMBAT STATS
    // ========================================

    std::cout
        << "ATK: "
        << character.GetCurrentAttackModifier() * 100.0f
        << "%";

    std::cout
        << "   DEF: "
        << character.GetCurrentDefense();

    std::cout
        << "   DMG: "
        << character.GetDamage();

    std::cout
        << "   SPD: "
        << character.GetActionSpeed();

    if (attacker)
    {
        std::cout << " ---> "
        << character.PreviewImpactSlow(attacker->GetImpactSlow());
    }


    std::cout << "\n";
}


// ========================================
// DISPLAY BATTLE SCENE
// ========================================

void DisplayManager::DisplayBattleScene(
    const std::vector<Character>& characters,
    const Character& currentCharacter,
    int round
)
{
    ClearScreen();

    // ========================================
    // BATTLE HEADER
    // ========================================

    DisplayHeader("BATTLE");

    std::cout << "\nROUND " << round;

    std::cout
        << "                     CURRENT TURN: ";

    if (currentCharacter.IsAlly())
    {
        SetGreen();
    }
    else
    {
        SetRed();
    }

    std::cout << currentCharacter.GetName();

    SetDefaultColor();

    std::cout << "\n";


    // ========================================
    // ALLIES
    // ========================================

    DisplaySectionHeader("ALLIES");

    for (const Character& character : characters)
    {
        if (!character.IsAlly())
        {
            continue;
        }

        DisplayCharacter(character);

        std::cout << "\n";
    }


    // ========================================
    // ENEMIES
    // ========================================

    DisplaySectionHeader("ENEMIES");

    for (const Character& character : characters)
    {
        if (character.IsAlly())
        {
            continue;
        }

        DisplayCharacter(character, &currentCharacter);

        std::cout << "\n";
    }

    DisplayDivider();
}

// ========================================
// ELEMENT HELPERS
// ========================================

std::string DisplayManager::GetElementName(
    ElementType element
)
{
    switch (element)
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


void DisplayManager::SetElementColor(
    ElementType element
)
{
    switch (element)
    {
    case ElementType::Fire:
        SetRed();
        break;

    case ElementType::Water:
        SetBlue();
        break;

    case ElementType::Ice:
        SetCyan();
        break;

    case ElementType::Lightning:
        SetYellow();
        break;

    case ElementType::Rock:
        SetGray();
        break;

    case ElementType::Air:
        SetGreen();
        break;
    }
}