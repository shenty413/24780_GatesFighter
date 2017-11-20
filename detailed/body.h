#ifndef body_h
#define body_h

#include <stdio.h>

class Body
{
    // protected:
    // 	int x1,y1,x2,y2
public:
	void DrawHead(double x,double y, int facialstate) const;
    void DrawNeck(double x, double y) const;
    void DrawBody(double x, double y) const;
};

#endif
