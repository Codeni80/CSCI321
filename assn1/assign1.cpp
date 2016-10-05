#include <SDL.h>
#include "SDL_image.h"

#include "Fixed_print.h"

SDL_Window* window;
SDL_Renderer* renderer;

SDL_Texture* image;

void setupSDL() {
  if (SDL_Init(SDL_INIT_TIMER|SDL_INIT_AUDIO|SDL_INIT_VIDEO) != 0) {
    printf("SDL failed to init: %s\n", SDL_GetError());
    exit(1);
  }

  // Create window and renderer
  window = SDL_CreateWindow("Assignment #1", 
			    SDL_WINDOWPOS_UNDEFINED, 
			    SDL_WINDOWPOS_UNDEFINED, 
			    600, 400, SDL_WINDOW_SHOWN);
  
  renderer = SDL_CreateRenderer(window, -1, 
				SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

  if ((window == NULL) || (renderer == NULL)) {
    printf("SDL_CreateWindowAndRenderer Error: %s\n", SDL_GetError() );
    exit(1);
    
  }



  FixedPrint_Setup();
}


SDL_Texture* loadImage(const char* filename) {
  SDL_Texture *texture;

  texture = IMG_LoadTexture(renderer, filename);
  if (texture == NULL) {
    printf("IMG_LoadTexture Error: %s\n", IMG_GetError() );
    exit(1);
  }
                                                             
                                                             
  return texture;                                            
}         

void postSDLCleanup() {                                                        
    SDL_DestroyRenderer(renderer);                           
    SDL_DestroyWindow(window);                               
    SDL_Quit();                                              
} 

int main(int argc, char* argv[]) {
	image = loadImage("square.png");
	SDL_Rect squareOne;
	squareOne.x = 0; squareOne.y = 0; squareOne.w = 50; squareOne.h = 50;
	
	//some sort of loop
	while(1){
		
	}