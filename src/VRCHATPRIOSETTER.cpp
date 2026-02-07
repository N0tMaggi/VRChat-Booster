// ============================================================================
// VRChat Priority Setter v2.0
// Author: Maggi (literally.maggi)
// Repository: https://github.com/N0tMaggi/VRChat-Booster
// License: MIT
// ============================================================================

#include "Config.h"
#include "UIManager.h"
#include "RegistryHelper.h"
#include "AdminPrivileges.h"
#include <iostream>
#include <windows.h>

// ============================================================================
// VRChat Priority Setter Application
// ============================================================================

class VRChatPrioritySetter {
public:
    void Run()
    {
        try
        {
            // Initialize console
            UIManager::Initialize();

            // Check for admin privileges
            if (!AdminPrivileges::IsRunningAsAdmin())
            {
                UIManager::ShowAdminStatus(false);
                Sleep(2000);
                AdminPrivileges::RestartAsAdmin();
                return;
            }

            // Main application loop
            MainLoop();
        }
        catch (const std::exception& ex)
        {
            UIManager::ShowError(ex.what());
            Sleep(3000);
        }
    }

private:
    void MainLoop()
    {
        while (true)
        {
            // Display UI
            UIManager::ClearScreen();
            UIManager::ShowBanner();
            UIManager::ShowAdminStatus(true);
            std::cout << "\n";
            UIManager::ShowInformation();
            UIManager::ShowPriorityOptions();

            // Get user input
            int priority = UIManager::GetPriorityInput();
            if (priority == -1)
            {
                continue; // Invalid input, try again
            }

            // Apply priority setting
            if (SetVRChatPriority(priority))
            {
                UIManager::ShowSuccess(priority);
            }
            else
            {
                UIManager::ShowError("Failed to modify registry. Please check permissions.");
            }

            // Wait for user to continue or exit
            UIManager::WaitForContinue();
        }
    }

    bool SetVRChatPriority(int priority)
    {
        UIManager::ShowStatus("Applying registry changes...");

        bool success = RegistryHelper::SetDWordValue(
            HKEY_LOCAL_MACHINE,
            Config::REG_KEY_PATH,
            Config::REG_VALUE_NAME,
            static_cast<unsigned long>(priority)
        );

        Sleep(800); // Brief delay for visual feedback
        return success;
    }
};

// ============================================================================
// Entry Point
// ============================================================================

int main()
{
    VRChatPrioritySetter app;
    app.Run();
    return 0;
}

