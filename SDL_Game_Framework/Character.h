#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <iostream>
#include <string>
#include "AW_Sprite_Interface.h"
#include "Text_Box.h"

class Character:
	public AW_Sprite_Interface
{
public:
	Character();
	Character(char* img, int rows, int cols, std::string message);
	virtual ~Character();
	virtual void Setup(char* imgPath, int rows, int cols);
	virtual void set_variables(int health, int damage);

	virtual void Update();
	virtual void Render();

	virtual void set_health(int health);
	virtual int get_health();

	virtual void set_lives(int lives);
	virtual int get_lives();

	virtual void set_damage(int damage);
	virtual int get_damage();

	virtual void set_score(int score);
	virtual int get_score();

	virtual void Attack(Character *target);

	virtual void set_message(std::string);
	virtual std::string get_message();

	virtual void React(Character* target);
	virtual bool Check_Alive();
	
	void set_display_box(bool display);
	bool get_display_box();

	Text_Box *m_message_box;
protected:
	int m_health;
	int m_lives;
	int m_damage;

	int m_score;

	std::string m_message;
	
};

#endif _CHARACTER_H_