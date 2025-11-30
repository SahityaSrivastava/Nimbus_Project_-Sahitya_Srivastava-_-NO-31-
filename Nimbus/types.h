#ifndef TYPES_H
#define TYPES_H

typedef enum {
    DEV_LIGHT,
    DEV_FAN,
    DEV_HEATER,
    DEV_AC,
    DEV_SMARTPLUG,
    DEV_CAMERA,
    DEV_DOORLOCK,
    DEV_GEYSER
} DeviceType;



// FAN
typedef struct {
    float temp;
    int humidity;
    int occupancy;
    int speed;
    int manual_override;
    int uptime;
    float power_rating;
    float energy;
} FanData;

// HEATER
typedef struct {
    float temp;
    int occupancy;
    int manual_override;
    int mode;
    int uptime;
    float power_rating;
    float energy;
} HeaterData;

// SMART PLUG
typedef struct {
    int status;
    float power_rating;
    float current_power;
    float energy;
    int uptime;
} SmartPlugData;

// CAMERA
typedef struct {
    float temp;
    int brightness;
    int night_vision;
    int temp_alert;
    int status;
    int uptime;
    float cam_power;
    float nv_power;
    float energy;
} CameraData;

// DOOR LOCK
typedef struct {
    int locked;
    int uptime;
    float power_rating;
    float energy;
} DoorLockData;

#endif
