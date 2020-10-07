#include "scene.h"

void Scene::menu() {
	cleardevice();																					//clear screen every update

	setcolor(BLACK);
	outtextxy(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, "Press any key to start, press ESC to exit.");	//display tips
	outtextxy(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 20, "Use w,a,s,d to move, use ESC to stop.");

	switch (getch()) {																				//press anykey to start
	case 27:
		closegraph();
		exit(0);
		break;
	default:
		break;
	}
}

void Scene::init() {
	
	cleardevice();

	startTime = fclock();																			//get start time of game

	player.init(SCREEN_WIDTH / 2, SCREEN_HEIGHT - PLAYER_HITRAND);									//initialize player with posision

	for (int i = 0; i <= DANMAKU_MAX - 1; ++i) {													//initialize danmakus one by one

		danmaku[i].init(2 * PI / DANMAKU_MAX * i);													//devide danmaku's direction as max
	}
}

void Scene::update() {
	cleardevice();																					//clear screen before update

	score = fclock() - startTime;																	//make score as current time - start time
	
		if (keystate('W')||keystate(VK_UP)) {														//get player input
			player.moveRY();
		}
		if (keystate('A')||keystate(VK_LEFT)) {
			player.moveRX();
		}
		if (keystate('S')||keystate(VK_DOWN)) {
			player.moveY();
		}
		if (keystate('D')||keystate(VK_RIGHT)) {
			player.moveX();
		}

		if (keystate(VK_ESCAPE)) {
			player.die();
		}

//		if (keystate(VK_TAB)) {
//			player.debug();
//		}
	
	for (int i = 0; i <= DANMAKU_MAX - 1; ++i) {													//update bullets one by one
		danmaku[i].update();																		//update each danmaku

		if (																						//if hit,do:
			(pow(danmaku[i].getPosX() - player.getPosX(), 2)
				+
				pow(danmaku[i].getPosY() - player.getPosY(), 2))
			<=
			pow((double)(PLAYER_HITRAND + DANMAKU_HITRAND), 2)
			) {
			
			player.hit();																			//do player damage function
		}
	}
	
	player.rend();																					//render player

	showStat();																						//show game status
}

void Scene::play() {
	init();																							//initialize the scene

	for (; is_run(); delay_fps(DELAY_FPS)) {														//loop when program is running

		if (this->player.getFail()) {																//if game is failed, show menu
			setcolor(BLACK);																		//display hint text
			outtextxy(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, "Try again? y(Yes)/n(No)/q(Quit)");

			if (keystate('Y')) {
				init();
			}
			else if (keystate('N')) {
				menu();
				init();
			}
			else if (keystate('Q')) {
				closegraph();
				exit(0);
			}
		}
		else {
			update();																				//scene update
		}
	}
}

void Scene::showStat() {
	setcolor(RED);

	xyprintf(0, 0, "HP:%d", player.getHP());

	setcolor(BLUE);

	xyprintf(0, 20, "Score:%d", (int)this->score);
}
