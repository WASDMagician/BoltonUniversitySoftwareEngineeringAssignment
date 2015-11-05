#pragma once
#include "AWSprite.h"

class Projectile :
	public AWSprite
{
public:
	Projectile();
	Projectile(char *img, int x, int y);
	~Projectile();

	bool Update();

	bool destroy;
	int direction; //1 = up  2 = down  3 = left  4 = right
private:
	int life_time;
	int current_time;
	float projectile_speed;
	int damage;
};

