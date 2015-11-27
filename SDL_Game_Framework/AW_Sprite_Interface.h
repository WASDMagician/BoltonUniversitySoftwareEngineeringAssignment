#ifndef _AW_SPRITE_INTERFACE_H_
#define _AW_SPRITE_INTERFACE_H_

#include <vector>
#include "AWSprite.h"
#include "Vector2.h"

struct position
{
	float x;
	float y;
};

class AW_Sprite_Interface :
	public AWSprite
{
public:
	AW_Sprite_Interface();
	AW_Sprite_Interface(char* imgPath, int rows, int cols, int animationSpeed);
	~AW_Sprite_Interface();

	void Update();

	void Add_Position(position);
	void Add_Positions(std::vector<position>positions);
	void Clear_Positions();
	
	void Move_By(float xAmount, float yAmount);
	void Move_By_Without_Record(float x, float y);

	void Move_To(float x, float y);
	void Move_Toward();

	bool In_Range(float range);

	void Increment_Target();

	void set_target_position(int targetIndex);
	void set_target_position(position target);
	void Update_Target_Position(position newTarget);
	bool Has_Target();

	void set_spawn(float x, float y);
	void Move_To_Spawn();

	void Randomize_Position(float xPos, float width, float yPos, float height);

	void Revert_Position();

	void Render();

private:
	std::vector<position>positions;

	bool has_target;

	float last_move_x;
	float last_move_y;

	int current_target_index;
	position target;

	float spawn_x;
	float spawn_y;
};

#endif //_AW_SPRITE_INTERFACE_