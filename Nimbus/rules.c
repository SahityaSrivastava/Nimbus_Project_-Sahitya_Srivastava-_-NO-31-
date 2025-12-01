#include "rules.h"
#include "device.h"



extern int currentHumidity; 



void applyRules(int temp, int light, int occ) {
    for (int i = 0; i < device_count; ++i) {
        Device* d = &devices[i];

        switch (d->type) {

            case TYPE_FAN: {
                
                d->mode = 0;
                if (temp > 35) d->mode = 3;
                else if (temp > 30) d->mode = 2;
                else if (currentHumidity > 70) d->mode = 1;
                else if (occ) d->mode = 1;
                
                d->state = (d->mode > 0) ? ON : OFF;
                break;
            }

            case TYPE_HEATER: {
                d->mode = 0;
                if (temp < 10) d->mode = 2;
                else if (temp < 18) d->mode = 1;
                else if (occ) d->mode = 1;
                d->state = (d->mode > 0) ? ON : OFF;
                break;
            }

            case TYPE_SMARTPLUG: {
                
                d->state = occ ? ON : OFF;
                d->mode = 0;
                break;
            }

            case TYPE_SECURITY: {
                
                int tc = (temp > 55 || temp < 25) ? 1 : 0;
                int nv = (light < 300) ? 1 : 0;
                d->state = (tc || nv) ? ON : OFF;
                d->mode = 0;
                break;
            }

            case TYPE_AC: {
                d->mode = 0;
                d->state = (temp > 32) ? ON : OFF;
                break;
            }

            case TYPE_GEYSER: {
                
                d->state = (temp < 20 && temp > 5) ? ON : OFF;
                d->mode = 0;
                break;
            }

            case TYPE_LIGHT:
            default:
                
                break;
        }
    }
}
