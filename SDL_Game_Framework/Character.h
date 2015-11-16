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

	virtual void set_npc_hint(const std::string &hint) =0;
	virtual const std::string get_npc_hint() = 0;
	virtual bool react() = 0;
	virtual bool Check_Health() = 0;

protected:
	std::vector<AWSprite*>images;
	std::string m_name;
	std::string m_hint;
	int m_health;
	unsigned int m_lives;
	unsigned int m_damage;
	unsigned int m_defence;

	int m_score;
};

#endif _CHARACTER_H_