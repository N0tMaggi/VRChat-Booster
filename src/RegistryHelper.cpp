#include "RegistryHelper.h"

bool RegistryHelper::SetDWordValue(
    HKEY hKeyRoot,
    const std::string& subKey,
    const std::string& valueName,
    unsigned long value)
{
    HKEY hKey = nullptr;

    // Create or open the registry key
    LSTATUS status = RegCreateKeyExA(
        hKeyRoot,
        subKey.c_str(),
        0,
        nullptr,
        REG_OPTION_NON_VOLATILE,
        KEY_WRITE,
        nullptr,
        &hKey,
        nullptr
    );

    if (status != ERROR_SUCCESS) {
        return false;
    }

    // Set the value
    status = RegSetValueExA(
        hKey,
        valueName.c_str(),
        0,
        REG_DWORD,
        reinterpret_cast<const BYTE*>(&value),
        sizeof(unsigned long)
    );

    RegCloseKey(hKey);
    return status == ERROR_SUCCESS;
}

bool RegistryHelper::GetDWordValue(
    HKEY hKeyRoot,
    const std::string& subKey,
    const std::string& valueName,
    unsigned long& outValue)
{
    HKEY hKey = nullptr;

    LSTATUS status = RegOpenKeyExA(
        hKeyRoot,
        subKey.c_str(),
        0,
        KEY_READ,
        &hKey
    );

    if (status != ERROR_SUCCESS) {
        return false;
    }

    DWORD dataSize = sizeof(unsigned long);
    status = RegQueryValueExA(
        hKey,
        valueName.c_str(),
        nullptr,
        nullptr,
        reinterpret_cast<BYTE*>(&outValue),
        &dataSize
    );

    RegCloseKey(hKey);
    return status == ERROR_SUCCESS;
}

bool RegistryHelper::KeyExists(
    HKEY hKeyRoot,
    const std::string& subKey)
{
    HKEY hKey = nullptr;

    LSTATUS status = RegOpenKeyExA(
        hKeyRoot,
        subKey.c_str(),
        0,
        KEY_READ,
        &hKey
    );

    if (hKey != nullptr) {
        RegCloseKey(hKey);
    }

    return status == ERROR_SUCCESS;
}
