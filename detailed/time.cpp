#include<stdlib.h>
#include<stdio.h>
#include"fssimplewindow.h"
#include "ysglfontdata.h"
#include "time.h"
#define fullHp 500

Time::Time(double m, double s) {
    second = s;
    min = m;
}

void DrawTimer(int decade, int unit) {
    glColor3b(0, 255, 0);
    glRasterPos2i(495, 55);
    Drawdigit(decade);
    glRasterPos2d(520, 55);
    Drawdigit(unit);
}
void Time::setTime() {
    sum = 60 * min + second;
}

void Time::tictoc() {
    sum -= 0.015;
    //printf("%lf\n", sum);
}
void Drawdigit(int d) {
    switch(d) {
        case 0:
        YsGlDrawFontBitmap20x32("0");
        break;
        
        case 1:
        YsGlDrawFontBitmap20x32("1");
        break;
        
        case 2:
        YsGlDrawFontBitmap20x32("2");
        break;
        
        case 3:
        YsGlDrawFontBitmap20x32("3");
        break;
        
        case 4:
        YsGlDrawFontBitmap20x32("4");
        break;
        
        case 5:
        YsGlDrawFontBitmap20x32("5");
        break;
        
        case 6:
        YsGlDrawFontBitmap20x32("6");
        break;
        
        case 7:
        YsGlDrawFontBitmap20x32("7");
        break;
        
        case 8:
        YsGlDrawFontBitmap20x32("8");
        break;
        case 9:
        YsGlDrawFontBitmap20x32("9");
        break;
    }
}
