# RN4020 Library
Arduino library for the RN4020 BLE module. The library is based off the following [datsheet](http://ww1.microchip.com/downloads/en/DeviceDoc/70005191B.pdf).

## Connection
|MCU             |BLE            |
| :--------------|:---------------|
| UART TX        | UART RX        |
| UART RX        | UART TX        |
| VDD 3.3V       | VDD 3.3V       |
| GND            | GND            |

## Commands
### Set Device Name
#### Description
This command sets the serialized Bluetooth-friendly name of the device, where <string> is up to 15 alphanumeric characters. This command automatically appends the last 2 bytes of the Bluetooth MAC address to the name, which is useful for generating a custom name with unique numbering.
#### Command
This function returns a true for success and false for a failure.
```C
setName(String name)
```  
#### Example
```C
BT.setName("MyBluetoothDev");
```
---
### Set UART baud rate
#### Description
This command sets the baud rate of the UART communication. When the baud rate is set to 2400, there is no need to 
wake the RN4020 module by pulling WAKE_SW high for UART communication.
  
Supported speeds
* 2400
* 9600
* 19200
* 38400
* 115200
* 230400
* 460800
* 921600

#### Command
This function returns a true for success and false for a failure. If the baud rate is not supported a false response will be returned and the device will be set to 115,200kbps by default.
```C
setBaud(int baud)
```  
#### Example
```C
BT.setBaud(115200);
```
