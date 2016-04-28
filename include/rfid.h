#ifndef RFID_H
#define RFID_H

typedef int RFID_t;

int TagHandler(CPhidgetRFIDHandle, void*, char*, CPhidgetRFID_Protocol);
int TagLostHandler(CPhidgetRFIDHandle, void*, char*, CPhidgetRFID_Protocol);
int rfid_cycle();

#endif