#include <iostream>
#include <SDL.h>
#include "othershit.hpp"

class Game
{
private:
    #define TITLE "Snake Game"
    #define WIDTH 640
    #define HEIGHT 480

    SDL_Window *window;
    SDL_Renderer *renderer;

    bool running = true;

    void input()
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            switch (e.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            
            default:
                break;
            }
        }
    }
    void draw()
    {
        SDL_RenderClear(renderer);
    }
    void update()
    {

    }
    
    void quit()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        std::cout << "QUITTING" << std::endl;
    }
public:
    void init()
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
        if (window != 0)
            renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer == 0)
            std::cout << SDL_GetError() << std::endl;
    }

    void mainloop()
    {
        init();
        while(running)
        {
            // input, update, draw
            input();
            std::cout << SDL_GetError() << std::endl;
            update();
            std::cout << SDL_GetError() << std::endl;
            //draw();
            //std::cout << SDL_GetError() << std::endl;
            SDL_Delay(60);
        }
        quit();
    }
};

int main(int argc, char**argv)
{
    Game game = Game();
    game.mainloop();
    return 0;
}