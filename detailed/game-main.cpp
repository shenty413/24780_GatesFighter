#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fssimplewindow.h"

#include "game-menu.h"
#include "game.h"



int main(void)
{
	srand((int)time(nullptr));

	FsOpenWindow(0,0,1024,768,1);

	for(;;)
	{
		GameMenu menu;
		// menu.End();

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
                    Game game;
                    // game.End();
                    game.SetCharacter(character1, character2); // Set choosen character
                    //FsCloseWindow();
                    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
                    FsSleep(20);
                    //FsOpenWindow(16,16,800,600,1);
                    game.Run(); // Start Game
					/*
						three possible ways of ending a game:
						1. user presses esc
						2. time runs out 
						3. one player k.o. the other 
						Depending on which way the game ends, different prompts will pop up on the screen. 
					*/
                    if (game.isExit()){
                        // break;
                        // printf("%d\n", game.getWinner());
                        // game.getWinner();
                        // menu.End(game.getWinner());
                        game.End();
                    }
					if (game.isTimeout()) {
						// break;
						// printf("%d\n", game.getWinner());
						// game.getWinner();
						// menu.End(game.getWinner());
						game.End();
					}
					if (game.isKo()) {
						// break;
						// printf("%d\n", game.getWinner());
						// game.getWinner();
						// menu.End(game.getWinner());
						game.End();
					}
				}
			}
		}
	}
	// printf("end\n");
	// menu.Player2ChooseCharacter();


	return 0;
}
