#define BLYNK_TEMPLATE_ID "TMPL30cSSQ0yl"
#define BLYNK_TEMPLATE_NAME "Hack4earth"
#define BLYNK_AUTH_TOKEN "IODm9Phbw4LCRYV2t45XvBWjJOMNw4X7"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[]="Moto G62";
char pass[]="1007@shikhar";
char auth[]=BLYNK_AUTH_TOKEN;

BlynkTimer timer;

void MDVSM() {                                           //Movement Detection and Vibration Sensing Module
  int value1=digitalRead(D6);
  int value2=digitalRead(D7);

  if (value1==1) {
    Blynk.logEvent("Alert1","Movement Detected!");
    Serial.println("Movement Detected!");
    digitalWrite(D1,HIGH);
    Blynk.virtualWrite(V0,HIGH);
    delay(1500);
    digitalWrite(D1,LOW);
    Blynk.virtualWrite(V0,LOW);
  }
  else if(value2==1) {
    Blynk.logEvent("Alert2","Deforestation going on!");
    Serial.println("Deforestation going on!");
    digitalWrite(D1,HIGH);
    digitalWrite(D2,HIGH);
    Blynk.virtualWrite(V1,HIGH);
    delay(2000);
    digitalWrite(D1,LOW);
    digitalWrite(D2,LOW);
    Blynk.virtualWrite(V1,LOW);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(D6,INPUT);      //PIR
  pinMode(D7,INPUT);      //vibration sensor
  pinMode(D1,OUTPUT);     //LED
  pinMode(D2,OUTPUT);     //Buzzer
  Blynk.begin(auth,ssid,pass);
  timer.setInterval(100L,MDVSM);
}

void loop() {
  Blynk.run();
  timer.run();
}