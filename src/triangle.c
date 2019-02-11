#include <stdio.h>
#include <math.h>
#include "triangle.h"

unsigned short triangle_curr;
char triangle_dir = 1;
unsigned short triangle_max = 65535-256;
unsigned char triangle_inc;

// Temp vars
unsigned char triangle_ovr;

void triangle_set_val1(unsigned char val) {
	if (val == 255) val = 254;
	triangle_max = val << 8;
}

void triangle_set_val2(unsigned char val) {
	triangle_inc = val;
}

unsigned char triangle_get() {
	return triangle_curr >> 8;
}

void triangle_tick() {
	if (triangle_curr < triangle_inc) {
		triangle_curr = triangle_inc - triangle_curr;
		triangle_dir = 1;
	} else if (triangle_curr > triangle_max - triangle_inc) {
		triangle_ovr = triangle_max - triangle_curr;
		triangle_curr = triangle_max - triangle_inc - triangle_ovr;
		triangle_dir = -1;
	} else {
		triangle_curr += ((unsigned short)(short)triangle_inc * triangle_dir);
	}
}

void triangle_reset() {
	triangle_curr = 0;
	triangle_dir = 1;
}
