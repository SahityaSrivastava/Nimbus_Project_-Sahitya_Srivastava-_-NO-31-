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


/* Output

=== Time: 00:00 ===
Living Room Light    : OFF
Bedroom Light        : OFF
Fan                  : OFF (mode=0)
AC                   : OFF
Heater               : OFF (mode=0)
Smart Plug - Laptop  : OFF
Smart Plug - Kitchen : OFF
Camera               : ON
Door Lock            : ON
Geyser               : OFF

=== Time: 01:00 ===
Living Room Light    : OFF
Bedroom Light        : OFF
Fan                  : OFF (mode=0)
AC                   : OFF
Heater               : OFF (mode=0)
Smart Plug - Laptop  : OFF
Smart Plug - Kitchen : OFF
Camera               : ON
Door Lock            : ON
Geyser               : ON

=== Time: 02:00 ===
Living Room Light    : OFF
Bedroom Light        : OFF
Fan                  : OFF (mode=0)
AC                   : OFF
Heater               : OFF (mode=0)
Smart Plug - Laptop  : OFF
Smart Plug - Kitchen : OFF
Camera               : ON
Door Lock            : ON
Geyser               : ON

=== Time: 03:00 ===
Living Room Light    : OFF
Bedroom Light        : OFF
Fan                  : OFF (mode=0)
AC                   : OFF
Heater               : OFF (mode=0)
Smart Plug - Laptop  : OFF
Smart Plug - Kitchen : OFF
Camera               : ON
Door Lock            : ON
Geyser               : ON

=== Time: 04:00 ===
Living Room Light    : OFF
Bedroom Light        : OFF
Fan                  : ON (mode=1)
AC                   : OFF
Heater               : ON (mode=1)
Smart Plug - Laptop  : ON
Smart Plug - Kitchen : ON
Camera               : ON
Door Lock            : ON
Geyser               : ON

=== Time: 05:00 ===
Living Room Light    : OFF
Bedroom Light        : OFF
Fan                  : ON (mode=1)
AC                   : OFF
Heater               : ON (mode=1)
Smart Plug - Laptop  : ON
Smart Plug - Kitchen : ON
Camera               : ON
Door Lock            : ON
Geyser               : OFF

=== Time: 06:00 ===
Living Room Light    : OFF
Bedroom Light        : OFF
Fan                  : ON (mode=1)
AC                   : OFF
Heater               : ON (mode=1)
Smart Plug - Laptop  : ON
Smart Plug - Kitchen : ON
Camera               : ON
Door Lock            : ON
Geyser               : OFF

=== Time: 07:00 ===
Living Room Light    : OFF
Bedroom Light        : OFF
Fan                  : ON (mode=1)
AC                   : OFF
Heater               : ON (mode=1)
Smart Plug - Laptop  : ON
Smart Plug - Kitchen : ON
Camera               : OFF
Door Lock            : OFF
Geyser               : OFF

=== Time: 08:00 ===
Living Room Light    : OFF
Bedroom Light        : OFF
Fan                  : ON (mode=2)
AC                   : OFF
Heater               : ON (mode=1)
Smart Plug - Laptop  : ON
Smart Plug - Kitchen : ON
Camera               : OFF
Door Lock            : OFF
Geyser               : OFF

=== Time: 09:00 ===
Living Room Light    : OFF
Bedroom Light        : OFF
Fan                  : ON (mode=2)
AC                   : ON
Heater               : ON (mode=1)
Smart Plug - Laptop  : ON
Smart Plug - Kitchen : ON
Camera               : OFF
Door Lock            : OFF
Geyser               : OFF

=== Time: 10:00 ===
Living Room Light    : OFF
Bedroom Light        : OFF
Fan                  : ON (mode=2)
AC                   : ON
Heater               : ON (mode=1)
Smart Plug - Laptop  : ON
Smart Plug - Kitchen : ON
Camera               : OFF
Door Lock            : OFF
Geyser               : OFF

=== Time: 11:00 ===
Living Room Light    : OFF
Bedroom Light        : OFF
Fan                  : ON (mode=2)
AC                   : ON
Heater               : ON (mode=1)
Smart Plug - Laptop  : ON
Smart Plug - Kitchen : ON
Camera               : OFF
Door Lock            : OFF
Geyser               : OFF

=== Time: 12:00 ===
Living Room Light    : OFF
Bedroom Light        : OFF
Fan                  : ON (mode=3)
AC                   : ON
Heater               : ON (mode=1)
Smart Plug - Laptop  : ON
Smart Plug - Kitchen : ON
Camera               : OFF
Door Lock            : OFF
Geyser               : OFF

=== Time: 13:00 ===
Living Room Light    : OFF
Bedroom Light        : OFF
Fan                  : ON (mode=2)
AC                   : ON
Heater               : ON (mode=1)
Smart Plug - Laptop  : ON
Smart Plug - Kitchen : ON
Camera               : OFF
Door Lock            : OFF
Geyser               : OFF

=== Time: 14:00 ===
Living Room Light    : OFF
Bedroom Light        : OFF
Fan                  : ON (mode=2)
AC                   : ON
Heater               : ON (mode=1)
Smart Plug - Laptop  : ON
Smart Plug - Kitchen : ON
Camera               : OFF
Door Lock            : OFF
Geyser               : OFF

=== Time: 15:00 ===
Living Room Light    : OFF
Bedroom Light        : OFF
Fan                  : ON (mode=2)
AC                   : OFF
Heater               : ON (mode=1)
Smart Plug - Laptop  : ON
Smart Plug - Kitchen : ON
Camera               : OFF
Door Lock            : OFF
Geyser               : OFF

=== Time: 16:00 ===
Living Room Light    : OFF
Bedroom Light        : OFF
Fan                  : ON (mode=1)
AC                   : OFF
Heater               : ON (mode=1)
Smart Plug - Laptop  : ON
Smart Plug - Kitchen : ON
Camera               : ON
Door Lock            : ON
Geyser               : OFF

=== Time: 17:00 ===
Living Room Light    : OFF
Bedroom Light        : OFF
Fan                  : ON (mode=1)
AC                   : OFF
Heater               : ON (mode=1)
Smart Plug - Laptop  : ON
Smart Plug - Kitchen : ON
Camera               : ON
Door Lock            : ON
Geyser               : OFF

=== Time: 18:00 ===
Living Room Light    : ON
Bedroom Light        : OFF
Fan                  : ON (mode=1)
AC                   : OFF
Heater               : ON (mode=1)
Smart Plug - Laptop  : ON
Smart Plug - Kitchen : ON
Camera               : ON
Door Lock            : ON
Geyser               : OFF

=== Time: 19:00 ===
Living Room Light    : ON
Bedroom Light        : ON
Fan                  : ON (mode=1)
AC                   : OFF
Heater               : ON (mode=1)
Smart Plug - Laptop  : ON
Smart Plug - Kitchen : ON
Camera               : ON
Door Lock            : ON
Geyser               : OFF

=== Time: 20:00 ===
Living Room Light    : ON
Bedroom Light        : ON
Fan                  : ON (mode=1)
AC                   : OFF
Heater               : ON (mode=1)
Smart Plug - Laptop  : ON
Smart Plug - Kitchen : ON
Camera               : ON
Door Lock            : ON
Geyser               : OFF

=== Time: 21:00 ===
Living Room Light    : ON
Bedroom Light        : ON
Fan                  : OFF (mode=0)
AC                   : OFF
Heater               : OFF (mode=0)
Smart Plug - Laptop  : OFF
Smart Plug - Kitchen : OFF
Camera               : ON
Door Lock            : ON
Geyser               : OFF

=== Time: 22:00 ===
Living Room Light    : ON
Bedroom Light        : ON
Fan                  : OFF (mode=0)
AC                   : OFF
Heater               : OFF (mode=0)
Smart Plug - Laptop  : OFF
Smart Plug - Kitchen : OFF
Camera               : ON
Door Lock            : ON
Geyser               : OFF

=== Time: 23:00 ===
Living Room Light    : ON
Bedroom Light        : ON
Fan                  : OFF (mode=0)
AC                   : OFF
Heater               : OFF (mode=0)
Smart Plug - Laptop  : OFF
Smart Plug - Kitchen : OFF
Camera               : ON
Door Lock            : ON
Geyser               : OFF

========== ENERGY USAGE REPORT ==========

Living Room Light      :  0.300 kWh
Bedroom Light          :  0.250 kWh
Fan                    :  4.750 kWh
AC                     :  9.000 kWh
Heater                 :  6.800 kWh
Smart Plug - Laptop    :  1.700 kWh
Smart Plug - Kitchen   :  3.400 kWh
Camera                 :  7.500 kWh
Door Lock              :  0.300 kWh
Geyser                 :  8.000 kWh
-----------------------------------------
TOTAL ENERGY USED : 42.000 kWh
=========================================

========== WHAT-IF: TEMP +2┬░C (no schedules) ==========

Living Room Light    : ON
Bedroom Light        : ON
Fan                  : ON (mode=3)
AC                   : ON
Heater               : ON (mode=1)
Smart Plug - Laptop  : ON
Smart Plug - Kitchen : ON
Camera               : OFF
Door Lock            : OFF
Geyser               : OFF

*/