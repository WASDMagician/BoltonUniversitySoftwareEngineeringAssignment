#include "UI_Play_Screen.h"

UI_Play_Screen* UI_Play_Screen::m_instance = NULL;

UI_Play_Screen::UI_Play_Screen()
	:m_display_character(NULL)
{
	UI_Play_Screen::m_instance = NULL;
	m_ui_details = new Text_Box(); //defined here to prevent crash
}

UI_Play_Screen::UI_Play_Screen(Character* character)
	: m_display_character(character)
{
	m_ui_details = new Text_Box(); //defined here to prevent crash
	Update();
}


UI_Play_Screen* UI_Play_Screen::get_instance()
{
	if (m_instance == NULL)
	{
		m_instance = new UI_Play_Screen();
	}

	return m_instance;
}

UI_Play_Screen::~UI_Play_Screen()
{
}

void UI_Play_Screen::set_character(Character *character)
{
	m_display_character = character;
	Update();
}

Character* UI_Play_Screen::get_character()
{
	return m_display_character;
}

void UI_Play_Screen::Update()
{
	//memory leak in here somewhere //@BUG
	if (m_ui_details != NULL)
	{
		delete m_ui_details;
		m_ui_details = NULL;
		m_ui_details = new Text_Box();
	}
	
	std::string health = "Health " + to_string(m_display_character->get_health());
	std::string lives = "Lives " + to_string(m_display_character->get_lives());
	std::string damage = "Damage " + to_string(m_display_character->get_damage());
	std::string score = "Score " + to_string(m_display_character->get_score());
	std::string output = health + " " + lives + " " + damage + " " + score;
	
	m_ui_details->set_font("fonts/game_font.ttf", 20);
	m_ui_details->set_color(200, 0, 0);
	m_ui_details->Position_Setting(0, 0);
	m_ui_details->Add_Message(output);
	m_ui_details->Setup_Box();
	m_ui_details->set_rects();
	m_ui_details->set_should_display(false);
	
}

void UI_Play_Screen:: Display()
{
	m_ui_details->Display();
}
