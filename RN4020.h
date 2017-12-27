/*
  RN4020.h - Arduino library for the RN4020 BLE module.
  The library is based off the following datasheet:
  http://ww1.microchip.com/downloads/en/DeviceDoc/70005191B.pdf
  Created by Matthew Kaiser, December 27, 2017.
*/

#ifndef RN4020
#define RN4020

#include "Arduino.h"

class Bluetooth
{
  public:
    void init(int baud);
    bool setName(String name);
    void setBaud(int baud);
    bool setFirmwareRev(String rev);
    bool setHardwareRev(String rev);
    bool setModel(String model);
    bool setMfg(String Mfg);
    bool setSoftRev(String rev);
    bool setSerialNum(String serialNum);
  private:
};

extern Bluetooth BT;


#endif
