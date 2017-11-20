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
}

void Player::SetCharacter(int charNo){
    switch (charNo) {
        case 1:
            attack = 5;
            break;
        case 2:
            attack = 10;
            break;
        case 3:
            attack = 20;
            break;
        case 4:
            attack = 30;
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

void Player::Move(int dis){
    x += dis;
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
    
}

void Player::CheckFinishPunching(void){
    
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
    arm.CalculateRightPart(x, y, direction, punchState, 0);
    arm.CalculateLeftPart(x, y, direction, punchState, 0);
    arm.DrawRightArm(x, y);
    arm.DrawLeftArm(x, y);
}




