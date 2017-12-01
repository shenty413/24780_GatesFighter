#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "body.h"
#include "leg.h"
#include "arm.h"

class Player
{
protected:
	int T, Ttemp;
	int x,y,hp,attack,ay,vx,vy,direction,jumpState,walkState,punchState,IsHit;
	int w1,w2,elbowAngle1,elbowAngle2;
    
    Arm arm;
    Leg leg;
    Body body;
    
public:
	Player(void); // initialize a player
	Player(int No);
	// test

    
    void SetCharacter(int charNo);

	/* The following functions are getters of this class. */
	int getAttack();
	int getLeftBoundary();
	int getRightBoundary();
<<<<<<< HEAD
	int getLowerBanMoveBoundary();
	int getUpperBanMoveBoundary();
	int getLeftBanMoveBoundary();
	int getRightBanMoveBoundary();
=======
	int getX(void) const; 
	int getY(void) const; 
>>>>>>> 8be5c612ec4cb5bde7d16f61680d3d0c70b4aea4

	/*
		The following functions are modifiers based on different moves that the players can do:
			1. move
			2. jump
			3. punch
			4. being punched
	*/

	void Move(); // change x according to character's speed
	void ResetWalkState();
	
    void ChangeDirc(bool dirc);  // change direction

	void InitializeJumping(void); // initialize a jump
	bool IsJumping(void); // jumpState=1, vy
	void Jump(void); // change vy, y
	void CheckHitGround(void);

	void InitializePunching(void); // initialize a punch
	bool IsPunching(void); // punchState=1, w1, w2
	void Punch(void); // change elbowAngle1, elbowAngle2
	int GetHitState(void);

	/*the following functions describe what happen when a player hit his/her opponent*/
	bool IfPunchHit(Player &opponent); // 
	void ChangeHitState(); // change the isHit state of a player if he/she is hit by the opponent
	void HPchange(const int amount);
	int GetHP(void);


	void Draw();
};

#endif
