#define BLYNK_PRINT Serial                         //แสดงข้อมูลของ BLYNK ผ่านทาง Serial Monitor
#include <ESP8266WiFi.h>                           //เรียกใช้ Libraryของบอร์ด ESP8266 WIFI
#include <BlynkSimpleEsp8266.h>                    //เรียกใช้ Libraryของบอร์ด ESP8266 BLYNK
#include "DHT.h"                                   //เรียกใช้ LibraryของSensor DHT
DHT dht;                                           

char auth[] = "64h3CzsFHJrn8FfHzm0Zk1rq3W3eUp9c";  //Auth Tokenของผู้ใช้
char ssid[] = "Adisorn";                           //ชื่อ WIFI
char pass[] = "25422542";                          //รหัส WIFI

int SensorPin = A0;                                //ขาที่ใช้รับค่า
int SensorValue = 0;                               //ตัวแปรของความชื้นในดิน ค่าเริ่มต้น = 0

void setup()                                       //กำหนดค่าเริ่มต้น
{
  Serial.begin(9600);                              //กำหนดค่า uart หรือ ความเร็วในการส่งข้อมูล = 9600
  Blynk.begin(auth, ssid, pass);                   //กำหนดค่าเริ่มต้นBLYNK
  dht.setup(4);                                    //data pin 2}
}

void loop()                                        //กำหนดเงื่อนไขการวนลูป
{
  Blynk.run();                                     //ส่วนในการเชื่อมต่อ BLYNK
 
  SensorValue = analogRead(SensorPin);             //กำหนดให้ SensorValue = ค่า analog ที่อ่านได้ของขา A0
  SensorValue = map(SensorValue, 0, 1023, 100, 0); //แปลงค่าให้อยู่ในรูปของเปอร์เซนต์
  
  Blynk.virtualWrite(V0, SensorValue);             //ส่งค่าไปยัง Blynk
  
  Serial.print("Moisture Sensor Value = ");        //ปริ้นท์ข้อความ "Mositure Sensor Value : "
  Serial.println(SensorValue);                     //ดูค่าทาง Serial Monitor
 
  float h = dht.getHumidity();                     //ดึงค่าความชื้นในอากาศ
  float t = dht.getTemperature();                  //ดึงค่าอุณหภูมิ

  Blynk.virtualWrite(V1, t);                       //ส่งค่าไปยัง Blynk
  Blynk.virtualWrite(V2, h);                       //ส่งค่าไปยัง Blynk
  
  Serial.print("Humidity: ");                      //ปริ้นท์ข้อความ "Humidity: "
  Serial.print(h);                                 //แสดงค่าอุณหภูมิ
  Serial.print(" %\t");                            //แสดงหน่วยเป็น " %" พร้อมกับเว้นวรรค
  Serial.print("Temperature: ");                   //ปริ้นท์ข้อความ "Temperature: "
  Serial.print(t);                                 //แสดงค่าความชื้นในอากาศ
  Serial.println("°C ");                           //แสดงหน่วยเป็น "°C "
delay(2500);                                       //หน่วงเวลา 2.5 วินาที
}
