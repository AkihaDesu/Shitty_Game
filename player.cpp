#include "player.h"

void Player::moveX() {
	if ((int)this->posX + PLAYER_HITRAND <= SCREEN_WIDTH) {
		posX += DEFAULT_SPEED;
	}
}

void Player::moveY() {
	if ((int)this->posY + PLAYER_HITRAND <= SCREEN_HEIGHT) {
		posY += DEFAULT_SPEED;
	}
}

void Player::moveRX() {
	if ((int)this->posX - PLAYER_HITRAND >= 0) {
		posX -= DEFAULT_SPEED;
	}
}

void Player::moveRY() {
	if ((int)this->posY - PLAYER_HITRAND >= 0) {
		posY -= DEFAULT_SPEED;
	}
}

void Player::hit() {

	if (fclock() - hitTime >= INVICIBLE_TIME) {			//if invisible time past, lose invicibility	
		invincibility = false;
	}

	switch (this->invincibility) {
	case true:break;

	case false:
		if (hp - DEFAULT_DAMAGE > 0) {
			hp -= DEFAULT_DAMAGE;
			this->hitTime = fclock();					//get the time when player be hitted
			this->invincibility = true;					//give player a period of invicible time
		}
		else {
			hp = 0;
			this->die();
		}

		break;
	}
}

void Player::init(int x, int y) {
	this->hp = HP_MAX;
	this->ifFail = false;
	this->posX = (double)x;
	this->posY = (double)y;
}

void Player::rend() {
	setcolor(BLUE);
	circle((int)posX, (int)posY, PLAYER_HITRAND);

	setcolor(BLACK);
	circle((int)posX, (int)posY, PLAYER_HITRAND + 4);

//	line((int)posX - 10, (int)posY, (int)posX, (int)posY - 10);
}

void Player::setInvi(bool i) {
	this->invincibility = i;
}