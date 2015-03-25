//Nathan Kowaleski
//3/24/15
//SDL tutorial
//Guy.h
#ifndef GUY_H_
#define GUY_H_
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#define GRAVITY 100.0
using namespace std;
class Guy
{
public:
Guy(SDL_Renderer*);
~Guy();
void update(Uint32);
void draw();
void handleEvent(SDL_Event&);
private:
SDL_Texture* tex;
SDL_Renderer* renderer;
double xpos;
double ypos;
double xv;
double yv;
void loadTexture(string);
};
#endif /* GUY_H_ */
