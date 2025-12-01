#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "device.h"

struct Schedule {
    int start_hour; 
    int end_hour;   
    State desired_state;
    struct Schedule* next;
};

void addSchedule(Device* d, int start, int end, State s);
void applySchedules(int hour);

#endif
