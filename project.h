#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sense.h"
#include <linux/input.h>
#include <signal.h>
#include <math.h>

#define KEY_UP 103
#define KEY_DOWN 108
#define KEY_RIGHT 106
#define KEY_LEFT 105
#define KEY_ENTER 28
void callBackJoystick(unsigned int);
bool get_current_position(int *x, int *y);
void displayPoint(int x,int y,uint16_t color);
void clear(void);
void initializeFB(void);
void configure_sensors();
void pollJoystick_i();
double getAccelMagnitude();
void freeSensors();
void freeFB(void);
