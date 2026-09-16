#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include "FileSystem.h"
#include "SDL_State.h"

using namespace std;
using namespace FileSystem;

#define dWidth 1600
#define dHeight 800
#define dLogW 640
#define dLogH 320

int main(int argc, char* argv[]) {
    SDL_State state;
    state.setLogSize(dLogW, dLogH);
    state.setResolution(dWidth, dHeight);
    state.init();

    // Configure presentation
    SDL_SetRenderLogicalPresentation(state.getRenderer(), state.getLogSize().width , state.getLogSize().height, SDL_LOGICAL_PRESENTATION_STRETCH);

    // Load file assets
    SDL_Texture* texture = IMG_LoadTexture(state.getRenderer(), GetPath("data/texture/idle.png").c_str());
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
                    state.setResolution(e.window.data1, e.window.data2);
                    break;
            }
        }

        // Drawing command
        SDL_SetRenderDrawColor(state.getRenderer(), 20, 10, 30, 255);
        SDL_RenderClear(state.getRenderer());

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

        SDL_RenderTexture(state.getRenderer(), texture, &src, &dst);

        // Swap buffer draw
        SDL_RenderPresent(state.getRenderer());
    }


    // End game loop
    SDL_DestroyTexture(texture);
    state.cleanup();
    return 0;
}
