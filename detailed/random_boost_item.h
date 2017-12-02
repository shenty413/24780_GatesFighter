#ifndef random_boost_item_h
#define random_boost_item_h

#include "player.h"

class Random_boost_item 
{
protected: 
	// position of the item
	int x, y; 

	// item index
	int index;
	
	// item box width and height
	int width, height; 

	// timer, counts the time for randomly generate a new item every 5 seconds 
	int timer; 

	// consume flag, 0 means the item is consumed; 1 means it's not. 
	bool consumed;

	// boost effects
	const int speed_up[4] = {10,0,0,-10};
	const int attack_up[4] = {0,5,0,5};
	const int hp_boost[4] = {-5,-5,10,0};

public:
	Random_boost_item(); // constructor
	void Update(void); 
	void Draw(); 
	void CheckConsume(Player &player);
	void Boost(Player &player); 
};
#endif 
