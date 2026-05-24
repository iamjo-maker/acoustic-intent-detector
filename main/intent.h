#ifndef INTENT_H
#define INTENT_H

#include <stdbool.h>

void intent_init(void);
bool intent_update(int sample);
float intent_get_energy(void);
float intent_get_baseline(void);

#endif
