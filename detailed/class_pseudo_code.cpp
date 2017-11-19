#include <stdio.h>
#include <stdlib>
#include <time.h>
#include "fssimplewindow.h"

#include "game-class.h"

/*
	This file describe the design of our project, including 
	the player class, multiple body parts classes and their 
	member variables and functions
*/

class Player
{
protected:
	
	/* 'x' and 'y' represent the x,y coordinate on the opengl window. */
	int x,y;

	/* 'hp' indicates the state of health. */
	int hp;

	/* 
		'attack' indicates that if the player is attacking others.
	 	'jumpState' indicates that if the player is jumping in the air.
	  	'punchState' indicates that if the player is punching.
	  	'isHit' indicates that if the current player is hit by others.
	*/
	bool attack, jumpState, punchState, IsHit;

	/* 
		'ay', 'vx' and 'vy' indicate the kinematics properties of the player.
	 	'direction' indicates the direction that the player is facing.
	 */
	int ay, vx, vy, direction,
 
	/* 
		'w1' and 'w2' are angular velocities of the arms.
	 	'elbowAngle1' and 'elbowAngle2' and the current angle of the arms.
	*/
	int w1,w2,elbowAngle1,elbowAngle2;

public:
	
	/* Default Construcor of the player. */
	Player();

	/* The following functions are getters of protected member variables. */
	const int getAttack();
	const int getLeftBoundary();
	const int getRightBoundary();

	/*
		The following functions are modifiers based on different moves that the players can do:
			1. move
			2. jump
			3. punch
			4. being punched
	*/

	/*
		change x
	*/
	void Move(void);

	/*	Following functions describe the action of jumping */
	/*
		Initialize a jump by set jumpState = 1 and vy = 20.
	*/
	void InitializeJumping(void);
	/*
		check jumpState, return true if jumpState == 1;
	*/
	bool IsJumping(void);
	/*
		change y and vy
		y += vy * dt;
		vy = ay * dt;
	*/
	void Jump(void);
	/*
		Check if the player is on the ground.
		Change vy = 0 if on the ground;
	*/
	void CheckHitGround(void);

	/*	Following functions describe the action of punching */
	/*
		Initialize a punch by set punchState = 1.
	*/
	void InitializePunching(void);
	/*
		check punchState, return true if puchState == 1;
	*/
	bool IsPunching(void);
	/*
		change arm state w1, w2 ,elbowAngle1 and elbowAngle2
	*/
	void Punch(void);
	/*
		check if punch is finished, return ture if finished
	*/
	void CheckFinishPunching(void);

	/* Following functions describe what happen when a player hit his/her opponent*/
	/*
		take the other player as input, calculate the distance and return true if 
		the punch could cause damage to this player.
	*/
	bool IfPunchHit(const Player &opponent); 
	/*
		Change isHit to 1 if this player is punched by the other player.
	*/
	void ChangeHitState();
	/*
		Decrease or increse hp by 'amount'.
	*/
	void HPchange(const int amount);


	/*
		Drawing function of player, including arm.draw and leg.draw.
	*/
	void Draw();
};

class Arm
{
// protected:
// 	int xa,ya,xh,yh // albow, hand
public:
	/*
		Drawing function for arms.
	*/
	void Draw(void);
};

class Leg
{
// protected:
// 	int x1,y1,x2,y2
public:
	/*
		Drawing function for legs.
	*/
	void Draw(void);
};

/*
	Game class, represents the whole game
*/
class Game
{
public:
	void Run(void);
};

/*
	Potential Background class
*/
// class Background
// {
// public:
// 	void Blood(void);
// 	void Timer(void);
// };

#endif
