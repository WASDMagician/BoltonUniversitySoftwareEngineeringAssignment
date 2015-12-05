#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Character.h"

class Enemy :
	public Character
{
public:

	Enemy();
	Enemy(char* imgPath, int rows, int cols);
	virtual ~Enemy();

	virtual void Setup(char* imgPath, int rows, int cols);
	virtual void Update();

	//@update_UML
	virtual void set_health_message();

	virtual void Enemy_Movement();

	//@update_UML
	virtual void Render();

protected:
	//@update_UML
	Text_Box *m_health_box;
};

#endif