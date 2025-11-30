#include "schedule.h"
#include <stdlib.h>

Schedule* add_schedule(Schedule *head, int start, int end) {
    Schedule *s = malloc(sizeof(Schedule));
    s->start_min = start;
    s->end_min = end;
    s->next = head;
    return s;
}

int in_schedule(Schedule *head, int now_min) {
    Schedule *cur = head;
    while (cur) {
        if (now_min >= cur->start_min && now_min < cur->end_min)
            return 1;
        cur = cur->next;
    }
    return 0;
}
