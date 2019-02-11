#include "rampinv.h"
#include <stdio.h>
#include <math.h>

unsigned short rampinv_curr;
unsigned short rampinv_max = 65535-255;
unsigned short rampinv_initial = 0;
unsigned char rampinv_inc;
unsigned char rampinv_single = 0;

void rampinv_check_bounds() {
	if (rampinv_initial > rampinv_max) {
		rampinv_initial = rampinv_max;
	}
}

void rampinv_set_max(unsigned char val) {
	rampinv_max = val << 8;

	rampinv_check_bounds();
}

void rampinv_set_inc(unsigned char val) {
	rampinv_inc = val;
}

void rampinv_set_single(unsigned char val) {
	rampinv_single = val;	
}

void rampinv_set_initial(unsigned char val) {
	rampinv_initial = val << 8;
		
	rampinv_check_bounds();
}

unsigned char rampinv_get() {
	return rampinv_curr >> 8;
}

void rampinv_tick() {
	if (rampinv_curr < rampinv_inc) {
		if (rampinv_single) {
			rampinv_curr = 0;
			return;
		}
		rampinv_curr = rampinv_max - (rampinv_inc - rampinv_curr);
	} else {
		rampinv_curr -= (unsigned short)rampinv_inc;
	}
}

void rampinv_reset() {
	rampinv_curr = rampinv_initial;
}

