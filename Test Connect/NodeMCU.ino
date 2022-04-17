#define BLYNK_PRINT Serial            //แสดงข้อมูลของ BLYNK ผ่านทาง Serial Monitor
#include <ESP8266WiFi.h>              //เรียกใช้ Libraryของบอร์ด ESP8266 WIFI
#include <BlynkSimpleEsp8266.h>       //เรียกใช้ Libraryของบอร์ด ESP8266 BLYNK

char auth[] = "64h3CzsFHJrn8FfHzm0Zk1rq3W3eUp9c"; //Auth Tokenของผู้ใช้
char ssid[] = "Adisorn";                          //ชื่อ WIFI
char pass[] = "25422542";                         //รหัส WIFI

void setup()                                     //กำหนดค่าเริ่มต้น
{  
  Serial.begin(9600);                            //กำหนดค่า uart หรือ ความเร็วในการส่งข้อมูล = 9600
  Blynk.begin(auth, ssid, pass);                 //กำหนดค่าเริ่มต้นBLYNK
}

void loop()                                      //กำหนดเงื่อนไขการวนลูป
{
  Blynk.run();                                   //ส่วนในการเชื่อมต่อ BLYNK
}
