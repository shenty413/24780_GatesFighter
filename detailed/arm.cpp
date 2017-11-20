#include "arm.h"

void Arm::CalculateRightPart(double x, double y,int rpunchstate,double T){
	double t = 0.;
	if (rpunchstate == 1)
	{
		t = T;
	}
	double xita = omiga*t;

	rshouldpo = x + shoulderl;    //The control point  of right shoulder
	relbowx = x + shoulderl + arml*sin((25+xita) * co); //The control point of right elbow (x)
	relbowy = y + arml * cos((25 + xita) * co); //The control point of right elbow (y)
	rhandx = x + shoulderl + arml*sin((45 + xita) * co) + arml*sin((25 + xita) * co); //The control point of right hand(x)
	rhandy = y + arml - arml * cos((45 + xita) * co) - arml * (1 - cos((25 + xita) * co));   //The control point of right hand(y)
}

void Arm::CalculateLeftPart(double x, double y,int rpunchstate,double T){
	double t = 0.;
	if (lpunchstate == 1)
	{
		t = T;
	}
	double xita = omiga*t;

	lshouldpo = x - shoulderl;    //The control point  of left shoulder
	lelbowx = x - shoulderl - arml*sin((25 +xita)* co); //The control point of left elbow (x)
	lelbowy = y + arml * cos((25 + xita)* co); //The control point of left elbow (y)
	lhandx = x - shoulderl - arml*sin((45 + xita) * co) - arml*sin((25 + xita) * co); //The control point of left hand(x)
	lhandy = y + arml - arml * cos((45 + xita) * co) - arml * (1 - cos((25 + xita) * co));   //The control point of left hand(y)
}

void Arm::DrawRightArm(double x, double y){
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

void Arm::DrawLeftArm(double x, double y){
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