#include "project.h"

int internal_x;
int internal_y;
int old_x;
int old_y;
bool old_enter;
int running = 1;


void signalHandler(int);
int main(void){
	signal(SIGINT, signalHandler);
	uint16_t color = getColor(255, 0, 255);
	float old_data;
	double ac_mag;
	initializeFB();
	configure_sensors();
	clear(); //FB clear
	while(running){
		pollJoystick_i();
		bool enter = get_current_position(&internal_x, &internal_y);
		ac_mag = getAccelMagnitude();
		if(old_y != internal_y || old_x != internal_x || enter != old_enter || abs(ac_mag - old_data) > 0.1){
 			displayPoint(internal_x, internal_y, color); 
			printf("X: %d, Y: %d ENTER: %d\n", internal_x, internal_y, enter);
			printf("Acceleration Magnitude: %.2f\n", ac_mag);

			old_x = internal_x;
			old_y = internal_y;
			old_enter = enter;
			old_data = ac_mag;

			
			if(enter){
				color = (int)(drand48() * (pow(2, 16) -1));
			}
			if(ac_mag > 5){
				running = 0;
			}
			if(ac_mag > 2){
				clear();
				printf("Shakey Shakey...\n");
			}
		}

	}
	printf("Releasing Hardware...\n");
	clear();
	freeSensors();
	freeFB();

return 0;
}

void signalHandler(int sig){
	printf("Signal Caught! Exiting...\n");
	running = 0;
}
