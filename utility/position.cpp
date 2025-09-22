class Position {
    public:
        int row;
        int col;
    
        // Constructor to initialize the position
        Position(int row, int col) {
            this->row = row;
            this->col = col;
        }
    
        // Optional: For better debugging or printing
        std::string toString() const {
            return "(" + std::to_string(row) + ", " + std::to_string(col) + ")"; // If row = 3 and col = 5, the result is:

"(3, 5)"
        }
    
        // Optional: Equals operator if you ever want to compare positions
        bool operator==(const Position& other) const {
            return this->row == other.row && this->col == other.col; // yahan compare kar re to * (pointer) ki jagah &(reference) lia
        }
    
        // Optional: hash function if you want to use in unordered_map/set
        std::size_t hash() const {
            return 31 * row + col;
        }
    };
