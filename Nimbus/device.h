#ifndef DEVICE_H
#define DEVICE_H

#include "types.h"
#include "schedule.h"

typedef struct {
    int id;
    char name[50];
    DeviceType type;

    void *data;

    float power_rating;
    float energy_used;

    Schedule *schedule;
    int status;

} Device;

Device* create_device(int id, const char *name, DeviceType type, float power);
void free_device(Device *d);

#endif
