#include "game.h"
#include "fssimplewindow.h"
#include "player.h"

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
	FsPollDevice(); 
	int key = FsInkey();
	switch (key) {
	case FSKEY_ESC: // exit the game 
		setExit();
		break; 
	
	// player 2 moves 
	case FSKEY_W: // jump 
		break;
	case FSKEY_A: // move left 
		break;
	case FSKEY_S: // move right 
		break;
	case FSKEY_D: // punch 
		break;

	// player 2 moves 
	case FSKEY_I: // jump 
		break;
	case FSKEY_J: // move left 
		break;
	case FSKEY_K: // move right 
		break; 
	case FSKEY_L: // punch 
		break; 
	default:
		break; 
	}
    printf("p1 attack: %d\n",p1.getAttack());
    printf("p2 attack: %d\n",p2.getAttack());
}
