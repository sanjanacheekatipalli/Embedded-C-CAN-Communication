#include <stdio.h>
#include <stdint.h>
#include "can.h"

int main(void)
{
    CAN_Message batteryMessage;
    CAN_Message motorMessage;
    CAN_Message temperatureMessage;
    CAN_Message statusMessage;

    /* Initialize CAN */
    CAN_Init();

    /*
     * Battery voltage message
     *
     * Battery voltage = 400 V
     * Stored as 4000 = 400.0 V
     * Resolution = 0.1 V
     */
    batteryMessage.id = CAN_ID_BATTERY;
    batteryMessage.dlc = 2;

    uint16_t batteryVoltage = 4000;

    batteryMessage.data[0] =
        (batteryVoltage >> 8) & 0xFF;

    batteryMessage.data[1] =
        batteryVoltage & 0xFF;

    CAN_SendMessage(&batteryMessage);

    /*
     * Motor speed message
     *
     * Motor speed = 3000 RPM
     */
    motorMessage.id = CAN_ID_MOTOR;
    motorMessage.dlc = 2;

    uint16_t motorSpeed = 3000;

    motorMessage.data[0] =
        (motorSpeed >> 8) & 0xFF;

    motorMessage.data[1] =
        motorSpeed & 0xFF;

    CAN_SendMessage(&motorMessage);

    /*
     * Temperature message
     *
     * Temperature = 75 °C
     */
    temperatureMessage.id = CAN_ID_TEMPERATURE;
    temperatureMessage.dlc = 1;

    temperatureMessage.data[0] = 75;

    CAN_SendMessage(&temperatureMessage);

    /*
     * Vehicle status message
     *
     * 0x01 = Vehicle system OK
     */
    statusMessage.id = CAN_ID_STATUS;
    statusMessage.dlc = 1;

    statusMessage.data[0] = 0x01;

    CAN_SendMessage(&statusMessage);

    return 0;
}
