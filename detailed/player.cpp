#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "fssimplewindow.h"

#include "player.h"
#include "header.h"

void drawhead(double x,double y, int facialstate);
void drawneck(double x, double y);
void drawbody(double x, double y);
void drawrightpart(double x, double y,int rpunchstate, double T);
void drawleftpart(double x, double y,int lpunchstate, double T);
void drawrightleg(double x, double y,int rlegstate,int jumpornot);
void drawleftleg(double x, double y,int llegstate,int jumpornot);

using namespace std;

const int default_x = 300;
const int default_y = 550;
const int jumpSpeed = -1000;
const int default_hp = 100;
const int default_attack = 10;
const bool default_dir = 1;
const double dt = 0.01;


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
    walkState = 0;
}

Player::Player(int No){
    x = default_x+(No-1)*400;
    y = default_y;
    hp = default_hp;
    attack = default_attack;
    direction = default_dir;
    ay = 2000;
    T = 0;
    Ttemp = 0;
    punchState = 0;
    walkState = 0;
    // test 
}


void Player::SetCharacter(int charNo){
    switch (charNo) {
        case 1:
            attack = 5;
            vx = 500;
			back = 50;
            break;
        case 2:
            attack = 10;
            vx = 3000;
			back = 50;
            break;
        case 3:
            attack = 20;
            vx = 1000;
			back = 200;
            break;
        case 4:
            attack = 30;
            vx = 100;
			back = 400;
            break;
    }
}

void Player::backtoScreen () {
    /* check which side is outofScreen */
    if (getRightBanMoveBoundary() >= 1024) {
        x = 1024 - 90;
    } else if (getLeftBanMoveBoundary() <= 0) {
        x = 0 + 90;
    }
}

int Player::getAttack(){
    return attack;
}

void Player::setAttack(const int attack_addition) 
{
	attack += attack_addition;
}

void Player::setVx(const int vx_addition) 
{
	vx += vx_addition;
};

int Player::getLeftBoundary(){
    return x - 60;
}

int Player::getRightBoundary(){
    return x + 60;
}

int Player::getUpperBoundary() {
	return y - neckl - 2 * headr;
}

int Player::getLowerBoundary() {
	return y + bodyl + 2 * legl;
}

/////get the BanMoveBoundary
int Player::getLeftBanMoveBoundary() {
	return x - 90;
}

int Player::getRightBanMoveBoundary() {
	return x + 90;
}

int Player::getUpperBanMoveBoundary() {
	return y - neckl-2*headr;
}

int Player::getLowerBanMoveBoundary() {
	return y + bodyl + 2*legl;
}

int Player::getX() const 
{
	return x; 
}

int Player::getY() const
{
	return y;
}

void Player::setX(int back)
{
	x=x + back;
}

void Player::Move(){


	//if (getLeftBanMoveBoundary() <=opponent.getRightBanMoveBoundary() && getRightBanMoveBoundary()  > opponent.getLeftBanMoveBoundary() && getUpperBanMoveBoundary()<=opponent.getLowerBanMoveBoundary() && getLowerBanMoveBoundary() >= opponent.getUpperBanMoveBoundary())


    if (direction == 1){
		x -= vx * dt;
		
    }
    else{
		x += vx * dt;
	
    }
    walkState = 1;


}

void Player::ResetWalkState(){
    walkState = 0;
}

// dirc = 1, left; dirc = 0, right
void Player::ChangeDirc(bool dirc){
    direction = dirc;
}

void Player::InitializeJumping(void){
    jumpState = 1;
    ay = 2000;
    // vy = -400;
    vy = jumpSpeed;
}

bool Player::IsJumping(void){
    if (jumpState == 1){
        return true;
    }
    return false;
}

void Player::Jump(void){
    y += vy * dt;
    vy += ay * dt;
    // printf("ay: %d, vy: %d, y: %d\n", ay, vy, y);
}

void Player::CheckHitGround(void){
    if (y > 550 && jumpState){
        ay = 0;
        vy = 0;
        y = 550;
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

bool Player::IfPunchHit(Player &opponent){
    int armLength = 300*0.5;

    /*printf("Left Boundry: %d\n", opponent.getLeftBoundary());
    printf("Right Boundry: %d\n", opponent.getRightBoundary());
    printf("x: %d\n", x);
    printf("left punch point: %d\n",x - armLength);
    printf("right punch point: %d\n",x + armLength);*/
    if (direction){ // facing left
        if (x - armLength <= opponent.getRightBoundary() && x - armLength >= opponent.getLeftBoundary()&& y>=opponent.getUpperBoundary() && y <= opponent.getLowerBoundary()){
            printf("Is hit from left!");
			opponent.setX(-1*back);
            return true;
        }
    }
    if (!direction){ // facing right
        if (x + armLength >= opponent.getLeftBoundary() && x + armLength <= opponent.getRightBoundary() && y >= opponent.getUpperBoundary() && y <= opponent.getLowerBoundary()){
            printf("Is hit from Right!");
			opponent.setX(back);
            return true;
        }
    }
    return false;
}

void Player::ChangeHitState(){
    if (IsHit == 1){
        IsHit = 0;
    }else{
        IsHit = 1;
    }
    printf("%i",IsHit);
}

int Player::GetHitState(){
    return IsHit;
}

void Player::HPchange(const int amount){
    hp += amount;

    if (hp<=0)
        hp = 0;

	if (hp >= default_hp)
		hp = default_hp;

    printf("HP: %d\n",hp);
}

int Player::GetHP(void) {
	return hp;
}

void Player::Draw(Player &opponent){
    // printf("x=%d,y=%d,direction=%d,punchState=%d,time=%d\n", x, y, direction, punchState, T);
    if (punchState == 1){
        if (T < 4 && (T == 0 || T - Ttemp > 0))
        {
            Ttemp = T;
            T++;
            if(T==4)
            {
                
            }
        }
        else{
            T--;
            if (T == 0){
                if (opponent.IsHit){
                    opponent.ChangeHitState();
//                    /printf("is hit\n");
                }
                punchState = 0;
            }
        }
    }
    //printf("T: %d, punchState: %d\n", T, punchState);
    //printf("x: %d, y: %d", x,y);
    

    // draw left and right boundary
     /*
    glColor3ub(0, 0, 0);
    //glBegin(GL_TRIANGLE_FAN);
    glBegin(GL_LINES);
    glVertex2d(getRightBoundary(),0);
    glVertex2d(getRightBoundary(),600);
    glVertex2d(getLeftBoundary(),0);
    glVertex2d(getLeftBoundary(),600);    
    glEnd();
     */



    arm.CalculateRightPart(x, y, direction, punchState, T);
    arm.CalculateLeftPart(x, y, direction, punchState, T);
    arm.DrawRightArm(x, y);
    arm.DrawLeftArm(x, y);

    leg.Calculate(x, y, walkState, walkState);
    leg.DrawRightLeg(jumpState);
    leg.DrawLeftLeg(jumpState);

    body.DrawHead(x, y, direction, IsHit);
    body.DrawNeck(x, y);
    body.DrawBody(x, y);
}




