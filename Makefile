SDLFLAGS=`sdl2-config --cflags --libs`
all:
	g++ main.cpp -o game.out $(SDLFLAGS)
	clear
	./game.out