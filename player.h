#pragma once
#include "def.h"
#include "player.h"

class Player {
private:
	//health point
	int hp;

	//declare posision
	double posX;
	double posY;
	
	//if game failed
	bool ifFail = false;

	//invicibility of player
	bool invincibility = false;

	//time when player got hitten
	double hitTime;

public:
	//to right
	void moveX();
	
	//to down
	void moveY();
	
	//to left
	void moveRX();
	
	//to up
	void moveRY();
	
	//damage function
	void hit();
	
	//death function
	void die() { this->ifFail = true; }
	
	//get if_fail
	bool getFail() { return this->ifFail; }
	
	//initialize player
	void init(int x, int y);
	
	//render player
	void rend();
	
	//get player's posision x
	int getPosX() { return (int)this->posX; }
	
	//get player's posision y
	int getPosY() { return (int)this->posY; }
	
	//get hp
	int getHP() { return this->hp; }
	
	//debug mode
	void debug() { this->hp = 100000; }

	//
	bool getInvi() { return this->invincibility; }

	//
	void setInvi( bool i);
};
