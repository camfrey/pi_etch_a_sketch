#include "project.h"

int running = 1;

void signalhandler(int sig){
	printf("Signal Caught! Exiting...\n");
	running = 0;
}

void callBackFunction(unsigned int code){
	if(code == KEY_UP){
		printf("UP Pressed\n");
	}else if(code == KEY_DOWN){
		printf("DOWN Pressed\n");
	}else if(code == KEY_RIGHT){
		printf("RIGHT Pressed\n");
	}else if(code == KEY_LEFT){
		printf("LEFT Pressed\n");
	}
}

int main(void){
	signal(SIGINT, signalhandler);
	pi_i2c_t* device = geti2cDevice();
	pi_joystick_t* joystick = getJoystickDevice();
	coordinate_t accel_data;
	
	configureAccelGyro(device);
	while(running){
		pollJoystick(joystick, callBackFunction, 1000);
		getAccelData(device, &accel_data);
		printf("Device Acceleration X=%.2f(G) Y=%.2f(G) Z=%.2f(G)\n", accel_data.x, accel_data.y, accel_data.z);
	}
	printf("Loop Terminated\n");

	return 0;
}
