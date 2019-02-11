#include "ramp.h"
#include <stdio.h>
#include <math.h>

unsigned short ramp_curr;
unsigned short ramp_max = 65535-255;
unsigned short ramp_initial = 0;
unsigned char ramp_inc;
unsigned char ramp_single = 0;
unsigned char ramp_eoc = 0;

void ramp_check_bounds() {
	if (ramp_initial > ramp_max) {
		ramp_initial = ramp_max;
	}
}

void ramp_set_max(unsigned char val) {
	ramp_max = val << 8;
}

void ramp_set_inc(unsigned char val) {
	ramp_inc = val;
}

void ramp_set_single(unsigned char val) {
	ramp_single = val;	
}

void ramp_set_initial(unsigned char val) {
	ramp_initial = val << 8;
		
	ramp_check_bounds();
}

unsigned char ramp_get() {
	return ramp_curr >> 8;
}

void ramp_tick() {
	if (ramp_eoc) return;

	if (ramp_curr > ramp_max - ramp_inc) {
		if (ramp_single) {
			ramp_curr = 0; // End low or high?
			ramp_eoc = 1;
			return;
		}
		ramp_curr = ramp_inc - (ramp_max - ramp_curr);
	} else {
		ramp_curr += (unsigned short)ramp_inc;
	}
}

void ramp_reset() {
	ramp_curr = ramp_initial;
	ramp_eoc = 0;
}

