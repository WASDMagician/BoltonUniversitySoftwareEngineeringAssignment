#include "UI_Play_Screen.h"


UI_Play_Screen::UI_Play_Screen()
	:m_collectibles(0), m_health(100), m_ammunition(0), m_lives(5), m_score(0), m_name("Pleb"), m_flickering(false), UI_Details(NULL)
{
	UI_Details = new Text_Box();
	/*sprite = new AW_Sprite_Interface();
	sprite->setImage(SCRN_WIDTH, SCRN_HEIGHT, 255, 0, 0);
	sprite->set_visibility(false);*/
}

UI_Play_Screen::UI_Play_Screen(unsigned int items, unsigned int health, unsigned int ammo, unsigned int lives, unsigned int score, std::string name)
	: m_collectibles(items), m_health(health), m_ammunition(ammo), m_lives(lives), m_score(score), m_name(name), m_flickering(false),
	UI_Details(NULL)
{
	UI_Details = new Text_Box();
	/*sprite = new AW_Sprite_Interface();
	sprite->setImage(SCRN_WIDTH, SCRN_HEIGHT, 255, 0, 0);
	sprite->set_visibility(false);*/
}


UI_Play_Screen::~UI_Play_Screen()
{
}

bool UI_Play_Screen::set_character(Character *character)
{
	m_display_character = character;
	Setup();
	return false;
}

bool UI_Play_Screen::Setup()
{
	UI_Details->set_font("fonts/game_font.ttf", 15);
	UI_Details->set_color(200, 0, 0);
	UI_Details->Position_Setting(0, 0, 0, 0);
	UI_Details->Add_Message("Name ");
	UI_Details->Setup_Box();
	UI_Details->set_rects();
	UI_Details->set_should_display(false);
	Update();
	return false;
}

bool UI_Play_Screen::Update()
{
	delete UI_Details;
	UI_Details = new Text_Box();
	std::string name = "Name " + m_display_character->get_name();
	std::string health = "Health " + to_string(m_display_character->get_health());
	std::string lives = "Lives " + to_string(m_display_character->get_lives());
	std::string damage = "Damage " + to_string(m_display_character->get_damage());
	std::string score = "Score " + to_string(m_display_character->get_score());
	std::string output = name + " " + health + " " + lives + " " + damage + " " + score;

	UI_Details->set_font("fonts/game_font.ttf", 15);
	UI_Details->set_color(200, 0, 0);
	UI_Details->Position_Setting(0, 0, 0, 0);
	UI_Details->Add_Message(output);
	UI_Details->Setup_Box();
	UI_Details->set_rects();
	UI_Details->set_should_display(false);
	return false;
}

bool UI_Play_Screen::Flicker(unsigned int numOfFlicks)
{
	if (m_flickering)
	{
		sprite->set_visibility(!sprite->is_visible());
		return true;
	}
	return false;
}

void UI_Play_Screen:: Display()
{
	UI_Details->Display();

	//sprite->update_everything();
}
