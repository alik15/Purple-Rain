#pragma once
#include <SDL2/SDL.h>
typedef struct Boid {
  int posX;
  int posY;
  int velX;
  int velY;
} Boid;

void updateBoid(Boid *boid, int posX, int posY, int velX, int velY);
void renderBoid(Boid *boid, SDL_Renderer *renderer);
