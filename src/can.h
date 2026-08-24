#ifndef CAN_H
#define CAN_H

#include <stdint.h>

/* Standard automotive CAN message structure */
typedef struct
{
    uint16_t id;
    uint8_t dlc;
    uint8_t data[8];

} CAN_Message;

/* CAN message identifiers */

#define CAN_ID_BATTERY      0x100
#define CAN_ID_MOTOR        0x101
#define CAN_ID_TEMPERATURE  0x102
#define CAN_ID_STATUS       0x103

/* CAN functions */

void CAN_Init(void);

void CAN_SendMessage(CAN_Message *message);

void CAN_ReceiveMessage(CAN_Message *message);

#endif
