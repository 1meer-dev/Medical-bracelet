// sms RX PIN = 10 sms TX PIN = 11 
#include <SIM800.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
class BoxM{
  const int buzer = 2, vPins[4] = {A3,3,4,A2};  
  int ledG, ledY, ledB;

  public:
  void pins(int ledG, int ledY, int ledB){

    this->ledG = ledG;
    this->ledY = ledY;
    this->ledB = ledB;
    
    int led[3] = {ledG,ledY,ledB};

    for(int i=0;i<3;i++)
      pinMode(led[i], OUTPUT);
    for(int i=0; i<4; i++)
      pinMode(vPins[i],OUTPUT);
    pinMode(buzer, OUTPUT);
  
  }
  void On(String Led){
    // Led Section
    int led[3] = {ledG,ledY,ledB};
    if(Led == "Green")
      digitalWrite(ledG,HIGH);
    else if(Led == "Yellow")
      digitalWrite(ledG,HIGH);
    else if(Led == "Blue")
      digitalWrite(ledB,HIGH);
    else{
      for(int i=0; i<3; i++)
        digitalWrite(led[i],HIGH); 
    }

    // V
    for(int i=0; i<4; i++)
      digitalWrite(vPins[i],HIGH);
    
    // Buzer
    digitalWrite(buzer,HIGH);
    delay(2000);
    digitalWrite(buzer,LOW);
  }

  void Off(){
    int led[3] = {ledG,ledY,ledB};
    for(int i=0; i<3; i++)
        digitalWrite(led[i],LOW);
    for(int i=0; i<4; i++)
        digitalWrite(vPins[i],LOW); 
  }
};
void delayTime(int hour, int minutes = 0, int second = 0){
  int Hour =  60 * 1000 * 60, Minutes = 60 * 1000, Second = 1000;
  int total = ( hour * Hour ) + ( minutes * Minutes ) + ( second * Second );
  delay( total );
}

BoxM Box1,Box2,Box3,Box4;
String point = " " ;
String gps_sms = " " ;
TinyGPSPlus gps;
SoftwareSerial ss(4,3);// gps RX PIN = 4 gps TX PIN = 3
char a[30];



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
ss.begin(9600);

  Box1.pins(5,12,0);
  Box2.pins(6,13,0);
  Box3.pins(7,A0,0);
  Box4.pins(8,A1,0);
 
}
void loop()
{ Box1.On("Green");
  delayTime(0,0,3);
  Box1.Off();
  delayTime(0,0,1);

  Box2.On("Yellow");
  delayTime(0,0,3);
  Box2.Off();
  delayTime(0,0,1);

  Box3.On("Blue");
  delayTime(0,0,3);
  Box3.Off();
  delayTime(0,0,1);
  
  Box4.On("W");
  delayTime(0,0,3);
  Box4.Off();
  delayTime(0,0,1);
  
  //.........................................................
  // Dispatch incoming characters
 /* while (ss.available() > 0)
    gps.encode(ss.read());
  if (gps.location.isUpdated()){
   // point="HELP MY LOCATION =  Lat=";
  point +=String(gps.location.lat(), 6);
    point += ",";
    point +=String(gps.location.lng(),6);
    gps_sms=point;
     Serial.println (gps_sms);
     gps_sms.toCharArray(a,30);
     point="";*/

      SIM.begin(9600);
    delay(100);
    SIM.pinCode(GET);
    if (SIM.reply("SIM PIN")) SIM.pinCode(SET, "0000");  
    SIM.smsFormat(SET, "1");
    SIM.smsSend("\"+9647813205535\"" ,"help my 35.571447,45.355634" );//send a
    
  }
  //..................................................................................
