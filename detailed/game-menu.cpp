#include <stdio.h>
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include <math.h>
#include "game-menu.h"

void DrawRectangle(int x,int y,int w,int h)
{
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2i(x  ,y  );
    glVertex2i(x+w,y  );
    glVertex2i(x+w,y+h);
    glVertex2i(x  ,y+h);
    glEnd();
}

void DrawCircle(int cx,int cy,int rad)
{
	const double pi=3.14159265;
    glColor3ub(0,0,0);
	glBegin(GL_LINE_LOOP);

	for(int a=0; a<64; ++a)
	{
		double radian=(double)a*2.0*pi/64.0;
		double c=cos(radian);
		double s=sin(radian);

		double x=(double)cx+c*(double)rad;
		double y=(double)cy+s*(double)rad;

		glVertex2d(x,y);
	}

	glEnd();
}

void DrawArrow(int x,int y,int s,int r,int g,int b)
{
    glColor3ub(r,g,b);
    glBegin(GL_QUADS);
    glVertex2i(x-5*s,y 	   );
    glVertex2i(x-5*s,y+40*s);
    glVertex2i(x+5*s,y+40*s);
    glVertex2i(x+5*s,y     );
    glEnd();

    glColor3ub(r,g,b);
    glBegin(GL_TRIANGLES);
    glVertex2i(x     ,y+55*s);
    glVertex2i(x-15*s,y+40*s);
    glVertex2i(x+15*s,y+40*s);
    glEnd();
}

void DrawKneel(int xc,int yc)
{
	// int x[13],y[13];
	int x[13]={10,14,14,25,46,38,24,24,34,34,45,44,55};
	int y[13]={27,16,5,26,20,10,13,9,5,2,0,11,7};

	for (int i = 0; i < 13; ++i)
	{
		x[i]*=5;
		y[i]*=5;
	}
	DrawCircle(xc+x[0],yc-y[0],10*5);
	glColor3ub(0,0,0);
	glBegin(GL_LINE_LOOP);
    glVertex2i(xc+x[1],yc-y[1]);
    glVertex2i(xc+x[3],yc-y[3]);
    glVertex2i(xc+x[4],yc-y[4]);
    glVertex2i(xc+x[5],yc-y[5]);
    // glVertex2i(xc+x[1],yc-y[1]);
    glEnd();
	glBegin(GL_LINES);
    glVertex2i(xc+x[1],yc-y[1]);
    glVertex2i(xc+x[2],yc-y[2]);
    glEnd();
	glBegin(GL_LINES);
    glVertex2i(xc+x[6],yc-y[6]);
    glVertex2i(xc+x[7],yc-y[7]);
    glEnd();
	glBegin(GL_LINES);
    glVertex2i(xc+x[5],yc-y[5]);
    glVertex2i(xc+x[8],yc-y[8]);
    glVertex2i(xc+x[8],yc-y[8]);
    glVertex2i(xc+x[9],yc-y[9]);
    glVertex2i(xc+x[9],yc-y[9]);
    glVertex2i(xc+x[10],yc-y[10]);
    glEnd();
	glBegin(GL_LINES);
    glVertex2i(xc+x[4],yc-y[4]);
    glVertex2i(xc+x[11],yc-y[11]);
    glVertex2i(xc+x[11],yc-y[11]);
    glVertex2i(xc+x[12],yc-y[12]);
    glEnd();
}

// void DrawCharacter()

void GameMenu::RunGameMenu(void)
{
	for(;;)
	{
		FsPollDevice();
		key=FsInkey();

		if(FSKEY_ESC==key || FSKEY_S==key || FSKEY_H==key)
		{
			return;
		}
		
		glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

		glColor3ub(0,255,0);
		glRasterPos2i(100,100);
		YsGlDrawFontBitmap32x48("GATES FIGHTER");
		glRasterPos2i(100,240);
		YsGlDrawFontBitmap20x32("S......START");
		glRasterPos2i(100,280);
		YsGlDrawFontBitmap20x32("H......HELP");
		glRasterPos2i(100,320);
		YsGlDrawFontBitmap20x32("ESC....CLOSE");	

		FsSwapBuffers();

		FsSleep(25);
	}
}

void GameMenu::Help(void)
{
	for(;;)
	{
		FsPollDevice();
		key=FsInkey();

		if(FSKEY_ESC==key)
		{
			return;
		}	
		glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
		glColor3ub(0,255,0);
		glRasterPos2i(100,60 );
		YsGlDrawFontBitmap20x32("Player 1");
		glRasterPos2i(100,120);
		YsGlDrawFontBitmap16x24("Left = A");
		glRasterPos2i(100,160);
		YsGlDrawFontBitmap16x24("Right = D");
		glRasterPos2i(100,200);
		YsGlDrawFontBitmap16x24("Jump = W");
		glRasterPos2i(100,240);
		// YsGlDrawFontBitmap16x24("Crouch = Down");
		// glRasterPos2i(500,120);
		YsGlDrawFontBitmap16x24("Punch = S");
		// glRasterPos2i(500,160);
		// YsGlDrawFontBitmap16x24("Kick = .>");
		// glRasterPos2i(100,240);
		// YsGlDrawFontBitmap16x24("Jump = Up");
		// glRasterPos2i(100,280);
		// YsGlDrawFontBitmap16x24("Crouch = Down");

		glColor3ub(0,255,0);
		glRasterPos2i(100,360);
		YsGlDrawFontBitmap20x32("Player 2");
		glRasterPos2i(100,420);
		YsGlDrawFontBitmap16x24("Left = J");
		glRasterPos2i(100,460);
		YsGlDrawFontBitmap16x24("Right = L");
		glRasterPos2i(100,500);
		YsGlDrawFontBitmap16x24("Jump = I");
		glRasterPos2i(100,540);
		// YsGlDrawFontBitmap16x24("Crouch = S");
		// glRasterPos2i(500,420);
		YsGlDrawFontBitmap16x24("Punch = K");
		// glRasterPos2i(500,460);
		// YsGlDrawFontBitmap16x24("Kick = 1!");
		// glRasterPos2i(100,540);
		// YsGlDrawFontBitmap16x24("Jump = W");
		// glRasterPos2i(100,580);
		// YsGlDrawFontBitmap16x24("Crouch = S");
		FsSwapBuffers();
		FsSleep(25);
	}
}

int GameMenu::Player1ChooseCharacter(void)
{
	int ArrowPosition=1;
	for(;;)
	{
		FsPollDevice();
		key=FsInkey();

		if(FSKEY_ESC==key)
		{
			return 0;
		} else if(FSKEY_Y==key)
		{
			return ArrowPosition;
		}

		if(FSKEY_RIGHT==key)
		{
			ArrowPosition++;
			if (ArrowPosition>=4)
			{
				ArrowPosition=4;
			}
		}
		if(FSKEY_LEFT==key)
		{
			ArrowPosition--;
			if (ArrowPosition<=1)
			{
				ArrowPosition=1;
			}
		}

		glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
		glColor3ub(255,0,0);
		glRasterPos2i(100,140);
		YsGlDrawFontBitmap20x32("Player 1: choose your character");
		glRasterPos2i(100,170);
		YsGlDrawFontBitmap16x20("(Press Y to enter)");
		// glRasterPos2i(100,140);
		// YsGlDrawFontBitmap20x32("Y......Choose your character");

		DrawArrow(200*(ArrowPosition-1)+100,200,1,255,0,0);
		DrawRectangle( 40,300,120,180); // character 1
		DrawRectangle(240,300,120,180);
		DrawRectangle(440,300,120,180);
		DrawRectangle(640,300,120,180);

		FsSwapBuffers();

		FsSleep(25);
	}
}

int GameMenu::Player2ChooseCharacter(void)
{
	int ArrowPosition=1;
	for(;;)
	{
		FsPollDevice();
		key=FsInkey();

		if(FSKEY_ESC==key)
		{
			return 0;
		} else if(FSKEY_Y==key)
		{
			return ArrowPosition;
		}

		if(FSKEY_RIGHT==key)
		{
			ArrowPosition++;
			if (ArrowPosition>=4)
			{
				ArrowPosition=4;
			}
		}
		if(FSKEY_LEFT==key)
		{
			ArrowPosition--;
			if (ArrowPosition<=1)
			{
				ArrowPosition=1;
			}
		}

		glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
		glColor3ub(0,0,255);
		glRasterPos2i(100,140);
		YsGlDrawFontBitmap20x32("Player 2: choose your character");
		glRasterPos2i(100,170);
		YsGlDrawFontBitmap16x20("(Press Y to enter)");
		// glRasterPos2i(100,140);
		// YsGlDrawFontBitmap20x32("Y......Choose your character");

		DrawArrow(200*(ArrowPosition-1)+100,200,1,0,0,255);
		DrawRectangle( 40,300,120,180); // character 1
		DrawRectangle(240,300,120,180);
		DrawRectangle(440,300,120,180);
		DrawRectangle(640,300,120,180);

		FsSwapBuffers();

		FsSleep(25);
	}
}

void GameMenu::End(int No)
{
	for(;;)
	{
		FsPollDevice();
		key=FsInkey();
		
		if(FSKEY_ESC==key)
		{
			return;
		}

		glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

		glColor3ub(0,255,0);
		glRasterPos2i(100,100);
		YsGlDrawFontBitmap32x48("GAME OVER");
		glRasterPos2i(100,240);
		if(No==1)
		{
			YsGlDrawFontBitmap32x48("PLAYER 1 WINS");
		}else if(No==2)
		{
			YsGlDrawFontBitmap32x48("PLAYER 2 WINS");
		}
		
		// glRasterPos2i(100,240);
		// YsGlDrawFontBitmap20x32("S......START");
		// glRasterPos2i(100,280);
		// YsGlDrawFontBitmap20x32("H......HELP");
		// glRasterPos2i(100,320);
		// YsGlDrawFontBitmap20x32("ESC....CLOSE");	
		DrawKneel(500,500);

		FsSwapBuffers();

		FsSleep(25);
	}
}
