#pragma once

#include <string>

// ============================================================================
// UI Manager - All console output and user interaction
// ============================================================================

class UIManager {
public:
    // Initialize console (title, colors, etc.)
    static void Initialize();

    // Display the application banner
    static void ShowBanner();

    // Display information about the tool
    static void ShowInformation();

    // Display priority options
    static void ShowPriorityOptions();

    // Display success message
    static void ShowSuccess(int priority);

    // Display error message
    static void ShowError(const std::string& message);

    // Display status/progress message
    static void ShowStatus(const std::string& message);

    // Display admin status
    static void ShowAdminStatus(bool isAdmin);

    // Get priority input from user
    static int GetPriorityInput();

    // Clear the console screen
    static void ClearScreen();

    // Wait for user confirmation
    static void WaitForContinue();

private:
    // Enable ANSI color support in Windows console
    static void EnableVirtualTerminalProcessing();
};
