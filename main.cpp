#include "scene.h"

int main() {

	setcaption("BOUNCE!");										//set caption of window

	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT, INIT_RENDERMANUAL);	//initialize window

	setbkcolor(WHITE);											//set background color as white

	Scene game;													//creat game scene

	game.menu();												//show menu

	game.play();												//enter game scene

	return 0;
}