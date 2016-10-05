/******************************
 *Name: Cody Wilson			  *
 *Date: 9/16/2016			  *
 *Class: CS 321				  *
 *Desciption: This program	  *
 *plays an annimation when 	  *
 * the user runs the program  *
 *of 2 stick men playing catch*
 *with a football			  *
 ******************************/

#include <SDL.h>
#include <SDL_image.h>

int main(int argc, char ** argv)
{
    bool quit = false;							//Check to end program
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window * window = SDL_CreateWindow("CS321 Assignment 2",		//Creating window for application
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640,
        480, 0);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);		//Initializing renderer
    SDL_Surface * image = IMG_Load("straight.png");						//Loading image into surface 
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,		//Creating texture with image
        image);
	SDL_Surface * ball = IMG_Load("ball.png");							//Loading image for ball
	SDL_Surface * jump = IMG_Load("jump.png");							//Loading image for jumping guy
	SDL_Texture * ballTex = SDL_CreateTextureFromSurface(renderer, ball);	//Setting up textures for other 2 elements of the program
	SDL_Texture * jumpTex = SDL_CreateTextureFromSurface(renderer, jump);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);						//Setting color of window to black
    SDL_RenderClear(renderer);											//Clearing renderer

    while (!quit)														//Main loop
    {
        Uint32 ticks = SDL_GetTicks();									//Getting ticks to tell which frame of the animation to show
        Uint32 sprite = (ticks / 100) % 4;
		int x = 150; int y = 10;						
        SDL_Rect srcrect = { sprite * 75, 0, 75, 150 };					//Setting locations for each of the elements used in the animation
        SDL_Rect dstrect = { 10, 10, 75, 150 };
		SDL_Rect ballsrcrect = {sprite * 75, 0, 75, 150};
		SDL_Rect balldstrect = { x, y, 75, 150 };
		SDL_Rect jumpsrc = { sprite * 75, 0, 75, 150 };
		SDL_Rect jumpdst = { 225, 10, 75, 150 };
		
		
		SDL_Delay(100);													//Delay for the animation
        SDL_PollEvent(&event);

        switch (event.type)												//Ending program if x in top right is clicked
        {
        case SDL_QUIT:
            quit = true;
            break;
        }

        SDL_RenderClear(renderer);										//Clearing renderer
        SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);			//Copying the renderers to present them
		SDL_RenderCopy(renderer, ballTex, &ballsrcrect, &balldstrect);
		SDL_RenderCopy(renderer, jumpTex, &jumpsrc, &jumpdst);
        SDL_RenderPresent(renderer);									//Presenting the renders
    }

    SDL_DestroyTexture(texture);										//Cleaning up SDL when we're done
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}