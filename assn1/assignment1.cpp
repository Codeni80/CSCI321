#include <iostream>
#include <SDL.h>    
#include "SDL_image.h"   
#include "Fixed_print.h" 
 
 SDL_Texture * texture;
 SDL_Renderer * renderer;
 
int main(int argc, char ** argv) {
    SDL_Event event;
	SDL_MouseButtonEvent eventM;
	SDL_Rect dest;
	SDL_Rect src;
	SDL_Rect ssrc;
	SDL_Rect sdest;
    SDL_Init(SDL_INIT_VIDEO);
	int clickX, clickY;
	clickX = 0; clickY = 0;
	char string[100];
	SDL_Color c;
 
    SDL_Window * window;
	window = SDL_CreateWindow("CS321 Assignment 1", 	//Creating the window for the application
			    SDL_WINDOWPOS_UNDEFINED, 
			    SDL_WINDOWPOS_UNDEFINED, 
			    600, 400, SDL_WINDOW_SHOWN);
 
	FixedPrint_Setup();
    							//Initializing the renderer
	renderer = SDL_CreateRenderer(window, -1, 
				SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	SDL_Surface * square;								//Creating the surface for the image to be placed on
    SDL_Surface * image;
	image = IMG_Load("square1.png");
	square = IMG_Load("square.png");					//Loading in the image for the square that is to be used by the program
    texture = SDL_CreateTextureFromSurface(renderer, image);	//Creating the texture 
	
    dest.x = 0; dest.y = 0; dest.w = 50; dest.h = 50;	//Default source and destination for the SDL_Rects that are used
	src.x = 0; src.y = 0; src.w = 50; src.h = 50;
	
	
    while (1) {											//Infinate loop to keep program running
        if (SDL_PollEvent(&event) > 0){					//Checking for an event to occur
 
			switch (event.type) {
				case SDL_MOUSEBUTTONDOWN: // Checking for mouse click event
					if(event.button.x <= 50 && event.button.y <= 50){	//Exiting program if the upper left hand corner of the screen is clicked
						exit(0);
					}
					else {								//Displaying a square where the user clicked 
						ssrc.x = 0; ssrc.y = 0; ssrc.w = 50; ssrc.h = 50;
						sdest.x = ((int)event.button.x - 25); sdest.y = ((int)event.button.y - 25); sdest.w = 50; sdest.h =50;		//Clicked location is subtracted by 25 on both the x 
						texture = SDL_CreateTextureFromSurface(renderer, square);													//and y coords in order to center the square
						SDL_RenderCopy(renderer, texture, &ssrc, &sdest);							//Copying the renderer to include newly placed square 
						for(int i =0; i < 100; i++){												//Displaying the renderer
							sprintf(string, "I am Twig.");
							c.r = 0; c.g = 255; c.b = 0;
							FixedPrint(renderer, 340, 150+i, string, &c, 2);
							SDL_RenderPresent(renderer);
						}
						break;
					}
				case SDL_QUIT:
					exit(0);																		//Exiting program if application is closed
					break;
			}
		}
		
		SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
        SDL_RenderPresent(renderer);
    }
 
    SDL_DestroyTexture(texture);					//Cleaning up SDL when we are finished 
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
 
    SDL_Quit();										//Ensuring we exit cleanly
 
    return 0;
}