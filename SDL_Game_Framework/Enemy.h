#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Character.h"

enum ENEMY_STATE{IDLE, ROAMING, ATTACK, DEAD};

class Enemy :
	public Character
{
public:

	Enemy();
	Enemy(char* imgPath, int rows, int cols, int animationSpeed);
	virtual ~Enemy();

	virtual void Setup(char* imgPath, int rows, int cols, int animationSpeed);
	virtual void Update();

	//@update_UML
	virtual void set_health_message();

	virtual void Enemy_Movement();
	virtual void Enemy_Idle();
	virtual void Enemy_Roam();
	virtual void Enemy_Attack();
	virtual void Enemy_Dead();

	//@update_UML
	virtual void Render();

protected:
	//@update_UML
	Text_Box* m_health_box;
	ENEMY_STATE enemy_state;
};

#endif