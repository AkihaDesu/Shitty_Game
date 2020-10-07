#pragma once
#include "def.h"

class Danmaku {
private:
	//posision of danmaku
	double posX;
	double posY;

	//devided speed vector
	double dX;
	double dY;

	//damage of danmaku
	int damage = DEFAULT_DAMAGE;

	//direction of angle
	double theta;

	//speed vector
	double speed;

public:
	//update danmaku
	void update();

	//hit edge
	void hitEdge();

	//initialize single danmaku
	void init(double t);

	//render single danmaku
	void rend();

	//get x posision
	double getPosX() { return this->posX; }

	//get y posision
	double getPosY() { return this->posY; }

	void reverseX();

	void reverseY();
};