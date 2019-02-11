#ifndef _RAMP_H
#define _RAMP_H

void ramp_set_val1(unsigned char val);
void ramp_set_val2(unsigned char val);

unsigned char ramp_get();
void ramp_tick();
void ramp_reset();

#endif
