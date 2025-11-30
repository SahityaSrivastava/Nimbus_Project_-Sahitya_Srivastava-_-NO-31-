#ifndef SCHEDULE_H
#define SCHEDULE_H

typedef struct Schedule {
    int start_min;
    int end_min;
    struct Schedule *next;
} Schedule;

Schedule* add_schedule(Schedule *head, int start, int end);
int in_schedule(Schedule *head, int now_min);

#endif
