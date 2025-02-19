#include <iostream>
#include <vector>
#include <limits>

enum class Cell { EMPTY, PLAYER_1, PLAYER_2 };
enum class GameState { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };

const int BOARD_SIZE = 15;
std::vector<std::vector<Cell>> board(BOARD_SIZE, std::vector<Cell>(BOARD_SIZE, Cell::EMPTY));

void printRules() {
    std::cout << "Welcome to Gomoku (Five in a Row)!\n";
    std::cout << "Rules:\n";
    std::cout << "1. Players take turns placing their symbol (X or O) on a 15x15 board.\n";
    std::cout << "2. The first player to align five of their symbols in a row (horizontally, vertically, or diagonally) wins.\n";
    std::cout << "3. The game ends in a draw if the board is full with no winner.\n";
    std::cout << "Enter your move as row and column numbers (0-based indexing).\n\n";
}

void makeBoard() {
    board.assign(BOARD_SIZE, std::vector<Cell>(BOARD_SIZE, Cell::EMPTY));
}

void displayBoard() {
    std::cout << "  ";
    for (int c = 0; c < BOARD_SIZE; ++c) std::cout << c % 10 << " ";
    std::cout << "\n";
    for (int r = 0; r < BOARD_SIZE; ++r) {
        std::cout << r % 10 << " ";
        for (int c = 0; c < BOARD_SIZE; ++c) {
            if (board[r][c] == Cell::PLAYER_1) std::cout << "R ";
            else if (board[r][c] == Cell::PLAYER_2) std::cout << "B ";
            else std::cout << ". ";
        }
        std::cout << "\n";
    }
}

bool isValidMove(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == Cell::EMPTY;
}

GameState checkWinner(int row, int col, Cell player) {
    const int directions[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };
    for (auto [dr, dc] : directions) {
        int count = 1;
        for (int d = -1; d <= 1; d += 2) {
            int r = row + d * dr, c = col + d * dc;
            while (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == player) {
                count++;
                r += d * dr;
                c += d * dc;
            }
        }
        if (count >= 5) {
            return (player == Cell::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
        }
    }
    for (const auto& row : board) {
        for (Cell cell : row) {
            if (cell == Cell::EMPTY) return GameState::ONGOING;
        }
    }
    return GameState::DRAW;
}

void play() {
    makeBoard();
    GameState gameState = GameState::ONGOING;
    Cell currentPlayer = Cell::PLAYER_1;

    while (gameState == GameState::ONGOING) {
        displayBoard();
        int row, col;
        std::cout << "Player " << ((currentPlayer == Cell::PLAYER_1) ? "R" : "B") << "'s turn. Enter row and column: ";

        while (!(std::cin >> row >> col) || !isValidMove(row, col)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Illegal move. Try again: ";
        }

        board[row][col] = currentPlayer;
        gameState = checkWinner(row, col, currentPlayer);

        if (gameState == GameState::ONGOING) {
            currentPlayer = (currentPlayer == Cell::PLAYER_1) ? Cell::PLAYER_2 : Cell::PLAYER_1;
        }
    }

    displayBoard();
    if (gameState == GameState::PLAYER_1_WINS) {
        std::cout << "Congratulations! Player R wins!\n";
    }
    else if (gameState == GameState::PLAYER_2_WINS) {
        std::cout << "Congratulations! Player B wins!\n";
    }
    else {
        std::cout << "It's a draw!\n";
    }
}

int main() {
    printRules();
    while (true) {
        play();
        char choice;
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> choice;
        if (choice != 'y' && choice != 'Y') break;
    }
    std::cout << "Thanks for playing Gomoku!\n";
    return 0;
}
