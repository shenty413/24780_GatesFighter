#ifndef leg_h
#define leg_h

#include <stdio.h>

class Leg
{
    // protected:
    // 	int x1,y1,x2,y2
protected:
	double rootxr,rootyr,gr;
	double rootxl,rootyl,gl;
	int rlegstate,llegstate;
public:
	void Calculate(int x,int y,int rlegstate,int llegstate);
    void DrawRightLeg(int jumpornot) const;
    void DrawLeftLeg(int jumpornot) const;
};

#endif
