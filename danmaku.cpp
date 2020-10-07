#include "danmaku.h"

void Danmaku::update() {
	this->posX += this->dX;
	this->posY += this->dY;

	hitEdge();

	this->rend();
}

//reverse vector when hit window edge
void Danmaku::hitEdge() {
	if (posX >= (double)SCREEN_WIDTH || posX <= 0.) {
		reverseX();
		dY += dY > 0 ? 0.1 : -0.1;//change y aris vector
	}

	if (posY >= (double)SCREEN_HEIGHT || posY <= 0.) {
		reverseY();
		dX += dX > 0 ? 0.2 : -0.2;//change x aris vector
	}
}

void Danmaku::rend() {
	setcolor(RED);
	setfillcolor(WHITE);
	circle((int)posX, (int)posY, DANMAKU_HITRAND);
}

void Danmaku::init(double t) {
	theta = t;
	speed = DEFAULT_DANMAKU_SPEED;

	//set the start point as middle of screen
	posX = (double)SCREEN_WIDTH / 2;
	posY = (double)SCREEN_HEIGHT / 2;

	dX = speed * cos(theta);
	dY = speed * sin(theta);
}

void Danmaku::reverseX() {
	this->dX *= -1;
}

void Danmaku::reverseY() {
	this->dY *= -1;
}