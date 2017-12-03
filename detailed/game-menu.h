#ifndef GAME_MENU_H_IS_INCLUDED
#define GAME_MENU_H_IS_INCLUDED
#include "yspng.h"
#include "yspngenc.h"
#include <string>

class GameMenu
{
public:
    YsRawPngDecoder title;
    YsRawPngDecoder instructions;
    YsRawPngDecoder p1select;
    YsRawPngDecoder p2select;
    
    YsRawPngDecoder sty;
    YsRawPngDecoder zzh;
    YsRawPngDecoder lty;
    YsRawPngDecoder czl;
    YsRawPngDecoder zwy;
    
	int key;
	void RunGameMenu(void);
	int Player1ChooseCharacter(void);
	int Player2ChooseCharacter(void);
	void Help(void);
	void End(int No);
    void LoadPNG(std::string fileName, YsRawPngDecoder *target);
};

#endif
