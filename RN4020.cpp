/*
  RN4020.cpp - Arduino library for the RN4020 BLE module.
  The library is based off the following datasheet:
  http://ww1.microchip.com/downloads/en/DeviceDoc/70005191B.pdf
  Created by Matthew Kaiser, December 27, 2017.
*/

#include "Arduino.h"
#include "RN4020.h"
#include "HardwareSerial.h"

Bluetooth BT;

void Bluetooth::init(int baud) {
  Serial.begin(baud);
  BT.setBaud(baud);
}

bool Bluetooth::setName(String name) {
  if(name.length() > 15) {
    return false;
  } else {
    Serial.println("S-," + name);
    return true;
  }
}

void Bluetooth::setBaud(int baud) {
  uint8_t setting;
  switch(baud) {
    case 2400:
      setting = 0;
      break;
    case 9600:
      setting = 1;
      break;
    case 19200:
      setting = 2;
      break;
    case 38400:
      setting = 3;
      break;
    case 115200:
      setting = 4;
      break;
    case 230400:
      setting = 5;
      break;
    case 460800:
      setting = 6;
      break;
    case 921600:
      setting = 7;
      break;
    default:
      setting = 5;
      break;
  }
  Serial.println("SB," + String(setting));
}

bool Bluetooth::setFirmwareRev(String rev) {
  if(rev.length() > 20) {
    return false;
  } else {
    Serial.println("SDF," + rev);
    return true;
  }
}

bool Bluetooth::setHardwareRev(String rev) {
  if(rev.length() > 20) {
    return false;
  } else {
    Serial.println("SDH," + rev);
    return true;
  }
}

bool Bluetooth::setModel(String model) {
  Serial.println("SDM," + model);
}

bool Bluetooth::setMfg(String Mfg) {
  Serial.println("SDN," + Mfg);
}

bool Bluetooth::setSoftRev(String rev) {
  Serial.println("SDR," + rev);
}

bool Bluetooth::setSerialNum(String serialNum) {
  Serial.println("SDS," + serialNum);
}
