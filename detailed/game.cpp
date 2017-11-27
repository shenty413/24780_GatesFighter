#include "game.h"
#include "fssimplewindow.h"
#include "player.h"
#include <time.h>
#include "fssimplewindow.h"
#include "yssimplesound.h"

void musicplayer( YsSoundPlayer &player, YsSoundPlayer::SoundData &punch,
                          YsSoundPlayer::SoundData &moaning, YsSoundPlayer::SoundData &running,
						  YsSoundPlayer::SoundData &backgnd)
{
    /* The sound player object must be made current and started before playing a sound data. */
    /* Make sure to do this after opening a Window. */
    player.MakeCurrent();
    player.Start();
    /* The point is you first need to add a folder reference, not a group, to your project before adding to
     the copy files phase. */
    FsChangeToProgramDir();
    
    
    // Use LoadWav function for loading a .WAV file to the variable.
    // Just in case you ended up copying datafiles directory instead of individual files,
    
    /* load running sound */
    if(YSOK != running.LoadWav("running.wav") &&
       YSOK != running.LoadWav("datafiles/running.wav"))
    {
        printf("Error!  Cannot load running.wav!\n");
    }
    /* load moaning sound */
    if(YSOK!= moaning.LoadWav("moaning.wav") &&
       YSOK!= moaning.LoadWav("datafiles/moaning.wav"))
    {
        printf("Error!  Cannot load moaning.wav!\n");
    }
    /* load punch sound */
    if(YSOK!= punch.LoadWav("punch.wav") &&
       YSOK!= punch.LoadWav("datafiles/punch.wav"))
    {
        printf("Error!  Cannot load punch.wav!\n");
    }
	/* load background music*/
	if (YSOK != backgnd.LoadWav("backgnd.wav")
		&& YSOK != backgnd.LoadWav("datafiles/backgnd.wav")) {
		printf("Error! Cannot load backgnd.wav!\n");
	}
	printf("Wav file reading successful.\n");
}

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
	printf("\n\n\n\nSound player?\n\n\n\n");
	
    YsSoundPlayer::SoundData punch,moaning,running, backgnd;
    YsSoundPlayer player;

    musicplayer(player, punch, moaning, running, backgnd);
	

    int termination = 0;
    int punch_timer = 0;
    int punch_process = 0;
    int timer = (int)time(NULL);
    while (termination==0) {
        FsPollDevice();
        int key = FsInkey();
        switch (key) {
            case FSKEY_ESC: // exit the game
                setExit();
                termination = 1;
                break;
                
                // player 1 moves
            case FSKEY_W: // jump
				// if not jumping, jump
				if (p1.IsJumping()!=true) 
				{
					p1.InitializeJumping(); 
					/* play move sound */
					//player.Stop(running);
					//player.PlayOneShot(running);
				}
				
                break;
            case FSKEY_A: // move left
				if (p1.IsPunching() != true) 
				{
					p1.ChangeDirc(1);
					p1.Move(); 
					// if punching, cannot move
					/* if moved, play running sound */
					//player.Stop(running);
					//player.PlayOneShot(running);
				}
               
                break;
            case FSKEY_S: // move right
				if (p1.IsPunching() != true)
				{
					p1.ChangeDirc(0);
					p1.Move();
					// if punching, cannot move
					/* if moved, play running sound */
					//player.Stop(running);
					//player.PlayOneShot(running);
				}
                break;

            case FSKEY_D: // punch
				// if not punching, punch 
				if (p1.IsPunching() != true)
				{
					p1.InitializePunching();
					/* if punch, play punch sound */
					//player.Stop(punch);
					//player.PlayOneShot(punch);
				}
                break;
				/* press Key B to play background music*/
			case FSKEY_B:
				player.PlayBackground(backgnd);
				break;
               /* press key P to stop background music*/
			case FSKEY_P:
				player.Stop(backgnd);
				break;
				// player 2 moves
            case FSKEY_I: // jump
				// if not jumping, jump
				if (p2.IsJumping() != true)
				{
					p2.InitializeJumping();
					/* play move sound */
					//player.Stop(running);
					//player.PlayOneShot(running);
				}
				break;

            case FSKEY_J: // move left
				if (p2.IsPunching() != true)
				{
					p2.ChangeDirc(1);
					p2.Move();
					// if punching, cannot move
					/* if moved, play running sound */
					//player.Stop(running);
					//player.PlayOneShot(running);
				}
				break;

            case FSKEY_K: // move right
				// if punching, cannot move
				if (p2.IsPunching() != true)
				{
					p2.ChangeDirc(0);
					p2.Move();
					/* if moved, play running sound */
					//player.Stop(running);
					//player.PlayOneShot(running);
				}
				break;

            case FSKEY_L: // punch
				// if not punching, punch 
				if (p1.IsPunching() != true)
				{
					p1.InitializePunching();
					/* if punch, play punch sound */
					//player.Stop(punch);
					//player.PlayOneShot(punch);
				}
				break;

            default:
                break;
        }
        // player 1 punching
        if (p1.IsPunching())
        {
            
            p1.Punch();
			/* if punch, play punch sound */
			//player.Stop(punch);
			//player.PlayOneShot(punch);

			if (p1.IfPunchHit(p2) && p2.GetHitState() != true)
            {
				p2.ChangeHitState(); 
				p2.HPchange(p1.getAttack()); 
                /* if hit, play moaning sound */
                //player.Stop(moaning);
                //player.PlayOneShot(moaning);
            }

            /*
			if (p1.CheckFinishPunching())
            {
				// if punch finished, change player punch state back to 0
                
            }
			*/
        }
        // player 1 jumping
        if (p1.IsJumping())
        {
			p1.Jump();
            /* play move sound */
            //player.Stop(running);
            //player.PlayOneShot(running);

			// check if jumping
			p1.CheckHitGround(); 
				
        }
        // player 2 punching
        if (p2.IsPunching())
        {
			p2.Punch();
			/* if punch, play punch sound */
			//player.Stop(punch);
			//player.PlayOneShot(punch);

			if (p2.IfPunchHit(p1) && p1.GetHitState() != true)
			{
				p1.ChangeHitState();
				p1.HPchange(p2.getAttack());
				/* if hit, play moaning sound */
				//player.Stop(moaning);
				//player.PlayOneShot(moaning);
			}

			/*
			if (p2.CheckFinishPunching())
			{


			}
			*/
        }
        // player 2 jumping
        if (p2.IsJumping())
        {
			p2.Jump();
            /* if punch, play punch sound */
			//player.Stop(punch);
			//player.PlayOneShot(punch);
			p2.CheckHitGround();
        }
        
        // count time, check if time runs out
        int current_time = (int)time(NULL);
        if (current_time - timer >= 20)
            termination = 1;
    }
    printf("p1 attack: %d\n",p1.getAttack());
    printf("p2 attack: %d\n",p2.getAttack());
}
