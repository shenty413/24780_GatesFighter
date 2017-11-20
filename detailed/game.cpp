#include "game.h"
#include "fssimplewindow.h"
#include "player.h"
#include <time.h>

void Game::SetCharacter(int pn1, int pn2){
    p1.SetCharacter(pn1);
    p2.SetCharacter(pn2);
}

const bool Game::isExit(void) const {
	return exit; 
};

const bool Game::isTimeout(void) const {
	return timeout;
};

const bool Game::isKo(void) const {
	return ko;
};

void Game::setExit(void) {
	exit = true;
}

void Game::setTimeout(void) {
	timeout = true;
}

void Game::setKo(void) {
	ko = true;
}

void Game::Run(){
	// wait for a key stroke 
	int termination = 0;
	int punch_timer = 0; 
	int punch_process = 0; 
	int timer = (int)time(NULL);
	while (termination==0) {
		// printf("1");
		FsPollDevice();
		int key = FsInkey();
		switch (key) {
		case FSKEY_ESC: // exit the game 
			setExit();
			termination = 1;
			break;

			// player 2 moves 
		case FSKEY_W: // jump 
			// if not jumping, jump 
			break;
		case FSKEY_A: // move left 
			// if punching, cannot move  
			break;
		case FSKEY_S: // move right 
			// if punching, cannot move  
			break;
		case FSKEY_D: // punch 
			break;

			// player 2 moves 
		case FSKEY_I: // jump 
			// if not jumping, jump
			break;
		case FSKEY_J: // move left 
			// if punching, cannot move  
			break;
		case FSKEY_K: // move right 
			// if punching, cannot move  
			break;
		case FSKEY_L: // punch 
			// if not punching, punch 
			if (p2.IsPunching())
			{
				punch_timer = 0;
			}
			break;
		default:
			break;
		}
		// player 1 punching 
		if (p1.IsPunching()) 
		{				

			p1.Punch();
			if (p1.IfPunchHit(p2)) 
			{
			
			}
			if (p1.CheckFinishPunching())
			{

			}
		}
		// player 1 jumping 
		if (p1.IsJumping()) 
		{
			
		}
		// player 2 jumping 
		if (p2.IsPunching()) 
		{
		
		}
		// player 2 punching 
		if (p2.IsJumping()) 
		{
		
		}

		// count time, check if time runs out 
		int current_time = (int)time(NULL);
		if (current_time - timer >= 20)
			termination = 1;
	}
    printf("p1 attack: %d\n",p1.getAttack());
    printf("p2 attack: %d\n",p2.getAttack());
}
