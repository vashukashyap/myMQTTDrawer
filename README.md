# myMQTTDrawer
Hi , It is just a simple device made while learning MQTT protocol. which is use to send the data over the low bandwidth. you can use this device with something else too. instead of using it in drawer.  
I also have design the App in reactnative for it to show notification of the Status.  
Here: https://github.com/vashukashyap/MyMQTTApp

----
Made in PlatformIO with Arduino framework.

therefore to use it....  
clone the project and open it inside vscode ( make sure that you have PlatformIO extension is installed otherwise vscode will not recognise the project. )

## Modules used
- esp01
- IR sensor

## Pin configuration
- GPIO 2 ,  is used as INPut for taking IR sensor in OUPUT.

#### All the MQTT parameter are present inside the ```common.h``` file in the include dir.

----
