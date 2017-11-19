#include"fssimplewindow.h"
#include"ysglfontdata.h"
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
using namespace std;
const double pi = 3.14;
const double co = 3.14 / 180.;
const double g = 2000.;

//character parameter
const double headr = 70.;
const double neckl = 30.;
const double bodyl = 200.;
const double shoulderl = 100.;
const double arml = 100;
const double legl = 40;
const double punchl = 40;
const double omiga = 9.;

void drawhead(double x,double y, int facialstate)
{
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
	
	
}



void drawneck(double x, double y)
{
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2d(x, y);
	glVertex2d(x , y -neckl);
	glEnd();
}

void drawbody(double x, double y)
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

void drawrightpart(double x, double y,int rpunchstate, double T)
{
	double t = 0.;
	if (rpunchstate == 1)
	{
		t = T;
	}
	double xita = omiga*t;

		double rshouldpo = x + shoulderl;    //The control point  of right shoulder
		double relbowx = x + shoulderl + arml*sin((25+xita) * co); //The control point of right elbow (x)
		double relbowy = y + arml * cos((25 + xita) * co); //The control point of right elbow (y)
		double rhandx = x + shoulderl + arml*sin((45 + xita) * co) + arml*sin((25 + xita) * co); //The control point of right hand(x)
		double rhandy = y + arml - arml * cos((45 + xita) * co) - arml * (1 - cos((25 + xita) * co));   //The control point of right hand(y)
		glColor3ub(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2d(x, y);
		//
		glVertex2d(rshouldpo, y);
		//glVertex2d(x + shoulderl, y);
		//glVertex2d(x + shoulderl + arml*sin(25 * co), y+arml - arml * (1-cos(25 * co)));
		//glVertex2d(x + shoulderl + arml*sin(25 * co), y + arml - arml * (1-cos(25 * co)));
		//glVertex2d(x + shoulderl + arml*sin(45*co) + arml*sin(25 * co), y + arml- arml * cos(45 * co) - arml * (1-cos(25 * co)));

		//draw muscle
		glVertex2d(rshouldpo, y);
		glVertex2d(rshouldpo + 0.3*shoulderl, y);
		glVertex2d(rshouldpo + 0.3*shoulderl, y);
		glVertex2d(relbowx + 0.1*shoulderl, relbowy - 0.3*shoulderl);
		glVertex2d(relbowx + 0.1*shoulderl, relbowy - 0.3*shoulderl);
		glVertex2d(rhandx, rhandy - 0.12*shoulderl);



		glVertex2d(rshouldpo, y + 0.7*shoulderl);
		glVertex2d(relbowx - 0.1*shoulderl, relbowy + 0.15*shoulderl);
		glVertex2d(relbowx - 0.1*shoulderl, relbowy + 0.15*shoulderl);
		glVertex2d(relbowx + 0.1*shoulderl, relbowy + 0.15*shoulderl);
		glVertex2d(relbowx + 0.1*shoulderl, relbowy + 0.15*shoulderl);
		glVertex2d(rhandx, rhandy + 0.12*shoulderl);

		//draw punch
		glVertex2d(rhandx, rhandy);
		glVertex2d(rhandx, rhandy - 0.5*punchl);
		glVertex2d(rhandx, rhandy - 0.5*punchl);
		glVertex2d(rhandx + punchl, rhandy - 0.5*punchl);
		glVertex2d(rhandx + punchl, rhandy - 0.5*punchl);
		glVertex2d(rhandx + punchl, rhandy + 0.5*punchl);
		glVertex2d(rhandx + punchl, rhandy + 0.5*punchl);
		glVertex2d(rhandx, rhandy + 0.5*punchl);
		glVertex2d(rhandx, rhandy + 0.5*punchl);
		glVertex2d(rhandx, rhandy);
		//punch detail
		glVertex2d(rhandx + 0.5* punchl, rhandy - 0.5*punchl);
		glVertex2d(rhandx + 0.5* punchl, rhandy + 0.5*punchl);
		glVertex2d(rhandx + 0.25*punchl, rhandy - 0.5*punchl);
		glVertex2d(rhandx + 0.25*punchl, rhandy);
		glVertex2d(rhandx + 0.25*punchl, rhandy);
		glVertex2d(rhandx + 0.5*punchl, rhandy);

		glVertex2d(rhandx + 0.5* punchl, rhandy - 0.25*punchl);
		glVertex2d(rhandx + punchl, rhandy - 0.25*punchl);
		glVertex2d(rhandx + 0.5* punchl, rhandy);
		glVertex2d(rhandx + punchl, rhandy);
		glVertex2d(rhandx + 0.5* punchl, rhandy + 0.25*punchl);
		glVertex2d(rhandx + punchl, rhandy + 0.25*punchl);

		//draw arm detail

		glEnd();
	

}

void drawleftpart(double x, double y,int lpunchstate, double T)
{
	double t=0.;
	if (lpunchstate == 1)
	{
		t = T;
	}
	double xita = omiga*t;
	
		double lshouldpo = x - shoulderl;    //The control point  of left shoulder
		double lelbowx = x - shoulderl - arml*sin((25 +xita)* co); //The control point of left elbow (x)
		double lelbowy = y + arml * cos((25 + xita)* co); //The control point of left elbow (y)
		double lhandx = x - shoulderl - arml*sin((45 + xita) * co) - arml*sin((25 + xita) * co); //The control point of left hand(x)
		double lhandy = y + arml - arml * cos((45 + xita) * co) - arml * (1 - cos((25 + xita) * co));   //The control point of left hand(y)
		glColor3ub(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2d(x, y);
		glVertex2d(x - shoulderl, y);

		//glVertex2d(x - shoulderl, y);
		//glVertex2d(x - shoulderl - arml*sin(25 * co), y + arml - arml * (1 - cos(25 * co)));
		//glVertex2d(x - shoulderl - arml*sin(25 * co), y + arml - arml * (1 - cos(25 * co)));
		//glVertex2d(x - shoulderl - arml*sin(45 * co) - arml*sin(25 * co), y + arml - arml * cos(45 * co) - arml * (1 - cos(25 * co)));

		//draw muscle
		glVertex2d(lshouldpo, y);
		glVertex2d(lshouldpo - 0.3*shoulderl, y);
		glVertex2d(lshouldpo - 0.3*shoulderl, y);
		glVertex2d(lelbowx - 0.1*shoulderl, lelbowy - 0.3*shoulderl);
		glVertex2d(lelbowx - 0.1*shoulderl, lelbowy - 0.3*shoulderl);
		glVertex2d(lhandx, lhandy - 0.12*shoulderl);

		glVertex2d(lshouldpo, y + 0.7*shoulderl);
		glVertex2d(lelbowx + 0.1*shoulderl, lelbowy + 0.15*shoulderl);
		glVertex2d(lelbowx + 0.1*shoulderl, lelbowy + 0.15*shoulderl);
		glVertex2d(lelbowx - 0.1*shoulderl, lelbowy + 0.15*shoulderl);
		glVertex2d(lelbowx - 0.1*shoulderl, lelbowy + 0.15*shoulderl);
		glVertex2d(lhandx, lhandy + 0.12*shoulderl);

		//draw punch
		glVertex2d(lhandx, lhandy);
		glVertex2d(lhandx, lhandy - 0.5*punchl);
		glVertex2d(lhandx, lhandy - 0.5*punchl);
		glVertex2d(lhandx - punchl, lhandy - 0.5*punchl);
		glVertex2d(lhandx - punchl, lhandy - 0.5*punchl);
		glVertex2d(lhandx - punchl, lhandy + 0.5*punchl);
		glVertex2d(lhandx - punchl, lhandy + 0.5*punchl);
		glVertex2d(lhandx, lhandy + 0.5*punchl);
		glVertex2d(lhandx, lhandy + 0.5*punchl);
		glVertex2d(lhandx, lhandy);
		//punch detail
		glVertex2d(lhandx - 0.5* punchl, lhandy - 0.5*punchl);
		glVertex2d(lhandx - 0.5* punchl, lhandy + 0.5*punchl);
		glVertex2d(lhandx - 0.25*punchl, lhandy - 0.5*punchl);
		glVertex2d(lhandx - 0.25*punchl, lhandy);
		glVertex2d(lhandx - 0.25*punchl, lhandy);
		glVertex2d(lhandx - 0.5*punchl, lhandy);

		glVertex2d(lhandx - 0.5* punchl, lhandy - 0.25*punchl);
		glVertex2d(lhandx - punchl, lhandy - 0.25*punchl);
		glVertex2d(lhandx - 0.5* punchl, lhandy);
		glVertex2d(lhandx - punchl, lhandy);
		glVertex2d(lhandx - 0.5* punchl, lhandy + 0.25*punchl);
		glVertex2d(lhandx - punchl, lhandy + 0.25*punchl);
		glEnd();
	

}

void drawrightleg(double x, double y,int rlegstate,int jumpornot)
{
	double rootx = x + 0.6*shoulderl;
	double rooty = y + bodyl;
	double g=1;

	if (rlegstate==1)
	{
		g = -1;
	}
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2d(rootx, y + bodyl);
	glVertex2d(rootx + g * legl*sin(45*co), rooty + legl *cos(45 * co));
	glVertex2d(rootx + g * legl*sin(45 * co), rooty + legl*cos(45 * co));
	if (jumpornot == 0)
	{
		glVertex2d(rootx + g * legl*sin(45 * co), rooty + legl*cos(45 * co) + legl);
	}
	if (jumpornot == 1)
	{
		glVertex2d(rootx + g * legl*sin(45 * co) -g * legl, rooty + legl*cos(45 * co) );
	}
	glEnd();
}

void drawleftleg(double x, double y,int llegstate,int jumpornot)
{
	double rootx = x - 0.6*shoulderl;
	double rooty = y + bodyl;
	double g = 1;
	if (llegstate == 1)
	{
		g = -1;
	}
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2d(rootx, y + bodyl);
	glVertex2d(rootx - g * legl*sin(45 * co), rooty + legl * cos(45 * co));
	glVertex2d(rootx - g * legl*sin(45 * co), rooty + legl * cos(45 * co));
	if (jumpornot == 0)
	{
		glVertex2d(rootx - g * legl*sin(45 * co), rooty + legl * cos(45 * co) + legl);
	}
	if (jumpornot == 1)
	{
		glVertex2d(rootx - g * legl*sin(45 * co) + g * legl, rooty + legl * cos(45 * co));
	}
	glEnd();
}

int main()
{
	FsOpenWindow(0, 0, 2000, 1000, 1);
	int terminate = 0;
	int facialstate = 0;  //0 means the direction is right; 1 means diresction is left

	int rlegstate = 0;    //
	int llegstate = 0;

	int rpunchstate=1;    //determine whether is left punch or right punch
	int lpunchstate=0;

	int punchornot = 0;

	int jumpornot = 0;

	double x = 500.;
	double y = 500.;
	double y0 = y;

	double T=0;
	double dt = 0.01;

	double vy = 0;

	while (terminate == 0)
	{

		FsPollDevice();
		auto key = FsInkey();
		switch (key)
		{
		case FSKEY_ESC:
			terminate = 1;
			break;
		case FSKEY_W:
			if (jumpornot == 0)
			{
				jumpornot = 1;
				vy = -1000.;
			}
			break;
		case FSKEY_A:
			if (punchornot == 0)
			{
				facialstate = 1;
				rlegstate = 1;
				llegstate = 1;
				rpunchstate = 0;
				lpunchstate = 1;
				x -= 40;
			}
			break;
		case FSKEY_D:
			if (punchornot == 0)
			{
				facialstate = 0;
				rlegstate = 1;
				llegstate = 1;
				x += 40;
				rpunchstate = 1;
				lpunchstate = 0;
			}
			break;
		case FSKEY_S:
			if(punchornot==0)
			{
				punchornot = 1;
			}
			break;
		}
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		if (punchornot == 1)
		{
			if (T < 5)
			{
				T++;
			}
			else
			{
				punchornot = 2;
			}
		}
		if (punchornot == 2)
		{
			if (T > 0)
			{
				T--;
			}
			else
			{
				punchornot = 0;
			}
		}

		if (jumpornot == 1)
		{
			vy = vy + g * dt;
			y = y + vy * dt;
			if (y == y0)
			{
				jumpornot = 0;
			}
		}

		drawleftpart(x, y,lpunchstate,T);
		drawbody(x, y);
		drawrightpart(x, y,rpunchstate,T);
		drawhead(x, y,facialstate);
		drawneck(x, y);
		drawrightleg(x, y,rlegstate,jumpornot);
		drawleftleg(x, y,llegstate,jumpornot);

		rlegstate = 0;    //
		llegstate = 0;
		FsSwapBuffers();
		FsSleep(10);
	}
}