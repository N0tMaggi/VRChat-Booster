#include "UIManager.h"
#include "Config.h"
#include <iostream>
#include <sstream>
#include <limits>

#define NOMINMAX
#include <windows.h>

void UIManager::Initialize()
{
    SetConsoleTitleA(Config::APP_TITLE);
    EnableVirtualTerminalProcessing();
    ClearScreen();
}

void UIManager::ShowBanner()
{
    std::cout << Color::BOLD << Color::MAGENTA
        << "   _   _   _   _   _   _     _   _   _   _     _   _   _   _   _   _  \n"
        << "  / \\ / \\ / \\ / \\ / \\ / \\   / \\ / \\ / \\ / \\   / \\ / \\ / \\ / \\ / \\ / \\ \n"
        << " ( V | R | C | H | A | T ) ( P | R | I | O ) ( S | E | T | T | E | R )\n"
        << "  \\_/ \\_/ \\_/ \\_/ \\_/ \\_/   \\_/ \\_/ \\_/ \\_/   \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \n"
        << Color::RESET << Color::GRAY
        << "                                 v" << Config::APP_VERSION << " by " << Config::AUTHOR << "\n"
        << "-----------------------------------------------------------------------------------------------------\n\n"
        << Color::RESET;
}

void UIManager::ShowInformation()
{
    std::cout << Color::GRAY
        << "[ i ] Information | EasyAntiCheat prevents setting VRChat's priority at runtime.\n"
        << "[ i ] Information | This tool sets priority at startup via registry, bypassing the restriction.\n"
        << "[ i ] Information | Completely safe - only adds a registry key, no game file modifications.\n"
        << Color::BOLD << "-----------------------------------------------------------------------------------------------------\n"
        << Color::RESET;

    std::cout << Color::RED
        << "[ ! ] Warning     | Realtime priority NOT recommended - may conflict with OS processes.\n"
        << Color::BOLD << "-----------------------------------------------------------------------------------------------------\n"
        << Color::RESET;

    std::cout << Color::YELLOW
        << "[ * ] Note        | FREE & OPEN SOURCE - If you paid for this, you got scammed!\n"
        << "[ * ] GitHub      | " << Config::GITHUB_REPO << "\n"
        << Color::BOLD << "-----------------------------------------------------------------------------------------------------\n"
        << Color::RESET;
}

void UIManager::ShowPriorityOptions()
{
    std::cout << "\n" << Color::WHITE << "[ # ] Priority Options:\n\n" << Color::RESET;
    std::cout << Color::GREEN << "  [2] Normal       (Standard Windows priority)\n" << Color::RESET;
    std::cout << Color::CYAN << "  [3] High         (Recommended for VRChat) ?\n" << Color::RESET;
    std::cout << Color::GRAY << "  [5] Below Normal (Lower priority)\n" << Color::RESET;
    std::cout << Color::GRAY << "  [6] Above Normal (Higher than normal)\n\n" << Color::RESET;
}

void UIManager::ShowSuccess(int priority)
{
    std::cout << "\n" << Color::GREEN << Color::BOLD
        << "[ ? ] Success! VRChat priority has been set to: " << priority << "\n"
        << Color::RESET;

    std::cout << Color::GRAY
        << "[ i ] The change will take effect the next time VRChat starts.\n"
        << Color::RESET << std::endl;
}

void UIManager::ShowError(const std::string& message)
{
    std::cout << Color::RED << Color::BOLD
        << "[ ? ] Error: " << message << "\n"
        << Color::RESET << std::endl;
}

void UIManager::ShowStatus(const std::string& message)
{
    std::cout << Color::YELLOW << "[ ? ] " << message << Color::RESET << std::endl;
}

void UIManager::ShowAdminStatus(bool isAdmin)
{
    if (isAdmin)
    {
        std::cout << Color::GREEN
            << "[ ? ] Administrator privileges confirmed.\n"
            << Color::RESET;
    }
    else
    {
        std::cout << Color::RED
            << "[ ! ] Administrator privileges required. Requesting elevation...\n"
            << Color::RESET;
    }
}

int UIManager::GetPriorityInput()
{
    std::string input;
    std::cout << Color::MAGENTA << "\n[ ? ] Enter priority level (2-6): " << Color::RESET;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    int priority = 0;
    ss >> priority;

    if (ss.fail() || priority < 2 || priority > 6)
    {
        ShowError("Invalid input. Please enter a number between 2 and 6.");
        Sleep(1500);
        return -1;
    }

    return priority;
}

void UIManager::ClearScreen()
{
    system("cls");
}

void UIManager::WaitForContinue()
{
    std::cout << "\n" << Color::GRAY
        << "Press ENTER to set priority again, or close the window to exit..."
        << Color::RESET << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void UIManager::EnableVirtualTerminalProcessing()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE)
    {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode))
        {
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
        }
    }
}
