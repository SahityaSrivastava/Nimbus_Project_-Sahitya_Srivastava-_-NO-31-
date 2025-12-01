#include <stdio.h>
#include "device.h"
#include "schedule.h"
#include "controller.h"

int main() {

    addDevice("Living Room Light", TYPE_LIGHT, 0.05f);
    addDevice("Bedroom Light", TYPE_LIGHT, 0.05f);
    addDevice("Fan", TYPE_FAN, 0.15f);
    addDevice("AC", TYPE_AC, 1.50f);
    addDevice("Heater", TYPE_HEATER, 1.20f);
    addDevice("Smart Plug - Laptop", TYPE_SMARTPLUG, 0.10f);
    addDevice("Smart Plug - Kitchen", TYPE_SMARTPLUG, 0.20f);
    addDevice("Camera", TYPE_SECURITY, 0.50f);
    addDevice("Door Lock", TYPE_SECURITY, 0.02f);
    addDevice("Geyser", TYPE_GEYSER, 2.00f);

    // schedules 
    addSchedule(&devices[0], 18, 23, ON);  // living room light 18-23
    addSchedule(&devices[1], 19, 22, ON);  // bedroom light 19-22
    addSchedule(&devices[2], 12, 16, ON);  // fan 
    addSchedule(&devices[3], 13, 18, ON);  // AC afternoon

    // simulation,
    runDaySimulation();
    printEnergyReport();
    runWhatIf(2); 

    return 0;
}
