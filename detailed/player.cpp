#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fssimplewindow.h"

#include "player.h"

const int default_x = 10;
const int default_y = 400;
const int jumpSpeed = -1000;
const int default_hp = 100;
const int default_attack = 10;
const bool default_dir = 1;
const int dt = 0.1;


Player::Player(){
    x = default_x;
    y = default_y;
    hp = default_hp;
    attack = default_attack;
    direction = default_dir;
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
    y += vy * dt;
    vy += ay * dt;
}

void Player::CheckHitGround(void){
    if (vy > 400){
        vy = 400;
        ay = 0;
        jumpState = false;
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
    
}






