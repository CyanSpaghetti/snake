#pragma once
class Snake
{
private:
    int x,y; 
    enum direction {W,A,S,D};
    direction moveTowards;
public:
    void init();
    void move();
    void changeDir(int change); // 0 = W, 1 = A, 2 = S, 3 = D.
    void drawBody(SDL_Renderer *renderer);
    int speed = 1;
    int length = 1;
};