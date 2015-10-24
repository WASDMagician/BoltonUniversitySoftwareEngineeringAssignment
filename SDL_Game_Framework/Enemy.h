#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Character.h"

enum ENEMY_STATE
{
	IDLE,
	ROAMING,
	ATTACK,
	DEAD
};

struct ENEMY_ROAMING
{
	
};

class Enemy : public Character
{
public:
	Enemy();
	Enemy(character_creation_variables *initialisers);

	virtual ~Enemy();

	bool Enemy_Movement();
	bool Enemy_Idle();
	bool Enemy_Roam();
	bool Enemy_Attack();
	bool Enemy_Dead();

	bool set_name(std::string name);
	std::string get_name();

	bool set_health(unsigned int health);
	unsigned int get_health();

	bool set_lives(unsigned int lives);
	unsigned int get_lives();

	bool set_damage(unsigned int damage);
	unsigned int get_damage();

	bool set_defence(unsigned int defence);
	unsigned int get_defence();

	std::string serialize_character();

private:
	ENEMY_STATE enemy_state;
	Character *character;
};

#endif