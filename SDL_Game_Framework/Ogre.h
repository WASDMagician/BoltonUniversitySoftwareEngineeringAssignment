#ifndef _OGRE_H_
#define _OGRE_H_

#include "Enemy.h"

class Ogre :
	public Enemy
{
public:
	Ogre();
	Ogre(std::string enemy_name, int enemy_health, int enemy_damage, int enemy_defence);
	~Ogre();

	std::string get_enemy_name();
	int get_enemy_health();
	int get_enemy_damage();
	int get_enemy_defence();

private:
	Enemy *ogre_enemy;
	std::string m_enemy_name;
	int m_enemy_health;
	int m_enemy_damage;
	int m_enemy_defence;
};

#endif
