#include <stdio.h>
#include "fan.h"
#include "heater.h"

int main() {
    printf("Starting System...\n");
    
    runfan();
    runheater();
    return 0;
}
