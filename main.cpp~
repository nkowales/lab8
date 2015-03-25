//Nathan Kowaleski
//3/24/15
//SDL tutorial
//main.cpp
#include <iostream>
#include <SDL2/SDL.h>
#include "Guy.h"
using namespace std;
#define SCREENW 640
#define SCREENH 640
int main(int argc, char* args[])
{
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
{
cout << "Failed to init SDL." << endl;
return 1;
}
window = SDL_CreateWindow("Simple", SDL_WINDOWPOS_UNDEFINED,
SDL_WINDOWPOS_UNDEFINED, SCREENW, SCREENH, SDL_WINDOW_SHOWN);
if (!window)
{
cout << "Failed to open window." << endl;
return 2;
}
IMG_Init(IMG_INIT_PNG);
renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
bool quit = false;
SDL_Event e;

Guy guy(renderer);

Uint32 lastUpdate, currentUpdate;
lastUpdate = currentUpdate = SDL_GetTicks();
while (!quit)
{
if (((currentUpdate = SDL_GetTicks()) - lastUpdate) > 10)
{
SDL_RenderClear(renderer);
guy.update(currentUpdate - lastUpdate);
guy.draw();
lastUpdate = currentUpdate;
SDL_RenderPresent(renderer);
while(SDL_PollEvent(&e) != 0)
{
if (e.type == SDL_QUIT)
{
quit = true;
}
else
{
guy.handleEvent(e);
}
}
}
}
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
IMG_Quit();
SDL_Quit();
return 0;
}
