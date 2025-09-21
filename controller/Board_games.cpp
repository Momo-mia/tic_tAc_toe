class BoardGames {
    public:
        // This interface illustrates how a large game company can manage multiple
        // types of games, including board games and non-board games. Tic Tac Toe is
        // an example of a game that is a child of the BoardGames interface.
        virtual void play() = 0; // Pure virtual function
        virtual ~BoardGames() = default; // Virtual destructor for safety
    };