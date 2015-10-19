#ifndef _CUSTOM_TYPES_H_
#define _CUSTOM_TYPES_H_

typedef struct Vector2{ 
	float x; 
	float y; 

	friend bool operator==(Vector2 first, Vector2 second)
	{ 
		return (first.x == second.x && first.y == second.y); 
	}

	friend bool operator !=(Vector2 first, Vector2 second)
	{
		return !(first == second);
	}

	friend bool operator < (Vector2 positionOne, Vector2 positionTwo)
	{
		return (positionOne.x < positionTwo.x && positionOne.y < positionTwo.y);
	}

	friend bool operator >(Vector2 positionOne, Vector2 positionTwo)
	{
		return (positionOne.x > positionTwo.x && positionOne.y > positionTwo.y);
	}

	friend Vector2 &operator +(Vector2 vector, int addition)
	{
		return (Vector2{ vector.x + addition, vector.y + addition });
	}

	friend bool In_Range(Vector2 position, Vector2 *target, float amount)
	{
		return((position.x <= target->x + amount && position.x >= target->x - amount) && 
			(position.y <= target->y + amount && position.y >= target->y - amount));
	}


};

#endif //_CUSTOM_TYPES_H_