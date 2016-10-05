#include <iostream>
#include <SDL.h>    
#include "SDL_image.h"
#include "Fixed_print.h"

 
 SDL_Texture * texture;
 SDL_Texture * tTexture;
 SDL_Renderer * renderer;
 SDL_Window * window;
 
int main(int argc, char ** argv) {
    SDL_Event event;
	SDL_MouseButtonEvent eventM;
	SDL_Rect dest;
	SDL_Rect src;
	SDL_Rect ssrc;
	SDL_Rect sdest;
	SDL_Rect tsrc;
	SDL_Rect tdest;
    SDL_Init(SDL_INIT_TIMER|SDL_INIT_AUDIO|SDL_INIT_VIDEO);
	int clickX, clickY;
	clickX = 0; clickY = 0;
	
	window = SDL_CreateWindow("CS321 Assignment 1", 	//Creating the window for the application
			    SDL_WINDOWPOS_UNDEFINED, 
			    SDL_WINDOWPOS_UNDEFINED, 
			    707, 480, SDL_WINDOW_SHOWN);
 
    SDL_Renderer * renderer;							//Initializing the renderer
	renderer = SDL_CreateRenderer(window, -1, 
				SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
				
	
	SDL_Surface * square;								//Creating the surfaces and textures for the images to be placed on
    SDL_Surface * image;
	SDL_Surface * imgX;
	SDL_Surface * board;
	SDL_Surface * imgO;
	SDL_Texture * drawImg;
	SDL_Texture * winX;
	SDL_Texture * winO;
	SDL_Surface * turnX;
	SDL_Surface * turnO;
	SDL_Surface * numO;
	SDL_Surface * numX;
	SDL_Surface * numWin;
	
	numWin = IMG_Load("wins.png");				//Loading in the images that will be used within the game
	numO = IMG_Load("oWins.png");
	numX = IMG_Load("xWins.png");
	turnX = IMG_Load("turnX.png");
	turnO = IMG_Load("turnO.png");
	winX = IMG_LoadTexture(renderer, "winX.png");
	winO = IMG_LoadTexture(renderer, "winO.png");
	drawImg = IMG_LoadTexture(renderer, "draw.png");
	board = IMG_Load("board.png");
	// square = IMG_Load("0.png");					
	imgX = IMG_Load("x.png");
	imgO = IMG_Load("o.png");
    int games = 0;								//Tracking number of games played, used to calculate who goes first
	int dTurn;									//dTurn is used to check to see if a draw has occured
	int xWins = 0;								//Number of wins by each player
	int oWins = 0;
	int draws = 0;
	char string[100];
	SDL_Color c;
	SDL_Rect pdest;
	SDL_Rect psrc;
	SDL_Rect wdest; 
	SDL_Rect wsrc;
	FixedPrint_Setup();
	sprintf(string, "X wins: %d || O wins: %d || Draws: %d", xWins, oWins, draws);	//Cheating to display number of wins by each player
	SDL_SetWindowTitle(window, string);											//by using window title as the counter
	start:										//Start of game
	
	int turn = 1;
	int tTurn = 1;
	int place[9] = {0,0,0,0,0,0,0,0,0};			//Array for marking which player has placed something in that spot
	bool EndGameLoop = false;					//Checking to see if game is over.
	bool EndGame = false;
	int winner = 0;
	
    dest.x = 0; dest.y = 0; dest.w = 640; dest.h = 480;	//Default source and destination for the SDL_Rects that are used
	src.x = 240; src.y = 320; src.w = 640; src.h = 480;
	SDL_RenderClear(renderer);
	texture = SDL_CreateTextureFromSurface(renderer, board);	//Creating the texture 
	SDL_RenderCopy(renderer, texture, &dest, &dest);
	
	pdest.x = 0; pdest.y = 0; pdest.w = 33; pdest.h = 129;	//Default source and destination for the SDL_Rects that are used
	psrc.x = 640; psrc.y = 351; psrc.w = 33; psrc.h = 129;
	texture = SDL_CreateTextureFromSurface(renderer, numWin);
	SDL_RenderCopy(renderer, texture, &pdest, &psrc);
	
	if(!(games % 2 == 1)) {										//Displaying the first person to move 
		turn = 1;
		dTurn = 10;
		ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;		//If check is true, O moves first
		sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 480;
		texture = SDL_CreateTextureFromSurface(renderer, turnO);
		SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
		SDL_RenderPresent(renderer);
	}
	else {
		turn = 0;
		dTurn = 9;
		ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;		//Else X moves first
		sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 480;
		texture = SDL_CreateTextureFromSurface(renderer, turnX);
		SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
		SDL_RenderPresent(renderer);
	}
	
    while (EndGameLoop != true) {											//Loop to keep game running
	

		
        if (SDL_PollEvent(&event) > 0){			//Checking for an event to occur
			switch (event.type) {
				case SDL_MOUSEBUTTONDOWN: // Checking for mouse click event
					if(event.button.x <= 213 && event.button.y <= 160){								//First space
						// float x = 160 / 2;
						// float y = 113 / 2;
						
						if(!(turn % 2 == 1)) {
							if(place[0] == 0) {									//Allows an X to be placed as long as no one else has played in that spot already
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 81; ssrc.h = 91;
								sdest.x = (113 - 40); sdest.y = (56 / 2); sdest.w = 81; sdest.h = 91;
								texture = SDL_CreateTextureFromSurface(renderer, imgX);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;			//Updating whos turn is being displayed
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 480;
								texture = SDL_CreateTextureFromSurface(renderer, turnO);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								turn++;											//Updating number of turns
								tTurn++;										
								place[0] = 1;									//Marking the move in the array
								break;
							}
							break;
						}
						else {
							
							if(place[0] == 0) {									//Allowing O to be placed as long as no one else has played in that spot already
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 81; ssrc.h = 91;
								sdest.x = (113 - 40); sdest.y = (56 / 2); sdest.w = 81; sdest.h = 91;
								texture = SDL_CreateTextureFromSurface(renderer, imgO);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;			//Updating whos turn is being displayed
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 480;
								texture = SDL_CreateTextureFromSurface(renderer, turnX);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								turn++;
								tTurn++;
								place[0] = 2;								//Marking move in the array
								break;
							}
							break;
						}
		
					}
					else if(event.button.x > 213 && event.button.x <= 426 && event.button.y <= 160) {	//Second space
						// float x = 160 / 2;															//Same proccess as above occurs for
						// float y = 113 / 2;															//the remaining places on the board
						if(!(turn % 2 == 1)) {															//most of this is just copy/pasted and only
																										//the array indexes and if statement conditionals
							if(place[1] == 0) {															//have been changed in order to bound check the proper
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 81; ssrc.h = 91;						//placement of them on the game board
								sdest.x = (280); sdest.y = (56 / 2); sdest.w = 81; sdest.h = 91;
								texture = SDL_CreateTextureFromSurface(renderer, imgX);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 480;
								texture = SDL_CreateTextureFromSurface(renderer, turnO);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								turn++;
								tTurn++;
								place[1] = 1;
								//SDL_RenderClear(renderer);
								break;
							}
							break;
						}
						else {

							if(place[1] == 0) {
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 81; ssrc.h = 91;
								sdest.x = (280); sdest.y = (56 / 2); sdest.w = 81; sdest.h = 91;
								texture = SDL_CreateTextureFromSurface(renderer, imgO);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 480;
								texture = SDL_CreateTextureFromSurface(renderer, turnX);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								turn++;
								tTurn++;
								place[1] = 2;
								//SDL_RenderClear(renderer);
								break;
							}
							break;
						}
					}
					else if(event.button.x > 426 && event.button.y <= 160){							//Third space
						
						if(!(turn % 2 == 1)) {
							
							if(place[2] == 0) {
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 81; ssrc.h = 91;
								sdest.x = (500); sdest.y = (56 / 2); sdest.w = 81; sdest.h = 91;
								texture = SDL_CreateTextureFromSurface(renderer, imgX);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 480;
								texture = SDL_CreateTextureFromSurface(renderer, turnO);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								turn++;
								tTurn++;
								place[2] = 1;
								//SDL_RenderClear(renderer);
								break;
							}
							break;
						}
						else {

							if(place[2] == 0) {
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 81; ssrc.h = 91;
								sdest.x = (500); sdest.y = (56 / 2); sdest.w = 81; sdest.h = 91;
								texture = SDL_CreateTextureFromSurface(renderer, imgO);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 480;
								texture = SDL_CreateTextureFromSurface(renderer, turnX);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								turn++;
								tTurn++;
								place[2] = 2;
								//SDL_RenderClear(renderer);
								break;
							}
							break;
						}
					}
					else if(event.button.x <= 213 && event.button.y <= 320 && event.button.y > 160){	//Fourth space
					
						if(!(turn % 2 == 1)) {

							if(place[3] != 1 && place[3] != 2) {
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 81; ssrc.h = 91;
								sdest.x = (113 - 40); sdest.y = ((56 / 2) + 160); sdest.w = 81; sdest.h = 91;
								texture = SDL_CreateTextureFromSurface(renderer, imgX);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 480;
								texture = SDL_CreateTextureFromSurface(renderer, turnO);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								turn++;
								tTurn++;
								place[3] = 1;
								//SDL_RenderClear(renderer);
								break;
							}
							break;
						}
						else {

							if(place[3] != 1 && place[3] != 2) {
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 81; ssrc.h = 91;
								sdest.x = (113 - 40); sdest.y = ((56 / 2) + 160); sdest.w = 81; sdest.h = 91;
								texture = SDL_CreateTextureFromSurface(renderer, imgO);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 480;
								texture = SDL_CreateTextureFromSurface(renderer, turnX);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								turn++;
								tTurn++;
								place[3] = 2;
								//SDL_RenderClear(renderer);
								break;
							}
							break;
						}
					}
					else if(event.button.x > 213 && event.button.x <= 426 && event.button.y <= 320 && event.button.y > 160){	//Fifth space
						
						if(!(turn % 2 == 1)) {

							if(place[4] == 0) {
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 81; ssrc.h = 91;
								sdest.x = (280); sdest.y = ((56 / 2) + 160); sdest.w = 81; sdest.h = 91;
								texture = SDL_CreateTextureFromSurface(renderer, imgX);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 480;
								texture = SDL_CreateTextureFromSurface(renderer, turnO);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								turn++;
								tTurn++;
								place[4] = 1;
								//SDL_RenderClear(renderer);
								break;
							}
							break;
						}
						else {

							if(place[4] == 0) {
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 81; ssrc.h = 91;
								sdest.x = (280); sdest.y = ((56 / 2) + 160); sdest.w = 81; sdest.h = 91;
								texture = SDL_CreateTextureFromSurface(renderer, imgO);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 480;
								texture = SDL_CreateTextureFromSurface(renderer, turnX);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								turn++;
								tTurn++;
								place[4] = 2;
								//SDL_RenderClear(renderer);
								break;
							}
							break;
						}
					}
					else if(event.button.x > 426 && event.button.y <= 320 && event.button.y > 160) {							//Sixth space
						
						if(!(turn % 2 == 1)) {

							if(place[5] == 0) {
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 81; ssrc.h = 91;
								sdest.x = (500); sdest.y = ((56 / 2) + 160); sdest.w = 81; sdest.h = 91;
								texture = SDL_CreateTextureFromSurface(renderer, imgX);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 480;
								texture = SDL_CreateTextureFromSurface(renderer, turnO);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								turn++;
								tTurn++;
								place[5] = 1;
								//SDL_RenderClear(renderer);
								break;
							}
							break;
						}
						else {
							tsrc.x = 0; tsrc.y = 0; tsrc.w = 67; tsrc.h = 351;

							if(place[5] == 0) {
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 81; ssrc.h = 91;
								sdest.x = (500); sdest.y = ((56 / 2) + 160); sdest.w = 81; sdest.h = 91;
								texture = SDL_CreateTextureFromSurface(renderer, imgO);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 480;
								texture = SDL_CreateTextureFromSurface(renderer, turnX);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								turn++;
								tTurn++;
								place[5] = 2;
								//SDL_RenderClear(renderer);
								break;
							}
							break;
						}
					}
					else if(event.button.x <= 213 && event.button.y > 320) {													//Seventh space
						
						if(!(turn % 2 == 1)) {

							if(place[6] == 0) {
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 81; ssrc.h = 91;
								sdest.x = (113 - 40); sdest.y = ((56 / 2) + 320); sdest.w = 81; sdest.h = 91;
								texture = SDL_CreateTextureFromSurface(renderer, imgX);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 480;
								texture = SDL_CreateTextureFromSurface(renderer, turnO);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								turn++;
								tTurn++;
								place[6] = 1;
								//SDL_RenderClear(renderer);
								break;
							}
							break;
						}
						else {

							if(place[6] == 0) {
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 81; ssrc.h = 91;
								sdest.x = (113 - 40); sdest.y = ((56 / 2) + 320); sdest.w = 81; sdest.h = 91;
								texture = SDL_CreateTextureFromSurface(renderer, imgO);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 480;
								texture = SDL_CreateTextureFromSurface(renderer, turnX);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								turn++;
								tTurn++;
								place[6] = 2;
								//SDL_RenderClear(renderer);
								break;
							}
							break;
						}
					}
					else if(event.button.x > 213 && event.button.x <= 426 && event.button.y > 320) {							//Eighth space
						
						if(!(turn % 2 == 1)) {

							if(place[7] == 0) {
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 81; ssrc.h = 91;
								sdest.x = (280); sdest.y = ((56 / 2) + 320); sdest.w = 81; sdest.h = 91;
								texture = SDL_CreateTextureFromSurface(renderer, imgX);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 480;
								texture = SDL_CreateTextureFromSurface(renderer, turnO);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								turn++;
								tTurn++;
								place[7] = 1;
								//SDL_RenderClear(renderer);
								break;
							}
							break;
						}
						else {

							if(place[7] == 0) {
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 81; ssrc.h = 91;
								sdest.x = (280); sdest.y = ((56 / 2) + 320); sdest.w = 81; sdest.h = 91;
								texture = SDL_CreateTextureFromSurface(renderer, imgO);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 480;
								texture = SDL_CreateTextureFromSurface(renderer, turnX);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								turn++;
								tTurn++;
								place[7] = 2;
								//SDL_RenderClear(renderer);
								break;
							}
							break;
						}
					}
					else if(event.button.x > 426 && event.button.y > 320) {													//Ninth space
						
						if(!(turn % 2 == 1)) {

							if(place[8] == 0) {
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 81; ssrc.h = 91;
								sdest.x = (500); sdest.y = ((56 / 2) + 320); sdest.w = 81; sdest.h = 91;
								texture = SDL_CreateTextureFromSurface(renderer, imgX);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 480;
								texture = SDL_CreateTextureFromSurface(renderer, turnO);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								turn++;
								tTurn++;
								place[8] = 1;
								//SDL_RenderClear(renderer);
								break;
							}
							break;
						}
						else {

							if(place[8] == 0) {
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 81; ssrc.h = 91;
								sdest.x = (500); sdest.y = ((56 / 2) + 320); sdest.w = 81; sdest.h = 91;
								texture = SDL_CreateTextureFromSurface(renderer, imgO);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 480;
								texture = SDL_CreateTextureFromSurface(renderer, turnX);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								turn++;
								tTurn++;
								place[8] = 2;
								break;
								//SDL_RenderClear(renderer);
							}
							break;
						}
					}
					else {
						// goto start;
					}
					
				case SDL_QUIT:
					exit(0);																		//Exiting program if application is closed
					break;
			}
		
			
		}
	
		SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
        SDL_RenderPresent(renderer);
		if (place[0] == 1 && place[1] == 1 && place[2] == 1) {		//Win conditions
			winner = 1;												//This long list of if else statements goes through to see if a win condition has
			EndGameLoop = true;										//been met by either player. This is done by checking the indexes of the array 
		}															//to see if any player has three of their team in a row on the board
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
		else if(turn == dTurn) {					//Base case to check to see if there was a draw.
			winner = 3;
			EndGameLoop = true;
		}
    }
	while(EndGame != true) {												//Displaying winner of game
				
			if(winner == 1){											//If winner is equal to 1, x was the winner
				for(int i  = 0; i < 200; i++){
					SDL_RenderCopy(renderer, winX, &dest, &dest);		//Displays image for x winning
					SDL_RenderPresent(renderer);
				}
				
				games++;												//Increments number of games played and how many wins x has
				xWins ++;
				sprintf(string, "X wins: %d || O wins: %d || Draws: %d", xWins, oWins, draws);
				SDL_SetWindowTitle(window, string);
				EndGame = true;
			}
			if(winner == 2){											//If winner is equal to 2, o was the winner
				for(int i = 0; i < 200; i++){
					SDL_RenderCopy(renderer, winO, &dest, &dest);		//Displaying image for o winning
					SDL_RenderPresent(renderer);
				}
				oWins ++;												//Increments the number of games played and how many wins o has
				games++;
				sprintf(string, "X wins: %d || O wins: %d || Draws: %d", xWins, oWins, draws);	//Cheating to display how many wins each player has
				SDL_SetWindowTitle(window, string);											//By using window title as counter
				EndGame = true;
				// SDL_RenderClear(renderer);
			}
			if(winner == 3){											//A draw occured if winner is euqal to 3
				for(int i = 0; i < 200; i++){
					SDL_RenderCopy(renderer, drawImg, &dest, &dest);	//Displays image for draw occurring
					SDL_RenderPresent(renderer);
				}
				draws ++;												//Increments number of games played and how many draws have occured
				games++;
				sprintf(string, "X wins: %d || O wins: %d || Draws: %d", xWins, oWins, draws);
				SDL_SetWindowTitle(window, string);
				EndGame = true;
				// SDL_RenderClear(renderer);
			}
		}
		goto start;														//Going back to the start of the game
 
    SDL_DestroyTexture(texture);					//Cleaning up SDL when we are finished 
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
 
    SDL_Quit();										//Ensuring we exit cleanly
 
    return 0;
}