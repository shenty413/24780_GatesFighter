#include "HP.h"

int HP::GetHP_left(void) const 
{
	return hp_left; 
}

int HP::GetHP_right(void) const
{
	return hp_right;
}

void HP::SetHP_left(int hp) 
{
	hp_left = hp;
}

void HP::SetHP_right(int hp)
{
	hp_right = hp;
}