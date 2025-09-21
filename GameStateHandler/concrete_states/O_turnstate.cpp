include "GameState.h"
#include "GameContext.h"
#include "Player.h"
#include "XWonState.h"
#include "OWonState.h"
#include "XTurnState.h"
#include "Symbol.h"

class OTurnState : public GameState {
public:
    void next(GameContext* context, Player* player, bool hasWon) override {
        if (hasWon) {
            context->setState(player->getSymbol() == Symbol::X ? new XWonState() : new OWonState());
        }
        // Switch to XTurnState
        context->setState(new XTurnState());
    }

    bool isGameOver() override {
        return false;
    }
};