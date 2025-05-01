#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);

    SDL_Window* window = SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Game game;
    SDL_Event event;
    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
                quit = true;
            }
            game.handleInput(event);
        }

        SDL_RenderClear(renderer);
        game.draw(renderer);
        SDL_RenderPresent(renderer);

        Game::Status gameStatus = game.status();
        if (gameStatus != Game::ONGOING) {
            if (gameStatus == Game::PLAYER_1_WINS || gameStatus == Game::PLAYER_2_WINS)
                Mix_PlayChannel(-1, Mix_LoadWAV("win.wav"), 0);
            else
                Mix_PlayChannel(-1, Mix_LoadWAV("draw.wav"), 0);

            SDL_Delay(2000);
            game.reset(); // Restart game
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}
