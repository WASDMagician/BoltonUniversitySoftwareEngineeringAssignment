#ifndef _CUSTOM_TYPES_H_
#define _CUSTOM_TYPES_H_

typedef struct Vector2{ 
	float x; 
	float y; 

	friend bool operator==(Vector2 first, Vector2 second)
	{ 
		return (first.x == second.x && first.y == second.y); 
	}

	friend bool operator < (Vector2 positionOne, Vector2 positionTwo)
	{
		return (positionOne.x < positionTwo.x && positionOne.y < positionTwo.y);
	}

	friend bool operator >(Vector2 positionOne, Vector2 positionTwo)
	{
		return (positionOne.x > positionTwo.x && positionOne.y > positionTwo.y);
	}
};

#endif //_CUSTOM_TYPES_H_