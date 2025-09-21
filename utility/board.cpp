
// Board Representation
class Board {
    private:
        const int rows;
        const int columns;
        vector<vector<Symbol>> grid;
    
    public:
        Board(int rows, int columns) {
            this->rows = rows;
            this->columns = columns;
            grid.resize(rows, vector<Symbol>(columns, Symbol::EMPTY));
        }
    
        // Checks if a given position is within the bounds of the board.
        bool isValidMove(Position* pos) {
            return pos->row >= 0 && pos->row < rows && pos->col >= 0 && pos->col < columns
                   && grid[pos->row][pos->col] == Symbol::EMPTY;
        }
    
        // Allows players to make their moves
        void makeMove(Position* pos, Symbol symbol) {
            grid[pos->row][pos->col] = symbol;
        }
    
        // Determines the current state of the game by checking for
        // Rows, Columns and Diagonals for winning conditions
        void checkGameState(GameContext* context, Player* currentPlayer) {
            for (int i = 0; i < rows; i++) {
                if (grid[i][0] != Symbol::EMPTY && isWinningLine(grid[i])) {
                    context->next(currentPlayer, true);
                    return;
                }
            }
    
            for (int i = 0; i < columns; i++) {
                vector<Symbol> column(rows);
                for (int j = 0; j < rows; j++) {
                    column[j] = grid[j][i];
                }
                if (column[0] != Symbol::EMPTY && isWinningLine(column)) {
                    context->next(currentPlayer, true);
                    return;
                }
            }
    
            vector<Symbol> diagonal1(min(rows, columns));
            vector<Symbol> diagonal2(min(rows, columns));
            for (int i = 0; i < min(rows, columns); i++) {
                diagonal1[i] = grid[i][i];
                diagonal2[i] = grid[i][columns - 1 - i];
            }
            if (diagonal1[0] != Symbol::EMPTY && isWinningLine(diagonal1)) {
                context->next(currentPlayer, true);
                return;
            }
            if (diagonal2[0] != Symbol::EMPTY && isWinningLine(diagonal2)) {
                context->next(currentPlayer, true);
                return;
            }
    
            // Additional logic to handle a draw or continue in progress can be added here
        }
    
    private:
        bool isWinningLine(const vector<Symbol>& line) {
            Symbol first = line[0];
            for (Symbol s : line) {
                if (s != first) {
                    return false;
                }
            }
            return true;
        }
    
    public:
        void printBoard() {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    Symbol symbol = grid[i][j];
                    switch (symbol) {
                        case Symbol::X:
                            cout << " X ";
                            break;
                        case Symbol::O:
                            cout << " O ";
                            break;
                        case Symbol::EMPTY:
                        default:
                            cout << " . ";
                    }
    
                    if (j < columns - 1) {
                        cout << "|";
                    }
                }
                cout << endl;
                if (i < rows - 1) {
                    cout << "---+---+---" << endl;
                }
            }
            cout << endl;
        }
    };