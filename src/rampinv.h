#ifndef _RAMPINV_H
#define _RAMPINV_H

void rampinv_set_max(unsigned char val);
void rampinv_set_inc(unsigned char val);

unsigned char rampinv_get();
void rampinv_tick();
void rampinv_reset();

#endif
