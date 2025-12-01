#include <stdlib.h>
#include "schedule.h"
#include "device.h"

static int within(int hour, int start, int end) {
    if (start <= end) return hour >= start && hour <= end;
    return hour >= start || hour <= end;
}

void addSchedule(Device* d, int start, int end, State s) {
    struct Schedule* p = malloc(sizeof(struct Schedule));
    p->start_hour = start;
    p->end_hour = end;
    p->desired_state = s;
    p->next = d->schedule_head;
    d->schedule_head = p;
}

void applySchedules(int hour) {
    for (int i = 0; i < device_count; ++i) {
        struct Schedule* s = devices[i].schedule_head;
        while (s) {
            if (within(hour, s->start_hour, s->end_hour)) {
                devices[i].state = s->desired_state;
            }
            s = s->next;
        }
    }
}
