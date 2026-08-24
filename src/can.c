#include "can.h"
#include <stdio.h>

/*
 * CAN initialization
 * In a real automotive ECU, this function would configure:
 * - CAN controller
 * - CAN bitrate
 * - CAN pins
 * - CAN interrupts
 */
void CAN_Init(void)
{
    printf("CAN initialized successfully.\n");
    printf("CAN Bitrate: 500 kbps\n");
}

/*
 * Transmit a CAN message
 */
void CAN_SendMessage(CAN_Message *message)
{
    if (message == NULL)
    {
        return;
    }

    printf("\nCAN TX\n");
    printf("ID  : 0x%03X\n", message->id);
    printf("DLC : %d\n", message->dlc);
    printf("DATA: ");

    for (uint8_t i = 0; i < message->dlc; i++)
    {
        printf("%02X ", message->data[i]);
    }

    printf("\n");
}

/*
 * Receive a CAN message
 *
 * This example function represents the software
 * interface where received CAN data would be processed.
 */
void CAN_ReceiveMessage(CAN_Message *message)
{
    if (message == NULL)
    {
        return;
    }

    printf("\nCAN RX\n");
    printf("ID  : 0x%03X\n", message->id);
    printf("DLC : %d\n", message->dlc);
    printf("DATA: ");

    for (uint8_t i = 0; i < message->dlc; i++)
    {
        printf("%02X ", message->data[i]);
    }

    printf("\n");
}
