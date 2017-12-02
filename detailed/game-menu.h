#ifndef GAME_MENU_H_IS_INCLUDED
#define GAME_MENU_H_IS_INCLUDED
#include "yspng.h"
#include "yspngenc.h"

class GameMenu
{
public:
    YsRawPngDecoder title;
    YsRawPngDecoder instructions;
    
	int key;
	void RunGameMenu(void);
	int Player1ChooseCharacter(void);
	int Player2ChooseCharacter(void);
	void Help(void);
	void End(int No);
};

#endif
