#include "DHT.h"                  //เรียกใช้ LibraryของSensor DHT
DHT dht;

void setup() {                    //กำหนดค่าเริ่มต้น
  Serial.begin(9600);             //กำหนดค่า uart หรือ ความเร็วในการส่งข้อมูล = 9600
  dht.setup(4);                   // data pin 2}
}
void loop() {
  float h = dht.getHumidity();   // ดึงค่าความชื้น
  float t = dht.getTemperature();//ดึงค่าอุณหภูมิ
  
  Serial.print("Humidity: ");    //ปริ้นท์ข้อความ "Humidity: "
  Serial.print(h);               //แสดงค่าอุณหภูมิ
  Serial.print(" %\t");          //แสดงหน่วยเป็น " %" พร้อมกับเว้นวรรค
  Serial.print("Temperature: "); //ปริ้นท์ข้อความ "Temperature: "
  Serial.print(t);               //แสดงค่าความชื้นในอากาศ
  Serial.println("°C ");         //แสดงหน่วยเป็น "°C "
  delay(500);                    //หน่วงเวลา 0.5 วินาที
}
