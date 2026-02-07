#pragma once

#include <windows.h>

// ============================================================================
// Admin Privileges Manager
// ============================================================================

class AdminPrivileges {
public:
    // Check if the current process is running with admin rights
    static bool IsRunningAsAdmin();

    // Restart the application with admin privileges
    static void RestartAsAdmin();
};
