#pragma once
#include "PickupObjects.h"
class PuzzleObjects :
	public PickupObjects
{
public:
	PuzzleObjects();
	~PuzzleObjects();

	bool is_puzzle_piece(); //check if its a puzzle piece
	bool can_be_dropped(); //probably need this so that the puzzle item cant be dropped

};

