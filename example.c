#include <msp430.h> 
#include "robot_motion.h"

/*
 * example.c
 * Description: Makes the robot move in the corresponding directions.
 * The length of delay cycles after each function call determines how
 * long/far the robot moves in that particular direction.
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    InitPinsOut();
    InitTimer();


	while (1) {
		//move forward
		moveForward();
		_delay_cycles(1000000);

		//move backward
		moveBackward();
		_delay_cycles(1000000);

		//complete a small (<45 degree) right turn
		rightTurn();
		_delay_cycles(500000);

		//complete a small (<45 degree) left turn
		leftTurn();
		_delay_cycles(500000);

		//complete a large (>45 degree) right turn
		rightTurn();
		_delay_cycles(1000000);

		//complete a large (>45 degree) left turn
		leftTurn();
		_delay_cycles(1000000);
	}

	return 0;
}
