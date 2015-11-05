#include "Projectile.h"


Projectile::Projectile()
{

}

Projectile::Projectile(char *img, int x, int y)
	:AWSprite(img, 1, 1)
{
	//set_world_position(x, y);
}

Projectile::~Projectile()
{
}

bool Projectile::Update()
{
	/*if (direction == 1) //up
	{
		set_velocities(0, -projectile_speed);
		set_auto_move(40);
		set_auto_accelerate(20);
		std::cout << "direction 1" << std::endl;
	}
	else if (direction == 2) //down
	{
		set_velocities(0, projectile_speed);
		set_auto_move(40);
		set_auto_accelerate(20);
		std::cout << "direction 2" << std::endl;
	}
	else if (direction == 3) //left
	{
//		proj->set_world_position(-projectile_speed, 0);
		std::cout << "direction 3" << std::endl;
	}
	else if (direction == 4) //right
	{
//		proj->set_world_position(projectile_speed, 0);
		std::cout << "direction 4" << std::endl;
	}
	else
	{
		//do nothing
	}*/
	return direction;
}