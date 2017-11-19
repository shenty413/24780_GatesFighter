#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fssimplewindow.h"

#include "player.h"

const int Player::getAttack(){
    return attack;
}

const int Player::getLeftBoundary(){
    return x - 5;
}

const int Player::getRightBoundary(){
    return x + 5;
}
