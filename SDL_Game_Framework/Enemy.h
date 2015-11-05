#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Character.h"

//DO I NEED TO RE-ADD CHARACTER CLASS FOR ENEMY AND PLAYER

enum ENEMY_STATE
{
	IDLE,
	ROAMING,
	ATTACK,
	DEAD
};

class Enemy :
	public Character
{
public:
	Enemy();
	Enemy(char* imgPath, int rows, int cols, int animationSpeed);
	virtual ~Enemy();

	virtual bool Setup(char* imgPath, int rows, int cols, int animationSpeed);
	virtual void Update();
	virtual void Render();

	virtual bool Enemy_Movement();
	virtual bool Enemy_Idle();
	virtual bool Enemy_Roam();
	virtual bool Enemy_Attack();
	virtual bool Enemy_Dead();

	virtual bool set_name(std::string name);
	virtual std::string get_name();

	virtual bool set_health(unsigned int health);
	virtual unsigned int get_health();

	virtual bool set_lives(unsigned int lives);
	virtual unsigned int get_lives();

	virtual bool set_damage(unsigned int damage);
	virtual unsigned int get_damage();

	virtual bool set_defence(unsigned int defence);
	virtual unsigned int get_defence();

protected:
	ENEMY_STATE enemy_state;
};

#endif