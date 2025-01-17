#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.hpp"

class Player: public Entity
{
public:
	enum {stay,walk,jump} STATE;
	int cash;
	float sx, sy;
	std::map<std::string,bool> key;
	int life;
	float lifeCooldown;
	
	Player(AnimationManager &a, Level &lev, int x, int y);
	void Keyboard();
	void Animation(float time);
	void update(float time);
	void Collision(int num);
	int getLife();
	void minusLife();
};
#endif PLAYER_H
