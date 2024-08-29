#pragma once
#include <memory>
#include "eGameMode.h"
using namespace std;

class GameMode
{
public:
    static void GameModeSelection();

    static void setGameMode(eGameMode value) { gameMode = value; }
    eGameMode getGameMode() { return gameMode; }

private:
    static eGameMode gameMode;
};
