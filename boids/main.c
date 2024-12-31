#include "boid.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>

#define sizeofFlock 100;
int SIZE[2] = {1000, 1000};

int main(int argc, char *argv[]) {
  // returns zero on success else non-zero
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }
  SDL_Window *win =
      SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       SIZE[0], SIZE[1], 0);

  Uint32 render_flags = SDL_RENDERER_ACCELERATED;
  SDL_Renderer *rend = SDL_CreateRenderer(win, -1, render_flags);

  SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
  // SDL_RenderDrawPoint(rend, 100, 100);

  Boid newboid = {.posX = 10, .posY = 100, .velX = 100, .velY = 10};

  updateBoid(&newboid, 100, 100, 90, 90);
  renderBoid(&newboid, rend);
  SDL_RenderPresent(rend);
  // Cleanup
  SDL_Event e;
  int quit = 0;
  while (!quit) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT)
        quit = 1;
    }
  }
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(win);
  SDL_Quit();
  printf("%d\n", newboid.posX);
  return 0;
}
