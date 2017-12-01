#include "game.h"
#include "fssimplewindow.h"
#include "player.h"
#include <time.h>
#include "fssimplewindow.h"
#include "yssimplesound.h"
#include <stdlib.h>
#include <stdio.h>
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include "time.h"
#include "HP.h"

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

void Game::DrawHpBar(int hp1, int hp2) {
    
    double p1 = (double)hp1 / 100;
    double p2 = (double)hp2 / 100;
    
    glColor3ub(0, 255, 0);
    glRasterPos2i(80, 100);
    YsGlDrawFontBitmap20x32("fighter1");
    glRasterPos2i(800, 100);
    YsGlDrawFontBitmap20x32("fighter2");
    /* draw HP bar of p1 */
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(10, 20);
    glVertex2i(10, 50);
    glVertex2i(310, 50);
    glVertex2i(310, 20);
    glEnd();
    
    /* red part */
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(10, 20);
    glVertex2i(10, 50);
    glVertex2i(310 * p1, 50);
    glVertex2i(310 * p1, 20);
    glEnd();
    
    /* draw HP bar of p2 */
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(1014, 20);
    glVertex2i(1014, 50);
    glVertex2i(714, 50);
    glVertex2i(714, 20);
    glEnd();
    
    /* draw red part */
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(1014, 20);
    glVertex2i(1014, 50);
    glVertex2i(714 + 300 * (1 - p2), 50);
    glVertex2i(714 + 300 * (1 - p2), 20);
    glEnd();
};

void Game::Run(){

    // wait for a key stroke
	printf("\n\n\n\nSound player?\n\n\n\n");
	
    YsSoundPlayer::SoundData punch,moaning,running, backgnd;
    YsSoundPlayer player;

    musicplayer(player, punch, moaning, running, backgnd);
	
    Time timer(1, 30);
    int termination = 0;
    int punch_timer = 0;
    int punch_process = 0;
    int decade, unit;
    timer.setTime();
    //printf("sum = %lf", timer.sum);
   // int timer = (int)time(NULL);
    //glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //FsOpenWindow(16,16,800,600,1);
    //glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	while (termination == 0) {
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
			if (p1.IsJumping() != true)
			{
				p1.InitializeJumping();
				/* play move sound */
				player.Stop(running);
				player.PlayOneShot(running);
			}

			break;
		case FSKEY_A: // move left
			// if punching, cannot move
			if (p1.IsPunching() != true)
			{
				p1.ChangeDirc(1);

				if (p1.getLowerBanMoveBoundary() <= p2.getUpperBanMoveBoundary())
				{
					p1.Move();
				}
				else if (p1.getLeftBanMoveBoundary() >= p2.getRightBanMoveBoundary() )
				{
					p1.Move();
				}
				else if ( p1.getLeftBanMoveBoundary() <= p2.getLeftBanMoveBoundary())
				{
					p1.Move();
				}

				/* if moved, play running sound */
				player.Stop(running);
				player.PlayOneShot(running);
			}

			break;
		case FSKEY_D: // move right
			// if punching, cannot move
			if (p1.IsPunching() != true)
			{
				p1.ChangeDirc(0);
				if (p1.getLowerBanMoveBoundary() <= p2.getUpperBanMoveBoundary())
				{
					p1.Move();
				}
				else if (p1.getRightBanMoveBoundary() <= p2.getLeftBanMoveBoundary())
				{
					p1.Move();
				}
				else if (p1.getRightBanMoveBoundary() >= p2.getRightBanMoveBoundary())
				{
					p1.Move();
				}
				/* if moved, play running sound */
				player.Stop(running);
				player.PlayOneShot(running);
			}
			break;

		case FSKEY_S: // punch
			// if not punching, punch 
			if (p1.IsPunching() != true)
			{
				p1.InitializePunching();
				/* if punch, play punch sound */
				player.Stop(punch);
				player.PlayOneShot(punch);
			}
			break;

			// player 2 moves
		case FSKEY_I: // jump
			// if not jumping, jump
			if (p2.IsJumping() != true)
			{
				p2.InitializeJumping();
				/* play move sound */
				player.Stop(running);
				player.PlayOneShot(running);
			}
			break;

		case FSKEY_J: // move left
			if (p2.IsPunching() != true)
			{
				p2.ChangeDirc(1);
				if (p2.getLowerBanMoveBoundary() <= p1.getUpperBanMoveBoundary())
				{
					p2.Move();
				}
				else if (p2.getLeftBanMoveBoundary() >= p1.getRightBanMoveBoundary())
				{
					p2.Move();
				}
				else if (p2.getLeftBanMoveBoundary() <= p1.getLeftBanMoveBoundary())
				{
					p2.Move();
				}
				//p2.Move();
				// if punching, cannot move
				/* if moved, play running sound */
				player.Stop(running);
				player.PlayOneShot(running);
			}
			break;

		case FSKEY_L: // move right
			// if punching, cannot move
			if (p2.IsPunching() != true)
			{
				p2.ChangeDirc(0);
				if (p2.getLowerBanMoveBoundary() <= p1.getUpperBanMoveBoundary())
				{
					p2.Move();
				}
				else if (p2.getRightBanMoveBoundary() <= p1.getLeftBanMoveBoundary())
				{
					p2.Move();
				}
				else if (p2.getRightBanMoveBoundary() >= p1.getRightBanMoveBoundary())
				{
					p2.Move();
				}
				p2.Move();
				/* if moved, play running sound */
				player.Stop(running);
				player.PlayOneShot(running);
			}
			break;

		case FSKEY_K: // punch
			// if not punching, punch 
			if (p2.IsPunching() != true)
			{
				p2.InitializePunching();
				/* if punch, play punch sound */
				player.Stop(punch);
				player.PlayOneShot(punch);
			}
			break;

			// music functions 
			/* press Key B to play background music*/
		case FSKEY_B:
			player.PlayBackground(backgnd);
			break;

			/* press key P to stop background music*/
		case FSKEY_P:
			player.Stop(backgnd);
			break;
		}


		// player motions and logic behind interactions  
        // player 1 punching
        if (p1.IsPunching())
        {
            printf("p1 is punching");
            p1.Punch();

			if (p1.IfPunchHit(p2) && p2.GetHitState() != true)
            {
				p2.ChangeHitState(); 
				p2.HPchange(p1.getAttack()); 
                /* if hit, play moaning sound */
                player.Stop(moaning);
                player.PlayOneShot(moaning);
                // p2.ChangeHitState(); 
            }

        }
        // player 1 jumping
        if (p1.IsJumping())
        {
			p1.Jump();

			// check if jumping
			p1.CheckHitGround(); 
				
        }
        // player 2 punching
        if (p2.IsPunching())
        {
            printf("p2 is punching");
			p2.Punch();

			if (p2.IfPunchHit(p1) && p1.GetHitState() != true)
			{
				p1.ChangeHitState();
				p1.HPchange(p2.getAttack());
				/* if hit, play moaning sound */
				player.Stop(moaning);
				player.PlayOneShot(moaning);
				// p1.ChangeHitState();
			}

        }
        // player 2 jumping
        if (p2.IsJumping())
        {
			p2.Jump();
			p2.CheckHitGround();
        }
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

        p1.Draw();
        p2.Draw();
        
		// boundary 
		/*
		glColor3d(1, 0, 0);
		glBegin(GL_LINES);
		glVertex2i(p2.getLeftBoundary(), 0);
		glVertex2i(p2.getLeftBoundary(), 1000);
		glEnd();

		glColor3d(0, 0, 1);
		glBegin(GL_LINES);
		glVertex2i(p2.getRightBoundary(), 0);
		glVertex2i(p2.getRightBoundary(), 1000);
		glEnd();
		*/
		p1.ResetWalkState();
		p2.ResetWalkState();

		
		// hp swap mechanism
		if (p1.getX() < p2.getX()) 
		{
			hp_bar.SetHP_left(p1.GetHP());
			hp_bar.SetHP_right(p2.GetHP());
		}
		else 
		{
			hp_bar.SetHP_left(p2.GetHP());
			hp_bar.SetHP_right(p1.GetHP());
		}

		// draw hp bars 
		DrawHpBar(hp_bar.GetHP_left(), hp_bar.GetHP_right());
        DrawTimer(decade, unit);
		FsSwapBuffers();
		FsSleep(10);


		// termination flags 

		// count time, check if time runs out
		/*int current_time = (int)time(NULL);
		if (current_time - timer >= 20) 
		{
			termination = 1;
			setTimeout(); 
		}*/
            

		// check if either player's hp is 0 
		if (p1.GetHP() <= 0 || p2.GetHP() <= 0) 
		{
			termination = 1; 
			setKo(); 
		}
		// printf("test\n");
    }
    
}
