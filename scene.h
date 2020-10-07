#pragma once
#include "danmaku.h"
#include "player.h"

class Scene {
private:
	//storage danmakus by array
	Danmaku danmaku[DANMAKU_MAX];

	//create player
	Player player;

	double startTime;

	double currentTime;

	double score;

	//the time when player be hitted
	double hitTime;

public:
	//show menu
	void menu();
	
	//initialize scene
	void init();

	//update scene
	void update();
	
	//show scene
	void play();
	
	//show status
	void showStat();
};
