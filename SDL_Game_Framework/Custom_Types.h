#ifndef _CUSTOM_TYPES_H_
#define _CUSTOM_TYPES_H_

typedef struct Vector2{ 
	float x; 
	float y; 
	bool operator==(Vector2 pos){ return (pos.x == pos.y); };
};

#endif //_CUSTOM_TYPES_H_