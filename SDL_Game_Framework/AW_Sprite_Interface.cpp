#include "AW_Sprite_Interface.h"

AW_Sprite_Interface::AW_Sprite_Interface()
	:AWSprite(), m_target({NULL, NULL}), m_has_target(false), 
	m_spawn_x(NULL), m_spawn_y(NULL), m_current_target_index(0), m_positions(NULL)
{
	set_transparent_colour(255, 0, 255); //set transparent colour of sprite (assuming it is always the same)
}

AW_Sprite_Interface::AW_Sprite_Interface(char* imgPath, int rows, int cols, int animationSpeed)
	: AWSprite(imgPath, rows, cols), m_target({NULL, NULL}), 
	m_has_target(false), m_spawn_x(NULL), m_spawn_y(NULL), m_current_target_index(0), m_positions(NULL)
{
	set_transparent_colour(255, 0, 255); //set transparent colour of sprite (assuming it is always the same)
}

AW_Sprite_Interface::~AW_Sprite_Interface()
{
}

void AW_Sprite_Interface::Add_Position(position pos)
{
	//DO NOT ADD POSITIONS AFTER LEVEL HAS STARTED
	m_positions.push_back(pos); //add single position to position array
	m_spawn_positions = m_positions; //set spawn position
}

void AW_Sprite_Interface::Add_Positions(std::vector<position> newPositions)
{
	//DO NOT ADD POSITIONS AFTER LEVEL HAS STARTED
	for (size_t i = 0; i < newPositions.size(); i++) //iterate through positions
	{
		m_positions.push_back(newPositions[i]); //add to position list
	}
	m_spawn_positions = m_positions; //set spawn positions
}

void AW_Sprite_Interface::Clear_Positions()
{
	m_positions.clear(); //remove positions
}

//template<typename T>
bool AW_Sprite_Interface::Is_Contained(std::vector<AW_Sprite_Interface*>vectorInput, position testPos)
{
	//is the entirety of the given sprite within in one of the vectorInput elements (map parts)
	bool is_contained = false; //initialise the return value

	//setup the bounds of the player
	float player_left = get_x();
	float player_right = get_x() + get_width();
	float player_top = get_y();
	float player_bottom = get_y() + get_height();

	for (size_t i = 0; i < vectorInput.size(); i++) //iterate through map elements
	{
		//setup area bounds
		float input_left = vectorInput[i]->get_x() + testPos.x;
		float input_right = vectorInput[i]->get_x() + testPos.x + vectorInput[i]->get_width();
		float input_top = vectorInput[i]->get_y() + testPos.y;
		float input_bottom = vectorInput[i]->get_y() + testPos.y + vectorInput[i]->get_height();
		
		if (input_left <= player_left && input_right >= player_right && input_top <= player_top && input_bottom >= player_bottom) //is contained
		{
			is_contained = true;
			break;
		}
	}
	return is_contained;
}

void AW_Sprite_Interface::Move_By(float xAmount, float yAmount)
{
	//set move amounts
	float moveX = get_x() + (xAmount);
	float moveY = get_y() + (yAmount);

	//move sprite
	Move_To(moveX, moveY);

}

void AW_Sprite_Interface::Move_To(float x, float y)
{
	set_world_position(x, y); //move
}

void AW_Sprite_Interface::Move_Toward()
{
	//get angle to target
	float xDiff = m_target.x - get_x();
	float yDiff = m_target.y - get_y();

	float angle = atan2(yDiff, xDiff);
	Move_By((10 * (cos(angle))), (10 * (sin(angle)))); //move along angle
}

bool AW_Sprite_Interface::In_Range(float range)
{
	//get if element is within x range of other element
	return(get_x() > m_target.x - range && get_x() < m_target.x + range && get_y() > m_target.y - range && get_y() < m_target.y + range);
}

void AW_Sprite_Interface::Increment_Target()
{
	if (In_Range(get_width())) //if element in range of target
	{
		set_target_position(m_current_target_index + 1); //increment target
	}
}

void AW_Sprite_Interface::set_target_position(int targetIndex)
{
	if (targetIndex < m_positions.size()) //if target index in vector
	{
		m_target = m_positions[targetIndex]; //set target to position at index
		m_current_target_index = targetIndex; //set current target index to passed index
	}
	else //else
	{
		m_target = m_positions[0]; //reset position to first in vector
		m_current_target_index = 0;
	}
	m_has_target = true;
}

void AW_Sprite_Interface::set_target_position(position targ) 
{
	m_target = targ;
	m_has_target = true;
}

void AW_Sprite_Interface::Update_Target_Position(float xAmount, float yAmount)
{
	for (size_t i = 0; i < m_positions.size(); i++) //move targets by amount level has moved
	{
		m_positions[i].x += xAmount;
		m_positions[i].y += yAmount;
	}
}

bool AW_Sprite_Interface::Has_Target()
{
	return m_has_target;
}

void AW_Sprite_Interface::set_spawn(float x, float y)
{
	m_spawn_x = x; //set spawn position x
	m_spawn_y = y; //set spawn position y
}

void AW_Sprite_Interface::Move_To_Spawn()
{
	Move_To(m_spawn_x, m_spawn_y); //move character to spawn
	m_positions = m_spawn_positions; //set current positions to positions at time of creation
}

void AW_Sprite_Interface::Randomize_Position(float xPos, float width, float yPos, float height)
{
	float rand_x = rand() % (int)(width - get_width());
	float rand_y = rand() % (int)(height - get_height());

	set_world_position(xPos + rand_x, yPos + rand_y);
}

void AW_Sprite_Interface::Render()
{
	update_everything();
}