#include "game.h"
#include "fssimplewindow.h"
#include "player.h"
#include <time.h>
#include "fssimplewindow.h"
#include "yssimplesound.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include "time.h"
#include "HP.h"
#include "random_boost_item.h"

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

// void DrawCircle(int cx,int cy,int rad)
// {
//     const double pi=3.14159265;
//     glColor3ub(0,0,0);
//     glBegin(GL_LINE_LOOP);

//     for(int a=0; a<64; ++a)
//     {
//         double radian=(double)a*2.0*pi/64.0;
//         double c=cos(radian);
//         double s=sin(radian);

//         double x=(double)cx+c*(double)rad;
//         double y=(double)cy+s*(double)rad;

//         glVertex2d(x,y);
//     }

//     glEnd();
// }

// void DrawKneel(int xc,int yc)
// {
//     // int x[13],y[13];
//     int x[13]={10,14,14,25,46,38,24,24,34,34,45,44,55};
//     int y[13]={27,16,5,26,20,10,13,9,5,2,0,11,7};

//     for (int i = 0; i < 13; ++i)
//     {
//         x[i]*=5;
//         y[i]*=5;
//     }
//     // DrawCircle(xc+x[0],yc-y[0],10*5);
//     glColor3ub(0,0,0);
//     glBegin(GL_LINE_LOOP);
//     glVertex2i(xc+x[1],yc-y[1]);
//     glVertex2i(xc+x[3],yc-y[3]);
//     glVertex2i(xc+x[4],yc-y[4]);
//     glVertex2i(xc+x[5],yc-y[5]);
//     // glVertex2i(xc+x[1],yc-y[1]);
//     glEnd();
//     glBegin(GL_LINES);
//     glVertex2i(xc+x[1],yc-y[1]);
//     glVertex2i(xc+x[2],yc-y[2]);
//     glEnd();
//     glBegin(GL_LINES);
//     glVertex2i(xc+x[6],yc-y[6]);
//     glVertex2i(xc+x[7],yc-y[7]);
//     glEnd();
//     glBegin(GL_LINES);
//     glVertex2i(xc+x[5],yc-y[5]);
//     glVertex2i(xc+x[8],yc-y[8]);
//     glVertex2i(xc+x[8],yc-y[8]);
//     glVertex2i(xc+x[9],yc-y[9]);
//     glVertex2i(xc+x[9],yc-y[9]);
//     glVertex2i(xc+x[10],yc-y[10]);
//     glEnd();
//     glBegin(GL_LINES);
//     glVertex2i(xc+x[4],yc-y[4]);
//     glVertex2i(xc+x[11],yc-y[11]);
//     glVertex2i(xc+x[11],yc-y[11]);
//     glVertex2i(xc+x[12],yc-y[12]);
//     glEnd();
// }

void Game::SetCharacter(int pn1, int pn2){
    p1.SetCharacter(pn1);
    p2.SetCharacter(pn2);
    p1.body.SetPic(pn1);
    p2.body.SetPic(pn2);
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
    
    if(p1>p2)
    {
        winner = 1;
    }else if(p1<p2)
    {
        winner = 2;
    }else
    {
        winner = 0;
    }
    
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

int Game::getWinner(void){
    return winner;
}

void Game::setLastDecade(int decade){
    lastDecade = decade;
}
void Game::setLastUnit(int unit){
    lastUnit = unit;
}
int Game::getLastDecade(void){
    return lastDecade;
}
int Game::getLastUnit(void){
    return lastUnit;
}

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
        timer.tictoc();
        decade = (int)(timer.sum + 1) / 10;
        unit = (int)(timer.sum + 1) - decade * 10;
        if (decade == 0 && unit == 0) {
            termination = 1;
            setTimeout();
        }
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
            //printf("p1 is punching");
            p1.Punch();
            
            if (p1.IfPunchHit(p2) && p2.GetHitState() != true)
            {
                p2.ChangeHitState(); 
                p2.HPchange(-p1.getAttack()); 
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
            //printf("p2 is punching");
            p2.Punch();
            
            if (p2.IfPunchHit(p1) && p1.GetHitState() != true)
            {
                p1.ChangeHitState();
                p1.HPchange(-p2.getAttack());
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

		item.CheckConsume(p1);
		item.CheckConsume(p2);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        
        p1.Draw(p2);
        p2.Draw(p1);
		item.Draw(); 
		item.Update(); 

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
        setLastDecade(decade);
        setLastUnit(unit);
        FsSwapBuffers();
        FsSleep(10);
        
        p1.backtoScreen();
        p2.backtoScreen();
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

void Game::End(void){
    // printf("here\n");
    for(;;)
    {
        FsPollDevice();
        int key=FsInkey();
        
        if(FSKEY_ESC==key)
        {
            return;
        }

        glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

        glColor3ub(255,0,0);
        glRasterPos2i(300,200);
        // YsGlDrawFontBitmap32x48("GAME OVER");
        // glRasterPos2i(100,240);
        int xc_lose = 500;
        int yc_lose = 500;
        if(winner==1)
        {
            YsGlDrawFontBitmap32x48("PLAYER 1 WINS !");
            xc_lose = p2.getX()-24*5;
            yc_lose = p2.getY()+13*5;
        }else if(winner==2)
        {
            YsGlDrawFontBitmap32x48("PLAYER 2 WINS !");
            xc_lose = p1.getX()-24*5;
            yc_lose = p1.getY()+13*5;
        }
        
        // glRasterPos2i(100,240);
        // YsGlDrawFontBitmap20x32("S......START");
        // glRasterPos2i(100,280);
        // YsGlDrawFontBitmap20x32("H......HELP");
        // glRasterPos2i(100,320);
        // YsGlDrawFontBitmap20x32("ESC....CLOSE"); 


    // int x[13],y[13];
        int x[13]={10,14,14,25,46,38,24,24,34,34,45,44,55};
        // printf("winner=%d,x1=%d,p2=%d\n",winner, p1.getX(), p2.getX());
        // if((winner==1 && p2.getX()>p1.getX()) || (winner==2 && p1.getX()>p2.getX()))
        // {
        //     // face left
        // }else 
        if((winner==1 && p2.getX()<p1.getX()) || (winner==2 && p1.getX()<p2.getX()))
        {
            for (int i = 0; i < 13; ++i)
            {
                x[i]=48-x[i]; // face right
            }
            // x[13]={38,32,32,23,2,10,24,24,14,14,3,4,-7};
        }
    
    int y[13]={27,16,5,26,20,10,13,9,5,2,0,11,7};

    for (int i = 0; i < 13; ++i)
    {
        x[i]*=5;
        y[i]*=5;
        y[i]-=100;
    }
    // DrawCircle(xc+x[0],yc-y[0],10*5);
    // int xc=500;
    // int yc=500;
    int rad=10*5;


    const double pi=3.14159265;
    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);

    for(int a=0; a<64; ++a)
    {
        double radian=(double)a*2.0*pi/64.0;
        double c=cos(radian);
        double s=sin(radian);

        double xx=(double)(xc_lose+x[0])+c*(double)rad;
        double yy=(double)(yc_lose-y[0])+s*(double)rad;

        glVertex2d(xx,yy);
    }

    glEnd();


    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(xc_lose+x[1],yc_lose-y[1]);
    glVertex2i(xc_lose+x[3],yc_lose-y[3]);
    glVertex2i(xc_lose+x[4],yc_lose-y[4]);
    glVertex2i(xc_lose+x[5],yc_lose-y[5]);
    // glVertex2i(xc_lose+x[1],yc_lose-y[1]);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(xc_lose+x[1],yc_lose-y[1]);
    glVertex2i(xc_lose+x[2],yc_lose-y[2]);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(xc_lose+x[6],yc_lose-y[6]);
    glVertex2i(xc_lose+x[7],yc_lose-y[7]);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(xc_lose+x[5],yc_lose-y[5]);
    glVertex2i(xc_lose+x[8],yc_lose-y[8]);
    glVertex2i(xc_lose+x[8],yc_lose-y[8]);
    glVertex2i(xc_lose+x[9],yc_lose-y[9]);
    glVertex2i(xc_lose+x[9],yc_lose-y[9]);
    glVertex2i(xc_lose+x[10],yc_lose-y[10]);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(xc_lose+x[4],yc_lose-y[4]);
    glVertex2i(xc_lose+x[11],yc_lose-y[11]);
    glVertex2i(xc_lose+x[11],yc_lose-y[11]);
    glVertex2i(xc_lose+x[12],yc_lose-y[12]);
    glEnd();



        // DrawKneel(500,500);
        DrawHpBar(hp_bar.GetHP_left(), hp_bar.GetHP_right());
        DrawTimer(getLastDecade(), getLastUnit());
        FsSwapBuffers();

        FsSleep(25);
    }
}