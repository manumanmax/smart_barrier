#include <stdio.h>
#include <phidget21.h> 
#include "rfid.h"

int TagHandler(CPhidgetRFIDHandle RFID, void *usrptr, char *TagVal, CPhidgetRFID_Protocol proto)
{
    RFID_t* t = (int*) usrptr;
    if (strcmp(TagVal, "4b00da5a83")==0 || strcmp(TagVal,"4b00da2856")==0)
        *t = 1;
    else
        *t = 0;
 
    return 0;
} 
 
int rfid_cycle()
{ 
    RFID_t val = -1;
    
    CPhidgetRFIDHandle rfid = 0; 
 
    CPhidgetRFID_create(&rfid); 

    CPhidgetRFID_set_OnTag2_Handler(rfid, TagHandler, &val);
 
    CPhidget_open((CPhidgetHandle)rfid, -1); 
    
    printf("Init...\n");
    
    //while (val == -1){
    	CPhidgetRFID_setAntennaOn(rfid, 1);
    	CPhidgetRFID_setLEDOn(rfid, 1);
    //}
    delay(100);
    CPhidgetRFID_setLEDOn(rfid, 0);
    CPhidget_close((CPhidgetHandle)rfid);
    CPhidget_delete((CPhidgetHandle)rfid); 
    printf("Closing rfid_cycle...\n");

    return val;
} 
/* 
int main(){
    int i = rfid_cycle();
    
    while (!i) {
    	printf("VAL = %d\n", i);
        printf("Carta NON valida\n");
        printf("Accendo il LED rosso !\n");
        i = rfid_cycle();
    }
    printf("VAL = %d\n", i);
    printf("Carta valida\n");
    printf("Accendo il LED verde !\n");
    
    return 0;
}
*/
