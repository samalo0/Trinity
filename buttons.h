#ifndef BUTTONS_H
#define BUTTONS_H

#define BUTTONS_A_READ    digitalRead(0)
#define BUTTONS_B_READ    digitalRead(7)
#define BUTTONS_C_READ    digitalRead(2)

void buttons_isr0(void *userData);
void buttons_isr1(void *userData);
void buttons_isr2(void *userData);

#endif

