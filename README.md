# RobotMotion
Library for making the robot move. Example code included in example.c.

## General Notes
The right motor signal and the left motor signal are opposite of eachother.
The robot will move in the desired direction for however long `_delay_cycles()` is called after that function call as seen in example.c. All movement of the motors is at a 50% duty cycle.

## Functions
- `void InitPinsOut()`
	- Configures the pins as outputs
- `void InitTimer()`
	- Configures both timers on the chip to help determine duty cycles
- `void moveLeftForward()`
	- Moves the left motor forward
- `void moveRightForward()`
	- Moves the right motor forward
- `void moveLeftBackward()`
	- Moves the left motor backward
- `void moveRightBackward()`
	- Moves the right motor backward
- `void moveForward()`
	- Moves the entire robot forward by making both motors move forward
- `void moveBackward()`
	- Moves the entire robot backward by making both motors move backward
- `void rightTurn()`
	- Makes the robot make a right turn in position by making the left motor move forward and the right motor move backward
- `void leftTurn()`
	- Makes the robot make a left turn in position by making the right motor move forward and the left motor move backward

## License
Anyone is free to use and modify this for any purpose, provided they document it.

## Documentation
C2C Michael Bentley helped me determine the pin outs to use for the proper signals.
