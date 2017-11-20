#include "leg.h"

void Leg::Calculate(int x,int y,int rlegstate,int llegstate){
	rootxr = x + 0.6*shoulderl;
	rootyr = y + bodyl;
	rootxl = x - 0.6*shoulderl;
	rootyl = y + bodyl;
	gr=1;
	gl=1;
	if (rlegstate==1)
	{
		gr = -1;
	}
	if (llegstate == 1)
	{
		gl = -1;
	}
}

void Leg::DrawRightLeg(int jumpornot){
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2d(rootxr, rootyr);
	glVertex2d(rootxr + gr * legl*sin(45 * co), rootyr + legl * cos(45 * co));
	glVertex2d(rootxr + gr * legl*sin(45 * co), rootyr + legl * cos(45 * co));
	if (jumpornot == 0)
	{
		glVertex2d(rootxr + gr * legl*sin(45 * co), rootyr + legl*cos(45 * co) + legl);
	}
	if (jumpornot == 1)
	{
		glVertex2d(rootxr + gr * legl*sin(45 * co) -gr * legl, rootyr + legl*cos(45 * co) );
	}
	glEnd();
}

void Leg::DrawLeftLeg(int jumpornot){
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2d(rootxl, rootyl);
	glVertex2d(rootxl - gl * legl*sin(45 * co), rootyl + legl * cos(45 * co));
	glVertex2d(rootxl - gl * legl*sin(45 * co), rootyl + legl * cos(45 * co));
	if (jumpornot == 0)
	{
		glVertex2d(rootxl - gl * legl*sin(45 * co), rootyl + legl * cos(45 * co) + legl);
	}
	if (jumpornot == 1)
	{
		glVertex2d(rootxl - gl * legl*sin(45 * co) + gl * legl, rootyl + legl * cos(45 * co));
	}
	glEnd();
}