#include <iostream>
#include <SDL.h>    
#include "SDL_image.h"
#include "Fixed_print.h"
 
 SDL_Texture * texture;
 SDL_Texture * tTexture;
 SDL_Renderer * renderer;
 
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
	
 
    SDL_Window * window;
	window = SDL_CreateWindow("CS321 Assignment 1", 	//Creating the window for the application
			    SDL_WINDOWPOS_UNDEFINED, 
			    SDL_WINDOWPOS_UNDEFINED, 
			    707, 480, SDL_WINDOW_SHOWN);
 
    SDL_Renderer * renderer;							//Initializing the renderer
	renderer = SDL_CreateRenderer(window, -1, 
				SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
				
	FixedPrint_Setup();
	SDL_Surface * square;								//Creating the surface for the image to be placed on
    SDL_Surface * image;
	SDL_Surface * imgX;
	SDL_Surface * board;
	SDL_Surface * imgO;
	SDL_Surface * drawImg;
	SDL_Surface * winX;
	SDL_Surface * winO;
	SDL_Surface * turnX;
	SDL_Surface * turnO;
	SDL_Surface * numO;
	SDL_Surface * numX;
	SDL_Surface * numWin;
	SDL_Surface * zero;
	SDL_Surface * one;
	SDL_Surface * two;
	SDL_Surface * three;
	SDL_Surface * four;
	SDL_Surface * five;
	SDL_Surface * six;
	SDL_Surface * seven;
	SDL_Surface * eight;
	SDL_Surface * nine;
	SDL_Surface * ten;
	SDL_Surface * eleven;
	SDL_Surface * twelve;
	SDL_Surface * thirteen;
	SDL_Surface * fourteen;
	SDL_Surface * fifteen;
	SDL_Surface * sixteen;
	SDL_Surface * seventeen;
	SDL_Surface * eightteen;
	SDL_Surface * nineteen;
	SDL_Surface * twenty;
	
	zero = IMG_Load("zero.png");
	one = IMG_Load("one.png");
	two = IMG_Load("two.png");
	three = IMG_Load("three.png");
	four = IMG_Load("four.png");
	five = IMG_Load("five.png");
	six = IMG_Load("six.png");
	seven = IMG_Load("seven.png");
	eight = IMG_Load("eight.png");
	nine = IMG_Load("nine.png");
	ten = IMG_Load("ten.png");
	eleven = IMG_Load("eleven.png");
	twelve = IMG_Load("twelve.png");
	thirteen = IMG_Load("13.png");
	fourteen = IMG_Load("14.png");
	fifteen = IMG_Load("15.png");
	sixteen = IMG_Load("16.png");
	seventeen = IMG_Load("17.png");
	eightteen = IMG_Load("18.png");
	nineteen = IMG_Load("19.png");
	twenty = IMG_Load("20.png");
	numWin = IMG_Load("wins.png");
	numO = IMG_Load("oWins.png");
	numX = IMG_Load("xWins.png");
	turnX = IMG_Load("turnX.png");
	turnO = IMG_Load("turnO.png");
	winX = IMG_Load("winX.png");
	winO = IMG_Load("winO.png");
	drawImg = IMG_Load("draw.png");
	board = IMG_Load("board.png");
	square = IMG_Load("0.png");					//Loading in the image for the square that is to be used by the program
	imgX = IMG_Load("x.png");
	imgO = IMG_Load("o.png");
    int games = 0;
	int dTurn;
	int xWins = 0;
	int oWins = 0;
	int draws = 0;
	char string[100];
	SDL_Color c;
	SDL_Rect pdest;
	SDL_Rect psrc;
	SDL_Rect wdest;
	SDL_Rect wsrc;
	
	start:
	
	int turn = 1;
	int tTurn = 1;
	int place[9] = {0,0,0,0,0,0,0,0,0};
	bool EndGameLoop = false;
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
		sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 351;
		texture = SDL_CreateTextureFromSurface(renderer, turnO);
		SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
		SDL_RenderPresent(renderer);
	}
	else {
		turn = 0;
		dTurn = 9;
		ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;		//Else X moves first
		sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 351;
		texture = SDL_CreateTextureFromSurface(renderer, turnX);
		SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
		SDL_RenderPresent(renderer);
	}
		
	
	// sprintf(string, "X wins: %d \nO wins: %d \nDraws: %d", &xWins, &oWins, &draws);
    // c.r = 255; c.g = 255; c.b = 255;
    // FixedPrint(renderer, 340, 150, string, &c, 2);
	
    while (EndGameLoop != true) {											//Loop to keep game running
	

		
        if (SDL_PollEvent(&event) > 0){			//Checking for an event to occur
			// if(!(tTurn & 2) == 1) {
			// tsrc.x = 640; tsrc.y = 0; tsrc.w = 67; tsrc.h = 351;
			// tdest.x = 640; tdest.y = 0; tdest.w = 67; tdest.h = 351;
			// texture = SDL_CreateTextureFromSurface(renderer, turnO);
			// SDL_RenderCopy(renderer, texture, &tsrc, &tdest);
		// }
		// else {
			// tsrc.x = 640; tsrc.y = 0; tsrc.w = 67; tsrc.h = 351;
			// tdest.x = 640; tdest.y = 0; tdest.w = 67; tdest.h = 351;
			// texture = SDL_CreateTextureFromSurface(renderer, turnX);
			// SDL_RenderCopy(renderer, texture, &tsrc, &tdest);
		// }
			switch (event.type) {
				case SDL_MOUSEBUTTONDOWN: // Checking for mouse click event
					if(event.button.x <= 213 && event.button.y <= 160){								//First space
						// float x = 160 / 2;
						// float y = 113 / 2;
						
						if(!(turn % 2 == 1)) {
							// tsrc.x = 0; tsrc.y = 0; tsrc.w = 67; tsrc.h = 351;
							// tdest.x = 640; tdest.y = 0; tdest.w = 67; tdest.h = 351;
							// texture = SDL_CreateTextureFromSurface(renderer, turnO);
							// SDL_RenderCopy(renderer, texture, &tsrc, &tdest);
						
							
							if(place[0] == 0) {
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 81; ssrc.h = 91;
								sdest.x = (113 - 40); sdest.y = (56 / 2); sdest.w = 81; sdest.h = 91;
								texture = SDL_CreateTextureFromSurface(renderer, imgX);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 351;
								texture = SDL_CreateTextureFromSurface(renderer, turnO);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								turn++;
								tTurn++;
								place[0] = 1;
								break;
							}
							break;
						}
						else {
							
							if(place[0] == 0) {
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 81; ssrc.h = 91;
								sdest.x = (113 - 40); sdest.y = (56 / 2); sdest.w = 81; sdest.h = 91;
								texture = SDL_CreateTextureFromSurface(renderer, imgO);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 351;
								texture = SDL_CreateTextureFromSurface(renderer, turnX);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								turn++;
								tTurn++;
								place[0] = 2;
								break;
							}
							break;
						}
		
					}
					else if(event.button.x > 213 && event.button.x <= 426 && event.button.y <= 160) {	//Second space
						// float x = 160 / 2;
						// float y = 113 / 2;
						if(!(turn % 2 == 1)) {
							
							if(place[1] == 0) {
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 81; ssrc.h = 91;
								sdest.x = (280); sdest.y = (56 / 2); sdest.w = 81; sdest.h = 91;
								texture = SDL_CreateTextureFromSurface(renderer, imgX);
								SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
								
								ssrc.x = 0; ssrc.y = 0; ssrc.w = 67; ssrc.h = 351;
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 351;
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
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 351;
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
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 351;
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
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 351;
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
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 351;
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
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 351;
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
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 351;
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
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 351;
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
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 351;
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
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 351;
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
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 351;
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
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 351;
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
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 351;
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
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 351;
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
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 351;
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
								sdest.x = 640; sdest.y = 0; sdest.w = 67; sdest.h = 351;
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
		// if(!(turn % 2 == 1)) {
			// tsrc.x = 640; tsrc.y = 0; tsrc.w = 67; tsrc.h = 351;
			// tdest.x = 640; tdest.y = 0; tdest.w = 67; tdest.h = 351;
			// tTexture = SDL_CreateTextureFromSurface(renderer, turnO);
			// SDL_RenderCopy(renderer, tTexture, &tsrc, &tdest);
			// SDL_RenderPresent(renderer);
		// }
		// else {
			// tsrc.x = 0; tsrc.y = 0; tsrc.w = 67; tsrc.h = 351;
			// tdest.x = 640; tdest.y = 0; tdest.w = 67; tdest.h = 351;
			// tTexture = SDL_CreateTextureFromSurface(renderer, turnX);
			// SDL_RenderCopy(renderer, tTexture, &tsrc, &tdest);
			// SDL_RenderPresent(renderer);
		// }
		
		
		// SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, &ssrc, &sdest);
        SDL_RenderPresent(renderer);
		if (place[0] == 1 && place[1] == 1 && place[2] == 1) {		//Win conditions
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
		
		else if(turn == dTurn) {
				winner = 3;
				EndGameLoop = true;
			}
    }
	while(EndGame != true) {												//Displaying winner of game
				
			if(winner == 1){
				texture = SDL_CreateTextureFromSurface(renderer, winX);
				for(int i  = 0; i < 200; i++){
					// texture = SDL_CreateTextureFromSurface(renderer, winX);		//X wins if winner equals 1
					// SDL_RenderCopy(renderer, texture, &dest, &dest);
					// SDL_RenderPresent(renderer);
					//SDL_Delay(2000);
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					// SDL_RenderClear(renderer);
					
					SDL_RenderCopy(renderer, texture, &dest, &dest);
					sprintf(string, "Number of wins: %d", xWins);
					c.r = 0; c.g = 255; c.b = 0;
					FixedPrint(renderer, 215, 300, string, &c, 2);
					SDL_RenderPresent(renderer);
				}
				games++;
				xWins ++;
				EndGame = true;
				// SDL_RenderClear(renderer);
			}
			if(winner == 2){
				texture = SDL_CreateTextureFromSurface(renderer, winO);		//O wins if winner equals 2
				SDL_RenderCopy(renderer, texture, &dest, &dest);
				SDL_RenderPresent(renderer);
				SDL_Delay(2000);
				oWins ++;
				games++;
				EndGame = true;
				// SDL_RenderClear(renderer);
			}
			if(winner == 3){
				texture = SDL_CreateTextureFromSurface(renderer, drawImg);	//Game ends in a draw if winner equals 3
				SDL_RenderCopy(renderer, texture, &dest, &dest);
				SDL_RenderPresent(renderer);
				SDL_Delay(2000);
				draws ++;
				games++;
				EndGame = true;
				// SDL_RenderClear(renderer);
			}
		}
		goto start;
 
    SDL_DestroyTexture(texture);					//Cleaning up SDL when we are finished 
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
 
    SDL_Quit();										//Ensuring we exit cleanly
 
    return 0;
}

// tsrc.x = 640; tsrc.y = 0; tsrc.w = 67; tsrc.h = 351;
							// tdest.x = 640; tdest.y = 0; tdest.w = 67; tdest.h = 351;
							// tTexture = SDL_CreateTextureFromSurface(renderer, turnO);
							// SDL_RenderCopy(renderer, tTexture, &tsrc, &tdest);
							// SDL_RenderPresent(renderer);