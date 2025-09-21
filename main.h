#include "TicTacToeGame.h"
#include "HumanPlayerStrategy.h"
#include "PlayerStrategy.h"

int main() {
    PlayerStrategy* playerXStrategy = new HumanPlayerStrategy("Player X");
    PlayerStrategy* playerOStrategy = new HumanPlayerStrategy("Player O");
    TicTacToeGame game(playerXStrategy, playerOStrategy, 3, 3);
    game.play();

    delete playerXStrategy;
    delete playerOStrategy;

    return 0;
}
