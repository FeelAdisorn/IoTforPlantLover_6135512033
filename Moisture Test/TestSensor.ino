#include <ESP8266WiFi.h>  //เรียกใช้ Libraryของบอร์ด ESP8266
void setup() {            //กำหนดค่าเริ่มต้น
  Serial.begin(9600);     //กำหนดค่า uart หรือ ความเร็วในการส่งข้อมูล = 9600
  pinMode(A0,INPUT);      //กำหนดให้รับค่าเซนเซอร์วัดความชื้นในดินมาจากขา A0

}
                                                  
void loop() {                                      //กำหนดเงื่อนไขการวนลูป
  int val = analogRead(A0);                        //กำหนดให้ตัวแปร val = ค่า analog ที่อ่านได้ของขา A0
  Serial.print("Mositure Sensor Value : ");        //ปริ้นท์ข้อความ "Mositure Sensor Value : "
  if(val>1000){                                    //เช็คค่าในตัวแปร val หากค่าที่วัดได้มากกว่า 1000 จะทำตามเงื่อนไขภายใน if
    Serial.println("Air \t" + String(val));        //ปริ้นท์ข้อความ "Air" ตามด้วยค่าของตัวแปร val ที่วัดได้
  }
  else if((val>800) && (val<1000)){                //เช็คค่าในตัวแปร val หากค่าที่วัดได้มากกว่า 800 และน้อยกว่า 1000 จะทำตามเงื่อนไขภายใน else if
    Serial.println("Dry Soil \t" + String(val));   //ปริ้นท์ข้อความ "Dry Soil" ตามด้วยค่าของตัวแปร val ที่วัดได้
  }
  else if((val>300) && (val<800)){                 //เช็คค่าในตัวแปร val หากค่าที่วัดได้มากกว่า 300 และน้อยกว่า 800 จะทำตามเงื่อนไขภายใน else if
    Serial.println("Humid Soil \t" + String(val)); //ปริ้นท์ข้อความ "Humid Soil" ตามด้วยค่าของตัวแปร val ที่วัดได้
  }
 else{                                             //กรณีที่ค่าในตัวแปร val น้อยกว่า 300 จะเข้าเงื่อนไข else
    Serial.println("In Water \t" + String(val));   //ปริ้นท์ข้อความ "In Water" ตามด้วยค่าของตัวแปร val ที่วัดได
  }
delay(500);                                        //กำหนดเวลาหน่วงในการเช็คค่า = 0.5 วินาที
}
