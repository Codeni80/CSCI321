#include <SDL.h>
#include "SDL_image.h"

#include "Fixed_print.h"

SDL_Window* window;
SDL_Renderer* renderer;

SDL_Texture* twigman;
SDL_Texture* kalata;
SDL_Texture* schemm;
SDL_Texture* boger;
SDL_Texture* help;
SDL_Texture* eraser;
SDL_Texture* logo;
SDL_Texture* sun;

void setupSDL()
  {
  if (SDL_Init(SDL_INIT_TIMER|SDL_INIT_AUDIO|SDL_INIT_VIDEO) != 0)
    {
    printf("SDL failed to init: %s\n", SDL_GetError());
    exit(1);
    }

  // Create window and renderer
  window = SDL_CreateWindow("Twig's Revenge", 
			    SDL_WINDOWPOS_UNDEFINED, 
			    SDL_WINDOWPOS_UNDEFINED, 
			    600, 400, SDL_WINDOW_SHOWN);
  
  renderer = SDL_CreateRenderer(window, -1, 
				SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
  //SDL_CreateWindowAndRenderer(600,400, SDL_WINDOW_SHOWN,&window, &renderer);

  if ((window == NULL) || (renderer == NULL))
    {
    printf("SDL_CreateWindowAndRenderer Error: %s\n", SDL_GetError() );
    exit(1);
    
    }



  FixedPrint_Setup();

  }

SDL_Texture* loadImage(const char* filename)
  {
  SDL_Texture *texture;

  texture = IMG_LoadTexture(renderer, filename);
  if (texture == NULL)
    {
    printf("IMG_LoadTexture Error: %s\n", IMG_GetError() );
    exit(1);
    }
                                                             
                                                             
  return texture;                                            
  }                


SDL_Texture* loadKeyedImage(const char* filename)
	{
	SDL_Surface* surface;
	SDL_Texture* texture;

	surface = IMG_Load(filename);
	SDL_SetColorKey(surface, SDL_TRUE, 0xff00ff);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	return texture;
	}


void postSDLCleanup()                                        
    {                                                        
    SDL_DestroyRenderer(renderer);                           
    SDL_DestroyWindow(window);                               
    SDL_Quit();                                              
    }                                                        
                                                             
       





void finally()
  {
  int y[701] = {125, 124, 124, 123, 123, 122, 122, 121, 121, 120, 120, 119, 		119, 118, 118, 117, 117, 116, 116, 115, 115, 114, 114, 113, 113, 112, 112, 111, 110, 110, 109, 109, 108, 108, 107, 107, 106, 106, 105, 105, 104, 104, 103, 103, 102, 102, 101, 101, 100, 100, 100, 99, 99, 98, 98, 97, 97, 96, 96, 95, 95, 94, 94, 93, 93, 92, 92, 91, 91, 90, 90, 89, 89, 88, 87, 87, 86, 86, 85, 85, 84, 84, 83, 83, 82, 82, 81, 81, 80, 80, 79, 79, 78, 78, 77, 77, 76, 76, 75, 75, 74, 74, 73, 73, 72, 72, 71, 71, 70, 70, 69, 69, 68, 68, 67, 67, 66, 66, 65, 65, 64, 64, 63, 63, 62, 62, 61, 61, 60, 60, 59, 59, 58, 58, 57, 57, 56, 56, 56, 55, 55, 54, 54, 53, 53, 52, 52, 51, 51, 50, 50, 50, 49, 49, 48, 48, 47, 47, 46, 46, 46, 45, 45, 44, 44, 43, 43, 42, 42, 42, 41, 41, 40, 40, 40, 39, 39, 38, 38, 37, 37, 37, 36, 36, 35, 35, 35, 34, 34, 33, 33, 33, 32, 32, 32, 31, 31, 30, 30, 30, 29, 29, 29, 28, 28, 27, 27, 27, 26, 26, 26, 25, 25, 25, 24, 24, 24, 23, 23, 23, 22, 22, 22, 21, 21, 21, 20, 20, 20, 19, 19, 19, 18, 18, 18, 18, 17, 17, 17, 16, 16, 16, 16, 15, 15, 15, 14, 14, 14, 14, 13, 13, 13, 13, 12, 12, 12, 12, 11, 11, 11, 11, 10, 10, 10, 10, 10, 9, 9, 9, 9, 8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 14, 15, 15, 15, 16, 16, 16, 16, 17, 17, 17, 18, 18, 18, 18, 19, 19, 19, 20, 20, 20, 21, 21, 21, 22, 22, 22, 23, 23, 23, 24, 24, 24, 25, 25, 25, 26, 26, 26, 27, 27, 27, 28, 28, 29, 29, 29, 30, 30, 30, 31, 31, 32, 32, 32, 33, 33, 33, 34, 34, 35, 35, 35, 36, 36, 37, 37, 37, 38, 38, 39, 39, 40, 40, 40, 41, 41, 42, 42, 42, 43, 43, 44, 44, 45, 45, 46, 46, 46, 47, 47, 48, 48, 49, 49, 50, 50, 50, 51, 51, 52, 52, 53, 53, 54, 54, 55, 55, 56, 56, 56, 57, 57, 58, 58, 59, 59, 60, 60, 61, 61, 62, 62, 63, 63, 64, 64, 65, 65, 66, 66, 67, 67, 68, 68, 69, 69, 70, 70, 71, 71, 72, 72, 73, 73, 74, 74, 75, 75, 76, 76, 77, 77, 78, 78, 79, 79, 80, 80, 81, 81, 82, 82, 83, 83, 84, 84, 85, 85, 86, 86, 87, 87, 88, 89, 89, 90, 90, 91, 91, 92, 92, 93, 93, 94, 94, 95, 95, 96, 96, 97, 97, 98, 98, 99, 99, 100, 100, 100, 101, 101, 102, 102, 103, 103, 104, 104, 105, 105, 106, 106, 107, 107, 108, 108, 109, 109, 110, 110, 111, 112, 112, 113, 113, 114, 114, 115, 115, 116, 116, 117, 117, 118, 118, 119, 119, 120, 120, 121, 121, 122, 122, 123, 123, 124, 124, 125, };

  
  SDL_Rect ksrc;
  SDL_Rect kdest;
  SDL_Rect tsrc;
  SDL_Rect tdest;
  SDL_Rect bsrc;
  SDL_Rect bdest;
  SDL_Rect hsrc;
  SDL_Rect hdest;
 SDL_Rect ssrc;
  SDL_Rect sdest;  


  SDL_Event event;
  
  int kalata_x;
  int kalata_y;
  int kalata_pose;
  int pose_timer;
  int hcount;
  SDL_Color c;
  char string[100];
  int loop;
  
  kdest.x = 200; kdest.y  = 100;  kdest.w = 49; kdest.h = 49;
  ksrc.x = 0; ksrc.y = 0; ksrc.w = 49; ksrc.h = 49;
  kalata_x = 5; kalata_y = 0; kalata_pose = 0;
  
  bdest.x = -50; bdest.y = 475; bdest.w = 49; bdest.h = 49;
	bsrc.x = 0; bsrc.y = 0; bsrc.w = 49; bsrc.h = 49;

  
  sdest.x = -53; sdest.y = 472; sdest.w = 64; sdest.h = 64;
	ssrc.x = 0; ssrc.y = 0; ssrc.w = 64; ssrc.h = 64;


	tdest.x = 275; tdest.y = 175; tdest.w = 49; tdest.h = 49;
	tsrc.x = 0; tsrc.y = 49; tsrc.w = 49; tsrc.h = 49;
	
	hdest.x = 325; hdest.y = 210; hdest.w = 38; hdest.h = 20;
	hsrc.x = 0; hsrc.y = 0; hsrc.w = 38; hsrc.h = 20;

	hcount = 0;
	pose_timer = 0;

	for (loop = -50; loop < 600; loop++)
		{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		bdest.x = loop; bdest.y = y[(loop)+50];
		sdest.x = loop-6;  sdest.y = bdest.y-6;
		kdest.x = kdest.x + kalata_x;
		kdest.y = kdest.y + kalata_y;

		hcount++;
		pose_timer++;
		if (pose_timer == 5)
		  {
		  kalata_pose++;	
		  pose_timer = 0;
		  }
		if (kalata_pose == 6) kalata_pose = 0;
		ksrc.x = kalata_pose * 49;
		tsrc.x = kalata_pose * 49;
		bsrc.x = kalata_pose * 49;

		SDL_RenderCopy(renderer, kalata, &ksrc, &kdest);
		SDL_RenderCopy(renderer, twigman, &tsrc, &tdest);
		SDL_RenderCopy(renderer, sun, &ssrc, &sdest);
		SDL_RenderCopy(renderer, boger, &bsrc, &bdest);
		if (hcount < 15)	
		  SDL_RenderCopy(renderer, help, &hsrc, &hdest);
		

		if ((loop >= 250)&& (loop <= 350))
		  {
		  sprintf(string, "Giggle.");
		  c.r = 255; c.g = 255; c.b = 0;
		  FixedPrint(renderer, 320+(loop-250), 3, 
			     string, &c, 2);
		  }

		SDL_RenderPresent(renderer);

	
		
		if ((kdest.x == 350) && (kdest.y == 100))
			{
			kalata_x  = 0; kalata_y = 5;
			hdest.x = 237; hdest.y = 210; hcount = 0;
			}
		
		if ((kdest.x == 350) && (kdest.y == 250))
			{
			kalata_x  = -5; kalata_y = 0;
			hdest.x = 237; hdest.y = 170; hcount = 0;
			}
		if ((kdest.x == 200) && (kdest.y == 250))
			{
			kalata_x  = 0; kalata_y = -5;
			hdest.x = 325; hdest.y = 170; hcount = 0;
			}
		if ((kdest.x == 200) && (kdest.y == 100))
			{
			kalata_x  = 5; kalata_y = 0;
			hdest.x = 325; hdest.y = 210; hcount = 0;
			}


        if (SDL_PollEvent(&event) > 0)
	  {
	  switch(event.type)
	    {
	    case SDL_KEYDOWN:
	      if (event.key.keysym.scancode ==
		  SDL_SCANCODE_ESCAPE)
		exit(0);
	    case SDL_QUIT: 
	      exit(0);
	    }
	  }
	
	SDL_Delay(50);
		}

	}



void intro()
  {
  int loop;
  int kalata_pose;
  int pose_timer;
  char string[100];
  
  SDL_Rect tsrc;
  SDL_Rect tdest;
  SDL_Color c;
   SDL_Event event;

   pose_timer = 0;
  
  tdest.x = 275; tdest.y = 175; tdest.w = 49; tdest.h = 49;
  tsrc.x = 0; tsrc.y = 0; tsrc.w = 49; tsrc.h = 49;
  
   
  for (loop = 0; loop < 650; loop++)
    {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    pose_timer++;
    if (pose_timer == 5)
      {
      kalata_pose++;	
      pose_timer = 0;
      }
    if (kalata_pose == 6) kalata_pose = 0;
    tsrc.x = kalata_pose * 49;

    SDL_RenderCopy(renderer, twigman, &tsrc, &tdest);



    if (loop < 100)
      {
      sprintf(string, "I am Twig.");
      c.r = 255; c.g = 255; c.b = 255;
      FixedPrint(renderer, 340, 150, string, &c, 2);

      sprintf(string, "I've been the star of");
      c.r = 255; c.g = 255; c.b = 255;
      FixedPrint(renderer, 340, 170, string, &c, 2);

      sprintf(string, "these games for a while");
      c.r = 255; c.g =255; c.b = 255;
      FixedPrint(renderer, 340, 190, string, &c, 2);

      sprintf(string, "now.");
      c.r = 255; c.g =255; c.b = 255;
      FixedPrint(renderer, 340, 210, string, &c, 2);
      }
    
    if ((loop >= 130)&& (loop < 230))
      {
      sprintf(string, "The time has come for");
      c.r = 255; c.g = 255; c.b = 255;
      FixedPrint(renderer, 340, 150, string, &c, 2);

      sprintf(string, "me to deal with this");
      c.r = 255; c.g = 255; c.b = 255;
      FixedPrint(renderer, 340, 170, string, &c, 2);

      sprintf(string, "indignity once and");
      c.r = 255; c.g =255; c.b = 255;
      FixedPrint(renderer, 340, 190, string, &c, 2);

      sprintf(string, "for all.");
      c.r = 255; c.g =255; c.b = 255;
      FixedPrint(renderer, 340, 210, string, &c, 2);
      }

    if ((loop >= 260)&& (loop < 360))
      {
      sprintf(string, "I finally intend to take");
      c.r = 255; c.g = 255; c.b = 255;
      FixedPrint(renderer, 340, 150, string, &c, 2);

      sprintf(string, "revenge on the Evil");
      c.r = 255; c.g = 255; c.b = 255;
      FixedPrint(renderer, 340, 170, string, &c, 2);

      sprintf(string, "    Dr. Schemm");
      c.r = 0; c.g =0; c.b = 255;
      FixedPrint(renderer, 340, 190, string, &c, 2);

      sprintf(string, "I'll show him the error");
      c.r = 255; c.g =255; c.b = 255;
      FixedPrint(renderer, 340, 210, string, &c, 2);

      sprintf(string, "of his ways.");
      c.r = 255; c.g =255; c.b = 255;
      FixedPrint(renderer, 340, 230, string, &c, 2);
      }

if ((loop >= 390)&& (loop < 490))
      {
      sprintf(string, "My plans are now complete.");
      c.r = 255; c.g = 255; c.b = 255;
      FixedPrint(renderer, 340, 150, string, &c, 2);

      sprintf(string, "Watch in awe as my plan");
      c.r = 255; c.g = 255; c.b = 255;
      FixedPrint(renderer, 340, 170, string, &c, 2);

      sprintf(string, "unfolds!");
      c.r = 255; c.g =255; c.b = 255;
      FixedPrint(renderer, 340, 190, string, &c, 2);

      sprintf(string, " ");
      c.r = 255; c.g =255; c.b = 255;
      FixedPrint(renderer, 340, 210, string, &c, 2);
      }

if ((loop >= 520)&& (loop < 650))
      {
      sprintf(string, "Activate TwigPower!");
      c.r = 255; c.g =0; c.b = 0;
      FixedPrint(renderer, 340, 210, string, &c, 2);
      }

if ((loop >= 520)&& (loop < 650))
      {
      SDL_SetRenderDrawColor(renderer, (15+loop*87)%256 , 
			     (67+loop*13)%256, (45+loop*29)%256, 255);

      // SDL_RenderDrawLine(renderer, 320, 180, 350, 165);
      // SDL_RenderDrawLine(renderer, 350, 165, 380, 165);

      // SDL_RenderDrawLine(renderer, 280, 180, 250, 165);
      // SDL_RenderDrawLine(renderer, 250, 165, 220, 165);

      // SDL_RenderDrawLine(renderer, 320, 220, 350, 235);
      // SDL_RenderDrawLine(renderer, 350, 235, 380, 235);

      // SDL_RenderDrawLine(renderer, 280, 220, 250, 235);
      // SDL_RenderDrawLine(renderer, 250, 235, 220, 235);

      // SDL_RenderDrawLine(renderer, 320, 200, 380, 200);
      // SDL_RenderDrawLine(renderer, 280, 200, 220, 200);


      }



    
    SDL_RenderPresent(renderer);

    if (SDL_PollEvent(&event) > 0)
      {
      switch(event.type)
	{
	case SDL_KEYDOWN:
	  if (event.key.keysym.scancode ==
	      SDL_SCANCODE_ESCAPE)
	    exit(0);
	case SDL_QUIT: 
	  exit(0);
	}
      }
    
    SDL_Delay(50);
    }
  
  
  }


void confront()
  {
  int loop;
  int kalata_pose;
  int eraser_pose;
  int pose_timer;
    char string[100];

  SDL_Rect tsrc;
  SDL_Rect tdest;
  SDL_Rect ssrc;
  SDL_Rect sdest;
  SDL_Rect esrc;
  SDL_Rect edest;
  SDL_Color c;

  SDL_Event event;
  pose_timer = 0;

  tdest.x = 275; tdest.y = 175; tdest.w = 49; tdest.h = 49;
  tsrc.x = 0; tsrc.y = 0; tsrc.w = 49; tsrc.h = 49;
  
  sdest.x = 275; sdest.y = 175; sdest.w = 49; sdest.h = 49;
  ssrc.x = 0; ssrc.y = 0; ssrc.w = 49; ssrc.h = 49;
  
  edest.x = 275; edest.y = 185; edest.w = 29; edest.h = 29;
  esrc.x = 0; esrc.y = 0; esrc.w = 29; esrc.h = 29;
  
  kalata_pose = 0;
  eraser_pose = 0;
  
  for (loop = 0; loop < 475; loop++)
    {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
   	pose_timer++;
	if (pose_timer == 5)
	  {
	  kalata_pose++;	
	  pose_timer = 0;
	  }
    if (kalata_pose == 6) kalata_pose = 0;
    tsrc.x = kalata_pose * 49;
    ssrc.x = kalata_pose * 49;

    eraser_pose++;
    if (eraser_pose == 24) eraser_pose = 0;
    esrc.x = eraser_pose * 29;

    if (loop < 75)
      {
      sdest.x = loop;
      }
    else if (loop > 400) 
      {
      sdest.x = 75 - (loop-400);
      }
    else
      sdest.x = 75;
    if (loop > 300) 
      {
      tsrc.y = 49;
      }
    if (loop > 400)
      {
      ssrc.y = 49;
      }

    if ((loop >= 200)&&(loop <= 300))
      {
      edest.x = 75 + ((loop - 200)*2);
      SDL_RenderCopy(renderer, eraser, &esrc, &edest);
      }

 if ((loop > 100)&& (loop <= 150))
      {
     sprintf(string, "There you are!");
      c.r = 255; c.g = 255; c.b = 255;
      FixedPrint(renderer, 340, 150, string, &c, 2);

      if ((loop > 150)&& (loop <= 200))
      {
      sprintf(string, " ");
      c.r = 255; c.g = 255; c.b = 255;
      FixedPrint(renderer, 340, 170, string, &c, 2);
      }

      sprintf(string, "Feel the wrath of");
      c.r = 255; c.g =255; c.b = 255;
      FixedPrint(renderer, 340, 190, string, &c, 2);

      sprintf(string, "TwigPower!");
      c.r = 255; c.g =255; c.b = 255;
      FixedPrint(renderer, 340, 210, string, &c, 2);
      }


    if ((loop > 300)&& (loop <= 350))
      {
      sprintf(string, "I'll get you for this!");
      c.r = 255; c.g = 255; c.b = 255;
      FixedPrint(renderer, 340, 150, string, &c, 2);
      }
      
 if ((loop > 370)&& (loop <= 390))
      {
      sprintf(string, "We shall see.");
      c.r = 255; c.g = 255; c.b = 255;
      FixedPrint(renderer, 50, 140, string, &c, 2);
      }
 if ((loop > 390)&& (loop <= 480))
   {
      sprintf(string, "Activate Shields!");
      c.r = 0; c.g = 0; c.b = 255;
      FixedPrint(renderer, 50, 160, string, &c, 2);
      }



if ((loop >= 150)&& (loop < 270))
      {
      SDL_SetRenderDrawColor(renderer, (15+loop*87)%256 , 
			     (67+loop*13)%256, (45+loop*29)%256, 255);

      // SDL_RenderDrawLine(renderer, 320, 180, 350, 165);
      // SDL_RenderDrawLine(renderer, 350, 165, 380, 165);

      // SDL_RenderDrawLine(renderer, 280, 180, 250, 165);
      // SDL_RenderDrawLine(renderer, 250, 165, 220, 165);

      // SDL_RenderDrawLine(renderer, 320, 220, 350, 235);
      // SDL_RenderDrawLine(renderer, 350, 235, 380, 235);

      // SDL_RenderDrawLine(renderer, 280, 220, 250, 235);
      // SDL_RenderDrawLine(renderer, 250, 235, 220, 235);

      // SDL_RenderDrawLine(renderer, 320, 200, 380, 200);
      // SDL_RenderDrawLine(renderer, 280, 200, 220, 200);


      }



    SDL_RenderCopy(renderer, twigman, &tsrc, &tdest);
    SDL_RenderCopy(renderer, schemm, &ssrc, &sdest);


    SDL_RenderPresent(renderer);

    
    if (SDL_PollEvent(&event) > 0)
      {
      switch(event.type)
	{
	case SDL_KEYDOWN:
	  if (event.key.keysym.scancode ==
	      SDL_SCANCODE_ESCAPE)
	    exit(0);
	case SDL_QUIT: 
	  exit(0);
	}
      }
    
    SDL_Delay(50);
    }
  
  
  }


void do_logo()
  {
  SDL_Rect lsrc;
  SDL_Rect ldest;
  char string[100];
  SDL_Event event;
  SDL_Color c;

  int loop;
  
  ldest.x = 138; ldest.y = 120; ldest.w = 325; ldest.h = 160;
  lsrc.x = 0; lsrc.y = 0; lsrc.w = 325; lsrc.h = 160;
  for (loop = 0; loop < 100; loop++){
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, logo, &lsrc, &ldest);
  sprintf(string, "Sometime last weesdfjasdkl;fjasdl;k");
    c.r = 255; c.g = 255; c.b = 255;
    FixedPrint(renderer, 215, 300, string, &c, 1);
    SDL_RenderPresent(renderer);
  }
  

// First line
for (loop = 0; loop < 70; loop++)
    {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, logo, &lsrc, &ldest);
    SDL_RenderPresent(renderer);

    if (SDL_PollEvent(&event) > 0)
      {
      switch(event.type)
	{
	case SDL_KEYDOWN:
	  if (event.key.keysym.scancode ==
	      SDL_SCANCODE_ESCAPE)
	    exit(0);
	case SDL_QUIT: 
	  exit(0);
	}
      }
    
    SDL_Delay(50);

    }
for (loop = 0; loop < 100; loop++)
    {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, logo, &lsrc, &ldest);
    sprintf(string, "Sometime last week");
    c.r = 255; c.g = 255; c.b = 255;
    FixedPrint(renderer, 215, 300+loop, string, &c, 1);
    SDL_RenderPresent(renderer);

    if (SDL_PollEvent(&event) > 0)
      {
      switch(event.type)
	{
	case SDL_KEYDOWN:
	  if (event.key.keysym.scancode ==
	      SDL_SCANCODE_ESCAPE)
	    exit(0);
	case SDL_QUIT: 
	  exit(0);
	}
      }
    
    SDL_Delay(50);

    }





for (loop = 0; loop < 100; loop++)
    {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, logo, &lsrc, &ldest);

    sprintf(string, "In a classroom just down the hall");
    c.r = 255; c.g = 255; c.b = 255;
    FixedPrint(renderer, 155, 300+loop, string, &c, 1);

    SDL_RenderPresent(renderer);

    if (SDL_PollEvent(&event) > 0)
      {
      switch(event.type)
	{
	case SDL_KEYDOWN:
	  if (event.key.keysym.scancode ==
	      SDL_SCANCODE_ESCAPE)
	    exit(0);
	case SDL_QUIT: 
	  exit(0);
	}
      }
    SDL_Delay(50);
    }



for (loop = 0; loop < 100; loop++)
    {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, logo, &lsrc, &ldest);
    SDL_RenderPresent(renderer);

    if (SDL_PollEvent(&event) > 0)
      {
      switch(event.type)
	{
	case SDL_KEYDOWN:
	  if (event.key.keysym.scancode ==
	      SDL_SCANCODE_ESCAPE)
	    exit(0);
	case SDL_QUIT: 
	  exit(0);
	}
      }
    SDL_Delay(50);
    }

  }

int main(int argc, char* argv[])
	{
	
	SDL_Rect ksrc;
	SDL_Rect kdest;
	SDL_Rect tsrc;
	SDL_Rect tdest;
	
SDL_Event event;

	int kalata_x;
	int kalata_y;
	int kalata_pose;
	
	int posetime;
 	setupSDL();



	twigman = loadImage("TwigManClear.png");
	kalata = loadImage("kalata2.png");
	boger = loadImage("Boger49.png");
	help = loadImage("help.png");
	schemm = loadKeyedImage("Schemm49.png");
	eraser = loadKeyedImage("eraser.png");
	logo = loadImage("twigman_revenge_logo.png");
	sun = loadImage("sun.png");
	do_logo();
	intro();
	confront();
	finally();

	}
