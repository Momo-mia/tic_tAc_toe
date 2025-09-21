#pragma once
#include "BoardGames.h"
#include "../Utility/Board.h"
#include "../Utility/Player.h"
#include "../GameStateHandler/Context/GameContext.h"
#include "../GameStateHandler/ConcreteStates/XWonState.h"
#include "../GameStateHandler/ConcreteStates/OWonState.h"
#include "../PlayerStrategies/PlayerStrategy.h"
#include "../CommonEnum/Symbol.h"
#include "../Utility/Position.h"
#include <iostream>

class TicTacToeGame : public BoardGames {
private:
    Board* board;
    Player* playerX;
    Player* playerO;
    Player* currentPlayer;
    GameContext* gameContext;

public:
    // Initializes the game board and players with their respective strategies.
    // Sets the current player to playerX. can be set to playerO as well
    TicTacToeGame(PlayerStrategy* xStrategy, PlayerStrategy* oStrategy,
                  int rows, int columns) {
        board = new Board(rows, columns);
        playerX = new Player(Symbol::X, xStrategy);
        playerO = new Player(Symbol::O, oStrategy);
        currentPlayer = playerX;
        gameContext = new GameContext();
    }

    ~TicTacToeGame() {
        delete board;
        delete playerX;
        delete playerO;
        delete gameContext;
    }

    // Loop continues until the game state indicates that the game is over.
    void play() override {
        do {
            // print the current state of the game
            board->printBoard();

            // current player makes the move
            Position move = currentPlayer->getPlayerStrategy()->makeMove(*board);
            board->makeMove(move, currentPlayer->getSymbol());

            // checks game state for win/draw
            board->checkGameState(*gameContext, *currentPlayer);

            switchPlayer();
        } while (!gameContext->isGameOver());

        announceResult();
    }

private:
    // Alternates the current player after each move.
    // Ensures both players take turns
    void switchPlayer() {
        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;
    }

    // Displays the outcome of the game based on the final game state.
    void announceResult() {
        GameState* state = gameContext->getCurrentState();
        board->printBoard();

        if (dynamic_cast<XWonState*>(state)) {
            std::cout << "Player X wins!" << std::endl;
        } else if (dynamic_cast<OWonState*>(state)) {
            std::cout << "Player O wins!" << std::endl;
        } else {
            std::cout << "It's a draw!" << std::endl;
        }
    }
};