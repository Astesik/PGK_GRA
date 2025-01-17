#include "changeLevel.hpp"

void changeLevel(Level &lvl, int &numberLevel)
{
	if (numberLevel == 1) { lvl.LoadFromFile("res/map/level1.tmx"); }
	if (numberLevel == 2) { lvl.LoadFromFile("res/map/level2.tmx"); }
	if (numberLevel == 3) { lvl.LoadFromFile("res/map/level3.tmx"); }

}