#pragma once
#include "AW_Sprite_Interface.h"
class Test_AW_Sprite_Interface :
	public AW_Sprite_Interface
{
public:
	Test_AW_Sprite_Interface(char* imgPath, int rows, int cols);
	~Test_AW_Sprite_Interface();
	std::vector<position>get_positions(); //vector of target positions
	std::vector<position>get_spawn_positions(); //vector of target positions at spawn (not to be updated)

	bool get_has_target(); //whethere the current element has a target within the position vector

	int get_current_target_index(); //position of target in vector of target positions
	position get_target(); //current target

	float get_spawn_x(); //spawn position on x
	float get_spawn_y(); //spawn position on y
};

