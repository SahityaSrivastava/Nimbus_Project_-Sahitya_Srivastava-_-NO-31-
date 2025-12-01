#ifndef DEVICE_H
#define DEVICE_H

#include "types.h"

typedef struct Schedule Schedule;

typedef struct {
    int id;
    char name[50];
    DeviceType type;
    State state;
    float power_rating;    // kW
    float energy_used;     // kWh
    int mode;              
    Schedule* schedule_head;
} Device;

extern Device* devices;
extern int device_count;

void addDevice(const char* name, DeviceType type, float rating);
void listDevices();
void resetDeviceEnergy();
void updateEnergyHour(int hour);

#endif
