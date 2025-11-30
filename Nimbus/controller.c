#include "controller.h"
#include "rules.h"
#include "schedule.h"
#include <stdio.h>

void controller_init(Controller *c) {
    c->count = 0;
    c->ambient_temp = 30;
    c->brightness = 600;
    c->occupancy = 1;
}

void controller_add(Controller *c, Device *d) {
    c->devices[c->count++] = d;
}

void controller_update(Controller *c, int minute) {

    // Schedules
    for (int i = 0; i < c->count; i++) {
        Device *d = c->devices[i];

        if (d->schedule) {
            d->status = in_schedule(d->schedule, minute);
        }
    }

    // Apply rule engine
    apply_rules(c, minute);

    // Energy and uptime
    for (int i = 0; i < c->count; i++) {

        Device *d = c->devices[i];
        if (d->status == 0) continue;

        switch (d->type) {

            case DEV_FAN: {
                FanData *f = d->data;
                f->uptime++;
                f->energy += f->power_rating * 0.001;
                break;
            }

            case DEV_HEATER: {
                HeaterData *h = d->data;
                h->uptime++;
                h->energy += h->power_rating * 0.001;
                break;
            }

            case DEV_SMARTPLUG: {
                SmartPlugData *p = d->data;
                p->uptime++;
                p->energy += p->power_rating * 0.001;
                break;
            }

            case DEV_CAMERA: {
                CameraData *cam = d->data;
                cam->uptime++;
                cam->energy += cam->cam_power * 0.001;
                if (cam->night_vision)
                    cam->energy += cam->nv_power * 0.001;
                break;
            }

            case DEV_DOORLOCK: {
                DoorLockData *lk = d->data;
                lk->uptime++;
                lk->energy += lk->power_rating * 0.001;
                break;
            }
        }
    }
}

// ===========================================================
// ENERGY REPORT (REQUIRED BY QUESTION)
// ===========================================================
void controller_report(Controller *c) {

    float total_energy = 0;

    printf("\n=========== ENERGY USAGE REPORT ===========\n");

    for (int i = 0; i < c->count; i++) {
        Device *d = c->devices[i];

        float used = 0;

        switch (d->type) {
            case DEV_FAN:        used = ((FanData*)d->data)->energy; break;
            case DEV_HEATER:     used = ((HeaterData*)d->data)->energy; break;
            case DEV_SMARTPLUG:  used = ((SmartPlugData*)d->data)->energy; break;
            case DEV_CAMERA:     used = ((CameraData*)d->data)->energy; break;
            case DEV_DOORLOCK:   used = ((DoorLockData*)d->data)->energy; break;
        }

        total_energy += used;

        printf("%-20s : %.3f kWh\n", d->name, used);
    }

    printf("-------------------------------------------\n");
    printf("TOTAL ENERGY USED : %.3f kWh\n", total_energy);
    printf("===========================================\n\n");
}

// ===========================================================
// WHAT-IF SCENARIO (REQUIRED BY QUESTION)
// ===========================================================
void simulate_what_if(Controller *c, float temp_change) {

    printf("\n=========== WHAT-IF: TEMP CHANGE %.1f°C ===========\n",
           temp_change);

    float old_temp = c->ambient_temp;
    c->ambient_temp += temp_change;

    // Apply rule engine once
    controller_update(c, 0);

    // Print status per device
    for (int i = 0; i < c->count; i++) {
        Device *d = c->devices[i];

        printf("%-20s : %s\n", d->name, d->status ? "ON" : "OFF");
    }

    // Restore normal temp
    c->ambient_temp = old_temp;

    printf("====================================================\n\n");
}
