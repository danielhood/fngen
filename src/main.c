#include <stdio.h>
#include "ramp.h"
#include "triangle.h"

void reset_all() {
	ramp_reset();
	triangle_reset();
}

void tick_all() {
	ramp_tick();
	triangle_tick();
}

void graph(unsigned char val) {
	printf("%3d: ", ramp_get());
	unsigned char val2 = val >> 1;
	for (int i = 0; i < val2; i++){
		printf(" ");
	}

	printf (".\n");
}

int main() {
	reset_all();

	ramp_set_val1(10);
	ramp_set_val2(10);
	triangle_set_val1(255);
	triangle_set_val2(10);

	for(int i=0; i<50000; i++) {
		tick_all();
		if (i % 12 == 0) {
			//graph(ramp_get());
			graph(triangle_get());
		}
	}
}
