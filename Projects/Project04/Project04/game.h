#pragma once
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SDL.h>
#include <SDL_mixer.h>

class Game {
public:
    enum Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
    enum Player { PLAYER_1, PLAYER_2 };
    enum Cell { EMPTY, PLAYER_1_BOX, PLAYER_2_BOX };

    Game(int rows = 5, int cols = 5);
    ~Game();

    void play(int row, int col);
    Status status() const;
    void draw(SDL_Renderer* renderer) const;
    void handleInput(const SDL_Event& e);
    void reset();

private:
    void updateScore(int row, int col);
    void togglePlayer();

    std::vector<std::vector<Cell>> board;
    Player currentPlayer;
    int rows;
    int cols;
    int player1Score;
    int player2Score;

    Mix_Chunk* placeSound;
    Mix_Chunk* winSound;
    Mix_Chunk* drawSound;
};

#endif // GAME_H
