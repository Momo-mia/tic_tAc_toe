#include "Board.h"
#include "Position.h"

// Strategy Interface for Player Moves
// Defines a makeMove(Board board) method.
class PlayerStrategy {
public:
    // Allows different player strategies to be used interchangeably without
    // modifying client code.
    virtual Position makeMove(Board& board) = 0; // Pure virtual function
    virtual ~PlayerStrategy() = default; // Virtual destructor for safety
};