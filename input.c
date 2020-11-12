#include "project.h"

/*Function to poll data from the joystick*/
/*Function to poll data from accelerometer*/

int current_x = 0;
int current_y = 0;
bool enter_pressed = false;
coordinate_t accel_data;
pi_joystick_t* joystick;
pi_i2c_t* device;
bool get_current_position(int *x, int *y){
	*y = current_y;
	*x = current_x;
	bool temp = enter_pressed;
	enter_pressed = false;
	return temp;
}

void callBackJoystick(unsigned int code){
	if (code == KEY_DOWN){
		if(current_y < 7){
			current_y++;
		}
	}else if(code == KEY_UP){
		if(current_y > 0){
			current_y--;
		}
	}else if(code == KEY_LEFT){
		if(current_x > 0){
			current_x--;
		}
	}else if(code == KEY_RIGHT){
		if(current_x < 7){
			current_x++;
		}
	}else if(code == KEY_ENTER){
		enter_pressed = true;
	}
}

void configure_sensors(){
	joystick = getJoystickDevice();
	device = geti2cDevice();
	configureAccelGyro(device);
	
}

void pollJoystick_i(){
	pollJoystick(joystick, callBackJoystick, 100);
}

double getAccelMagnitude(){
	getAccelData(device, &accel_data);
	double mag = sqrt(pow(accel_data.x, 2) + pow(accel_data.y, 2) + pow(accel_data.z, 2));
	return mag;	
	
}

void freeSensors(){
	freeJoystick(joystick);
	freei2cDevice(device);
}
