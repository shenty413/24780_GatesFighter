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
    int key, T;
    bool terminate = 0;
    while (!terminate){
        FsPollDevice();
        key = FsInkey();
        switch (key) {
            case FSKEY_ESC: // exit the game
                setExit();
                terminate = 1;
                break;
	
                // player 2 moves
            case FSKEY_W: // jump
                if (!p1.IsJumping()){
                    //p1.CheckHitGround();
                    p1.InitializeJumping();
                    p1.Jump();
                }
                break;
            case FSKEY_A: // move left
                p1.Move(-20);
                p1.ChangeDirc(1);
                break;
            case FSKEY_S: // move right
                break;
            case FSKEY_D: // punch
                p1.Move(20);
                p1.ChangeDirc(0);
                break;

        }
        
        glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
        
        p1.Draw();
        FsSwapBuffers();
        
    }
    printf("p1 attack: %d\n",p1.getAttack());
    printf("p2 attack: %d\n",p2.getAttack());
}
