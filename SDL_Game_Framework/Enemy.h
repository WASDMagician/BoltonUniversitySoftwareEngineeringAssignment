#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Character.h"

enum EnemyState
{
	IDLE,
	ROAMING,
	ATTACK,
	DEAD
};

class Enemy : public Character
{
public:
	Enemy();
	~Enemy();

	int get_enemy_name();
	int get_health();
	int get_defence();
	int get_damage();

	bool enemy_movement();
	bool enemy_idle();
	bool enemy_roam();
	bool enemy_attack();
	bool enemy_dead();
private:
	Character *character;
	EnemyState enemyState;

	int m_name;
	int m_health;
	int m_defence;
	int m_damage;
};

#endif