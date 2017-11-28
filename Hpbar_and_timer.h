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
void Time::setTime(int min, int second);
void Drawdigit(int d);
void drawHpBar(double p1, double p2);
void DrawTimer(int decade, int unit);
void Drawdigit(int d);
