#include "boid.h"

void updateBoid(Boid *boid, int posX, int posY, int velX, int velY) {
  boid->posX = posX;
  boid->posY = posY;
  boid->velX = velX;
  boid->velY = velY;
};

void renderBoid(Boid *boid, SDL_Renderer *rend) {
  SDL_RenderDrawPoint(rend, boid->posX, boid->posY);
}
