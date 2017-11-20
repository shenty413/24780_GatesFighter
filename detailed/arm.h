#ifndef arm_h
#define arm_h

#include <stdio.h>

class Arm
{
    // protected:
    // 	int xa,ya,xh,yh // albow, hand
protected:
	double t;
	double rshouldpo,relbowx,relbowy,rhandx,rhandy;
	double lshouldpo,lelbowx,lelbowy,lhandx,lhandy;
public:
	void CalculateRightPart(double x, double y,int rpunchstate,double T);
	void CalculateLeftPart(double x, double y,int lpunchstate,double T);
    void DrawRightArm(double x, double y) const;
    void DrawLeftArm(double x, double y) const;
};

#endif
