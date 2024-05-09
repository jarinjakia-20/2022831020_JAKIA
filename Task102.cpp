#include<stdio.h>

#include<SDL2/SDL.h>

#include<math.h>

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 640;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
bool game_running = false;
int rad =70 ;
int cenx = SCREEN_WIDTH/2;
int ceny = SCREEN_HEIGHT/2;

bool open_window()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) !=  0)
    {
        printf("FAILED THE EVENT!");
        return false;
    }

    window=SDL_CreateWindow("Circle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH , SCREEN_HEIGHT, 0);
    
    if(!window) 
    {
         return false;
    }

    renderer=SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(!renderer)
    {
        return false;
    }

    return true;
}

void setup()
{
    SDL_SetRenderDrawColor(renderer, 90, 100, 120, 255);

    SDL_RenderClear(renderer);

    SDL_Color color = {0,0,0,0};

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

}

void createCircle(SDL_Renderer* renderer, int cenx, int ceny, int rad)
{
    for (int x = -rad; x <= rad; x++)
    {
        for (int y = -rad; y <= rad; y++) 
        {
            if (x * x + y * y <= rad * rad) 
            {
                SDL_RenderDrawPoint(renderer, cenx + x, ceny + y);
            }
        }
    }
}

void update()
{
    rad += 5;

    if(rad >=320 )
    {
        rad = 20;
    }

    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer,255, 255, 255, 255);

    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer,0,0,0,0);
}

void render()
{
    createCircle(renderer, cenx , ceny, rad);

    SDL_RenderPresent(renderer);
}

void destroyWindow()
{
    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);

    SDL_Quit();
}

int main(int argc, char *argv[])
{
    game_running = open_window();

    while(game_running != false)
    {
        update();

        render();

    } 
    
   destroyWindow();   

  return 0;
}
