#pragma once
#include "GameContext.h"
#include "Player.h"

// GameState Interface
class GameState {
public:
    virtual void next(class GameContext* context, class Player* player, bool hasWon) = 0;
    virtual bool isGameOver() = 0;
    virtual ~GameState() = default;
};