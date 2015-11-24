// Written by Kyle Thomas - 12/10/15
// Handles certain things for the player eg.
// Setting up the player position, image and name

#include "Player.h"
#include "UI_Play_Screen.h"


Player::Player()
:Character()
{
}

Player::Player(char* imgPath, int rows, int cols, int animationSpeed)
: Character(imgPath, rows, cols, animationSpeed, "")
{
}

Player::~Player()
{
}

bool Player::Setup(char* imgPath, int rows, int cols, int animationSpeed)
{
	setImage(imgPath, rows, cols);
	return false;
}

void Player::Update()
{

}

bool Player::set_name(std::string name)
{
	m_name = name;
	return m_name == name;
}

std::string Player::get_name()
{
	return m_name;
}

bool Player::set_health(int health)
{
	m_health = health;
	return m_health == health;
}

int Player::get_health()
{
	return m_health;
}

bool Player::set_lives(int lives)
{
	m_lives = lives;
	return m_lives == lives;
}

int Player::get_lives()
{
	return m_lives;
}

bool Player::set_damage(int damage)
{
	m_damage = damage;
	return m_damage == damage;
}

int Player::get_damage()
{
	return m_damage;
}

bool Player::set_defence(int defence)
{
	m_defence = defence;
	return m_defence == defence;
}

int Player::get_defence()
{
	return m_defence;
}

bool Player::set_score(int score)
{
	m_score = score;
	return m_score == score;
}

int Player::get_score()
{
	return m_score;
}

void Player::Attack(Character* target)
{
	target->Defend(target);
}

void Player::Defend(Character* target)
{
	m_health -= target->get_damage() - get_defence();
}

bool Player::Check_Alive()
{
	return m_health > 0;
}

bool Player::React(Character* target)
{
	return false;
}