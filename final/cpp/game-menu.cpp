#include <stdio.h>
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include <math.h>
#include "game-menu.h"
#include <string>

void GameMenu::LoadPNG(std::string fileName, YsRawPngDecoder *target){
    if(YSOK == target->Decode(fileName.c_str()))
    {
        target->Flip();
        printf("%dx%d\n",target->wid,target->hei);
    }
    else
    {
        printf("Cannot open file %s.\n", fileName.c_str());
    }
}

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
    LoadPNG("title.png", &title);
    LoadPNG("instructions.png", &instructions);
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
		glRasterPos2i(150,300);
        glDrawPixels(title.wid,title.hei,GL_RGBA,GL_UNSIGNED_BYTE,title.rgba);
        
        /*
        glRasterPos2i(100,240);
		YsGlDrawFontBitmap20x32("S......START");
        
		glRasterPos2i(100,280);
		YsGlDrawFontBitmap20x32("H......HELP");
         */
        
		glRasterPos2i(250,630);
        glDrawPixels(instructions.wid,instructions.hei,GL_RGBA,GL_UNSIGNED_BYTE,instructions.rgba);

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
    LoadPNG("p1select.png", &p1select);
    LoadPNG("styCard.png", &sty);
    LoadPNG("zwyCard.png", &zwy);
    LoadPNG("zzhCard.png", &zzh);
    LoadPNG("czlCard.png", &czl);
    LoadPNG("ltyCard.png", &lty);

    
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
			if (ArrowPosition>=5)
			{
				ArrowPosition=5;
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
		glRasterPos2i(100,240);
        glDrawPixels(p1select.wid,p1select.hei,GL_RGBA,GL_UNSIGNED_BYTE,p1select.rgba);
        
		DrawArrow(190*(ArrowPosition-1)+125,260,1,255,0,0);
        
        glRasterPos2i(40,700);
        glDrawPixels(sty.wid,sty.hei,GL_RGBA,GL_UNSIGNED_BYTE,sty.rgba);
        glRasterPos2i(230,700);
        glDrawPixels(zwy.wid,zwy.hei,GL_RGBA,GL_UNSIGNED_BYTE,zwy.rgba);
        glRasterPos2i(420,700);
        glDrawPixels(zzh.wid,zzh.hei,GL_RGBA,GL_UNSIGNED_BYTE,zzh.rgba);
        glRasterPos2i(610,700);
        glDrawPixels(czl.wid,czl.hei,GL_RGBA,GL_UNSIGNED_BYTE,czl.rgba);
        glRasterPos2i(800,700);
        glDrawPixels(lty.wid,lty.hei,GL_RGBA,GL_UNSIGNED_BYTE,lty.rgba);

		FsSwapBuffers();

		FsSleep(25);
	}
}

int GameMenu::Player2ChooseCharacter(void)
{
	int ArrowPosition=1;
    LoadPNG("p2select.png", &p2select);

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
			if (ArrowPosition>=5)
			{
				ArrowPosition=5;
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

        glRasterPos2i(100,240);
        glDrawPixels(p2select.wid,p2select.hei,GL_RGBA,GL_UNSIGNED_BYTE,p2select.rgba);
        
        
        DrawArrow(190*(ArrowPosition-1)+125,260,1,255,0,0);
        
        glRasterPos2i(40,700);
        glDrawPixels(sty.wid,sty.hei,GL_RGBA,GL_UNSIGNED_BYTE,sty.rgba);
        glRasterPos2i(230,700);
        glDrawPixels(zwy.wid,zwy.hei,GL_RGBA,GL_UNSIGNED_BYTE,zwy.rgba);
        glRasterPos2i(420,700);
        glDrawPixels(zzh.wid,zzh.hei,GL_RGBA,GL_UNSIGNED_BYTE,zzh.rgba);
        glRasterPos2i(610,700);
        glDrawPixels(czl.wid,czl.hei,GL_RGBA,GL_UNSIGNED_BYTE,czl.rgba);
        glRasterPos2i(800,700);
        glDrawPixels(lty.wid,lty.hei,GL_RGBA,GL_UNSIGNED_BYTE,lty.rgba);
        
        
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
