#include <stdio.h>
#include "controller.h"
#include "device.h"
#include "schedule.h"

int main() {

    Controller c;
    controller_init(&c);

    // DEVICES
    controller_add(&c, create_device(1, "Fan", DEV_FAN, 50));
    controller_add(&c, create_device(2, "Heater", DEV_HEATER, 1000));
    controller_add(&c, create_device(3, "Laptop Plug", DEV_SMARTPLUG, 65));
    controller_add(&c, create_device(4, "Kitchen Plug", DEV_SMARTPLUG, 1500));
    controller_add(&c, create_device(5, "Camera", DEV_CAMERA, 7));
    controller_add(&c, create_device(6, "Door Lock", DEV_DOORLOCK, 3));

    // Schedule: laptop charger ON between 6AM–8AM
    c.devices[2]->schedule = add_schedule(NULL, 360, 480);

    // SIMULATE 24 HOURS (1-hour steps)
    for (int t = 0; t < 1440; t += 60) {
        printf("\n=== Time: %02d:00 ===\n", t/60);
        controller_update(&c, t);
    }

    // REQUIRED PART 1: ENERGY REPORT
    controller_report(&c);

    // REQUIRED PART 2: WHAT-IF SCENARIO
    simulate_what_if(&c, +2.0);

    return 0;
}
