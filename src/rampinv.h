#ifndef _RAMPINV_H
#define _RAMPINV_H

void rampinv_set_val1(unsigned char val);
void rampinv_set_val2(unsigned char val);

unsigned char rampinv_get();
void rampinv_tick();
void rampinv_reset();

#endif
