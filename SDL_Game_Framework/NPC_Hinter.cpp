// Written by Ed Hawksworth
// Class for hint giving NPC(s)

#include "NPC_Hinter.h"

NPC_Hinter::NPC_Hinter()
{

}

NPC_Hinter::NPC_Hinter(char* img, int rows, int cols, std::string message)
	: Character(img, rows, cols, message)
{

}

NPC_Hinter::~NPC_Hinter()
{
}
