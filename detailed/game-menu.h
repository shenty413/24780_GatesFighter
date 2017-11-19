#ifndef GAME_MENU_H_IS_INCLUDED
#define GAME_MENU_H_IS_INCLUDED

class GameMenu
{
public:
	int key;
	void RunGameMenu(void);
	int Player1ChooseCharacter(void);
	int Player2ChooseCharacter(void);
	void Help(void);
};

#endif
