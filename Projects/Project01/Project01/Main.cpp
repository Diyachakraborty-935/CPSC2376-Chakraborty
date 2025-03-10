#include <iostream>
#include <vector>
#include <limits>

// Enumeration for game state
enum class GameState {
    ONGOING,
    PLAYER_1_WINS,
    PLAYER_2_WINS,
    DRAW
};

// Enumeration for players
enum class Player {
    PLAYER_1 = 1,
    PLAYER_2 = 2
};

// Class to represent the game board
class DotsAndBoxes {
private:
    int rows, cols;
    std::vector<std::vector<bool>> horizontalLines;  // Horizontal lines
    std::vector<std::vector<bool>> verticalLines;    // Vertical lines
    std::vector<std::vector<int>> boxes;             // Boxes (0 - empty, 1 - Player 1, 2 - Player 2)
    int player1Score, player2Score;

public:
    DotsAndBoxes(int r, int c) : rows(r), cols(c), player1Score(0), player2Score(0) {
        // Initialize the grid
        horizontalLines.resize(rows - 1, std::vector<bool>(cols, false));
        verticalLines.resize(rows, std::vector<bool>(cols - 1, false));
        boxes.resize(rows - 1, std::vector<int>(cols - 1, 0));
    }

    void printBoard() {
        std::cout << "\nGame Board:\n";

        // Print top row of dots
        for (int i = 0; i < cols; ++i) std::cout << ". ";
        std::cout << "\n";

        // Print the board
        for (int r = 0; r < rows - 1; ++r) {
            for (int c = 0; c < cols - 1; ++c) {
                // Print horizontal lines
                if (horizontalLines[r][c]) {
                    std::cout << "-";
                }
                else {
                    std::cout << " ";
                }
                std::cout << " ";
            }
            std::cout << "\n";

            // Print vertical lines and boxes
            for (int c = 0; c < cols; ++c) {
                // Print vertical lines
                if (c < cols - 1 && verticalLines[r][c]) {
                    std::cout << "|";
                }
                else {
                    std::cout << " ";
                }

                // Print boxes
                if (c < cols - 1) {
                    if (boxes[r][c] == 0) {
                        std::cout << " ";
                    }
                    else if (boxes[r][c] == 1) {
                        std::cout << "X"; // Player 1's box
                    }
                    else {
                        std::cout << "O"; // Player 2's box
                    }
                    std::cout << " ";
                }
            }
            std::cout << "\n";
        }
    }

    bool makeMove(int x, int y, Player currentPlayer) {
        if (x < 0 || x >= rows - 1 || y < 0 || y >= cols - 1) {
            return false; // Invalid move
        }

        // If the move completes a box, mark it and return true
        bool boxCompleted = false;
        if (!horizontalLines[x][y] && !verticalLines[x][y] && !verticalLines[x][y + 1] && !horizontalLines[x + 1][y]) {
            if (currentPlayer == Player::PLAYER_1) {
                boxes[x][y] = 1; // Player 1's box
                player1Score++;
                boxCompleted = true;
            }
            else {
                boxes[x][y] = 2; // Player 2's box
                player2Score++;
                boxCompleted = true;
            }
        }
        return boxCompleted;
    }

    bool checkMove(int x, int y) {
        return horizontalLines[x][y] || verticalLines[x][y] || verticalLines[x][y + 1] || horizontalLines[x + 1][y];
    }

    GameState getGameStatus() {
        if (player1Score + player2Score == (rows - 1) * (cols - 1)) {
            if (player1Score > player2Score) return GameState::PLAYER_1_WINS;
            if (player2Score > player1Score) return GameState::PLAYER_2_WINS;
            return GameState::DRAW;
        }
        return GameState::ONGOING;
    }

    void displayRules() {
        std::cout << "Dots and Boxes Game Rules:\n";
        std::cout << "1. Players take turns drawing a horizontal or vertical line between two unjoined adjacent dots.\n";
        std::cout << "2. When a player completes the 4th side of a 1x1 box, they score a point and take another turn.\n";
        std::cout << "3. The player with the most completed boxes at the end of the game wins.\n";
    }
};

// Function to handle player input
void getInput(int& x, int& y) {
    std::cout << "Enter row and column for your move (e.g., 0 1 for row 0, col 1): ";
    while (!(std::cin >> x >> y) || x < 0 || y < 0 || x >= 3 || y >= 3) {
        std::cout << "Invalid input. Please enter valid row and column indices.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    DotsAndBoxes game(4, 4); // Create a game with a 4x4 grid
    game.displayRules();

    bool playAgain = true;
    while (playAgain) {
        GameState status = GameState::ONGOING;
        Player currentPlayer = Player::PLAYER_1;

        while (status == GameState::ONGOING) {
            game.printBoard();
            std::cout << "Player " << static_cast<int>(currentPlayer) << "'s turn.\n";

            int x, y;
            getInput(x, y);

            if (game.makeMove(x, y, currentPlayer)) {
                std::cout << "Move completed.\n";
            }
            else {
                std::cout << "Move not valid, try again.\n";
                continue;
            }

            status = game.getGameStatus();
            currentPlayer = (currentPlayer == Player::PLAYER_1) ? Player::PLAYER_2 : Player::PLAYER_1;
        }

        game.printBoard();
        if (status == GameState::PLAYER_1_WINS) {
            std::cout << "Player 1 wins!\n";
        }
        else if (status == GameState::PLAYER_2_WINS) {
            std::cout << "Player 2 wins!\n";
        }
        else {
            std::cout << "It's a draw!\n";
        }

        std::cout << "Do you want to play again? (1 for Yes, 0 for No): ";
        std::cin >> playAgain;
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}
