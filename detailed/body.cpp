#include "body.h"
#include <math.h>
#include "fssimplewindow.h"
#include "header.h"
#include <string>

void Body::SetPic(int index){
    std::string fileName[6];
    switch (index) {
        case 1:
            fileName[0] = "player1left.png";
            fileName[1] = "player1right.png";
            fileName[2] = "player1bpl.png";
            fileName[3] = "player1bpr.png";
            fileName[4] = "player1punch.png";
            fileName[5] = "palyer1jump.png";
            break;
        case 2:
            fileName[0] = "player2left.png";
            fileName[1] = "player2right.png";
            fileName[2] = "player2bpl.png";
            fileName[3] = "player2bpr.png";
            fileName[4] = "player2punch.png";
            fileName[5] = "palyer2jump.png";
            break;
        case 3:
            fileName[0] = "player3left.png";
            fileName[1] = "player3right.png";
            fileName[2] = "player3bpl.png";
            fileName[3] = "player3bpr.png";
            fileName[4] = "player3punch.png";
            fileName[5] = "palyer3jump.png";
            break;
        case 4:
            fileName[0] = "player4left.png";
            fileName[1] = "player4right.png";
            fileName[2] = "player4bpl.png";
            fileName[3] = "player4bpr.png";
            fileName[4] = "player4punch.png";
            fileName[5] = "palyer4jump.png";
            break;
        default:
            break;
    }
    
    if(YSOK == leftpng.Decode(fileName[0].c_str()))
    {
        leftpng.Flip();
        printf("%dx%d\n",leftpng.wid,leftpng.hei);
    }
    else
    {
        printf("Cannot open file 1.\n");
    }
    
    if(YSOK == rightpng.Decode(fileName[1].c_str()))
    {
        rightpng.Flip();
        printf("%dx%d\n",rightpng.wid,rightpng.hei);
    }
    else
    {
        printf("Cannot open file 1.\n");
    }
    
    if(YSOK == bplpng.Decode(fileName[2].c_str()))
    {
        bplpng.Flip();
        printf("%dx%d\n",bplpng.wid,bplpng.hei);
    }
    else
    {
        printf("Cannot open file 1.\n");
    }
    
    if(YSOK == bprpng.Decode(fileName[3].c_str()))
    {
        bprpng.Flip();
        printf("%dx%d\n",bprpng.wid,bprpng.hei);
    }
    else
    {
        printf("Cannot open file 1.\n");
    }
    
    if(YSOK == punchpng.Decode(fileName[4].c_str()))
    {
        punchpng.Flip();
        printf("%dx%d\n",punchpng.wid,punchpng.hei);
    }
    else
    {
        printf("Cannot open file 1.\n");
    }
    
    if(YSOK == jumppng.Decode(fileName[5].c_str()))
    {
        jumppng.Flip();
        printf("%dx%d\n",jumppng.wid,jumppng.hei);
    }
    else
    {
        printf("Cannot open file 1.\n");
    }
}

void Body::DrawHead(double x,double y, int facialstate, int IsHit) const{
    glRasterPos2i(x-50,y-15);
    
    
    if (IsHit){
        if (facialstate){
            glDrawPixels(bplpng.wid,bplpng.hei,GL_RGBA,GL_UNSIGNED_BYTE,bplpng.rgba);
            
        }else{
            glDrawPixels(bprpng.wid,bprpng.hei,GL_RGBA,GL_UNSIGNED_BYTE,bprpng.rgba);
        }
        return;
    }
    
    if (facialstate){
        glDrawPixels(leftpng.wid,leftpng.hei,GL_RGBA,GL_UNSIGNED_BYTE,leftpng.rgba);
        
    }else{
        glDrawPixels(rightpng.wid,rightpng.hei,GL_RGBA,GL_UNSIGNED_BYTE,rightpng.rgba);
    }
}
    
    /*
	glColor3ub(0, 0, 0);
	//glBegin(GL_TRIANGLE_FAN);
	glBegin(GL_LINES);
	for (int i = 0; i <= 64; ++i)
	{

		double angle1 = (double)i*pi / 32.0;
		double angle2 = (double)(i+1)* pi / 32.0;
		double c1 = cos(angle1);
		double s1 = sin(angle1);
		double c2 = cos(angle2);
		double s2 = sin(angle2);
		glVertex2d(x + c1*headr , y + s1*headr - (headr + neckl));
		glVertex2d(x + c2*headr, y + s2*headr - (headr + neckl));
	}
	glEnd();


	//draw facial expression
	glBegin(GL_LINES);
	//draw eye
	glVertex2d(x + headr/7, y - (headr + neckl) - headr/4);
	glVertex2d(x + headr / 7 +0.5*headr, y - (headr + neckl) - headr / 4);
	glVertex2d(x - headr / 7, y - (headr + neckl) - headr / 4);
	glVertex2d(x - headr / 7 -0.5*headr, y - (headr + neckl) - headr / 4);
	glEnd();
	//draw eyeball
	double g;
	if (facialstate == 0)
	{
	    g = 1.;
	}
	if (facialstate == 1)
	{
		g = -1.;
	}
		glBegin(GL_TRIANGLE_FAN);
		for (int i = 0; i <= 64; ++i)
		{

			double angle = (double)i*pi / 32.0;
			double c = cos(angle);
			double s = sin(angle);
			glVertex2d(x + g*headr / 7 + g*0.5*headr + c*3., y - (headr + neckl) - headr / 4 + s*3.);
		}
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		for (int i = 0; i <= 64; ++i)
		{

			double angle = (double)i*pi / 32.0;
			double c = cos(angle);
			double s = sin(angle);
			glVertex2d(x - g*headr / 7 + c * 3, y - (headr + neckl) - headr / 4 + s*3.);
		}
		glEnd();

		//draw mouse
		glBegin(GL_LINES);
		glVertex2d(x - g*headr / 9, y - (headr + neckl) + headr / 4);
		glVertex2d(x + g*headr / 7 + g*0.4*headr, y - (headr + neckl) + headr / 4);
		glEnd();
     */
    
void Body::DrawNeck (double x, double y) const
{
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2d(x, y);
	glVertex2d(x , y -neckl);
	glEnd();
}

void Body::DrawBody(double x, double y) const
{
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	//glVertex2d(x, y);
	//glVertex2d(x, y + bodyl);
	glVertex2d(x + shoulderl, y);
	glVertex2d(x + 0.8*shoulderl, y + bodyl);
	glVertex2d(x + 0.8*shoulderl, y + bodyl);
	glVertex2d(x - 0.8*shoulderl, y + bodyl);
	glVertex2d(x - 0.8*shoulderl, y + bodyl);
	glVertex2d(x - shoulderl, y);
	
	
	//draw chest
	glVertex2d(x + 0.01*shoulderl, y + 0.1*bodyl);
	glVertex2d(x + 0.01*shoulderl, y + 0.4*bodyl);
	glVertex2d(x + 0.01*shoulderl, y + 0.4*bodyl);
	glVertex2d(x + 0.8*shoulderl, y + 0.4*bodyl);
	glVertex2d(x + 0.8*shoulderl, y + 0.4*bodyl);	
	glVertex2d(x + 0.9*shoulderl, y + 0.1*bodyl);

	glVertex2d(x - 0.01*shoulderl, y + 0.1*bodyl);
	glVertex2d(x - 0.01*shoulderl, y + 0.4*bodyl);
	glVertex2d(x - 0.01*shoulderl, y + 0.4*bodyl);
	glVertex2d(x - 0.8*shoulderl, y + 0.4*bodyl);
	glVertex2d(x - 0.8*shoulderl, y + 0.4*bodyl);
	glVertex2d(x - 0.9*shoulderl, y + 0.1*bodyl);

	//draw abs
	glVertex2d(x + 0.3*shoulderl, y + 0.6*bodyl);
	glVertex2d(x + 0.3*shoulderl, y + 0.9*bodyl);
	glVertex2d(x + 0.3*shoulderl, y + 0.9*bodyl);
	glVertex2d(x - 0.3*shoulderl, y + 0.9*bodyl);
	glVertex2d(x - 0.3*shoulderl, y + 0.9*bodyl);
	glVertex2d(x - 0.3*shoulderl, y + 0.6*bodyl);
	glVertex2d(x - 0.3*shoulderl, y + 0.6*bodyl);
	glVertex2d(x + 0.3*shoulderl, y + 0.6*bodyl);
	
	glVertex2d(x , y + 0.6*bodyl);
	glVertex2d(x, y + 0.9*bodyl);

	glVertex2d(x + 0.3*shoulderl, y + 0.7*bodyl);
	glVertex2d(x - 0.3*shoulderl, y + 0.7*bodyl);
	glVertex2d(x - 0.3*shoulderl, y + 0.8*bodyl);
	glVertex2d(x + 0.3*shoulderl, y + 0.8*bodyl);

	glEnd();

}
