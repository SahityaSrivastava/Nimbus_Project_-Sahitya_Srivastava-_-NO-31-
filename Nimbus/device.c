#include "device.h"
#include <stdlib.h>
#include <string.h>

Device* create_device(int id, const char *name, DeviceType type, float power) {
    Device *d = malloc(sizeof(Device));

    d->id = id;
    strcpy(d->name, name);
    d->type = type;
    d->power_rating = power;
    d->energy_used = 0;
    d->schedule = NULL;
    d->status = 0;


    switch (type) {
        case DEV_FAN:        d->data = calloc(1, sizeof(FanData)); break;
        case DEV_HEATER:     d->data = calloc(1, sizeof(HeaterData)); break;
        case DEV_SMARTPLUG:  d->data = calloc(1, sizeof(SmartPlugData)); break;
        case DEV_CAMERA:     d->data = calloc(1, sizeof(CameraData)); break;
        case DEV_DOORLOCK:   d->data = calloc(1, sizeof(DoorLockData)); break;
        default:             d->data = NULL;
    }

    return d;
}

void free_device(Device *d) {
    if (d) {
        if (d->data) free(d->data);
        free(d);
    }
}
