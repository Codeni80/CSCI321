include <SDL/SDL.h>
#include <SDL/SDL_image.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

void DrawImage(SDL_Surface *img, SDL_Surface *screen, int x, int y)
{
    SDL_Rect alue;
    alue.x = x;
    alue.y = y;

    SDL_BlitSurface(img, NULL, screen, &alue);
}

void DrawMarks(int *Places, SDL_Surface *imgX, SDL_Surface *imgO, SDL_Surface *screen)
{
    if (Places[0] == 1)
    {
        DrawImage(imgX, screen, 120, 43);
    }
    else if (Places[0] == 2)
    {
        DrawImage(imgO, screen, 120, 43);
    }

    if (Places[1] == 1)
    {
        DrawImage(imgX, screen, 273, 43);
    }
    else if (Places[1] == 2)
    {
        DrawImage(imgO, screen, 273, 43);
    }

    if (Places[2] == 1)
    {
        DrawImage(imgX, screen, 423, 43); 
    }
    else if (Places[2] == 2)
    {
        DrawImage(imgO, screen, 423, 43);
    }

    if (Places[3] == 1)
    {
        DrawImage(imgX, screen, 120, 188);
    }
    else if (Places[3] == 2)
    {
        DrawImage(imgO, screen, 120, 188);
    }

    if (Places[4] == 1)
    {
        DrawImage(imgX, screen, 273, 188); 
    }
    else if (Places[4] == 2)
    {
        DrawImage(imgO, screen, 273, 188); 
    }

    if (Places[5] == 1)
    {
        DrawImage(imgX, screen, 423, 188); 
    }
    else if (Places[5] == 2)
    {
        DrawImage(imgO, screen, 423, 188);
    }

    if (Places[6] == 1)
    {
        DrawImage(imgX, screen, 120, 338);
    }
    else if (Places[6] == 2)
    {
        DrawImage(imgO, screen, 120, 338);
    }

    if (Places[7] == 1)
    {
        DrawImage(imgX, screen, 273, 338);
    }
    else if (Places[7] == 2)
    {
        DrawImage(imgO, screen, 273, 338);
    }

    if (Places[8] == 1)
    {
        DrawImage(imgX, screen, 423, 338);
    }
    else if (Places[8] == 2)
    {
        DrawImage(imgO, screen, 423, 338);
    }
}

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetCaption("Tic Tac Toe", NULL);

    SDL_Surface *screen = NULL; 
    SDL_Surface *board = NULL; 
    SDL_Surface *imgX = NULL;
    SDL_Surface *imgO = NULL;
    SDL_Surface *winX = NULL; 
    SDL_Surface *winO = NULL; 
    SDL_Surface *xTurn = NULL;
    SDL_Surface *oTurn = NULL;
    SDL_Surface *draw = NULL;

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF); 

    board = IMG_Load("board.png"); 
    imgX = IMG_Load("imgX.png"); 
    imgO = IMG_Load("imgO.png"); 
    winX = IMG_Load("xwin.png");
    winO = IMG_Load("owin.png");
    xTurn = IMG_Load("xturn.png");
    oTurn = IMG_Load("oturn.png");
    draw = IMG_Load("draw.png");

    start:

    bool EndGameLoop = false;
    bool EndGame = false;
    int winner = 0; 
    int turn = 1;

    int Places[9] = {NULL};

    SDL_Event event;


    while(EndGameLoop != true)
    {

    DrawImage(board, screen, 0, 0); 

    if(!(turn % 2) == 1)
    {
        DrawImage(xTurn, screen, 15, 43);
    }
    else if (!(turn % 2) == 0)
    {
        DrawImage(oTurn, screen, 13, 43);
    }

        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT) 
            {
                EndGameLoop = true;
                EndGame = true;
                goto endgame;
            }

        if(event.type == SDL_KEYDOWN)
            {

                if(event.key.keysym.sym == SDLK_ESCAPE) 
                {
                    EndGameLoop = true;
                    EndGame = true;
                    goto endgame;
                }


        if(event.key.keysym.sym == SDLK_KP7)
        {
            if(!(turn % 2) == 1)
            {
                if(Places[0] == 0)
                {
                Places[0] = 1;
                turn++;
                }
            }
            if(!(turn % 2) == 0)
            {
                if(Places[0] == 0)
                {
                Places[0] = 2;
                turn++;
                }
            }
        }

        if(event.key.keysym.sym == SDLK_KP8)
        {
            if(!(turn % 2) == 1)
            {
                if(Places[1] == 0)
                {
                Places[1] = 1;
                turn++;
                }
            }
            if(!(turn % 2) == 0)
            {
                if(Places[1] == 0)
                {
                Places[1] = 2;
                turn++;
                }
            }

        }

        if(event.key.keysym.sym == SDLK_KP9)
        {
            if(!(turn % 2) == 1)
            {
                if(Places[2] == 0)
                {
                Places[2] = 1;
                turn++;
                }
            }
            if(!(turn % 2) == 0)
            {
                if(Places[2] == 0)
                {
                Places[2] = 2;
                turn++;
                }
            }
        }


        if(event.key.keysym.sym == SDLK_KP4)
        {
            if(!(turn % 2) == 1)
            {
                if(Places[3] == 0)
                {
                Places[3] = 1;
                turn++;
                }
            }
            if(!(turn % 2) == 0)
            {
                if(Places[3] == 0)
                {
                Places[3] = 2;
                turn++;
                }
            }
        }

        if(event.key.keysym.sym == SDLK_KP5)
        {
            if(!(turn % 2) == 1)
            {
                if(Places[4] == 0)
                {
                Places[4] = 1;
                turn++;
                }
            }
            if(!(turn % 2) == 0)
            {
                if(Places[4] == 0)
                {
                Places[4] = 2;
                turn++;
                }
            }
        }

        if(event.key.keysym.sym == SDLK_KP6)
        {
            if(!(turn % 2) == 1)
            {
                if(Places[5] == 0)
                {
                Places[5] = 1;
                turn++;
                }
            }
            if(!(turn % 2) == 0)
            {
                if(Places[5] == 0)
                {
                Places[5] = 2;
                turn++;
                }
            }
        }

        if(event.key.keysym.sym == SDLK_KP1)
        {
            if(!(turn % 2) == 1)
            {
                if(Places[6] == 0)
                {
                Places[6] = 1;
                turn++;
                }
            }
            if(!(turn % 2) == 0)
            {
                if(Places[6] == 0)
                {
                Places[6] = 2;
                turn++;
                }
            }
        }

        if(event.key.keysym.sym == SDLK_KP2)
        {
            if(!(turn % 2) == 1)
            {
                if(Places[7] == 0)
                {
                Places[7] = 1;
                turn++;
                }
            }
            if(!(turn % 2) == 0)
            {
                if(Places[7] == 0)
                {
                Places[7] = 2;
                turn++;
                }
            }
        }

        if(event.key.keysym.sym == SDLK_KP3)
        {
            if(!(turn % 2) == 1)
            {
                if(Places[8] == 0)
                {
                Places[8] = 1;
                turn++;
                }
            }
            if(!(turn % 2) == 0)
            {
                if(Places[8] == 0)
                {
                Places[8] = 2;
                turn++;
                }
            }

        }


    }

    DrawMarks(Places, imgX, imgO, screen);

            if (Places[0] == 1 && Places[1] == 1 && Places[2] == 1)
    {
        winner = 1;
        EndGameLoop = true;
    }
    else if (Places[0] == 2 && Places[1] == 2 && Places[2] == 2)
    {
        winner = 2;
        EndGameLoop = true;
    }

    else if (Places[3] == 1 && Places[4] == 1 && Places[5] == 1)
    {
        winner = 1;
        EndGameLoop = true;
    }
    else if (Places[3] == 2 && Places[4] == 2 && Places[5] == 2)
    {
        winner = 2;
        EndGameLoop = true;
    }

    else if (Places[6] == 1 && Places[7] == 1 && Places[8] == 1)
    {
        winner = 1;
        EndGameLoop = true;
    }
    else if (Places[6] == 2 && Places[7] == 2 && Places[8] == 2)
    {
        winner = 2;
        EndGameLoop = true;
    }

    else if (Places[0] == 1 && Places[3] == 1 && Places[6] == 1)
    {
        winner = 1;
        EndGameLoop = true;
    }
    else if (Places[0] == 2 && Places[3] == 2 && Places[6] == 2)
    {
        winner = 2;
        EndGameLoop = true;
    }

    else if (Places[1] == 1 && Places[4] == 1 && Places[7] == 1)
    {
        winner = 1;
        EndGameLoop = true;
    }
    else if (Places[1] == 2 && Places[4] == 2 && Places[7] == 2)
    {
        winner = 2;
        EndGameLoop = true;
    }

    else if (Places[2] == 1 && Places[5] == 1 && Places[8] == 1)
    {
        winner = 1;
        EndGameLoop = true;
    }
    else if (Places[2] == 2 && Places[5] == 2 && Places[8] == 2)
    {
        winner = 2;
        EndGameLoop = true;
    }

    else if (Places[0] == 1 && Places[4] == 1 && Places[8] == 1)
    {
        winner = 1;
        EndGameLoop = true;
    }
    else if (Places[0] == 2 && Places[4] == 2 && Places[8] == 2)
    {
        winner = 2;
        EndGameLoop = true;
    }

    else if (Places[2] == 1 && Places[4] == 1 && Places[6] == 1)
    {
        winner = 1;
        EndGameLoop = true;
    }
    else if (Places[2] == 2 && Places[4] == 2 && Places[6] == 2)
    {
        winner = 2;
        EndGameLoop = true;
    }


    SDL_Flip(screen);

    if(turn == 10)
    {
        EndGameLoop = true;
    }

    }

    while (EndGame != true)
    {
        if (winner == 1)
        {
            DrawImage(winX, screen, 0, 0);
            SDL_Flip(screen);
            SDL_Delay(2000);
            EndGame = true;
        }
        else if (winner == 2)
        {
            DrawImage(winO, screen, 0, 0);
            SDL_Flip(screen);
            SDL_Delay(2000);
            EndGame = true;
        }
        else
        {
            DrawImage(draw, screen, 0, 0);
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
    SDL_FreeSurface(xTurn);
    SDL_FreeSurface(oTurn);
    SDL_FreeSurface(draw);

    SDL_Quit();

    return 0;
}