#ifndef TYPES_H
#define TYPES_H

typedef enum {
    TYPE_LIGHT,
    TYPE_FAN,
    TYPE_AC,
    TYPE_HEATER,
    TYPE_SMARTPLUG,
    TYPE_SECURITY,
    TYPE_GEYSER
} DeviceType;

typedef enum {
    OFF = 0,
    ON = 1
} State;

#endif
