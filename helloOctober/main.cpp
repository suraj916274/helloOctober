#include <iostream>

using namespace std;
#include <SDL.h>
#include <SDL_main.h>
#include <SDL_image.h>
int main(int argc, char* argv[])
{
    bool october = true;
    int frame = 0;
    int windowWidth = 800; int windowHeight = 600;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window =
    SDL_CreateWindow("helloOctober", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN );
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0) ;
    SDL_Surface* bgSurf1 = IMG_Load("images/halloween-moving1.png") ;
    SDL_Texture* bgTexture1 = SDL_CreateTextureFromSurface(renderer, bgSurf1);
    SDL_Surface* bgSurf2 = IMG_Load("images/halloween-moving2.png") ;
    SDL_Texture* bgTexture2 = SDL_CreateTextureFromSurface(renderer, bgSurf2);
    SDL_Surface* bgSurf3 = IMG_Load("images/halloween-moving3.png") ;
    SDL_Texture* bgTexture3 = SDL_CreateTextureFromSurface(renderer, bgSurf3);
    SDL_Texture* bg[3]; bg[0] = bgTexture1; bg[1] = bgTexture2; bg[2] = bgTexture3;
    SDL_Rect bgRect; bgRect.w = windowWidth; bgRect.h = windowHeight; bgRect.x = 0; bgRect.y = 0;
    SDL_Event event;
    while(october)
    {
 // message processing loop

        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                october = false;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        october = true;
                     if (event.key.keysym.sym == SDLK_RIGHT)
                     {

                     }
                     if (event.key.keysym.sym == SDLK_LEFT)
                     {

                     }
                    break;
                }
            } // end switch
        } // end of message processing

        // DRAWING STARTS HERE

        // clear screen
       // SDL_RenderClear(renderer);

        // draw
        SDL_RenderClear(renderer);
        //SDL_RenderCopy(renderer, bg[0], &bgRect, NULL);
        SDL_RenderCopy(renderer, bg[0], &bgRect, NULL);
        SDL_RenderCopy(renderer, bg[frame], &bgRect, NULL);

        SDL_RenderPresent(renderer);
        frame= frame + 1; if (frame > 2) frame = 1;
        SDL_Delay(600);

        // DRAWING ENDS HERE

        // finally, update the screen :
    }
    cout << "Hello October!" << endl;
    return 0;
}
