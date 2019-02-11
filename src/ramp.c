#include "ramp.h"
#include <stdio.h>
#include <math.h>

unsigned short ramp_curr;
unsigned short ramp_max = 63000;
unsigned char ramp_inc;
unsigned char ramp_scale;

void ramp_set_val1(unsigned char val) {
	ramp_scale = val;
}

void ramp_set_val2(unsigned char val) {
	ramp_inc = val;
}

unsigned char ramp_get() {
	//printf("%d", ramp_curr);
	
	// Ramp
	return ramp_curr >> 8;

}

void ramp_tick() {
	//printf("%d,%d\n", ramp_curr, dir);
	ramp_curr += (unsigned short)ramp_inc;
	if (ramp_curr > ramp_max) {
		ramp_curr = ramp_curr - ramp_max;
	}
}

void ramp_reset() {
	ramp_curr = 0;
}

