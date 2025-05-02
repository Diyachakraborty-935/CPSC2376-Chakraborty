#include "Game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include <iostream>

Game::Game(SDL_Renderer* renderer)
    : renderer(renderer), currentPlayer(Player::Player1), gameState(GameState::InProgress) {
    clickSound = Mix_LoadWAV("assets/click.wav");
    victorySound = Mix_LoadWAV("assets/victory.wav");
    if (!clickSound || !victorySound) {
        std::cerr << "Mix_LoadWAV Error: " << Mix_GetError() << std::endl;
    }
    initialize();
}

Game::~Game() {
    if (clickSound) Mix_FreeChunk(clickSound);
    if (victorySound) Mix_FreeChunk(victorySound);
}

void Game::initialize() {
    for (auto& row : grid) {
        row.fill(Player::None);
    }
    gameState = GameState::InProgress;
}

void Game::draw() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Draw grid and players' moves

    SDL_RenderPresent(renderer);
}

void Game::handleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quit();
        }
        else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_r) {
                restart();
            }
            else if (event.key.keysym.sym == SDLK_ESCAPE) {
                quit();
            }
        }
    }
}

void Game::update() {
    // Update game state
    // Check for completed boxes and switch players
}

void Game::playSound(Mix_Chunk* sound) {
    if (sound) {
        Mix_PlayChannel(-1, sound, 0);
    }
}

void Game::displayOutcome() {
    // Display win/loss/draw message
    playSound(victorySound);
}

void Game::restart() {
    initialize();
}

void Game::quit() {
    SDL_Quit();
    exit(0);
}

void Game::play() {
    while (true) {
        handleInput();
        update();
        draw();
        SDL_Delay(100);
    }
}
