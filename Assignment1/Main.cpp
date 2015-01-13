#include <iostream>
#include <SDL.h>

using namespace std;

int main(int argc, char ** argv)
{
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Window *window = SDL_CreateWindow("Asteroids Beta", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640, SDL_WINDOW_SHOWN);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	// Set the draw colour for the background.
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	//Clear the renderer with the current draw colour.
	SDL_RenderClear(renderer);
	int posY = 100, posX = 100;
	while (true)
	{
		SDL_Event evt;
		SDL_PollEvent(&evt);

		// Set the draw color for our point.
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

		SDL_RenderDrawPoint(renderer, posX, posY);

		posY = ((posY < posX) ? posY + 1 : posY);

		SDL_RenderDrawPoint(renderer, 100, 100);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_QUIT;

	return 0;
}