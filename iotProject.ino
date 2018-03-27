//written for Arduino UNO by praveen kumar
#include <ESP8266_Lib.h>                          //this include all the AT commands of WiFi module_ESP8266
#include <BlynkSimpleShieldEsp8266.h>             //ESP8266 AT commands mapped to Blynk as required
#define EspSerial Serial                          //define hardware serial as EspSerial
#define ESP8266_BAUD 115200                       //Baudrate forn the communication between Esp8266 with Arduino-UNO
ESP8266 wifi(&EspSerial);                         //declaring Esp8266 serial as wi-fi
int a=0,b=0;                                      //these two variables for LED's on the APP
const int trigPin = 9;                            //9th pins of Arduino connected to trigger pin of HC-SR04(sends a pulse)
const int echoPin = 8;                            //8th pin of Arduino connected to echo pin of HC-SR04(receives pulse)           
long duration, inches, cm;                        //these are the variables used in the code
char auth[] = "********************************"; //this is the authentication token to get connected with the app(sent to email by Blynk app)
char ssid[] = "************";                     //enter the wi-fi name here
char pass[] = "*********";                        //enter the passward here
BlynkTimer timer;                                 //declaring the Blynk timer(which triggers the server in an interval)

void setup()
{
  pinMode(trigPin, OUTPUT);                       //defining as output
  pinMode(echoPin, INPUT);                        //defining as input 
  pinMode(7, OUTPUT);                             //defining as output(which is used to controll the motor
  EspSerial.begin(ESP8266_BAUD);                  //start the communication with Esp8266 at 115200 baudrate
  delay(10);                                      //giving a small delay
  Blynk.begin(auth, wifi, ssid, pass);            //this initialises the wi-fi connection and server
  timer.setInterval(1500L,myTimerEvent );         //Setup a function to be called every second or defined delay
  timer.setInterval(2500L,statusOfMotor );         //Setup a function to be called every second or defined delay
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);                    //this sends a 10 microseconds pulse
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);                   
  duration = pulseIn(echoPin, HIGH);              //calculates the pulse width according to triggered pulse travell
  cm = microsecondsToCentimeters(duration);       //gets the duration in terms of distance in cm
  if(cm>100)cm=103;                               //limits the cm value to 103 cm
  cm=103-cm;                                      //inverts the obtained cm value to display properly in the app
  if(cm<15)                                       //if the water level below 15 cm motor will turned ON
  {
    digitalWrite(7,HIGH);
    a=255;                                        //LEDs on the app glow according to the motor status
    b=0;    
  }
  if(cm>=100)                                     //if the water filled 100 cm the motor will turned OFF
  {
    digitalWrite(7,LOW);
    a=0;                                          //LEDs on the app glow according to the motor status
    b=255;                                          
    
  }

  Blynk.run();                                    //runs blynk library according to the timer
  timer.run();                                    // Initiates BlynkTimer
}

                                                  // that you define how often to send data to Blynk App.
void myTimerEvent()                               // This function sends Arduino's up time every second to Virtual Pin 2,3,4&5
{
  Blynk.virtualWrite(V3,cm);                      //writing cm value to the virtual pin V3 in the server
  Blynk.virtualWrite(V5,cm);                      //writing cm value to the virtual pin V5 in the server
}
void statusOfMotor()
{
 Blynk.virtualWrite(V2,a);                       //writing a value to the virtual pin V2 in the server
 Blynk.virtualWrite(V4,b);                       //writing b value to the virtual pin V4 in the server
}
BLYNK_WRITE(V1){
  int pinValue = param.asInt();                    // assigning incoming value from pin V1 to a variable
  digitalWrite(7,pinValue);           
  if(pinValue==1)                                  //if switched on, first LED will glows and another will off
  {      
    a=255;
    b=0;}
   if(pinValue==0)                                 //opposite to above function
   {
     a=0;b=255;
   }
}
long microsecondsToCentimeters(long microseconds) // The speed of sound is 340 m/s or 29 microseconds per centimeter.
{                                                 // The ping travels out and back, so to find the distance of the
  return microseconds / 29 / 2;                   // object we take half of the distance travelled.
  
}

