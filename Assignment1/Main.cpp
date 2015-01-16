#include <iostream>
#include <SDL.h>

using namespace std;

int main(int argc, char ** argv)
{
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Window *window = SDL_CreateWindow("Asteroids Beta", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640, SDL_WINDOW_SHOWN);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


	float posX = 100.0f, posY = 100.0f;
	float endPointOffsetX = 10.0f, endPointOffsetY = 0.0f;
	float oldTime, currentTime, deltaTime;
	float speed = 100.0f;

	oldTime = SDL_GetTicks();
	currentTime = oldTime;

	while (true)
	{
		SDL_Event evt;
		SDL_PollEvent(&evt);
		//Check for user input.

		//Calculate time since last loop
		oldTime = currentTime;
		currentTime = SDL_GetTicks();
		deltaTime = (currentTime - oldTime) / 1000;//Converting from miliseconds to seconds.
		
		/*Player Controls*/
		if (evt.type == SDL_KEYDOWN)
		{
			SDL_KeyboardEvent &keyboardEvt = evt.key; //reference because prevents to rewrite the right side of these two lines.
			SDL_Keycode &keyCode = keyboardEvt.keysym.sym;
			switch (keyCode)
			{
			case SDLK_UP:
				posY -= (speed * deltaTime);
				break;
			case SDLK_DOWN:
				posY += (speed * deltaTime);
				break;
			case SDLK_RIGHT:
				posX += (speed * deltaTime);
				break;
			case SDLK_LEFT:
				posX -= (speed * deltaTime);
				break;
			default:
				break;
			}
		}


		// Set the draw colour for the background.
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

		//Clear the renderer with the current draw colour.
		SDL_RenderClear(renderer);

		// Set the draw color for our point.
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		//Draw the point
		float transformedEndPointX = posX + endPointOffsetX;
		float transformedEndPointY = posY + endPointOffsetY;
		SDL_RenderDrawLine(renderer, posX, posY, transformedEndPointX, transformedEndPointY);

		float rotationDegrees = 10.0f;
		float degreesToRadians = 3.141592653f / 180.0f;
		float radiansToDegrees = 180.0f / 3.141592653f;
		float rotationRadians = rotationDegrees * degreesToRadians;


		float rX = endPointOffsetX * cos(degreesToRadians) + endPointOffsetY * sin(degreesToRadians);
		float rY = endPointOffsetX * sin(degreesToRadians) + endPointOffsetY * cos(degreesToRadians);

		transformedEndPointX = posX + rX;
		transformedEndPointY = posY + rY;

		//SDL_RenderDrawPoint(renderer, posX, posY);

		/*
		posY++;
		if (posY > 640){ posY = 0; }
		*/
		SDL_RenderDrawPoint(renderer, posX, posY);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_QUIT;

	return 0;
}
