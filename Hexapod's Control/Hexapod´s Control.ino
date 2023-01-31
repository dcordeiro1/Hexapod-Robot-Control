#include <stdio.h>
#include <math.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>
#include <MPU9255.h>  //include MPU9255 library

MPU9255 mpu;

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// DECLARAÇÃO DE FUNÇÕES
void writeServos(int posicao, int tempo);
void beginServos();

int pos = 0;
double xe;
double ye;
double ze;
double l1 = 63.75;
int l2 = 80;
int l3 = 120;
double r;
double t;
double phi1;
double theta3;
double theta34;
int marcha;

double p;   //Tamanho do Passo
double h;   //Altura do pé relativamente ao torso
double pm;  // Ponto de posição máximo do pé

double v;  //Velocidade

int inp;
int estado = 0;
Servo femur;
Servo tibia;

// Sensores:
double gyro_x_cal;
double gyro_y_cal;
double gyroX;
double gyroY;
double accX_cal;
double accY_cal;
double accZ_cal;
double accX;
double accY;




void setup() {
  beginServos();  // INCIA OS SERVOS
  Serial.begin(115200);
  p = 60;
  h = -120;
  pm = -20;
  marcha = 2;
  femur.attach(2);
  tibia.attach(3);
  delay(300);
  v = 0.095;
  for (int i = 0; i <= 15; i = i + 3) {
    writeServos(i, 35);
    writeServos((i + 1), 85);
    writeServos((i + 2), 85);
  }
  femur.write(85);
  tibia.write(85);
}


void loop() {
  if (Serial.available() > 0) {
    inp = Serial.read();
    if (inp == 119) {  //"w" pressionado
      estado = 1;
    }
    if (inp == 48) {
      marcha = 0;
    }
    if (inp == 57) {
      marcha = 9;
    }
    if (inp == 49) {
      marcha = 1;
    }
    if (inp == 50) {
      marcha = 2;
    }
    if (inp == 51){
      marcha = 3;
    }

  }
  if (estado == 1) {
    //-----------------Movimento de Rotação (marcha == 0)------------------------------
      if (marcha ==0){        
        for (double i=0; i<= 2.0; i=i+v){
          
           balanco(0,i);
           balanco (2,i);
           balanco(4,i);
           apoio(1,i);
           apoio(3,i);
           apoio(5,i);
          // Serial.print(analogReading);
           if (Serial.available()>0){
            inp = Serial.read();
            if (inp == 115 || inp == 49 || inp == 50 || inp ==51){
              estado = 0;
              break ;
            }
          }
        }
        
        for (double i=0; i<= 2.0; i=i+v){
           apoio (0,i);
           apoio (2,i);
           apoio (4,i);
           balanco(1,i);
           balanco(3,i);
           balanco(5,i);
          // Serial.print(analogReading);
         if (Serial.available()>0){
          inp = Serial.read();
         if (inp == 115 || inp == 49 || inp == 50 || inp ==51){
          estado = 0;
          break ;
          }
        }
        }
      }
        //-----------------Movimento de Rotação 2 (marcha == 0)------------------------------
      if (marcha ==9){        
        for (double i=0; i<= 2.0; i=i+v){
           balanco(0,2-i);
           balanco (2,2-i);
           balanco(4,2-i);
           apoio(1,2-i);
           apoio(3,2-i);
           apoio(5,2-i);
           if (Serial.available()>0){
            inp = Serial.read();
            if (inp == 115 || inp == 49 || inp == 50 || inp ==51){
              estado = 0;
              break ;
            }
          }
        }
        for (double i=0; i<= 2.0; i=i+v){
           apoio (0,2-i);
           apoio (2,2-i);
           apoio (4,2-i);
           balanco(1,2-i);
           balanco(3,2-i);
           balanco(5,2-i);
         if (Serial.available()>0){
          inp = Serial.read();
         if (inp == 115 || inp == 49 || inp == 50 || inp ==51){
          estado = 0;
          break ;
          }
        }
        }
      }

     //-----------------Marcha Trípode (marcha = 1)-------------------------------------
     if (marcha ==1){     
        for (double i=0; i<= 2.0; i=i+v){
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
        for (double i=0; i<= 2.0; i=i+v){
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
    //-----------------Marcha Metacronal (marcha = 2)-------------------------------------
    if (marcha == 2) {
      for (double i = 0; i <= 2.0; i = i + v) {
        balanco(0, i);
        apoio(1, 1.6 + i/5);
        apoio(2, 1.2 + i/5);
        apoio(3, 1.2 - i/5);
        apoio(4, 1.6 - i/5);
        apoio(5, 2.0 - i/5);
        
     
        if (Serial.available() > 0) {
          inp = Serial.read();
          if (inp == 115 || inp == 49 || inp == 48 || inp == 51) {
            estado = 0;
            break;
          }
        }
      }
      for (double i = 0; i <= 2.0; i = i + v) {
        apoio(0, i/5);
        balanco(1, i);
        apoio(2, 1.6 + i/5); 
        apoio(3, 0.8 - i/5);
        apoio(4, 1.2 - i/5);
        apoio(5, 1.6 - i/5);
       
        if (Serial.available() > 0) {
          inp = Serial.read();
          if (inp == 115 || inp == 49 || inp == 48 || inp == 51) {
            estado = 0;
            break;
          }
        }
      }
      for (double i = 0; i <= 2.0; i = i + v) {
        apoio(0, 0.4 + i/5); 
        apoio(1, i/5);
        balanco(2, i);   
        apoio(3, 0.4 - i/5);  
        apoio(4, 0.8 - i/5);
        apoio(5, 1.2 - i/5);

        if (Serial.available() > 0) {
          inp = Serial.read();
          if (inp == 115 || inp == 49 || inp == 48 || inp == 51) {
            estado = 0;
            break;
          }
        }
      }
      for (double i = 0; i <= 2.0; i = i + v) {
        apoio(0, 0.8 + i/5);
        apoio(1, 0.4 + i/5);
        apoio(2, i/5); 
        balanco(3, 2 - i);
        apoio(4, 0.4 - i/5);
        apoio(5, 0.8- i/5);
        
        
        
        
        if (Serial.available() > 0) {
          inp = Serial.read();
          if (inp == 115 || inp == 49 || inp == 48 || inp == 51) {
            estado = 0;
            break;
          }
        }
      }
      for (double i = 0; i <= 2.0; i = i + v) {
        apoio(0, 1.2 + i/5);
        apoio(1, 0.8 + i/5);
        apoio(2, 0.4 + i/5);
        apoio(3, 2 - i/5);
        balanco(4, 2 - i);
        apoio(5, 0.4 - i/5);
        
        
        if (Serial.available() > 0) {
          inp = Serial.read();
          if (inp == 115 || inp == 49 || inp == 48 || inp == 51) {
            estado = 0;
            break;
          }
        }
      }
      for (double i = 0; i <= 2.0; i = i + v) {
        apoio(0, 1.6 + i/5);
        apoio(1, 1.2 + i/5);
        apoio(2, 0.8 + i/5);
        apoio(3, 1.6 - i/5);
        apoio(4, 1.2 - i/5);
        balanco(5, 2 - i);
        

        if (Serial.available() > 0) {
          inp = Serial.read();
          if (inp == 115 || inp == 49 || inp == 48 || inp == 51) {
            estado = 0;
            break;
          }
        }
      }
    }
    //---------------------------Marcha de Onda----------
      if (marcha ==3){ 
      for (double i=0; i<= 2.0; i=i+v){
          balanco(0,i);
          balanco (5,2-i);
          apoio(4,2-i/2);
          apoio(1,1+i/2);
          apoio(3,1-i/2);
          apoio(2,i/2);
          if (Serial.available()>0){
          inp = Serial.read();
          if (inp == 115 || inp == 49 || inp == 48 || inp ==50){
            estado = 0;
            break ;
          }
        }
      }
      for (double i=0.0; i<= 2.0; i=i+v){
          balanco (1,i);
          balanco (3,2-i);
          apoio(4,1-i/2);
          apoio(0,i/2);
          apoio(5,2-i/2);
          apoio(2,1+i/2);
          if (Serial.available()>0){
          inp = Serial.read();
          if (inp == 115 || inp == 49 || inp == 48 || inp ==50){
            estado = 0;
            break ;
          }
        }
      }
      for (double i=0.0; i<= 2.0; i=i+v){
          balanco(2,i);
          balanco (4,2-i);
          apoio(0,1+i/2);
          apoio(1,i/2);
          apoio(3,2-i/2);
          apoio(5,1-i/2);
          if (Serial.available()>0){
          inp = Serial.read();
          if (inp == 115 || inp == 49 || inp == 48 || inp ==50){
            estado = 0;
            break ;
          }
        }
        } 
       } 
  }
}


void apoio(int perna, double i) {
  if (i > 0 and i <= 1.0) {
    t = i;
    double P0[] = { 143.75, -(p / 2), h };
    double P1[] = { 143.75, -(p / 2) + (p / 8), h };
    double P2[] = { 143.75, -(p / 2) + (p / 4) , h };
    double P3[] = { 143.75, 0, h };
    xe = pow((1 - t), 3) * P0[0] + 3 * pow((1 - t), 2) * t * P1[0] + 3 * (1 - t) * pow(t, 2) * P2[0] + pow(t, 3) * P3[0];
    ye = pow((1 - t), 3) * P0[1] + 3 * pow((1 - t), 2) * t * P1[1] + 3 * (1 - t) * pow(t, 2) * P2[1] + pow(t, 3) * P3[1];
    ze = pow((1 - t), 3) * P0[2] + 3 * pow((1 - t), 2) * t * P1[2] + 3 * (1 - t) * pow(t, 2) * P2[2] + pow(t, 3) * P3[2];
  }
  if (i > 1.0 and i <= 2.0) {
    t = i - 1;
    double P0[] = { 143.75, 0 , h };
    double P1[] = { 143.75, (p/2)-(p/4), h };
    double P2[] = { 143.75, (p/2)-(p/8), h };
    double P3[] = { 143.75, (p / 2), h };
    xe = pow((1 - t), 3) * P0[0] + 3 * pow((1 - t), 2) * t * P1[0] + 3 * (1 - t) * pow(t, 2) * P2[0] + pow(t, 3) * P3[0];
    ye = pow((1 - t), 3) * P0[1] + 3 * pow((1 - t), 2) * t * P1[1] + 3 * (1 - t) * pow(t, 2) * P2[1] + pow(t, 3) * P3[1];
    ze = pow((1 - t), 3) * P0[2] + 3 * pow((1 - t), 2) * t * P1[2] + 3 * (1 - t) * pow(t, 2) * P2[2] + pow(t, 3) * P3[2];
  }
  

  if (ye != 0 && xe != 0) {
    phi1 = atan2(ye, xe);
  } else if (ye == 0) {
    phi1 = 0;
  }
  double p1[] = { cos(phi1) * l1, l1 * sin(phi1), 0 };
  r = sqrt(pow((xe - p1[0]), 2) + pow((ye - p1[1]), 2) + pow((ze - p1[2]), 2));
  theta3 = acos((-pow(l3, 2) + pow(l2, 2) + pow(r, 2)) / (2 * l2 * r)) - asin((p1[2] - ze) / r);
  theta34 = -PI + acos((-r * r + l2 * l2 + l3 * l3) / (2 * l2 * l3));
  writeServos((perna * 3), phi1 * (180.0 / (PI)) + 35.0);
  writeServos((perna * 3 + 1), -theta3 * (180 / (PI)) + 85.0);
  writeServos((perna * 3 + 2), 170.0 + theta34 * (180.0 / PI));
  if (perna == 5) {
    femur.write(-theta3 * (180.0 / (PI)) + 85.0);
    tibia.write(170 + theta34 * (180.0 / PI));
  }
  
}

void balanco(int perna, double i) {
  if (i > 0 and i <= 1.0) {
    t = i;
    double P0[] = { 143.75, (p / 2) + (p / 10), h };
    double P1[] = { 143.75, (p / 2) + (p / 5), h / 2 };
    double P2[] = { 143.75, (p / 2) - (p / 10), pm / 2 };
    double P3[] = { 143.75, 0, pm };
    xe = pow((1 - t), 3) * P0[0] + 3 * pow((1 - t), 2) * t * P1[0] + 3 * (1 - t) * pow(t, 2) * P2[0] + pow(t, 3) * P3[0];
    ye = pow((1 - t), 3) * P0[1] + 3 * pow((1 - t), 2) * t * P1[1] + 3 * (1 - t) * pow(t, 2) * P2[1] + pow(t, 3) * P3[1];
    ze = pow((1 - t), 3) * P0[2] + 3 * pow((1 - t), 2) * t * P1[2] + 3 * (1 - t) * pow(t, 2) * P2[2] + pow(t, 3) * P3[2];
  }
  if (i > 1.0 and i <= 2.0) {
    t = i - 1;
    double P0[] = { 143.75, 0, pm };
    double P1[] = { 143.75, -(p/2)+(p / 10), pm / 2 };
    double P2[] = { 143.75, -(p/2)-(p / 5), h / 2 };
    double P3[] = { 143.75, -(p / 2) - (p / 10), h };
    xe = pow((1 - t), 3) * P0[0] + 3 * pow((1 - t), 2) * t * P1[0] + 3 * (1 - t) * pow(t, 2) * P2[0] + pow(t, 3) * P3[0];
    ye = pow((1 - t), 3) * P0[1] + 3 * pow((1 - t), 2) * t * P1[1] + 3 * (1 - t) * pow(t, 2) * P2[1] + pow(t, 3) * P3[1];
    ze = pow((1 - t), 3) * P0[2] + 3 * pow((1 - t), 2) * t * P1[2] + 3 * (1 - t) * pow(t, 2) * P2[2] + pow(t, 3) * P3[2];
  }
  if (ye != 0 && xe != 0) {
    phi1 = atan2(ye, xe);
  } else if (ye == 0) {
    phi1 = 0;
  }
  double p1[] = { cos(phi1) * l1, l1 * sin(phi1), 0 };
  r = sqrt(pow((xe - p1[0]), 2) + pow((ye - p1[1]), 2) + pow((ze - p1[2]), 2));
  theta3 = acos((-pow(l3, 2) + pow(l2, 2) + pow(r, 2)) / (2 * l2 * r)) - asin((p1[2] - ze) / r);
  theta34 = -PI + acos((-r * r + l2 * l2 + l3 * l3) / (2 * l2 * l3));
  writeServos(perna * 3, phi1 * (180 / (PI)) + 35);
  writeServos(perna * 3 + 1, -theta3 * (180 / (PI)) + 85);
  writeServos(perna * 3 + 2, 170 + theta34 * (180 / PI));

  if (perna == 5) {
    femur.write(-theta3 * (180.0 / (PI)) + 85.0);
    tibia.write(170 + theta34 * (180.0 / PI));
  }
}
// IMPLEMENTO DE FUNÇÕES
void writeServos(int nServo, int posicao) {
#define SERVOMIN 155  // VALOR PARA UM PULSO MAIOR QUE 1 mS
#define SERVOMAX 535  // VALOR PARA UM PULSO MENOR QUE 2 mS


  int pos = map(posicao, 0, 180.0, SERVOMIN, SERVOMAX);
  pwm.setPWM(nServo, 0, pos);
}
void beginServos() {

#define Frequencia 50  // VALOR DA FREQUENCIA DO SERVO

  pwm.begin();                 // INICIA O OBJETO PWM
  pwm.setPWMFreq(Frequencia);  // DEFINE A FREQUENCIA DE TRABALHO DO SERVO
}
