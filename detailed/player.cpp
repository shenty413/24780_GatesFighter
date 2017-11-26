#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "fssimplewindow.h"

#include "player.h"

void drawhead(double x,double y, int facialstate);
void drawneck(double x, double y);
void drawbody(double x, double y);
void drawrightpart(double x, double y,int rpunchstate, double T);
void drawleftpart(double x, double y,int lpunchstate, double T);
void drawrightleg(double x, double y,int rlegstate,int jumpornot);
void drawleftleg(double x, double y,int llegstate,int jumpornot);


using namespace std;

const int default_x = 300;
const int default_y = 400;
const int jumpSpeed = -10;
const int default_hp = 100;
const int default_attack = 10;
const bool default_dir = 1;
const int dt = 0.01;


Player::Player(){
    x = default_x;
    y = default_y;
    hp = default_hp;
    attack = default_attack;
    direction = default_dir;
    ay = 2000;
    T = 0;
    Ttemp = 0;
    punchState = 0;
}

void Player::SetCharacter(int charNo){
    switch (charNo) {
        case 1:
            attack = 5;
            vx = 50;
            break;
        case 2:
            attack = 10;
            vx = 3000;
            break;
        case 3:
            attack = 20;
            vx = 1000;
            break;
        case 4:
            attack = 30;
            vx = 100;
            break;
    }
}

const int Player::getAttack(){
    return attack;
}

const int Player::getLeftBoundary(){
    return x - 5;
}

const int Player::getRightBoundary(){
    return x + 5;
}

void Player::Move(){
    x += vx;
    y += vy * dt;
    vy += ay * dt;
}

void Player::ChangeDirc(bool dirc){
    direction = dirc;
}

void Player::InitializeJumping(void){
    jumpState = 1;
    vy = jumpSpeed;
}

bool Player::IsJumping(void){
    if (jumpState == 1){
        return true;
    }
    return false;
}

void Player::Jump(void){
    ay = 2000;
    vy = -400;
}

void Player::CheckHitGround(void){
    if (vy > 400 && jumpState){
        ay = 0;
        jumpState = 0;
    }
}

void Player::InitializePunching(void){
    punchState = 1;
}

bool Player::IsPunching(void){
    if (punchState == 1){
        return true;
    }
    return false;
}

void Player::Punch(void){
    punchState = 1;
}

bool Player::CheckFinishPunching(void){

	return true; 
}

bool Player::IfPunchHit(const Player &opponent){
    return false;
}

void Player::ChangeHitState(){
    
}

void Player::HPchange(const int amount){
    hp -= amount;
}

void Player::Draw(){
    // printf("x=%d,y=%d,direction=%d,punchState=%d,time=%d\n", x, y, direction, punchState, T);
    if (punchState == 1){
        if (T < 5 && (T == 0 || T - Ttemp > 0)){
            Ttemp = T;
            T++;
        }else{
            T--;
            if (T == 0){
                punchState = 0;
            }
        }
    }
    //printf("T: %d, punchState: %d\n", T, punchState);
    
    arm.CalculateRightPart(x, y, direction, punchState, T);
    arm.CalculateLeftPart(x, y, direction, punchState, T);
    arm.DrawRightArm(x, y);
    arm.DrawLeftArm(x, y);

    leg.Calculate(x, y, walkState, walkState);
    leg.DrawRightLeg(jumpState);
    leg.DrawLeftLeg(jumpState);

    body.DrawHead(x, y, direction);
    body.DrawNeck(x, y);
    body.DrawBody(x, y);
}




