# IoTBasedWaterMonitoringAndControllingSystem
The aim of this preject is to monitor the water level in the over head tank and control the motor with an app over internet. I used Blynk library with arduino. In this project I used Arduino Uno, esp8266, L293D IC,12V relay, 240VAC cooler motor and Blynk app
I provided only Nessesary files.
FOLLOW THESE STEPS TO UNDERSTAND THE PROJECT:
Step1:
Install Arduino-IDE_which included in the software folder or download newer.
Step2:
Install the Blynk library to the Arduino-IDE (go to Sketch>Include library>Manage
libraries>Search "Blynk">Install latest version
Step3:
Open the iotProject.ino
Step4:
Just look into the code and the logics in it.
Step5:
Look at the hardware provided_find the circuit diagram in the circuitDiagram folder.
Step6:
Understand the circuit diagram and it mapped with physical hardware.
Step7:
Understand the mapping of physical pins on Arduino-UNO and in the
code(iotProject.ino).
Step8:
Change SSID and passward according to your wi-fi(make sure that you have Internet
on wi-fi and on your Phone).
Step9:
Open the app provided>scan the QR code provided.
Step10:
Connect the UltraSonic Sensor module and motor controll system to the main unit.
Step11:
Dip the motor in the water source, arrange a small tank and keep the motor pipe in the
tank.
Step12:
Keep the UltraSonic Sensor on the top of the tank facing into the water inside.
Step13:
Make changes in the code at cm according to the hight of the tank.
Step14:
Power ON the unit with 9V adapter provided.
Step15:
Select the proper COM port and proper board (goto Tools>Boards>Select "ArduinoUNO",Tools>port>Select
"COM port with Arduino-UNO").
Step16:
You should turn OFF the buttons provided on the main unit to upload the code to
Arduino-UNO.(these switches provide communication to ESp8266 with ArduinoUNO.
Step17:
Connect the Arduino-UNO to the computer and upload the code (by clicking left
arrow appearing on right side of the screen).
Step18:
Disconnect the USB cable, turn ON the two switches on the main unit and press the
reset button on Arduino-UNO.
Step19:
Now it is ready to communicate with the app via Blynk server through Internet.
Step20:
It should connected to the app, values should be shown and you can controll the motor
with the switch in the app.
Step21:
If all OK no need to repeat the above steps till Step18.From the next time just power
ON and it simply connects to the app via server to the app.
