
#ifndef Timer_h
#define Timer_h
#include <stdio.h>
class Time {
    public:
    double second;
    double min;
    void tictoc();
    double sum;
    void setTime();
    Time(double s, double m);
};
void Drawdigit(int d);
void DrawTimer(int decade, int unit);
#endif /* Timer_hpp */

