#include <msp430.h>
#include "robot_motion.h"
/*
 * robot_motion.c
 *
 *  Created on: Nov 20, 2013
 *      Author: C15Brandon.Belcher
 *      Description: It is important to note that the motors' signals are flipped.
 *      In order to make the right motor move forward, a similar signal as making the left
 *      motor move backward is sent. This is because of the wiring on my specific robot. The
 *      terminals are switched.
 */

void InitPinsOut() {
	//initialize pins out
	//I used BITS 1 and 2 for P1 to control the left motor
	P1DIR |= BIT1;
	P1SEL |= BIT1;

	P1DIR |= BIT2;
	P1SEL |= BIT2;

	//The following declarations were used to control the right motor
	P2DIR |= BIT0;
	P2SEL |= BIT0;

	P2DIR |= BIT1;
	P2SEL |= BIT1;
}

//This initializes the timers for P1 and P2
void InitTimer() {

	TA0CTL &= ~MC1 | MC0;
	TA1CTL &= ~MC1 | MC0;

	TA0CTL |= TACLR;                // clear timer A0
	TA1CTL |= TACLR;

	TA0CTL |= TASSEL1;           // configure for SMCLK
	TA1CTL |= TASSEL1;

	TA0CCR0 = 100;   // set signal period to 100 clock cycles (~100 microseconds)
	TA1CCR0 = 100;	// set the signal period to 100 clock cycles (~100 microseconds)
	TA0CCR1 = 0;	// set the value of the duty cycle (0% here)
	TA1CCR1 = 0;	// set the value of the duty cycle (0% here)

	TA0CCTL1 |= OUTMOD_7;
	TA0CCTL0 |= OUTMOD_5;	//makes this the equivalent of ground for the left motor
	TA1CCTL1 |= OUTMOD_7;
	TA1CCTL0 |= OUTMOD_5;	//makes this the equivalent of ground for the right motor


	//count up
	TA0CTL |= MC0;
	TA1CTL |= MC0;

}

//moves the left motor forward
void moveLeftForward(){
	//set a 50% duty cycle in the positive terminal
	TA0CCR1 = 50;
	//make the negative terminal the equivalent of ground
	TA0CCTL0 = OUTMOD_5;
}

//moves the right motor backward
void moveRightBackward(){
	//set a 50% duty cycle in the terminal
	TA1CCR1 = 50;
	//make other terminal the equivalent of ground
	TA1CCTL0 = OUTMOD_5;
}

//moves the left motor backward
void moveLeftBackward(){
	//set the positive terminal signal to the equivalent of ground
	TA0CCR1 = 0;
	//set the negative terminal signal to toggle mode, equivalent of 50% duty cycle
	TA0CCTL0 = OUTMOD_4;
}

//moves the right motor forward
void moveRightForward(){
	//set the positive terminal signal to the equivalent of ground, 0% duty cycle
	TA1CCR1 = 0;
	//set the negative terminal signal to toggle mode, equivalent of 50% duty cycle
	TA1CCTL0 = OUTMOD_4;
}

//moves the entire robot forward in a straight line
void moveForward(){
	moveLeftForward();
	moveRightForward();
}

//moves the entire robot backward in a straight line
void moveBackward(){
	moveLeftBackward();
	moveRightBackward();
}

//makes the robot turn right in place
void rightTurn(){
	moveLeftForward();
	moveRightBackward();
}

//makes the robot turn left in place
void leftTurn(){
	moveLeftBackward();
	moveRightForward();
}
