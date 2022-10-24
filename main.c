#include "SDL2/SDL.h"

SDL_Window *window;
SDL_Renderer *renderer;

int width = 512, height = 512, frame_rate = 60;

SDL_Rect box;

void draw_checkerboard(int size)
{
  SDL_SetRenderDrawColor(renderer, 255, 0, 77, 0);

  int length = width / size;

  int drew_prev;

  for (int x = 0; x < size; ++x)
  {
    int drew_prev = x % 2;

    for (int y = 0; y < size; ++y)
    {
      if (drew_prev == 1)
      {
        drew_prev = 0;
        continue;
      }

      drew_prev = 1;

      box.x = x * length;
      box.y = y * length;
      box.w = length;
      box.h = length;

      SDL_RenderFillRect(renderer, &box);
    }
  }
}

int main(int argc, char *argv[])
{
  SDL_InitSubSystem(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

  SDL_Event event;

  SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_RESIZABLE, &window, &renderer);

  SDL_bool quit = SDL_FALSE;

  while (!quit)
  {
    Uint64 start = SDL_GetTicks64();

    while (SDL_PollEvent(&event))
      switch (event.type)
      {
      case SDL_QUIT:
        quit = SDL_TRUE;
        break;
      default:
        break;
      }

    SDL_SetRenderDrawColor(renderer, 255, 204, 170, 0);
    SDL_RenderClear(renderer);

    draw_checkerboard(32);

    SDL_RenderPresent(renderer);

    Uint64 end = SDL_GetTicks64();

    int wait_for = 1000 / frame_rate - (end - start);

    if (wait_for > 0)
    {
      SDL_Delay(wait_for);
    }
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  SDL_Quit();

  return 0;
}
