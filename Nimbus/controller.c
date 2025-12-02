#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include "controller.h"
#include "device.h"
#include "schedule.h"
#include "rules.h"




static int dayTemp[24] = {

 20,19,18,18,19,21,24,28,31,33,34,35,
 36,35,34,32,30,28,26,25,24,23,22,21
};

static int dayLight[24] = {
 0,0,10,30,200,600,900,1100,1200,1000,800,700,
 600,500,400,300,200,100,60,20,10,5,0,0
};

static int dayOcc[24] = {

 0,0,0,0,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,0,0,0
};

static int dayHum[24] = {

 60,60,62,65,68,70,72,75,78,80,75,70,
 68,65,60,58,55,53,50,48,50,55,58,60
};

int currentHumidity = 0; 

void runDaySimulation() {

    
    resetDeviceEnergy();

    for (int hr = 0; hr < 24; ++hr) {
        printf("\n=== Time: %02d:00 ===\n", hr);

        
        int temp = dayTemp[hr];
        int light = dayLight[hr];
        int occ = dayOcc[hr];
        currentHumidity = dayHum[hr];

        
        applySchedules(hr);

        applyRules(temp, light, occ);


        updateEnergyHour(hr);

        
        for (int i = 0; i < device_count; ++i) {
            Device* d = &devices[i];
            if (d->type == TYPE_FAN || d->type == TYPE_HEATER) {
                printf("%-20s : %s (mode=%d)\n", d->name, d->state ? "ON" : "OFF", d->mode);
            } else {
                printf("%-20s : %s\n", d->name, d->state ? "ON" : "OFF");
            }
        }
    }
}

void printEnergyReport() {
    printf("\n========== ENERGY USAGE REPORT ==========\n\n");
    float total = 0.0f;
    for (int i = 0; i < device_count; ++i) {
        printf("%-22s : %6.3f kWh\n", devices[i].name, devices[i].energy_used);
        total += devices[i].energy_used;
    }
    printf("-----------------------------------------\n");
    printf("TOTAL ENERGY USED : %.3f kWh\n", total);
    printf("=========================================\n");
}

void runWhatIf(int deltaTemp) {
    printf("\n========== WHAT-IF: TEMP +%d°C (no schedules) ==========\n\n", deltaTemp);


    Device* backup = malloc(device_count * sizeof(Device));
    memcpy(backup, devices, device_count * sizeof(Device));


    int baseHour = 12;
    int temp = dayTemp[baseHour] + deltaTemp;
    int light = dayLight[baseHour];
    int occ = dayOcc[baseHour];
    currentHumidity = dayHum[baseHour];

    // apply rules 
    for (int i = 0; i < device_count; ++i) {
        Device* d = &backup[i];

        switch (d->type) {
            case TYPE_FAN:
                d->mode = 0;
                if (temp > 35) d->mode = 3;
                else if (temp > 30) d->mode = 2;
                else if (currentHumidity > 70) d->mode = 1;
                else if (occ) d->mode = 1;
                d->state = (d->mode > 0) ? ON : OFF;
                break;

            case TYPE_HEATER:
                d->mode = 0;
                if (temp < 10) d->mode = 2;
                else if (temp < 18) d->mode = 1;
                else if (occ) d->mode = 1;
                d->state = (d->mode > 0) ? ON : OFF;
                break;
            case TYPE_SMARTPLUG:
                d->state = occ ? ON : OFF;
                break;

            case TYPE_SECURITY: {
                int tc = (temp > 55 || temp < 25) ? 1 : 0;
                int nv = (light < 300) ? 1 : 0;
                d->state = (tc || nv) ? ON : OFF;
                break;
            }
            case TYPE_AC:
                d->state = (temp > 32) ? ON : OFF;
                break;
            case TYPE_GEYSER:
                d->state = (temp < 20 && temp > 5) ? ON : OFF;
                break;
            default:
                break;
        }
    }


    for (int i = 0; i < device_count; ++i) {
        Device* d = &backup[i];
        if (d->type == TYPE_FAN || d->type == TYPE_HEATER)
            printf("%-20s : %s (mode=%d)\n", d->name, d->state ? "ON" : "OFF", d->mode);
        else
            printf("%-20s : %s\n", d->name, d->state ? "ON" : "OFF");
    }

    free(backup);
}
