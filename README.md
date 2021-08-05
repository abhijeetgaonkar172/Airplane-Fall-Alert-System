# Airplane-Fall-Alert-System

## Introduction
In this project I have made an Airplane Fall Alert System using MPU-6050 Sensor. Basically, MPU-6050 Sensor is 6-axis motion tracking device which will detect the orientation and acceleration of the airplane body and based on this parameter certain failure conditions have been defined like extreme left, extreme right, extreme upwards and falling. Whenever these conditions will occur an alert message will be displayed on serial monitor along with red led light blinking.

## MPU-6050 Sensor
MPU-6050 IC is MEMS, Micro Electromechanical System which changes the voltage depending on the change in axis position.

 ![MPU6050-Pinout](https://user-images.githubusercontent.com/51810591/128363516-c0d0a1ae-6f6d-467a-8b0c-8fe4af64dca7.png)
 
MPU-6050 Sensor is 6-Axis motion tracking device that combines a 3-Axis Gyroscope, 3-Axis Accelerometer, Temperature sensor and Digital Motion Processor (DMP).

![mpu6050_6DOF](https://user-images.githubusercontent.com/51810591/128363626-9bbc6d98-a617-4c87-a815-4a601e3a5a8f.jpg)

It follows I2C Protocol.
Power Supply: 3-5 V (Other details of the sensor can be found in the given sensor datasheet)
Accelerometer measure non-gravitational acceleration.
Gyroscope uses earths gravity to determine orientation.
DMP browses complex algorithms directly onboard, usually it browses this algorithm to turn raw values from sensor into stable data.
Simple Example:
When we throw a ball in air away from us, then motion of that ball is going to be rotational and forward. For tracking rotation (i.e., orientation) gyroscope is used and for forward acceleration an accelerometer is used. We combine both this motions in this sensor and further complex mathematical analysis filters are used, DMP helps in this analysis.  

![GYROro+ACC](https://user-images.githubusercontent.com/51810591/128363747-38e7ad62-d437-4325-9e07-7db727482e93.png)

## Accelerometer
Accelerometer works on the principle of piezoelectric effect.
Example: Consider a cuboidal box with a small ball inside it.
The walls are piezo electric crystals, when the ball collides the wall its creates tiny piezoelectric current.
3 parts of walls each corresponds to X, Y, Z Axis.
Depending upon the current produced from the piezoelectric walls we can determine acceleration
![Accelerometer_Working](https://user-images.githubusercontent.com/51810591/128363821-e98ab7ff-ce41-4ade-a0ee-144a5a87bc10.png)

## Gyroscope
Gyroscope works on the principle of Coriolis Acceleration.

 ![Gyro_Working](https://user-images.githubusercontent.com/51810591/128363925-527ad722-a523-4c09-872a-d9b3db2fee3f.jpg)

Imagine there is a fork like structure that is in a constant back and forth motion. It is held in a place using piezo electric crystals. Whenever you try to tilt the arrangement, the crystal experiences a force in the direction of inclination. The crystal thus produces a current.

## Roll-Pitch-Yaw
An aircraft in flight is free to rotate in three dimensions: yaw, nose left or right about an axis running up and down; pitch, nose up or down about an axis running from wing to wing; and roll, rotation about an axis running from nose to tail. The axes are alternatively designated as vertical, transverse, and longitudinal respectively. These axes move with the vehicle and rotate relative to the Earth along with the craft. These definitions were analogously applied to spacecraft when the first manned spacecraft were designed in the late 1950s.

![Roll_Pitch_Yaw](https://user-images.githubusercontent.com/51810591/128363999-02e60d51-2b58-4737-a28f-2b01423cff8d.png)

Roll axis or Longitudinal axis— an axis drawn through the body of the vehicle from tail to nose in the normal direction of flight, or the direction the pilot faces, similar to a ship's waterline.
Pitch axis  Transverse axis, lateral axis— an axis running from the pilot's left to right in piloted aircraft, and parallel to the wings of a winged aircraft, parallel to the buttock line.
Yaw axis or Normal axis, vertical axis— an axis drawn from top to bottom, and perpendicular to the other two axes, parallel to the fuselage station.

![RPY_Explained](https://user-images.githubusercontent.com/51810591/128364084-79b516a7-f136-4197-ad1c-44588d5e3a51.jpg)

 
