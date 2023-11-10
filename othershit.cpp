#include <SDL.h>
class Snake
{
private:
    int x,y,length = 1;
    const int speed = 4;
    enum direction {W,A,S,D};
    direction moveTowards;
public:
    void move()
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
    void changeDir(int change) // 0 = W, 1 = A, 2 = S, 3 = D.
    {
        switch (change)
        {
        case 0:
            moveTowards = W;
            break;
        case 1:
            moveTowards = A;
            break;
        case 2:
            moveTowards = S;
            break;
        case 3:
            moveTowards = D;
            break;
        default:
            break;
        }
    }
    void drawBody(SDL_Renderer *renderer)
    {
        // draw body using a for loop * size
    }

};

class Fruit
{
    int x,y;
};