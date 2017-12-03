#include "random_boost_item.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include "fssimplewindow.h"


Random_boost_item::Random_boost_item() 
{
	x = 400;
	y = 300; 
	width = 30; 
	height = width; 
	timer = 0;
	consumed = false; 
	index = rand() % 4 + 1;
}

void Random_boost_item::Update(void) 
{
	if (timer < 150) 
	{
		timer++;
	}
	else
	{
		timer = 0;
		index = rand() % 4;
		printf("index=%i\n", index);
		consumed = false;
	}
}

void Random_boost_item::Draw()
{
	if(consumed==false)
	{
		switch (index) {
		case 0: // blue->speed up
				glColor3ub(0, 0, 255);
				break;
		case 1: // red->attack up 
				glColor3ub(255, 0, 0);
				break;
		case 2: // green->heal
				glColor3ub(0, 255, 0);
				break;
		case 3: // lb->attack up speed down 
				glColor3ub(0, 255, 255);
				break;
		default:
				break;
		}
		glBegin(GL_QUADS);
		glVertex2i(x, y);
		glVertex2i(x + width, y);
		glVertex2i(x + width, y - height);
		glVertex2i(x, y - height);
		glEnd();
	}
}

void Random_boost_item::CheckConsume(Player &player) 
{
	if (consumed == false) 
	{
		if (x >= player.getLeftBoundary() && x <= player.getRightBoundary() && y <= player.getLowerBoundary() && y >= player.getUpperBoundary())
		{
			consumed = true; 
			Boost(player);
		}
	}
};

void Random_boost_item::Boost(Player &player) 
{
	player.setAttack(attack_up[index]);
	player.setVx(speed_up[index]);
	player.HPchange(hp_boost[index]);
	printf("Player attack: %i Player hp: %i", player.getAttack(), player.GetHP());
};
