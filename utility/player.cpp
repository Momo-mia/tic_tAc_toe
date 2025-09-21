class Player {
    private:
        Symbol symbol;
        PlayerStrategy* playerStrategy;
    
    public:
        // Constructor to initialize the player with a symbol and strategy
        Player(Symbol symbol, PlayerStrategy* playerStrategy) {
            this->symbol = symbol;
            this->playerStrategy = playerStrategy;
        }
    
        // Getter for the player's symbol
        Symbol getSymbol() {
            return symbol;
        }
    
        // Getter for the player's strategy
        PlayerStrategy* getPlayerStrategy() {
            return playerStrategy;
        }
    };