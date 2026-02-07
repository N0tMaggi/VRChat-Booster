#include "AdminPrivileges.h"
#include "UIManager.h"
#include <stdexcept>

bool AdminPrivileges::IsRunningAsAdmin()
{
    BOOL isAdmin = FALSE;
    PSID adminGroup = nullptr;

    SID_IDENTIFIER_AUTHORITY ntAuthority = SECURITY_NT_AUTHORITY;

    if (!AllocateAndInitializeSid(
        &ntAuthority,
        2,
        SECURITY_BUILTIN_DOMAIN_RID,
        DOMAIN_ALIAS_RID_ADMINS,
        0, 0, 0, 0, 0, 0,
        &adminGroup))
    {
        return false;
    }

    if (!CheckTokenMembership(nullptr, adminGroup, &isAdmin))
    {
        isAdmin = FALSE;
    }

    if (adminGroup)
    {
        FreeSid(adminGroup);
    }

    return isAdmin == TRUE;
}

void AdminPrivileges::RestartAsAdmin()
{
    wchar_t exePath[MAX_PATH];

    if (!GetModuleFileNameW(nullptr, exePath, ARRAYSIZE(exePath)))
    {
        throw std::runtime_error("Failed to get executable path");
    }

    SHELLEXECUTEINFOW shellInfo = { sizeof(shellInfo) };
    shellInfo.lpVerb = L"runas";
    shellInfo.lpFile = exePath;
    shellInfo.hwnd = nullptr;
    shellInfo.nShow = SW_NORMAL;

    if (!ShellExecuteExW(&shellInfo))
    {
        DWORD error = GetLastError();
        if (error == ERROR_CANCELLED)
        {
            UIManager::ShowError("User cancelled elevation request");
            Sleep(3000);
            ExitProcess(0);
        }
        throw std::runtime_error("Failed to restart with admin privileges");
    }

    ExitProcess(0);
}
