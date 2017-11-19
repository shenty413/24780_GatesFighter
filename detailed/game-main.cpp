#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fssimplewindow.h"

// #include "game-class.h"
#include "game-menu.h"


int main(void)
{
	srand((int)time(nullptr));

	FsOpenWindow(0,0,800,600,1);

	for(;;)
	{
		GameMenu menu;
		menu.RunGameMenu();
		if(FSKEY_ESC==menu.key)
		{
			break;
		}
		if(FSKEY_H==menu.key)
		{
			menu.Help();
		}
		else if(FSKEY_S==menu.key)
		{
			int character1,character2;
			character1 = menu.Player1ChooseCharacter();
			if(FSKEY_Y==menu.key)
			{
				printf("Player 1 has chosen %d\n", character1);
				character2 = menu.Player2ChooseCharacter();
				if(FSKEY_Y==menu.key)
				{
					printf("Player 2 has chosen %d\n", character2);
					// Game game;
					// game.Run();
				}
			}
		}
	}

	return 0;
}
