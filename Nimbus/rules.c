#include "rules.h"
#include <stdio.h>

void apply_rules(Controller *c, int now_min) {

    for (int i = 0; i < c->count; i++) {
        Device *d = c->devices[i];

        switch(d->type) {

            // -------------------------------------------------
            // FAN LOGIC (your old logic)
            // -------------------------------------------------
            case DEV_FAN: {
                FanData *f = d->data;

                if (!f->manual_override) {

                    if (f->temp > 35) f->speed = 3;
                    else if (f->temp > 30) f->speed = 2;
                    else if (f->humidity > 70) f->speed = 1;
                    else if (f->occupancy == 1) f->speed = 1;
                    else f->speed = 0;
                }

                d->status = (f->speed > 0);
                break;
            }

            // -------------------------------------------------
            // HEATER LOGIC (your old logic)
            // -------------------------------------------------
            case DEV_HEATER: {
                HeaterData *h = d->data;

                if (!h->manual_override) {

                    if (h->temp < 10) h->mode = 2;
                    else if (h->temp < 18) h->mode = 1;
                    else if (h->occupancy == 1) h->mode = 1;
                    else h->mode = 0;
                }

                d->status = (h->mode > 0);
                break;
            }

            // -------------------------------------------------
            // CAMERA LOGIC (your old logic)
            // -------------------------------------------------
            case DEV_CAMERA: {
                CameraData *cam = d->data;

                cam->night_vision = (cam->brightness < 300);
                cam->temp_alert = (cam->temp > 55 || cam->temp < 25);

                d->status = (cam->night_vision || cam->temp_alert);

                break;
            }

            // -------------------------------------------------
            // DOOR LOCK LOGIC (depends on camera)
            // -------------------------------------------------
            case DEV_DOORLOCK: {
                DoorLockData *lk = d->data;

                lk->locked = 0;
                for (int j = 0; j < c->count; j++) {
                    Device *camDev = c->devices[j];
                    if (camDev->type == DEV_CAMERA && camDev->status == 1) {
                        lk->locked = 1;
                        break;
                    }
                }

                break;
            }

            case DEV_SMARTPLUG:
                // smart plug follows schedule
                break;
        }
    }
}
