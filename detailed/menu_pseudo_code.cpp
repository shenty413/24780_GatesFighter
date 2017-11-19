#include <stdio.h>
#include "fssimplewindow.h"
#include "ysglfontdata.h"

#include "game-menu.h"

/*
	This file describes what is contained in the menu works for this project
*/

void GameMenu::RunGameMenu(void)
{
	/*
		Show the initialization of the menu, take the key as input to decide whether
		to go to the help page or directly start the game.
		
		S means start the game -> player 1 choose character -> player 2 choose character
		H means go to the help page
		ESC means quit
	*/
}

void GameMenu::Help(void)
{
	/*
		Illustrate the instruction of this game for both player 1 and player 2.
	*/
}

int GameMenu::Player1ChooseCharacter(void)
{
	/*
		If start the game, player 1 first choose the character
		return the character number that player 1 has chosen
	*/
}

int GameMenu::Player2ChooseCharacter(void)
{
	/*
		Player 2 choose the character 
		return the character number that player 2 has chosen
	*/
}