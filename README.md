VRChat Priority Setter
======================

[![Platform](https://img.shields.io/badge/platform-Windows-0078d7?logo=windows)]()
[![IDE](https://img.shields.io/badge/IDE-Visual%20Studio%202022-5c2d91?logo=visualstudio)]()
[![License](https://img.shields.io/badge/license-MIT-brightgreen)](https://opensource.org/licenses/MIT)

A small console helper that sets VRChat's process priority *before* the game launches by writing a registry value. No game files are touched.

Features
--------
- Elevates itself when needed, then writes the priority once.
- Keeps the UI readable in the console (VT100 colors, status lines).
- Open source, minimal footprint (few CPP/H headers).

Build
-----
1. Open `VRCHATPRIOSETTER.sln` in Visual Studio 2022.
2. Select `x64` + `Release` (or `Debug` for testing).
3. Build with `Ctrl+Shift+B`.
4. Optional: run `update_project.ps1` to regenerate the project files if you move sources again.

Usage
-----
Run the compiled `VRCHATPRIOSETTER.exe` as Administrator, choose a priority (2–6), then start VRChat. The change applies on the next launch.

Project Layout
--------------
- `src/` – all C++ sources and headers.
- `update_project.ps1` – regenerates `vcxproj` + filters to point at `src/`.

Flow (mermaid)
--------------
```mermaid
flowchart TD
    Start([Start app]) --> Init[Init console + colors]
    Init --> Admin{Running as admin?}
    Admin -- no --> Elevate[Show warning + restart elevated]
    Admin -- yes --> Menu[Show priority menu]
    Menu --> Input{Valid priority?}
    Input -- no --> Menu
    Input -- yes --> Reg[Write registry value for VRChat.exe]
    Reg --> Done[Confirm + wait for next change]
```

Notes
-----
- Needs administrative rights to modify `HKLM`.
- "Realtime" priority is not recommended; use `High` for safer results.
