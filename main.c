#include "SDL2/SDL.h"

int width = 512, height = 512, frame_rate = 60;

int main(int argc, char *argv[])
{
  SDL_InitSubSystem(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Event event;

  SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_RESIZABLE, &window, &renderer);

  SDL_bool quit = SDL_FALSE;

  SDL_Rect box;

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

    SDL_SetRenderDrawColor(renderer, 255, 0, 77, 0);

    box.x = 0;
    box.y = 0;
    box.w = width / 2;
    box.h = height / 2;

    SDL_RenderFillRect(renderer, &box);

    box.x = width / 2;
    box.y = height / 2;
    box.w = width / 2;
    box.h = height / 2;

    SDL_RenderFillRect(renderer, &box);

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
