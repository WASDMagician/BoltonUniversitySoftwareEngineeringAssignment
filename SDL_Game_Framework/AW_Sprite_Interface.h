#ifndef _AW_SPRITE_INTERFACE_H_
#define _AW_SPRITE_INTERFACE_H_

#include <vector>
#include "AWSprite.h"
#include "Game_Time.h"

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
	AW_Sprite_Interface(char* imgPath, int rows, int cols);
	~AW_Sprite_Interface();

	void Add_Position(position pos);
	void Add_Positions(std::vector<position>positions);
	void Clear_Positions();

	//template<typename T>
	bool Is_Contained(std::vector<AW_Sprite_Interface*>vectorInput, position testPos);
	
	void Move_By(float xAmount, float yAmount);

	void Move_To(float x, float y);
	void Move_Toward(); //move toward target

	bool In_Range(float range);

	void Increment_Target(); //set current target to next target in vector

	void set_target_position(int targetIndex);
	void set_target_position(position target);
	void Update_Target_Position(float xAmount, float yAmount);
	bool Has_Target();

	void set_spawn(float x, float y);
	void Move_To_Spawn();

	void Randomize_Position(float xPos, float width, float yPos, float height);

	void Render();

private:
	std::vector<position>m_positions; //vector of target positions
	std::vector<position>m_spawn_positions; //vector of target positions at spawn (not to be updated)

	bool m_has_target; //whethere the current element has a target within the position vector

	int m_current_target_index; //position of target in vector of target positions
	position m_target; //current target

	float m_spawn_x; //spawn position on x
	float m_spawn_y; //spawn position on y

	
};

#endif //_AW_SPRITE_INTERFACE_