class Player {
    private:
        Symbol symbol; //no pointer here mtlb no SYmbol* as it is enum or small like symbol can only be 0,X or empty
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
