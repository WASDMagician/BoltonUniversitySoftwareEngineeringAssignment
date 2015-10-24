#ifndef _PUZZLE_OBJECTS_H_
#define _PUZZLE_OBJECTS_H_

#include "Pickup_Objects.h"
class Puzzle_Objects :
	public Pickup_Objects
{
public:
	Puzzle_Objects();
	~Puzzle_Objects();

	bool is_puzzle_piece(); //check if its a puzzle piece
	bool can_be_dropped(); //probably need this so that the puzzle item cant be dropped

};

#endif _PUZZLE_OBJECTS_H_