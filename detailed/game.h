#ifndef game_h
#define game_h

#include <stdio.h>
#include "player.h"
#include "game.h"
#include "arm.h"
#include "leg.h"

class Game
{
    Player p1;
    Player p2;
public:
    bool finish;
    void Run(void);
    void SetCharacter(int pn1, int pn2); // player No 1 and 2
};

#endif
