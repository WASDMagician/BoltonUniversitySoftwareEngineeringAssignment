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
	AW_Sprite_Interface(char* imgPath, int rows, int cols);
	~AW_Sprite_Interface();

	void Update();
	void Render();

	bool Move_By(int xAmount, int yAmount);
	bool Move_To(int x, int y);

	bool Move_Increment(int x, int y);
	bool Move_Between();

	bool Lerp_To(Vector2<int, int> *target, int moveSpeed, int rangeSnap);

	void Add_Patrol_Position(Vector2<int, int>* position);
	void Add_Patrol_Position(std::vector<Vector2<int, int>*> position);

	bool In_Range(Vector2<int, int> *position, Vector2<int, int> *target, int rangeSnap);

	void Remove_Patrol_Position(int index);

	Vector2<int, int>*get_current_position();
	

private:
	std::vector<Vector2<int, int>*>m_patrol_positions;
	Vector2<int, int> *m_current_target;
	Vector2<int, int> *m_current_position;
	unsigned int m_current_target_index;
};

#endif //_AW_SPRITE_INTERFACE_