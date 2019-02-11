#include "rampinv.h"
#include <stdio.h>
#include <math.h>

unsigned short rampinv_curr;
unsigned short rampinv_max = 65535-255;
unsigned char rampinv_inc;

void rampinv_set_max(unsigned char val) {
	rampinv_max = val << 8;
}

void rampinv_set_inc(unsigned char val) {
	rampinv_inc = val;
}

unsigned char rampinv_get() {
	return rampinv_curr >> 8;
}

void rampinv_tick() {
	if (rampinv_curr < rampinv_inc) {
		rampinv_curr = rampinv_max - (rampinv_inc - rampinv_curr);
	} else {
		rampinv_curr -= (unsigned short)rampinv_inc;
	}
}

void rampinv_reset() {
	rampinv_curr = 0;
}

