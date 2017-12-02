#ifndef body_h
#define body_h

#include <stdio.h>
#include "yspng.h"
#include "yspngenc.h"

class Body
{
    // protected:
    // 	int x1,y1,x2,y2
public:
    YsRawPngDecoder leftpng;
    YsRawPngDecoder rightpng;
    YsRawPngDecoder bplpng;
    YsRawPngDecoder bprpng;
    YsRawPngDecoder punchpng;
    YsRawPngDecoder jumppng;
    //Body();
    void DrawHead(double x,double y, int facialstate, int IsHit) const;
    void DrawNeck(double x, double y) const;
    void DrawBody(double x, double y) const;
    void SetPic(int index);
};

#endif
