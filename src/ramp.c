#include "ramp.h"
#include <stdio.h>
#include <math.h>

unsigned short ramp_curr;
unsigned short ramp_max = 65535-255;
unsigned char ramp_inc;

void ramp_set_val1(unsigned char val) {
	if (val == 255) val = 254;

	ramp_max = val << 8;
}

void ramp_set_val2(unsigned char val) {
	ramp_inc = val;
}

unsigned char ramp_get() {
	return ramp_curr >> 8;
}

void ramp_tick() {
	if (ramp_curr > ramp_max - ramp_inc) {
		ramp_curr = ramp_inc - (ramp_max - ramp_curr);
	} else {
		ramp_curr += (unsigned short)ramp_inc;
	}
}

void ramp_reset() {
	ramp_curr = 0;
}

