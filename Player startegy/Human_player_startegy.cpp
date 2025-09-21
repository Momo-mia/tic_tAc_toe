class HumanPlayerStrategy : public PlayerStrategy {
    private:
        string playerName;
    public:
        // HumanPlayerStrategy Constructor
        HumanPlayerStrategy(const string& playerName) {
            this->playerName = playerName;
        }
    
        Position makeMove(Board& board) override {
            while (true) {
                cout << playerName << ", enter your move (row [0-2] and column [0-2]): ";
                int row, col;
                cin >> row >> col;
    
                // Prompts the human player to enter their move.
                Position move(row, col);
    
                // Validates the player's input.
                // If the move is valid, returns the position.
                if (board.isValidMove(move)) {
                    return move;
                }
    
                // If the move is invalid, prompts the player to try again.
                cout << "Invalid move. Try again." << endl;
    
                // Clear input buffer
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    };