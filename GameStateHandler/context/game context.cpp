class GameContext {
    private:
        GameState* currentState;
    
    public:
        GameContext() {
            currentState = new XTurnState(); // Start with X's turn
        }
    
        void setState(GameState* state) {
            currentState = state;
        }
    
        void next(Player* player, bool hasWon) {
            currentState->next(this, player, hasWon);
        }
    
        bool isGameOver() {
            return currentState->isGameOver();
        }
    
        GameState* getCurrentState() {
            return currentState;
        }
    
        ~GameContext() {
            delete currentState; // Clean up dynamically allocated state
        }
    };