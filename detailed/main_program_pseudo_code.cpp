#include <gates_fighter.h>

#include <stdio.h>
#include <stdlib>
#include <time.h>
#include "fssimplewindow.h"

// pseudo code of the main program of gates fighter 
int main(void){
	/*******************************************************************/
	// initialize the background parameters

	/*******************************************************************/
	// the first while loop prompts a menu in the window
	// this menu allows the users to choose their characters
	// after users made their choices, exit while loop 

	/*******************************************************************/
	// initialize the corresponding fighter objects based on user's choice 

	/*******************************************************************/
	// the second while loop is the main body of the game
	/* 
		check for user inputs, possible inputs are:
			1. Esc exit the game 
			2. lateral movements (left or right). 
			   In total there should be four cases, two for player 1 and two for player two
			3. Jump In total, two cases. 
			4. Punch Each player can punch toward right and left, therefore, 4 cases. 
	*/
	/*
		if player1.IsPunching() == true 
			call Punch() to update arm position 
			if IfPunchHit()==true
				change player2 states and properties
			if CheckFinishPunching() == true
				change player 1 punching state to 0/false
	*/
	/*
		if player1.IsJumping() == 1
			call Jump() to update player's position 
			if checkHitGround() == 1
				change player's jumping state to 0
	*/
	/*
		if player2.IsPunching() == true 
			call Punch() to update arm position 
			if IfPunchHit()==true
				change player1 states and properties
			if CheckFinishPunching() == true
				change player 2 punching state to 0/false
	*/
	/*
		if player2.IsJumping() == 1
			call Jump() to update player's position 
			if checkHitGround() == 1
				change player's jumping state to 0
	*/
	/*
		Drawing everything by calling both player's Draw() function. 
		Draw() function will call corresponding body parts' draw functions. 
	*/
	// update game time
	// check both players' health powers   
	// exit the second loop if one player's health power equals to 0 or time runs out 
	/*******************************************************************/

	// enters the third while loop which displays the result of the game
	return 0;
}