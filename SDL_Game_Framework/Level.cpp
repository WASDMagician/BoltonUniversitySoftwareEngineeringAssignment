#include "Level.h"


Level::Level()
{
}


Level::~Level()
{
}


void Level::Render()
{
	for (auto &a : m_areas)
	{
		a->update_everything();
	}
	for (auto &e : m_enemies)
	{
		e->update_everything();
	}
}