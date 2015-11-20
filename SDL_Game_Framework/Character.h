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
	Character(char* img, int rows, int cols, int animationSpeed, std::string message);
	virtual ~Character();
	virtual bool Setup(char* imgPath, int rows, int cols, int animationSpeed) = 0;
	virtual void Update();
	virtual void Render();

	virtual bool set_name(std::string name) = 0;
	virtual std::string get_name() = 0;

	virtual bool set_health(unsigned int health) = 0;
	virtual int get_health() = 0;

	virtual bool set_lives(unsigned int lives) = 0;
	virtual unsigned int get_lives() = 0;

	virtual bool set_damage(unsigned int damage) = 0;
	virtual unsigned int get_damage() = 0;

	virtual bool set_defence(unsigned int defence) = 0;
	virtual unsigned int get_defence() = 0;

	virtual bool set_score(int score);
	virtual int get_score();

	virtual void Attack(Character *target) = 0;
	virtual void Defend(Character *target) = 0;

	virtual void set_message(std::string hint);
	virtual const std::string get_message();
	virtual bool react(Character* target) = 0;
	virtual bool Check_Alive() = 0;
	
	void set_display_box(bool display);
	bool get_display_box();

	Text_Box *m_message_box;
protected:
	std::vector<AWSprite*>images;
	std::string m_name;
	int m_health;
	unsigned int m_lives;
	unsigned int m_damage;
	unsigned int m_defence;

	int m_score;

	std::string m_message;
	
};

#endif _CHARACTER_H_