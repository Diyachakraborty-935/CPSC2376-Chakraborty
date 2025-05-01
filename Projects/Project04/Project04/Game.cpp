#include "game.h"

Game::Game(int r, int c)
    : rows(r), cols(c), player1Score(0), player2Score(0), currentPlayer(PLAYER_1) {
    board = std::vector<std::vector<Cell>>(rows, std::vector<Cell>(cols, EMPTY));
    placeSound = Mix_LoadWAV("place.wav");
    winSound = Mix_LoadWAV("win.wav");
    drawSound = Mix_LoadWAV("draw.wav");
}

Game::~Game() {
    Mix_FreeChunk(placeSound);
    Mix_FreeChunk(winSound);
    Mix_FreeChunk(drawSound);
}

void Game::play(int row, int col) {
    if (row >= 0 && row < rows && col >= 0 && col < cols && board[row][col] == EMPTY) {
        board[row][col] = (currentPlayer == PLAYER_1) ? PLAYER_1_BOX : PLAYER_2_BOX;
        updateScore(row, col);
        Mix_PlayChannel(-1, placeSound, 0);
        togglePlayer();
    }
}

Game::Status Game::status() const {
    if (player1Score + player2Score == rows * cols) {
        if (player1Score > player2Score) return PLAYER_1_WINS;
        if (player2Score > player1Score) return PLAYER_2_WINS;
        return DRAW;
    }
    return ONGOING;
}

void Game::draw(SDL_Renderer* renderer) const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            SDL_Rect cell = { j * 100, i * 100, 100, 100 };
            switch (board[i][j]) {
            case PLAYER_1_BOX:
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                break;
            case PLAYER_2_BOX:
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
                break;
            case EMPTY:
            default:
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                break;
            }
            SDL_RenderFillRect(renderer, &cell);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &cell);
        }
    }
}

void Game::handleInput(const SDL_Event& e) {
    if (e.type == SDL_KEYDOWN) {
        if (e.key.keysym.sym == SDLK_r) {
            reset();
        }
    }
}

void Game::reset() {
    board = std::vector<std::vector<Cell>>(rows, std::vector<Cell>(cols, EMPTY));
    currentPlayer = PLAYER_1;
    player1Score = 0;
    player2Score = 0;
}

void Game::updateScore(int row, int col) {
    if (row > 0 && board[row - 1][col] != EMPTY && board[row - 1][col] == board[row][col]) {
        (board[row][col] == PLAYER_1_BOX) ? ++player1Score : ++player2Score;
    }
    if (col > 0 && board[row][col - 1] != EMPTY && board[row][col - 1] == board[row][col]) {
        (board[row][col] == PLAYER_1_BOX) ? ++player1Score : ++player2Score;
    }
}

void Game::togglePlayer() {
    currentPlayer = (currentPlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;
}
