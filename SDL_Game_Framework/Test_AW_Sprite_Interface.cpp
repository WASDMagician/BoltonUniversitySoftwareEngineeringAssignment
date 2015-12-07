#include "Test_AW_Sprite_Interface.h"


Test_AW_Sprite_Interface::Test_AW_Sprite_Interface(char* imgPath, int rows, int cols)
	:AW_Sprite_Interface(imgPath, rows, cols)
{
}


Test_AW_Sprite_Interface::~Test_AW_Sprite_Interface()
{
}

std::vector<position>Test_AW_Sprite_Interface::get_positions()
{
	return m_positions;
}

std::vector<position>Test_AW_Sprite_Interface::get_spawn_positions()
{
	return m_spawn_positions;
}

bool Test_AW_Sprite_Interface::get_has_target()
{
	return m_has_target;
}

int Test_AW_Sprite_Interface::get_current_target_index()
{
	return m_current_target_index;
}

position Test_AW_Sprite_Interface::get_target()
{
	return m_target;
}

float Test_AW_Sprite_Interface::get_spawn_x()
{
	return m_spawn_x;
}

float Test_AW_Sprite_Interface::get_spawn_y()
{
	return m_spawn_y;
}