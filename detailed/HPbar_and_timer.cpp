#include<stdlib.h>
#include<stdio.h>
#include"fssimplewindow.h"
#include "ysglfontdata.h"
#define fullHp 500

class Time {
public:
    double second;
    double min;
    void tictoc();
    double sum;
    void setTime(int min, int second);
};

void Time::setTime(int min, int second) {
    this->second = second;
    this->min = min;
    sum = min * 60 + second;
}

void Drawdigit(int d);
void Time::tictoc() {
    sum -= 0.01;
    printf("%lf\n", sum);
}
void drawHpBar(double p1, double p2) {
   
    //int a = 1;
    glColor3ub(0,255,0);
    glRasterPos2i(0, 70);
    YsGlDrawFontBitmap20x32("fighter1");
    glRasterPos2i(640, 70);
    YsGlDrawFontBitmap20x32("fighter2");
    /* draw HP bar of p1 */
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(0, 0);
    glVertex2i(0, 30);
    glVertex2i(200, 30);
    glVertex2i(200, 0);
    glEnd();
    
    /* red part */
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(0, 30);
    glVertex2i(200 * p1, 30);
    glVertex2i(200 * p1, 0);
    glEnd();
    
    /* draw HP bar of p2 */
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(800, 0);
    glVertex2i(800, 30);
    glVertex2i(600, 30);
    glVertex2i(600, 0);
    glEnd();
    /* draw red part */
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(800, 0);
    glVertex2i(800, 30);
    glVertex2i(600 + 200 * (1 - p2), 30);
    glVertex2i(600 + 200 * (1 - p2), 0);
    glEnd();
}

//int decade, int unit
void DrawTimer(int decade, int unit) {
    glColor3ub(0,255,0);
    glRasterPos2i(380, 70);
    Drawdigit(decade);
    glRasterPos2i(400, 70);
    Drawdigit(unit);
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

int main(void) {
     Time timer;
     FsOpenWindow(16,16,800,600,0);
     timer.setTime(0, 5);
     int decade, unit;
     while(FSKEY_NULL==FsInkey() && timer.sum >= -1) {
         decade = (int)(timer.sum + 1) / 10;
         unit = (int)(timer.sum + 1) - decade * 10;
        timer.tictoc();
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        drawHpBar(timer.sum/5, timer.sum/5);
        DrawTimer(decade, unit);
        glFlush();
        FsSleep(10);
    }
}

