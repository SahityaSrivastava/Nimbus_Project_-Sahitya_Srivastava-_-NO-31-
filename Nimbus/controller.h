#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "device.h"

typedef struct {
    Device *devices[20];
    int count;

    float ambient_temp;
    int brightness;
    int occupancy;

} Controller;

void controller_init(Controller *c);
void controller_add(Controller *c, Device *d);
void controller_update(Controller *c, int minute);

// NEW FUNCTIONS
void controller_report(Controller *c);
void simulate_what_if(Controller *c, float temp_change);

#endif
