#include "GameState.h"
#include "GameContext.h"
#include "Player.h"
#include "XWonState.h"
#include "OWonState.h"
#include "OTurnState.h"
#include "Symbol.h"

class XTurnState : public GameState {
public:
    void next(GameContext* context, Player* player, bool hasWon) override {
        if (hasWon) {
            context->setState(player->getSymbol() == Symbol::X ? new XWonState() : new OWonState());
        } else {
            // Switch to OTurnState
            context->setState(new OTurnState());
        }
    }

    bool isGameOver() override {
        return false;
    }
};