#pragma once
#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include <array>

class Game {
public:
    Game(SDL_Renderer* renderer);
    ~Game();

    void play();

private:
    enum class Player { None, Player1, Player2 };
    enum class GameState { InProgress, Player1Wins, Player2Wins, Draw };

    SDL_Renderer* renderer;
    Mix_Chunk* clickSound;
    Mix_Chunk* victorySound;
    Player currentPlayer;
    GameState gameState;
    std::array<std::array<Player, 3>, 3> grid;

    void initialize();
    void draw();
    void handleInput();
    void update();
    void playSound(Mix_Chunk* sound);
    void displayOutcome();
    void restart();
    void quit();
};

#endif // GAME_H
