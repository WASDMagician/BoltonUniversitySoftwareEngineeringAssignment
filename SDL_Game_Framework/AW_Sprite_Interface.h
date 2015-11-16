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
	void Render();

	int get_angle_between(AW_Sprite_Interface* target);
	int get_distance_between(AW_Sprite_Interface* target);

	bool Move_By(int xAmount, int yAmount);
	bool Move_To(float x, float y);

	bool Move_Increment(float x, float y);
	bool Move_Between();

	bool Lerp_To(Vector2<float, float> *target, double moveSpeed, int rangeSnap);

	void Add_Patrol_Position(Vector2<float, float> *position);
	void Add_Patrol_Position(std::vector<Vector2<float, float>*> position);

	bool In_Range(Vector2<float, float> *position, Vector2<float, float> *target, int rangeSnap);

	void Remove_Patrol_Position(int index);

	Vector2<float, float>*get_current_position();

	void Randomize_Position(int xPos, int width, int yPos, int height);

	void Debug();
	

private:
	std::vector<Vector2<float, float>*>m_patrol_positions;
	Vector2<float, float> *m_current_target;
	Vector2<float, float> *m_current_position;
	unsigned int m_current_target_index;
};

#endif //_AW_SPRITE_INTERFACE_