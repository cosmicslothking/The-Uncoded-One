#include "GameMode.h"
#include "eGameMode.h"
#include <iostream>

eGameMode GameMode::gameMode;

void GameMode::GameModeSelection()
{
    int gameModeChoice;
    bool selected = false;
    
    cout << "What game mode would you like?" << "\n";
    cout << "1. Player VS. Computer" << "\n";
    cout << "2. Computer VS. Computer" << "\n";
    cout << "3. Player VS. Player" << "\n";

    while(!selected)
    {
        cin >> gameModeChoice;

        switch (gameModeChoice)
        {
        case 1:
            gameMode = PVE;
            selected = true;
            break;
        case 2:
            gameMode = CVC;
            selected = true;
            break;
        case 3:
            gameMode = PVP;
            selected = true;
            break;
        default:
            cout << "I am sorry I did not understand your input. Please use a number between 1 and 3";
            selected = false;
        }
    }
}
