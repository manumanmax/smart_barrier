#ifndef RFID_H
#define RFID_H
#include <phidget21.h>

typedef int RFID_t;

int TagHandler(CPhidgetRFIDHandle, void*, char*, CPhidgetRFID_Protocol);
int TagLostHandler(CPhidgetRFIDHandle, void*, char*, CPhidgetRFID_Protocol);
int rfid_cycle();

#endif
