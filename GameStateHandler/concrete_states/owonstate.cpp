#pragma once
#include "GameState.h"
#include "GameContext.h"
#include "Player.h"

class OWonState : public GameState {
public:
    void next(GameContext* context, Player* player, bool hasWon) override {
        // Game over, no next state
    }

    bool isGameOver() override {
        return true;
    }
};