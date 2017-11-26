#include<stdlib.h>
#include<stdio.h>
#include"fssimplewindow.h"
#include "ysglfontdata.h"
#define fullHp 500
/* p1, p2 are the percentage of the of left HP of Player1 and Player2 respectively */
void drawHpBar(double p1, double p2) {
   
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
    glVertex2i(200 * (1 - p1), 30);
    glVertex2i(200 * (1 - p1), 0);
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

void Hp(double HP1, double HP2) {
    double percentHp1 = HP1 / fullHp;
    double percentHp2 = HP2 / fullHp;
    
}

//int main(void) {
//    
//     FsOpenWindow(16,16,800,600,0);
//     while(FSKEY_NULL==FsInkey()) {
//       
//        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//        drawHpBar(0.8, 0.6);
//        glFlush();
//        FsSleep(10);
//    }
//}

