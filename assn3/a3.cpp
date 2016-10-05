#include <SDL.h>
#include "SDL_image.h""

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

void drawImg(SDL_Surface *image, SDL_Surface *screen, int x, int y) {
	SDL_Rect toLoad;
	toLoad.x = x;
	toLoad.y = y;

	SDL_BlitSurface(image, NULL, screen, &toLoad);
}

void makeMarks(int *place, SDL_Surface *imgX, SDL_Surface *imgO, SDL_Surface *screen) {
	if(place[0] == 1)
		drawImg(imgX, screen, 120, 43);
	else if(place[0] == 2)
		drawImg(imgO, screen, 120, 43);
	
	if(place[1] == 1)
		drawImg(imgX, screen, 273, 43);
	else if(place[1] == 2)
		drawImg(imgO, screen, 273, 43);
	
	if(place[2] == 1)
		drawImg(imgX, screen, 423, 43);
	else if(place[2] == 2)
		drawImg(imgO, screen, 423, 43);
	
	if(place[3] == 1)
		drawImg(imgX, screen, 120, 188);
	else if(place[3] == 2)
		drawImg(imgO, screen, 120, 188);
	
	if(place[4] == 1)
		drawImg(imgX, screen, 273, 188);
	else if(place[4] == 2)
		drawImg(imgO, screen, 273, 188);
	
	if(place[5] == 1)
		drawImg(imgX, screen, 423, 188);
	else if(place[5] == 2)
		drawImg(imgO, screen, 423, 188);
	
	if(place[6] == 1)
		drawImg(imgX, screen, 120, 338);
	else if(place[6] == 2)
		drawImg(imgO, screen, 120, 338);
	
	if(place[7] == 1)
		drawImg(imgX, screen, 273, 338);
	else if(place[7] == 2)
		drawImg(imgO, screen, 273, 338);
	
	if(place[0] == 1)
		drawImg(imgX, screen, 423, 338);
	else if(place[0] == 2)
		drawImg(imgO, screen, 423, 338);
}

int main(int argc, char **argv[]){
	SDL_Init(SDL_INIT_VIDEO);
	
	//SDL_WM_SetCaption("Assignment 3 - Tic Tac Toe", NULL);
	
	SDL_Surface *screen = NULL;
	SDL_Surface *board = NULL;
	SDL_Surface *imgX = NULL;
	SDL_Surface *imgO = NULL;
	SDL_Surface *winX = NULL;
	SDL_Surface *winO = NULL;
	SDL_Surface *turnX = NULL;
	SDL_Surface *turnO = NULL;
	SDL_Surface *draw = NULL;
	
	SDL_Window *screen = SDL_CreateWindow("Assignment 3 - Tic Tac Toe", 
										SDL_WINDOWPOS_UNDEFINED,
										SDL_WINDOWPOS_UNDEFINED,
										640, 480, SDL_WINDOW_SHOWN);
	
	// screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF);
	
	board = IMG_Load("board.png"); 	
	imgX = IMG_Load("x.png"); 		
	imgO = IMG_Load("o.png");		
	winX = IMG_Load("winX.png"); 	
	winO = IMG_Load("winO.png");	
	turnX = IMG_Load("turnX.png");
	turnO = IMG_Load("turnO.png");
	draw = IMG_Load("draw.png");	
	
	start:
	
	bool EndGameLoop = false;
	bool EndGame = false;
	int winner = 0;
	int turn = 1;
	
	int place[9] = {NULL};
	
	SDL_Event event;
	
	while(EndGameLoop != true){
		drawImg(board, screen, 0, 0);
		
		if(!(turn % 2) == 1) {
			drawImg(turnX, screen, 15, 43);
		}
		else if(!(turn % 2) == 0) {
			drawImg(turnO, screen, 13, 43);
		}
		
		SDL_PollEvent(&event);
		if(event.type == SDL_QUIT){
			EndGameLoop = true;
			EndGame = true; 
			goto endgame;
		}
		
		if(event.type == SDL_KEYDOWN) {
			if(event.key.keysym.sym == SDLK_ESCAPE) {
				EndGameLoop = true;
				EndGame = true;
				goto endgame;
			}
			
			if(event.key.keysym.sym == SDLK_KP7) {
				if(!(turn % 2) == 1) {
					if(place[0] == 0) {
						place[0] = 1;
						turn ++;
					}
				}
				if(!(turn % 2) == 0) {
					if(place[0] == 0) {
						place[0] = 2;
						turn ++;
					}
				}
			}
			
			if(event.key.keysym.sym == SDLK_KP9) {
				if(!(turn % 2) == 1) {
					if(place[2] == 0) {
						place[2] = 1;
						turn ++;
					}
				}
				if(!(turn % 2) == 0) {
					if(place[2] == 0) {
						place[2] = 2;
						turn ++;
					}
				}
			}
			
			if(event.key.keysym.sym == SDLK_KP4) {
				if(!(turn % 2) == 1) {
					if(place[3] == 0) {
						place[3] = 1;
						turn ++;
					}
				}
				if(!(turn % 2) == 0) {
					if(place[3] == 0) {
						place[3] = 2;
						turn ++;
					}
				}
			}
			if(event.key.keysym.sym == SDLK_KP5) {
				if(!(turn % 2) == 1) {
					if(place[4] == 0) {
						place[4] = 1;
						turn ++;
					}
				}
				if(!(turn % 2) == 0) {
					if(place[4] == 0) {
						place[4] = 2;
						turn ++;
					}
				}
			}
			if(event.key.keysym.sym == SDLK_KP6) {
				if(!(turn % 2) == 1) {
					if(place[5] == 0) {
						place[5] = 1;
						turn ++;
					}
				}
				if(!(turn % 2) == 0) {
					if(place[5] == 0) {
						place[5] = 2;
						turn ++;
					}
				}
			}
			if(event.key.keysym.sym == SDLK_KP1) {
				if(!(turn % 2) == 1) {
					if(place[6] == 0) {
						place[6] = 1;
						turn ++;
					}
				}
				if(!(turn % 2) == 0) {
					if(place[6] == 0) {
						place[6] = 2;
						turn ++;
					}
				}
			}
			if(event.key.keysym.sym == SDLK_KP2) {
				if(!(turn % 2) == 1) {
					if(place[7] == 0) {
						place[7] = 1;
						turn ++;
					}
				}
				if(!(turn % 2) == 0) {
					if(place[7] == 0) {
						place[7] = 2;
						turn ++;
					}
				}
			}
			if(event.key.keysym.sym == SDLK_KP3) {
				if(!(turn % 2) == 1) {
					if(place[8] == 0) {
						place[8] = 1;
						turn ++;
					}
				}
				if(!(turn % 2) == 0) {
					if(place[8] == 0) {
						place[8] = 2;
						turn ++;
					}
				}
			}
			
		}
		makeMarks(place, imgX, imgO, screen);
		
		if (place[0] == 1 && place[1] == 1 && place[2] == 1) {
			winner = 1;
			EndGameLoop = true;
		}
		else if (place[0] == 2 && place[1] == 2 && place[2] == 2) {
			winner = 2;
			EndGameLoop = true;
		}
		else if (place[3] == 1 && place[4] == 1 && place[5] == 1) {
			winner = 1;
			EndGameLoop = true;
		}
		else if (place[3] == 2 && place[4] == 2 && place[5] == 2) {
			winner = 2;
			EndGameLoop = true;
		}
		else if (place[6] == 1 && place[7] == 1 && place[8] == 1) {
			winner = 1;
			EndGameLoop = true;
		}
		else if (place[6] == 2 && place[7] == 2 && place[8] == 2) {
			winner = 2;
			EndGameLoop = true;
		}
		else if (place[0] == 1 && place[3] == 1 && place[6] == 1) {
			winner = 1;
			EndGameLoop = true;
		}
		else if (place[0] == 2 && place[3] == 2 && place[6] == 2) {
			winner = 2;
			EndGameLoop = true;
		}
		else if (place[1] == 1 && place[4] == 1 && place[7] == 1) {
			winner = 1;
			EndGameLoop = true;
		}
		else if (place[1] == 2 && place[4] == 2 && place[7] == 2) {
			winner = 2;
			EndGameLoop = true;
		}
		else if (place[2] == 1 && place[5] == 1 && place[8] == 1) {
			winner = 1;
			EndGameLoop = true;
		}
		else if (place[2] == 2 && place[5] == 2 && place[8] == 2) {
			winner = 2;
			EndGameLoop = true;
		}
		else if (place[0] == 1 && place[4] == 1 && place[8] == 1) {
			winner = 1;
			EndGameLoop = true;
		}
		else if (place[0] == 2 && place[4] == 2 && place[8] == 2) {
			winner = 2;
			EndGameLoop = true;
		}
		else if (place[2] == 1 && place[4] == 1 && place[6] == 1) {
			winner = 1;
			EndGameLoop = true;
		}
		else if (place[2] == 2 && place[4] == 2 && place[6] == 2) {
			winner = 2;
			EndGameLoop = true;
		}
		
		SDL_Flip(screen);
		
		if (turn == 10) {
			EndGameLoop = true;
		}
		
	}
	
	while (EndGame != true) {
		if (winner == 1) {
			drawImg(winX, screen, 0, 0);
			SDL_Flip(screen);
			SDL_Delay(2000);
			EndGame = true;
		}
		else if (winner == 2) {
			drawImg(winO, screen, 0, 0);
			SDL_Flip(screen);
			SDL_Delay(2000);
			EndGame = true;
		}
		else {
			drawImg(draw, screen, 0, 0);
			SDL_Flip(screen);
			SDL_Delay(2000);
			EndGame = true;
		}
	}
	
	goto start;
	
	endgame:
	
	SDL_FreeSurface(screen);
	SDL_FreeSurface(imgX);
	SDL_FreeSurface(imgO);
	SDL_FreeSurface(board);
	SDL_FreeSurface(winX);
	SDL_FreeSurface(winO);
	SDL_FreeSurface(turnX);
	SDL_FreeSurface(turnO);
	SDL_FreeSurface(draw);
	
	SDL_Quit();
	
	return 0;
}