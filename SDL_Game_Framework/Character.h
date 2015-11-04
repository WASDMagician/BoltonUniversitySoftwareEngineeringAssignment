#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <iostream>
#include <string>
#include "AW_Sprite_Interface.h"

class Character:
	public AW_Sprite_Interface
{
public:
	Character();
	Character(char* img, int rows, int cols, int animationSpeed);
	virtual ~Character();
	virtual bool Setup(char* imgPath, int rows, int cols, int animationSpeed) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

	virtual bool set_name(std::string name) = 0;
	virtual std::string get_name() = 0;

	virtual bool set_health(unsigned int health) = 0;
	virtual unsigned int get_health() = 0;

	virtual bool set_lives(unsigned int lives) = 0;
	virtual unsigned int get_lives() = 0;

	virtual bool set_damage(unsigned int damage) = 0;
	virtual unsigned int get_damage() = 0;

	virtual bool set_defence(unsigned int defence) = 0;
	virtual unsigned int get_defence() = 0;

protected:
	std::string m_name;
	unsigned int m_health;
	unsigned int m_lives;
	unsigned int m_damage;
	unsigned int m_defence;
};

#endif _CHARACTER_H_