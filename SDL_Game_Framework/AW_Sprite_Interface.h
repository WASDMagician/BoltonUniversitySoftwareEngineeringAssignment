#ifndef _AW_SPRITE_INTERFACE_H_
#define _AW_SPRITE_INTERFACE_H_

#include <vector>
#include "AWSprite.h"
#include "Vector2.h"

class AW_Sprite_Interface :
	public AWSprite
{
public:
	AW_Sprite_Interface();
	AW_Sprite_Interface(char* imgPath, int rows, int cols, int animationSpeed);
	~AW_Sprite_Interface();

	void Update();
	
	void Move_By(float xAmount, float yAmount);
	void Move_By_Without_Record(float x, float y);

	void Move_To(float x, float y);
	void Move_Toward();

	bool In_Range(float range);

	void Set_Target_Position(float x, float y);
	void Update_Target_Position(float x, float y);
	bool Has_Target();

	void set_spawn(float x, float y);
	void Move_To_Spawn();

	void Randomize_Position(float xPos, float width, float yPos, float height);

	void Revert_Position();

	void Render();

private:
	bool has_target;

	float last_move_x;
	float last_move_y;

	float target_position_x;
	float target_position_y;

	float spawn_x;
	float spawn_y;
};

#endif //_AW_SPRITE_INTERFACE_