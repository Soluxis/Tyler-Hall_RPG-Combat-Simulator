#pragma once

#include <string>
#include <vector>

#include "Character.h"


class DisplayManager
{
private:

    static std::string GetElementName(
        ElementType element
    );

    static void SetElementColor(
        ElementType element
    );

    static void DisplayAffinityModifier(
        const AffinityModifier& modifier
    );

public:

    // ========================================
    // SCREEN MANAGEMENT
    // ========================================

    static void ClearScreen();


    // ========================================
    // BASIC LAYOUT
    // ========================================

    static void DisplayHeader(const std::string& title);
    static void DisplaySectionHeader(const std::string& title);
    static void DisplayDivider();


    // ========================================
    // COLORS
    // ========================================

    static void SetDefaultColor();

    static void SetRed();
    static void SetBlue();
    static void SetCyan();
    static void SetYellow();
    static void SetGray();
    static void SetGreen();
    static void SetPurple();


    // ========================================
    // BARS
    // ========================================

    static std::string CreateBar(
        float currentValue,
        float maxValue,
        int width
    );


    // ========================================
    // ELEMENT DISPLAY
    // ========================================

    static void DisplayElementInteractions();

    static void DisplayActiveElements(
        const std::vector<Character>& characters
    );


    // ========================================
    // BATTLE DISPLAY
    // ========================================

    static void DisplayBattleScene(
        const std::vector<Character>& characters,
        const Character& currentCharacter,
        int round
    );

    static void DisplayCharacter(
        const Character& character,
        const Character* attacker
    );

};

