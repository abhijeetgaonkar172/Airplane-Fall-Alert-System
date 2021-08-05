// Airplane Fall Alert System
#define ledpin D5   //declare D5 as ledpin

#include "Wire.h"
#include <MPU6050_light.h>

MPU6050 mpu(Wire);
float x,y,z;

void setup() {
  Serial.begin(9600);
  Wire.begin();     // join i2c bus (address optional for master)
  pinMode(ledpin,OUTPUT);  //set ledpin as OUTPUT pin
  
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: ")); //Moves constant string to program memory instead of RAM
  Serial.println(status);
  while(status!=0){ } // stop everything if could not connect to MPU6050
  
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  mpu.calcOffsets(); // gyro and accelero
  Serial.println("Done!\n");
}

void loop() {
  mpu.update();

  x = mpu.getAngleX();
  y = mpu.getAngleY();
  z = mpu.getAngleZ();

  Serial.print("X : ");
  Serial.print(x);
  Serial.print("\tY : ");
  Serial.print(y);
  Serial.print("\tZ : ");
  Serial.println(z);
  delay(10);    // print data every 10ms
  
/*.......................................Fall Alert System...........................................*/
 
  if (x >= 40){             //Pitch threshold value
    Serial.println("Going Extreme Upwards");
    alertMessage();
    }
  else if(x <= -40){          //Pitch threshold value opposite side
    Serial.println("Falling Down");
    alertMessage();
    } 
  else if(y >= 40){          //Roll threshold value
    Serial.println("Moving Extreme Right");
    alertMessage();
    }  
  else if(y <= -40){         //Roll threshold value opposite side
    Serial.println("Moving to Extreme Left");
    alertMessage();
    }
  else{
    Serial.println("Good Going-GG");
    }  
}
void alertMessage(){    //Function to blink led and display DANGER message
  digitalWrite(ledpin,HIGH);     //turn led ON 
  Serial.println("DANGER !!!!!"); //DANGER message
  delay(100);                    //delay of 100ms
  digitalWrite(ledpin,LOW);      //turn led OFF 
  delay(100);                    //delay of 100ms
  }
