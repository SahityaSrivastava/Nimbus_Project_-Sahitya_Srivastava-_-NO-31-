#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "device.h"

Device* devices = NULL;
int device_count = 0;

void addDevice(const char* name, DeviceType type, float rating) {
    device_count++;
    devices = realloc(devices, device_count * sizeof(Device));

    Device* d = &devices[device_count - 1];
    d->id = device_count;
    strncpy(d->name, name, sizeof(d->name)-1);
    d->name[sizeof(d->name)-1] = '\0';
    d->type = type;
    d->state = OFF;
    d->power_rating = rating;
    d->energy_used = 0.0f;
    d->mode = 0;
    d->schedule_head = NULL;
}

void listDevices() {
    printf("\n=== Devices ===\n");
    for (int i = 0; i < device_count; ++i) {
        printf("%2d: %-22s | type=%d | state=%s | mode=%d | power=%.2f kW\n",
               devices[i].id,
               devices[i].name,
               devices[i].type,
               devices[i].state ? "ON" : "OFF",
               devices[i].mode,
               devices[i].power_rating);
    }
}

void resetDeviceEnergy() {
    for (int i = 0; i < device_count; ++i) {
        devices[i].energy_used = 0.0f;
    }
}


void updateEnergyHour(int hour) {
    for (int i = 0; i < device_count; ++i) {
        Device* d = &devices[i];
        if (d->state == ON) {
            float add = 0.0f;
            if (d->type == TYPE_FAN) {
                

                if (d->mode == 1) add = 0.20f;
                else if (d->mode == 2) add = 0.35f;
                else if (d->mode == 3) add = 0.50f;
                else add = d->power_rating; 
            } else if (d->type == TYPE_HEATER) {
               
                if (d->mode == 1) add = 0.40f;
                else if (d->mode == 2) add = 0.75f;
                else add = d->power_rating;
            } else {
                // power rating
                add = d->power_rating * 1.0f;
            }
            d->energy_used += add;
        }
    }
}
