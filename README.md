VRChat Priority Setter
======================

Dieses Projekt setzt die Prozess-Priorität von VRChat beim Start per Registry-Eintrag.

Build
-----
1. Öffne VRCHATPRIOSETTER.sln in Visual Studio 2022.
2. Stelle das Ziel x64 und Release ein.
3. Baue das Projekt (Strg+Shift+B).

Ordnerstruktur
---------------
- src/    : Quell- und Headerdateien
- VRCHATPRIOSETTER/ : von Visual Studio erzeugte Build-Ausgaben (Debug/Release/x64)
- update_project.ps1: regeneriert die vcxproj/vcxproj.filters

Hinweis
-------
Das Tool benötigt Administratorrechte, um in die Registry zu schreiben.
