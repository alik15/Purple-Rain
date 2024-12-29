#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>
#include <time.h>

int A[2] = {500, 200};
int B[2] = {100, 800};
int C[2] = {900, 800};
int P[2];
int currentPoint[2] = {200, 200};
int iterations = 1000000;
int randomNumber;
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
  SDL_RenderDrawPoint(rend, A[0], A[1]);
  SDL_RenderDrawPoint(rend, B[0], B[1]);
  SDL_RenderDrawPoint(rend, C[0], C[1]);
  SDL_RenderDrawPoint(rend, currentPoint[0], currentPoint[1]);

  SDL_RenderPresent(rend);

  srand(time(NULL));

  for (int i = 0; i < iterations; i++) {
    randomNumber = rand() % (3);
    // choose random point from A,B and C
    switch (randomNumber) {
    case 0:
      currentPoint[0] = (A[0] + currentPoint[0]) / 2;
      currentPoint[1] = (A[1] + currentPoint[1]) / 2;
      break;
    case 1:
      currentPoint[0] = (B[0] + currentPoint[0]) / 2;
      currentPoint[1] = (B[1] + currentPoint[1]) / 2;
      break;
    case 2:
      currentPoint[0] = (C[0] + currentPoint[0]) / 2;
      currentPoint[1] = (C[1] + currentPoint[1]) / 2;
      break;
    };

    // find draw midpoint

    SDL_RenderDrawPoint(rend, currentPoint[0], currentPoint[1]);
    SDL_RenderPresent(rend);
  }
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(win);
  SDL_Quit();

  SDL_Event e;
  int quit = 0;
  while (!quit) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT)
        quit = 1;
    }
  }

  // Cleanup
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(win);
  SDL_Quit();
  return 0;
}
