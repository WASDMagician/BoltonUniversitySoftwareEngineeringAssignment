#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"

class UI_Play_Screen;

class Player : 
	public Character
{
public:
	//char* img_path, unsigned int rows, unsigned int cols, string name, unsigned int health, unsigned int damage, unsigned int defence, unsigned animation_speed
	Player();
	Player(char* imgPath, int rows, int cols, int animationSpeed);
	~Player();

	bool Setup(char* imgPath, int rows, int cols, int animationSpeed);
	void Update();
	void Render();

	void update_player_ui();

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

	 bool is_blocking = false;
private:
	UI_Play_Screen *player_ui;
};

#endif

