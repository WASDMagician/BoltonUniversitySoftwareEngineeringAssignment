#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"

class UI_Play_Screen;

class Player : 
	public Character
{
public:
	Player();
	Player(char* imgPath, int rows, int cols, int animationSpeed);
	~Player();

	bool Setup(char* imgPath, int rows, int cols, int animationSpeed);
	void Update();

	 bool set_name(std::string name);
	 std::string get_name();

	 bool set_health(int health);
	 int get_health();

	 bool set_lives(int lives);
	 int get_lives();

	 bool set_damage(int damage);
	 int get_damage();

	 bool set_score(int score);
	 int get_score();

	 bool is_blocking = false;

	 bool Check_Alive();

	 bool React(Character* target);
	 
private:
};

#endif

