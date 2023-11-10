#include <SDL.h>
#include <iostream>
#include "snake.hpp"
#include "settings.hpp"
void Snake::init()
{
    std::cout << "Snake Made" << std::endl;
    x = WIDTH/2;
    y = HEIGHT/2;
    moveTowards = W;

}
void Snake::move()
{
    switch(moveTowards)
    {
        case W:
            y-=speed;
            break;
        case A:
            x-=speed;
            break;
        case S:
            y+=speed;
            break;
        case D:
            x+=speed;
            break;
    }
}
void Snake::changeDir(int change) // 0 = W, 1 = A, 2 = S, 3 = D.
{
    switch (change)
    {
    case 0:
        moveTowards = W;
        std::cout << "Changed Dir to W" << std::endl;
        break;
    case 1:
        moveTowards = A;
        std::cout << "Changed Dir to A" << std::endl;
        break;
    case 2:
        moveTowards = S;
        std::cout << "Changed Dir to S" << std::endl;
        break;
    case 3:
        moveTowards = D;
        std::cout << "Changed Dir to D" << std::endl;
        break;
    default:
        break;
    }
}
void Snake::drawBody(SDL_Renderer *renderer)
{
    SDL_Rect piece;
    piece.w = SIZE, piece.h = SIZE;
    // for(int i = 0; i < length; i++)
    // {
    //     piece.x = x - (i * SIZE)  + SIZE/2;
    //     piece.y = y - (i * SIZE) + SIZE/2;
    //     SDL_RenderFillRect(renderer, &piece);
    // }
    piece.x = x;
    piece.y = y;
    SDL_RenderFillRect(renderer, &piece);

}