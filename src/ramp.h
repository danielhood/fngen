#ifndef _RAMP_H
#define _RAMP_H

void ramp_set_max(unsigned char val);
void ramp_set_inc(unsigned char val);
void ramp_set_single(unsigned char val);
void ramp_set_initial(unsigned char val);

unsigned char ramp_get();
void ramp_tick();
void ramp_reset();

#endif
