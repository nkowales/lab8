//Nathan Kowaleski
//3/24/15
//SDL tutorial
//Guy.cpp
#include "Guy.h"
Guy::Guy(SDL_Renderer* ren)
{
tex = NULL;
renderer = ren;
loadTexture("mario.png");
xpos = 300;
ypos = 300;
xv = 0;
yv = 0;
}
Guy::~Guy()
{
if (tex)
{
SDL_DestroyTexture(tex);
tex = NULL;
}
}
void Guy::loadTexture(string fname)
{
SDL_Texture* texture = NULL;
SDL_Surface* surf = IMG_Load(fname.c_str());
texture = SDL_CreateTextureFromSurface(renderer, surf);
SDL_FreeSurface(surf);
tex = texture;
}
void Guy::update(Uint32 time)
{
double secs = time / 1000.;

xpos += xv * secs;
ypos += yv * secs;
yv += GRAVITY * secs;
if (ypos > 590)
{
yv = 0;
ypos=600;
}
}

void Guy::draw()
{
SDL_Rect dest;
dest.x = xpos - 32;
dest.y = ypos - 32;
dest.w = 64;
dest.h = 64;
SDL_RenderCopy(renderer, tex, NULL, &dest);
}

void Guy::handleEvent(SDL_Event& e)
{

if(e.type==SDL_KEYDOWN)
{
switch(e.key.keysym.sym)
{
case SDLK_UP:
if(ypos==600)
yv=-200;
break; 
case SDLK_LEFT:
xv=-100;
break;
case SDLK_RIGHT:
xv=100;
break;
case SDLK_w:
yv=-200;
break;
case SDLK_a:
xv=-100;
break;
case SDLK_d:
xv=100;
break;
default:
break; 
} 
}
if(e.type==SDL_KEYUP)
{
switch(e.key.keysym.sym)
{
case SDLK_LEFT:
xv=0;
break;
case SDLK_RIGHT:
xv=0;
break;
break;
case SDLK_a:
xv=0;
break;
case SDLK_d:
xv=0;
break;
default:
break; 
} 
}

}

