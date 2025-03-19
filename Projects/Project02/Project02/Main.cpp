#include <iostream>
#include <vector>

class Game {
public:
    enum Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
    enum Player { PLAYER_1, PLAYER_2 };
    enum Cell { EMPTY, PLAYER_1_BOX, PLAYER_2_BOX };

private:
    std::vector<std::vector<Cell>> board;
    Player currentPlayer;
    int rows, cols;
    int player1Score, player2Score;

public:
    Game(int r = 5, int c = 5) : rows(r), cols(c), player1Score(0), player2Score(0) {
        // Initialize the board with EMPTY cells
        board = std::vector<std::vector<Cell>>(rows, std::vector<Cell>(cols, EMPTY));
        currentPlayer = PLAYER_1;
    }

    void play(int row, int col) {
        // Validate the move (ensures it's a valid range)
        if (row >= 0 && row < rows && col >= 0 && col < cols && board[row][col] == EMPTY) {
            board[row][col] = currentPlayer == PLAYER_1 ? PLAYER_1_BOX : PLAYER_2_BOX;
            updateScore(row, col);
            togglePlayer();
        }
    }

    Status status() const {
        if (player1Score + player2Score == rows * cols) {
            if (player1Score > player2Score) return PLAYER_1_WINS;
            else if (player2Score > player1Score) return PLAYER_2_WINS;
            else return DRAW;
        }
        return ONGOING;
    }

    void display() const {
        // Display the current board state
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == EMPTY)
                    std::cout << ".";
                else if (board[i][j] == PLAYER_1_BOX)
                    std::cout << "X";
                else if (board[i][j] == PLAYER_2_BOX)
                    std::cout << "O";
            }
            std::cout << std::endl;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Game& game) {
        game.display();
        return os;
    }

private:
    void updateScore(int row, int col) {
        // Update scores based on completed boxes after the current move
        if (row > 0 && board[row - 1][col] != EMPTY && board[row - 1][col] == board[row][col]) {
            if (board[row][col] == PLAYER_1_BOX) player1Score++;
            else player2Score++;
        }
        if (col > 0 && board[row][col - 1] != EMPTY && board[row][col - 1] == board[row][col]) {
            if (board[row][col] == PLAYER_1_BOX) player1Score++;
            else player2Score++;
        }
    }

    void togglePlayer() {
        currentPlayer = (currentPlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;
    }
};

int main() {
    Game game;
    int row, col;

    while (game.status() == Game::ONGOING) {
        std::cout << "Player " << (game.status() == Game::PLAYER_1_WINS ? 1 : 2) << "'s turn\n";
        game.display();

        std::cout << "Enter row and column (0-based index): ";
        std::cin >> row >> col;

        game.play(row, col);
    }

    std::cout << "Game Over! ";
    Game::Status result = game.status();
    if (result == Game::PLAYER_1_WINS) {
        std::cout << "Player 1 wins!";
    }
    else if (result == Game::PLAYER_2_WINS) {
        std::cout << "Player 2 wins!";
    }
    else {
        std::cout << "It's a draw!";
    }

    return 0;
}
