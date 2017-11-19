#ifndef GAME_CLASS_IS_INCLUDED
#define GAME_CLASS_IS_INCLUDED

void DrawPlayer(int x,int y);

class Player
{
protected:
	int x,y,hp,attack,ay,vx,vy,direction,jumpState,punchState,IsHit;
	int w1,w2,elbowAngle1,elbowAngle2;

public:
	Player(); // initialize a player

	/* The following functions are getters of this class. */
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

	void Move(void); // change x

	void InitializeJumping(void); // initialize a jump
	bool IsJumping(void); // jumpState=1, vy
	void Jump(void); // change vy, y
	void CheckHitGround(void);

	void InitializePunching(void); // initialize a punch
	bool IsPunching(void); // punchState=1, w1, w2
	void Punch(void); // change elbowAngle1, elbowAngle2
	void CheckFinishPunching(void);

	/*the following functions describe what happen when a player hit his/her opponent*/
	bool IfPunchHit(const Player &opponent); // 
	void ChangeHitState(); // change the isHit state of a player if he/she is hit by the opponent
	void HPchange(const int amount);


	void Draw();
};

class Arm
{
// protected:
// 	int xa,ya,xh,yh // albow, hand
public:
	void Draw(void);
};

class Leg
{
// protected:
// 	int x1,y1,x2,y2
public:
	void Draw(void);
};

class Game
{
public:
	void Run(void);
};

// class Background
// {
// public:
// 	void Blood(void);
// 	void Timer(void);
// };

#endif
