#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include "FileSystem.h"
#include "SDL_State.h"

using namespace std;
using namespace FileSystem;

#define height 1600;
#define width 800;
#define logW 640;
#define logH 320;

int main(int argc, char* argv[]) {
    SDL_State state;


    // Configure presentation
    int logW=640;
    int logH=320;
    SDL_SetRenderLogicalPresentation(state.renderer, logW, logH, SDL_LOGICAL_PRESENTATION_STRETCH);

    // Load file assets
    SDL_Texture* texture = IMG_LoadTexture(state.renderer, GetPath("data/texture/idle.png").c_str());
    SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);

    // Start main game loop
    bool running = true;
    while (running)
    {
        // Quit handle event
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            switch (e.type)
            {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;

                case SDL_EVENT_WINDOW_RESIZED:
                    state.width = e.window.data1;
                    state.height = e.window.data2;
                    break;
            }
        }

        // Drawing command
        SDL_SetRenderDrawColor(state.renderer, 20, 10, 30, 255);
        SDL_RenderClear(state.renderer);

        SDL_FRect src{
        .x = 0,
        .y = 0,
        .w = 32,
        .h = 32,};

        SDL_FRect dst{
        .x = 0,
        .y = 0,
        .w = 32,
        .h = 32,};

        SDL_RenderTexture(state.renderer, texture, &src, &dst);

        // Swap buffer draw
        SDL_RenderPresent(state.renderer);
    }


    // End game loop
    SDL_DestroyTexture(texture);
    cleanup(state);
    return 0;
}
