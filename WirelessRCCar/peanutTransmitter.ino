#include "transmitter.h"
#include "IMU.h"
#include "sensor_fusion.h"
#define RED 3
#define GREEN 5
#define YELLOW 6
extern float IMU_X;
extern float IMU_Y;
extern float IMU_Z;

void setup() {
  imu_setup();
  transmitter_setup();
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  Serial.begin(9600); 
}

int v1 = 0;
int v2 = 0;
int v3 = 0;

void loop() {
  imu_loop();

  v1 = map(((int)(IMU_X * 100)), -100, 100, 0, 255 );
  v2 = map(((int)(IMU_Y * 100)), -100, 100, 0, 255 );
  v3 = map(((int)(IMU_Z * 100)), -100, 100, 0, 255 );

  Serial.print("x = ");
  Serial.println(v1);
  sending(v1);

  Serial.print("y = ");
  Serial.println(v2);
  sending(v2);

  Serial.print("z = ");
  Serial.println(v3);
  sending(v3);

  //analogWrite(RED, v1);
  //analogWrite(GREEN, v2);
  //analogWrite(YELLOW, v3);
  delay(100);
}
