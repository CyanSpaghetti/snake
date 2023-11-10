#include <iostream>
#include <SDL.h>
#include "snake.hpp"
#include "snake.cpp"
#include "fruit.hpp"
#include "fruit.cpp"
class Game
{
private:
    // settings
    #define TITLE "Snake Game"

    SDL_Window *window;
    SDL_Renderer *renderer;

    bool running = true;

    // snake
    Snake player;

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
                case SDL_KEYDOWN:
                    switch (e.key.keysym.scancode) // W = 0, A = 1, S = 2, D = 3;
                    {
                        case SDL_SCANCODE_W:
                            player.changeDir(0);
                            break;
                        case SDL_SCANCODE_A:
                            player.changeDir(1);
                            break;case SDL_SCANCODE_S:
                            player.changeDir(2);
                            break;
                        case SDL_SCANCODE_D:
                            player.changeDir(3);
                            break;
                        case SDL_SCANCODE_ESCAPE:
                            running = false;
                            break;
                        case SDL_SCANCODE_UP:
                            player.speed++;
                            break;
                        case SDL_SCANCODE_DOWN:
                            player.speed--;
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }
    }
    void draw()
    {
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        player.drawBody(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderPresent(renderer);
    }
    void update()
    {
        player.move();
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
        player.init();
    }

    void mainloop()
    {
        init();
        while(running)
        {
            // input, update, draw
            input();
            update();
            draw();
            SDL_Delay(FPS);
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