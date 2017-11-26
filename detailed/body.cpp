#include "body.h"
#include <math.h>
#include "fssimplewindow.h"
#include "header.h"

void Body::DrawHead(double x,double y, int facialstate) const{
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
