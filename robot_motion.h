/*
 * robot_motion.h
 *
 *  Created on: Nov 20, 2013
 *      Author: C15Brandon.Belcher
 *      Description: Header file for the robot motion library.
 */

#ifndef ROBOT_MOTION_H_
#define ROBOT_MOTION_H_

void InitPinsOut();

void InitTimer();

void moveForward();

void moveLeftForward();

void moveRightForward();

void moveLeftBackWard();

void moveRightBackward();

void moveBackward();

void rightTurn();

void leftTurn();


#endif /* ROBOT_MOTION_H_ */
