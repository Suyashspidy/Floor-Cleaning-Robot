#include <SoftwareSerial.h>
#include <Servo.h>
#include <HCSR04.h>
SoftwareSerial BlueTooth(5, 6); // (TXD, RXD) of HC-06
Servo myservo;
UltraSonicDistanceSensor distanceSensor(11, 12);

const int m1_1 = 2;
const int m1_2 = 3;
const int m2_1 = 4;
const int m2_2 = 5;
const int m3_1 = 6;
const int m3_2 = 7;
const int m4_1 = 8;
const int m4_2 = 9;
const int pump = 13;

char BT_input; // to store input character received via BT.

void setup()  
{
  myservo.attach(10);
  pinMode(m1_1, OUTPUT); 
  pinMode(m1_2, OUTPUT);  
  pinMode(m2_1, OUTPUT); 
  pinMode(m2_2, OUTPUT);  
  pinMode(m3_1, OUTPUT); 
  pinMode(m3_2, OUTPUT);  
  pinMode(m4_1, OUTPUT); 
  pinMode(m4_2, OUTPUT);
  pinMode(pump, OUTPUT);  
  digitalWrite(m1_1,LOW);
  digitalWrite(m1_2,LOW);
  digitalWrite(m2_1,LOW);
  digitalWrite(m2_2,LOW);
  digitalWrite(m3_1,LOW);
  digitalWrite(m3_2,LOW);
  digitalWrite(m4_1,LOW);
  digitalWrite(m4_2,LOW);
  digitalWrite(pump,LOW);
  BlueTooth.begin(9600);  
  Serial.begin(9600);
}

void loop() 
{
  Serial.println(distanceSensor.measureDistanceCm());
  delay(500);
   
  if (Serial.available())
 {
    BT_input=(Serial.read());
    if (BT_input=='F')
    {
      digitalWrite(m3_1, HIGH);
      digitalWrite(m3_2, LOW);
      digitalWrite(m4_1, HIGH);
      digitalWrite(m4_2, LOW);
     }
    if (BT_input=='B')
    {
      digitalWrite(m3_1, LOW);
      digitalWrite(m3_2, HIGH);
      digitalWrite(m4_1, LOW);
      digitalWrite(m4_2, HIGH);
     }
   if (BT_input=='L')
    {
      digitalWrite(m3_1, HIGH);
      digitalWrite(m3_2, LOW);
      digitalWrite(m4_1, LOW);
      digitalWrite(m4_2, LOW); 
    }   
    if (BT_input=='R')
    {
      digitalWrite(m3_1, LOW);
      digitalWrite(m3_2, LOW);
      digitalWrite(m4_1, HIGH);
      digitalWrite(m4_2, LOW); 
    } 
    if (BT_input=='S')
    {
      digitalWrite(m3_1, LOW);
      digitalWrite(m3_2, LOW);
      digitalWrite(m4_1, LOW);
      digitalWrite(m4_2, LOW); 
    } 
    if (BT_input=='1')
    {
      digitalWrite(m1_1, HIGH);
      digitalWrite(m1_2, LOW);
      digitalWrite(m2_1, LOW);
      digitalWrite(m2_2, HIGH); 
    } 
    if (BT_input=='2')
    {
      digitalWrite(m1_1, LOW);
      digitalWrite(m1_2, HIGH);
      digitalWrite(m2_1, HIGH);
      digitalWrite(m2_2, LOW); 
    } 
    if (BT_input=='3')
    {
      digitalWrite(m1_1, LOW);
      digitalWrite(m1_2, LOW);
      digitalWrite(m2_1, LOW);
      digitalWrite(m2_2, LOW); 
    } 
    if(BT_input == 'P')
    {
      myservo.write(90);
      }
      if(BT_input == 'D')
    {
      myservo.write(0);
      }
      if(BT_input == 'W')
      {
        digitalWrite(pump,HIGH);
        }
        if(BT_input == 'O')
      {
        digitalWrite(pump,LOW);
        }
        if(BT_input == 'U')
        {
          if(distanceSensor.measureDistanceCm() < 20)
        {
          digitalWrite(m3_1, HIGH);
          digitalWrite(m3_2, LOW);
          digitalWrite(m4_1, LOW);
          digitalWrite(m4_2, LOW); 
          delay(1500);
          digitalWrite(m3_1, HIGH);
          digitalWrite(m3_2, LOW);
          digitalWrite(m4_1, HIGH);
          digitalWrite(m4_2, LOW);
          }
        }
       
   // You may add other if else condition here. 
  }
}