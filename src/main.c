#include <stdio.h>
#include "ramp.h"
#include "rampinv.h"
#include "triangle.h"

void reset_all() {
	ramp_reset();
	rampinv_reset();
	triangle_reset();
}

void tick_all() {
	ramp_tick();
	rampinv_tick();
	triangle_tick();
}

void graph(unsigned char val) {
	printf("%3d: ", val);
	unsigned char val2 = val >> 1;
	for (int i = 0; i < val2; i++) {
		printf(" ");
	}

	printf (".\n");
}

int main() {
	reset_all();

	ramp_set_val1(255);
	ramp_set_val2(10);
	rampinv_set_val1(255);
	rampinv_set_val2(10);
	triangle_set_val1(255);
	triangle_set_val2(10);

	for(int i=0; i<50000; i++) {
		tick_all();
		if (i % 12 == 0) {
			graph(ramp_get());
			//graph(rampinv_get());
			//graph(triangle_get());
		}
	}
}
