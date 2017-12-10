#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_HBridge, openLoop, driveLeft, encoderPort, None)
#pragma config(Motor,  port4,           rightMotor,    tmotorVex393_HBridge, openLoop, driveRight)
#pragma config(Motor,  port6,           armMotor,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           clawMotor,     tmotorVex393_MC29, openLoop)
// REMOVE THIS MOTOR CONFIG AND USE THE 'Motor and Sensors Setup' TO CONFIGURE MOTORS!!!!
/*

OPEN-SOURCE BASIC CLAWBOT VEX 2.0 v1
 ______     ______     ______     __  __    
/\  ___\   /\  __ \   /\  == \   /\ \_\ \   
\ \ \____  \ \ \/\ \  \ \  __<   \ \____ \  
 \ \_____\  \ \_____\  \ \_\ \_\  \/\_____\ 
  \/_____/   \/_____/   \/_/ /_/   \/_____/ 
                                            
  coded by the CG Creations.
--==============================================================================================================--  
  currentMovement currently does nothing, but instead of setting the motors based on signals of Channels 3 and 2
  of the JoyStick, we will set them on preset threshold and speed values.
	Basically, it would look something like this:
	int speed = whateverYouWant;
	int currentMovement = 0;
	0 == Left Moving
  1 == Right Moving
  2 == None Moving
  3 == All Moving
	int threshold = 20;
if(currentMovement == 0) {
	if(speed >= threshold){
	   motor[nameOfMotor] = speed;
  }
}
--==============================================================================================================--  
Changelog:
>> Minor Control changes
>> Major Claw Fix

  */
task main() {
  //int currentMovement = 0;
	//int speed = 0;
  //int threshold = 20;

  while (true) {
    if (vexRT[Ch3]) {
      motor[leftMotor] = vexRT[Ch3];
    } else {
			motor[leftMotor] = 0;
    }
    // Right Joystick ^
    if (vexRT[Ch2]) {
      motor[rightMotor] = vexRT[Ch2];
    } else {
      motor[rightMotor] = 0;
    }
    //Left Joystick ^
    if(vexRT[Btn5D]) {
    	motor[armMotor] = 127;
    } else if(vexRT[Btn6D]) {
  		motor[armMotor] = -127;
    } else {
  		motor[armMotor] = 0;
    }
    // Right Trigger 2 && Left Trigger 2 ^
    if(vexRT[Btn5U]){
    	motor[clawMotor] = 127;	
    } else if(vexRT[Btn6U]){
  		motor[clawMotor] = -127;
    } else {
  		motor[clawMotor] = 0;
    }
    // Right Trigger 1 && Left Trigger 1 ^
  }
}
