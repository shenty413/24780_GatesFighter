#include "random_boost_item.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include "fssimplewindow.h"
#include "ysglfontdata.h"


void Random_boost_item::LoadPNG(std::string fileName, YsRawPngDecoder *target){
    if(YSOK == target->Decode(fileName.c_str()))
    {
        target->Flip();
        printf("%dx%d\n",target->wid,target->hei);
    }
    else
    {
        printf("Cannot open file %s.\n", fileName.c_str());
    }
}

Random_boost_item::Random_boost_item() 
{
	x = 400;
	y = 300; 
	width = 30; 
	height = width; 
	timer = 0;
	consumed = false; 
	index = rand() % 4;
    LoadPNG("item1.png", &item1);
    LoadPNG("item2.png", &item2);
    LoadPNG("item3.png", &item3);
    LoadPNG("item4.png", &item4);
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
                glRasterPos2i(x,y);
                glDrawPixels(item1.wid,item1.hei,GL_RGBA,GL_UNSIGNED_BYTE,item1.rgba);				break;
		case 1: // red->attack up 
                glRasterPos2i(x,y);
                glDrawPixels(item2.wid,item2.hei,GL_RGBA,GL_UNSIGNED_BYTE,item2.rgba);				break;
		case 2: // green->heal
                glRasterPos2i(x,y);
                glDrawPixels(item3.wid,item3.hei,GL_RGBA,GL_UNSIGNED_BYTE,item3.rgba);
                break;
		case 3: // lb->attack up speed down 
                glRasterPos2i(x,y);
                glDrawPixels(item4.wid,item4.hei,GL_RGBA,GL_UNSIGNED_BYTE,item4.rgba);				break;
		default:
				break;
		}
    }else{
        glColor3ub(0, 0, 255);
        switch (index) {
            case 0: // blue->speed up
                glRasterPos2i(x,y);
                YsGlDrawFontBitmap16x24("Speed + 10");
                glRasterPos2i(x,y-30);
                YsGlDrawFontBitmap16x24("HP - 5");
                break;
            case 1: // red->attack up
                glRasterPos2i(x,y);
                YsGlDrawFontBitmap16x24("Attack + 5");
                glRasterPos2i(x,y-30);
                YsGlDrawFontBitmap16x24("HP - 5");
                break;
            case 2: // green->heal
                glRasterPos2i(x,y);
                YsGlDrawFontBitmap16x24("Hp + 10");
                break;
            case 3: // lb->attack up speed down
                glRasterPos2i(x,y);
                YsGlDrawFontBitmap16x24("Speed - 10");
                glRasterPos2i(x,y-30);
                YsGlDrawFontBitmap16x24("Attacl + 5");
                break;
            default:
                break;
        }
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
