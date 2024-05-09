#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#define SCREEN_WIDTH 700
#define SCREEN_HEIGHT 700

int centerx = SCREEN_WIDTH / 2;
int centery = SCREEN_HEIGHT / 2;
int radius= 70;


void createCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius)
{
    for (int x = -radius; x <= radius; x++)
    {
        for (int y = -radius; y <= radius; y++)
        {
            if (x*x + y*y <= radius*radius)
            {
                SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
            }
        }
    }
}
bool activateSDL(SDL_Window** window, SDL_Renderer** renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("FAILED THE EVENT!");

        return false;
    }

    *window = SDL_CreateWindow("Circle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (*window == NULL)
    {
        printf("FAILED THE EVENT!");

        return false;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (*renderer == NULL)
    {
        printf("FAILED THE EVENT!");

        return false;
    }

    return true;
}

int main(int argc, char* argv[])
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (!activateSDL(&window, &renderer))
    {
        return 1;
    }

    SDL_Event event;

    bool running = true;

    while (running) 
    {
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 60, 120, 260, 255);
        SDL_RenderClear(renderer);

            
        SDL_SetRenderDrawColor(renderer,50 , 60, 70, 255);
        createCircle(renderer, centerx, centery, radius);

        SDL_RenderPresent(renderer);
    }
   
    return 0;
}