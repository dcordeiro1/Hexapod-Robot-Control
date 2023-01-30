#include <stdio.h>
#include <math.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>
#define FORCE_SENSOR_PIN A0
#include <MPU9255.h>//include MPU9255 library

MPU9255 mpu;

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// DECLARAÇÃO DE FUNÇÕES
void writeServos(int posicao, int tempo);
void beginServos();

int pos = 0;    
float xe;
float ye;
float ze;
float l1=63.75;
int l2=80;
int l3=120;
float r;
float t;
float phi1;
float theta3;
float theta34;
int marcha ;

float p; //Tamanho do Passo 
float h; //Altura do pé relativamente ao torso
float pm; // Ponto de posição máximo do pé

float v; //Velocidade

int inp;
int estado =0;
Servo femur;
Servo tibia;

// Sensores:
unsigned long previousTime = 0;
unsigned long interval;
unsigned long currentTime;
float gyro_x_cal;
float gyro_y_cal;
float gyroX;
float gyroY;
float accX_cal;
float accY_cal;
float accZ_cal;
float accX;
float accY;




void setup() {
  beginServos(); // INCIA OS SERVOS
  Serial.begin(115200);
  p= 60;
  h= -120;
  pm=-20;
  marcha =  1;
  femur.attach(2);
  tibia.attach(3);
  delay(300);
  v=0.095;
  for (int i=0; i<=15;i=i+3){
    writeServos(i,35);
    writeServos((i+1),85);
    writeServos((i+2),85);
  }
  femur.write (85);
  tibia.write (85);
  //-------------Calibração IMU-----------------
  if(mpu.init())
  {
  //Serial.println("initialization failed");
  }
  else
  {
  //Serial.println("initialization succesful!");
  }
  for (int i=0; i<2000; i++){   
    mpu.set_gyro_scale(scale_250dps);
    mpu.read_gyro();//get data from the gyroscope
    gyro_x_cal += (float(mpu.gx)/131);
    gyro_y_cal += (float(mpu.gy)/131);
    accX_cal += float(mpu.ax) /8192 ;
    accY_cal += float(mpu.ay) /8192 ;
    accZ_cal += float(mpu.az) /8192 ;
  }
  gyro_x_cal /= 2000;
  gyro_y_cal /= 2000;
  accX_cal /= 2000;
  accY_cal /= 2000;
  accZ_cal /= 2000;

}


void loop() {
  /*int analogReading = analogRead(FORCE_SENSOR_PIN);
  Serial.println(analogReading);*/
   if (Serial.available()>0){
   inp = Serial.read();
      if (inp == 119){ //"w" pressionado
        estado = 1 ;
      }
      if (inp == 48){
        marcha = 0;
      }
      if (inp==57){
        marcha = 9;
      }
      if (inp == 49){
        marcha = 1;
      }
      if (inp == 50){
        marcha = 2;
      }
      if (inp == 51){
        marcha = 3;
      }
      }
    if (estado==1){
     //-----------------Marcha Trípode (marcha = 1)-------------------------------------
     if (marcha ==1){     
      previousTime = currentTime;
      currentTime = millis();
      interval = (currentTime) - previousTime;
      
      mpu.set_acc_scale(scale_4g);
      mpu.read_acc();//get data from the accelerometer 


      float accX_raw = (float(mpu.ax) /8192  - accX_cal) * 9.8;
      float accY_raw = (float(mpu.ay) /8192  - accY_cal) * 9.8;
      float accZ_raw = (float(mpu.az) /8192  - accZ_cal) * 9.8;

      accY = (atan((accX_raw)/sqrt(pow(accY_raw,2)+pow(accZ_raw,2)))) * (180/PI);
      accX = (atan((accY_raw)/sqrt(pow(accX_raw,2)+pow(accZ_raw,2)))) * (180/PI);

      mpu.set_gyro_scale(scale_250dps);
      mpu.read_gyro();//get data from the gyroscope
      gyroX =  ((mpu.gx/131-gyro_x_cal));// * (float(interval)/1000);
      gyroY = ((mpu.gy/131-gyro_y_cal)) ;//* (float(interval)/1000);
        
      int AngX = gyroX;
      int AngY = gyroY;
      /*int AngX = 0.02 * ( gyroX) + 0.98 * (AngX +accX);
      int AngY = 0.02 * ( gyroY) + 0.98 * (AngY +accY);*/
      //Serial.print("Wx= ");
      Serial.print(int(gyroX));
      Serial.print(" , ");  // Wy: ");
      Serial.print(int(gyroY));
      Serial.print(" , ");//   X: ");
      Serial.print(int(accX));
      Serial.print(" , ");//   Y: ");
      Serial.println(int(accY));
      
      for (float i=0; i<= 2; i=i+v){
          balanco(0,i);
          balanco (2,i);
          balanco(4,2-i);
          apoio(1,i);
          apoio(3,2-i);
          apoio(5,2-i);
          if (Serial.available()>0){
          inp = Serial.read();
          if (inp == 115 || inp == 48 || inp == 50 || inp ==51){
            estado = 0;
            break ;
          }
        }
      }
      for (float i=0; i<= 2; i=i+v){
          apoio (0,i);
          apoio (2,i);
          apoio (4,2-i);
          balanco(1,i);
          balanco(3,2-i);
          balanco(5,2-i);
          if (Serial.available()>0){
          inp = Serial.read();
          if (inp == 115|| inp == 48 || inp == 50 || inp ==51){
            estado = 0;
            break ;
          }
        }
      }
  
  

    }
  }
}
 
 
void apoio (int perna , float i){   
      //--------Marcha Trípode------      
       if (marcha == 1 || marcha ==0 ){
          if (i>0 and i<=1){
            t=i;
            float P0[]={143.75,-(p/2),h};
            float P1[]={143.75,-(p/2)+(p/6),h};
            float P2 []={143.75,-(p/2)+(p/3), h};
            float P3 []={143.75,0,h};       
            xe = pow((1 - t),3) * P0[0] + 3 * pow((1 - t),2) * t * P1[0] + 3 * (1-t) * pow(t,2) * P2[0] + pow(t,3)*P3[0];
            ye = pow((1 - t),3) * P0[1] + 3 * pow((1 - t),2) * t * P1[1] + 3 * (1-t) * pow(t,2) * P2[1] + pow(t,3)*P3[1];
            ze = pow((1 - t),3) * P0[2] + 3 * pow((1 - t),2) * t * P1[2] + 3 * (1-t) * pow(t,2) * P2[2] + pow(t,3)*P3[2];
          }
          if (i>1 and i<=2){
            t=i-1;
            float P0[]={143.75, 0, h};
            float P1[]={143.75, (p/2)-(p/3), h};
            float P2 []={143.75, (p/2)-(p/6), h};
            float P3 []={143.75, (p/2), h};
            xe = pow((1 - t),3) * P0[0] + 3 * pow((1 - t),2) * t * P1[0] + 3 * (1-t) * pow(t,2) * P2[0] + pow(t,3)*P3[0];
            ye = pow((1 - t),3) * P0[1] + 3 * pow((1 - t),2) * t * P1[1] + 3 * (1-t) * pow(t,2) * P2[1] + pow(t,3)*P3[1];
            ze = pow((1 - t),3) * P0[2] + 3 * pow((1 - t),2) * t * P1[2] + 3 * (1-t) * pow(t,2) * P2[2] + pow(t,3)*P3[2];
          }
          
         if (ye != 0 && xe!=0){
          phi1 = atan2(ye,xe);
          }
          else if (ye == 0){
            phi1 = 0;
          }
          float p1[] = {cos(phi1)*l1, l1*sin(phi1), 0};
          r = sqrt(pow((xe-p1[0]),2)+pow((ye-p1[1]),2)+pow((ze-p1[2]),2));
          theta3 = acos ((-pow(l3,2)+pow(l2,2)+pow(r,2))/(2*l2*r))-asin((p1[2]-ze)/r);
          theta34 = -PI   + acos((-r*r+l2*l2+l3*l3)/(2*l2*l3));  
          writeServos((perna*3), phi1*(180/(PI))+35);
          writeServos((perna*3+1),-theta3 *(180/(PI))+85);
          writeServos((perna*3+2),170+theta34 *(180/PI));   
          if (perna ==5){
            femur.write (-theta3 *(180/(PI))+85);
            tibia.write (170+theta34 *(180/PI));
          }
             
         
        }
       
}

void balanco (int perna, float i){ 
      if (i>0 and i<=1){
        t=i;
        float P0[]={143.75, (p/2)+(p/10), h};
        float P1[]={143.75, (p/2)+(p/5), h/2};
        float P2 []={143.75, (p/2)-(p/10), pm/2};
        float P3 []={143.75, 0, pm};
        xe = pow((1 - t),3) * P0[0] + 3 * pow((1 - t),2) * t * P1[0] + 3 * (1-t) * pow(t,2) * P2[0] + pow(t,3)*P3[0];
        ye = pow((1 - t),3) * P0[1] + 3 * pow((1 - t),2) * t * P1[1] + 3 * (1-t) * pow(t,2) * P2[1] + pow(t,3)*P3[1];
        ze = pow((1 - t),3) * P0[2] + 3 * pow((1 - t),2) * t * P1[2] + 3 * (1-t) * pow(t,2) * P2[2] + pow(t,3)*P3[2];
      }
      if (i>1 and i<=2){
        t=i-1;
        float P0[]={143.75, 0, pm};
        float P1[]={143.75, -(p/10), pm/2};
        float P2 []={143.75, -(p/5), h/2};
        float P3 []={143.75,-(p/2)+(p/10),h};
        xe = pow((1 - t),3) * P0[0] + 3 * pow((1 - t),2) * t * P1[0] + 3 * (1-t) * pow(t,2) * P2[0] + pow(t,3)*P3[0];
        ye = pow((1 - t),3) * P0[1] + 3 * pow((1 - t),2) * t * P1[1] + 3 * (1-t) * pow(t,2) * P2[1] + pow(t,3)*P3[1];
        ze = pow((1 - t),3) * P0[2] + 3 * pow((1 - t),2) * t * P1[2] + 3 * (1-t) * pow(t,2) * P2[2] + pow(t,3)*P3[2];
      }
     if (ye != 0 && xe!=0){
        phi1 = atan2(ye,xe);
      }
    else if (ye == 0){
      phi1 = 0;
    }
    float p1[] = {cos(phi1)*l1, l1*sin(phi1), 0};
    r = sqrt(pow((xe-p1[0]),2)+pow((ye-p1[1]),2)+pow((ze-p1[2]),2));
    theta3 = acos ((-pow(l3,2)+pow(l2,2)+pow(r,2))/(2*l2*r))-asin((p1[2]-ze)/r);
    theta34 = -PI   + acos((-r*r+l2*l2+l3*l3)/(2*l2*l3));
    writeServos(perna*3, phi1*(180/(PI))+35);
    writeServos(perna*3+1,-theta3 *(180/(PI))+85);
    writeServos(perna*3+2,170+theta34 *(180/PI)); 
    
    if (perna == 5){
      femur.write (-theta3 *(180/(PI))+85); 
      tibia.write (170+theta34 *(180/PI));
    }

}
  // IMPLEMENTO DE FUNÇÕES
void writeServos(int nServo, int posicao) {
#define SERVOMIN  155 // VALOR PARA UM PULSO MAIOR QUE 1 mS 
#define SERVOMAX  535 // VALOR PARA UM PULSO MENOR QUE 2 mS

  
  int pos = map ( posicao , 0 , 180 , SERVOMIN, SERVOMAX);
  pwm.setPWM(nServo , 0, pos);

}
void beginServos() {

#define Frequencia 50 // VALOR DA FREQUENCIA DO SERVO 

  pwm.begin(); // INICIA O OBJETO PWM
  pwm.setPWMFreq(Frequencia); // DEFINE A FREQUENCIA DE TRABALHO DO SERVO
}
