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
: Character(imgPath, rows, cols, animationSpeed)
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

void Player::Render()
{
	update_everything();
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

bool Player::set_health(unsigned int health)
{
	m_health = health;
	return m_health == health;
}

int Player::get_health()
{
	return m_health;
}

bool Player::set_lives(unsigned int lives)
{
	m_lives = lives;
	return m_lives == lives;
}

unsigned int Player::get_lives()
{
	return m_lives;
}

bool Player::set_damage(unsigned int damage)
{
	m_damage = damage;
	return m_damage == damage;
}

unsigned int Player::get_damage()
{
	return m_damage;
}

bool Player::set_defence(unsigned int defence)
{
	m_defence = defence;
	return m_defence == defence;
}

unsigned int Player::get_defence()
{
	return m_defence;
}

void Player::update_player_ui()
{
	player_ui->set_health(get_health());
	player_ui->set_lives(m_lives);
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

bool Player::Check_Health()
{
	return m_health > 0;
}

void Player::set_npc_hint(const std::string &hint)
{
	m_hint = hint;
}
const std::string Player::get_npc_hint()
{
	return m_hint;
}

bool Player::react()
{
	return false;
}