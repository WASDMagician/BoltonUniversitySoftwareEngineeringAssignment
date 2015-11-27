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

class Enemy :
	public Character
{
public:

	Enemy();
	Enemy(char* imgPath, int rows, int cols, int animationSpeed);
	virtual ~Enemy();

	virtual bool Setup(char* imgPath, int rows, int cols, int animationSpeed);
	virtual void Update();

	virtual bool Enemy_Movement();
	virtual bool Enemy_Idle();
	virtual bool Enemy_Roam();
	virtual bool Enemy_Attack();
	virtual bool Enemy_Dead();

	virtual bool set_name(std::string name);
	virtual std::string get_name();

	virtual bool set_health(int health);
	virtual int get_health();

	virtual bool set_lives(int lives);
	virtual int get_lives();

	virtual bool set_damage(int damage);
	virtual int get_damage();

	virtual bool set_score(int score);
	virtual int get_score();

	virtual bool Check_Alive();
	virtual bool React(Character* target);

protected:
	ENEMY_STATE enemy_state;
};

#endif