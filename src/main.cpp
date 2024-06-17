#include <Arduino.h>
#include <Servo.h>


/*  Definicion de Servos    */

Servo motor0;
Servo motor1;
Servo motor2;
Servo motor3;


/*    Pines de entrada    */

int Motor0_ent = 13;
char Motor0_sal = 11;
char Motor1_ent = 3;
char Motor1_sal = 7;
char Motor2_ent = 5;
char Motor2_sal = 9;
int Posicion_garra = 50;


/*  Variables de posicion   */

int Pmotor0 = 60;
int Pmotor1 = 90;
int Pmotor2 = 175;


void movimiento(){

              /*  MOTOR 0  */

    if (digitalRead(Motor0_ent) == HIGH){
        if (Pmotor0 < 175) {
            Pmotor0 = Pmotor0 +  5;
            motor0.write(Pmotor0);
            Serial.println("Motor0E");
            Serial.println(Pmotor0);

            
        }

    }

    if (digitalRead(Motor0_sal) == HIGH){
        if (Pmotor0 > 5){
            Pmotor0 = Pmotor0 -  5;
            motor0.write(Pmotor0);
            Serial.println("Motor0S");
            Serial.println(Pmotor0);
        }
    }


            /*  MOTOR 1  */

    if (digitalRead(Motor1_ent) == HIGH){
        if (Pmotor1 < 180) {
            Pmotor1 = Pmotor1 +  5;
            motor1.write(Pmotor1);
            Serial.println("Motor1E");
            Serial.println(Pmotor1);

            
        }

    }

    if (digitalRead(Motor1_sal) == HIGH){
        if (Pmotor1 > 5){
            Pmotor1 = Pmotor1 -  5;
            motor1.write(Pmotor1);
            Serial.println("Motor1S");
            Serial.println(Pmotor1);
        }
    }


              /*  MOTOR 2  */

     if (digitalRead(Motor2_ent) == HIGH){
        if (Pmotor2 < 180) {
            Pmotor2 = Pmotor2 +  5;
            motor2.write(Pmotor2);
            Serial.println("Motor2E");
            Serial.println(Pmotor2);

            
        }

    }

    if (digitalRead(Motor2_sal) == HIGH){
        if (Pmotor2 > 100){
            Pmotor2 = Pmotor2 -  5;
            motor2.write(Pmotor2);
            Serial.println("Motor2S");
            Serial.println(Pmotor2);
        }

    }

    Posicion_garra = analogRead(A0);
    //Serial.println(map(Posicion_garra,0,1024,5,90));

    
    motor3.write(map(Posicion_garra,0,1024,5,90));
   

    
}


void setup() {
    
    Serial.begin(9600);

    



/*   Definicion de pines   */

    pinMode(Motor0_ent,INPUT);
    pinMode(Motor0_sal,INPUT);

    pinMode(Motor1_ent,INPUT);
    pinMode(Motor1_sal,INPUT);

    pinMode(Motor2_ent,INPUT);
    pinMode(Motor2_sal,INPUT);


    motor0.attach(6,500,2300);
    motor1.attach(10,500,2400);
    motor2.attach(8,500,2400);
    motor3.attach(4,500,2400);

motor2.write(Pmotor2);
delay(2000);

}

void loop() {

movimiento();
  

delay(50);

}

