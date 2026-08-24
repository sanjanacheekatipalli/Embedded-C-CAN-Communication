#ifndef VEHICLE_DATA_H
#define VEHICLE_DATA_H

#include <stdint.h>

/* Vehicle operating data */

typedef struct
{
    uint16_t batteryVoltage;
    uint16_t motorSpeed;
    int8_t temperature;
    uint8_t vehicleStatus;

} VehicleData;

/* Vehicle status definitions */

#define VEHICLE_STATUS_OK       0x01
#define VEHICLE_STATUS_WARNING  0x02
#define VEHICLE_STATUS_FAULT    0x03

#endif
