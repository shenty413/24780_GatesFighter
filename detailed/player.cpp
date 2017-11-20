#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fssimplewindow.h"

#include "player.h"

#define default_x 10;
#define default_y 400;
#define default_hp 100;
#define default_attack 10;
#define default_direction 1;


Player::Player(){
    x = default_x;
    y = default_y;
    hp = default_hp;
    attack = default_attack;
    direction = default_direction;
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

void Player::Move(void){
    
}

void Player::InitializeJumping(void){
    
}

bool Player::IsJumping(void){
    return false;
}

void Player::Jump(void){
    
}

void Player::CheckHitGround(void){
    
}

void Player::InitializePunching(void){
    
}

bool Player::IsPunching(void){
    return false;
}

void Player::Punch(void){
    
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
    
}

void Player::Draw(){
    
}






