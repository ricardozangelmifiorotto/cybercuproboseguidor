// Declaração de Bibliotecas
#include <AFMotor.h>
#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(13, 3); // RX, TX
 //Motores
  AF_DCMotor motor1(1); //Seleciona o motor 1
  AF_DCMotor motor2(2); //Seleciona o motor 2
  AF_DCMotor motor3(3); //Seleciona o motor 3
  AF_DCMotor motor4(4); //Seleciona o motor 4
 //Servo Motor
  Servo servo1;
  int val = 100;
 //Bluetooth
  char X;
 //Sensores
  int S1 = A0;
  int S2 = A1;
  int S3 = A2;
  int S4 = A3;
  int S5 = A4;
  int objeto1 = 0;
  int objeto2 = 0;
  int objeto3 = 1;
  int objeto4 = 1;
 int objeto5 = 1;
 //Tipo de pista e etapa
  int tipoPista = 1;
  int etapa = 0;
//Funções Gerais
    
    void le_bluetooth()
        {
          // Leitura de dados que chegaram via serial (RX do Arduino)

          Serial.println("Esperando dado...");
          while (mySerial.available() == 0){} // Dado novo disponível ?
          
            X = mySerial.read();
            Serial.print("Dado Recebido: ");
            Serial.println(X);         
        }
     void detectalado()
       {
         if ((objeto1 == 1) && (objeto2 == 0) && (objeto3 == 0))
         {
         tipoPista = 1; // esquerda
          etapa++;      
          }
          else if((objeto1 == 0) && (objeto2 == 1) && (objeto3 == 0))
          {
              tipoPista = 2; // direita  
         etapa++; 
         }
        }
     void parafrente()
       {
         motor1.run(FORWARD);
         motor2.run(BACKWARD);
         etapa++;
       }
//Funções lado esquerdo
void pularcurvaesquerda()
{
objeto1 = digitalRead(S1);
objeto2 = digitalRead(S2);
objeto3 = digitalRead(S3);  
if((objeto1 == 0) && (objeto2 == 1) && (objeto3 == 1))
{
motor1.run(FORWARD);
motor2.run(BACKWARD); //Lógica invertida
etapa++;
}
}
void parareiresquerda()
{
objeto1 = digitalRead(S1);
objeto2 = digitalRead(S2);
objeto3 = digitalRead(S3);  
if((objeto1 == 0) && (objeto2 == 1) && (objeto3 == 1))
{
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(FORWARD); //<-------
motor4.run(FORWARD); //<-------
delay(2500);
etapa++; 
}
}
void servoesquerda()
{
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE); 
motor4.run(RELEASE);
delay(1000);
motor3.run(FORWARD);
motor2.run(BACKWARD); //Lógica invertida
delay(1000);
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE); 
motor4.run(RELEASE);

servo1.write(val);
delay(100);
val = val-5;
if (val == 10) 
{
// Caso val chegue a 180, volta a 0
val = -10;
etapa++;
   }
}
void curvadireita() 
{
objeto1 = digitalRead(S1);
objeto2 = digitalRead(S2);
objeto3 = digitalRead(S3);
if((objeto1 == 1) && (objeto2 == 0) && (objeto3 == 1) && (objeto4 == 1) && (objeto5 == 1))
{
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE); 
motor4.run(RELEASE);
delay(1000);
motor4.run(FORWARD);
motor2.run(FORWARD); //Lógica invertida BACKWARD
etapa++;
}  
}
void curvadireitaespecial() 
{
objeto1 = digitalRead(S1);
objeto2 = digitalRead(S2);
objeto3 = digitalRead(S3);
if((objeto1 == 1) && (objeto2 == 1) && (objeto3 == 1) && (objeto4 == 1) && (objeto5 == 1))
{
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE); 
motor4.run(RELEASE);
delay(1000);
motor4.run(FORWARD);
motor2.run(FORWARD); //Lógica invertida BACKWARD
etapa++;
}  
}
//lado direita
void pularcurvadireita()
{
objeto1 = digitalRead(S1);
objeto2 = digitalRead(S2);
objeto3 = digitalRead(S3);
if((objeto1 == 1) && (objeto2 == 0) && (objeto3 == 1)&& (objeto4 == 1) && (objeto5 == 1))
{
motor1.run(BACKWARD);
motor2.run(FORWARD); //Lógica invertida
etapa++;
}
}      
void parareirdireita()
{
objeto1 = digitalRead(S1);
objeto2 = digitalRead(S2);
objeto3 = digitalRead(S3);  
if((objeto1 == 1) && (objeto2 == 0) && (objeto3 == 1)&& (objeto4 == 1) && (objeto5 == 1))
{
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(BACKWARD); //------->
motor4.run(BACKWARD); //------->
delay(2500);
etapa++; 
}
}
void servodireita()
{
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE); 
motor4.run(RELEASE);
delay(1000);
motor3.run(BACKWARD);
motor2.run(FORWARD); //Lógica invertida
delay(1000);
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE); 
motor4.run(RELEASE);

servo1.write(val);
delay(100);
val = val-5;
if (val == 10) 
{
// Caso val chegue a 180, volta a 0
val = -10;
etapa++;
   }
}
void curvaesquerda() 
{
objeto1 = digitalRead(S1);
objeto2 = digitalRead(S2);
objeto3 = digitalRead(S3);
if((objeto1 == 0) && (objeto2 == 1) && (objeto3 == 1)&& (objeto4 == 1) && (objeto5 == 1))
{
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE); 
motor4.run(RELEASE);
delay(1000);
motor4.run(BACKWARD);
motor2.run(BACKWARD); //Lógica invertida FORWARD
etapa++;
}  
}
void curvaesquerdaespecial() 
{
objeto1 = digitalRead(S1);
objeto2 = digitalRead(S2);
objeto3 = digitalRead(S3);
if((objeto1 == 1) && (objeto2 == 1) && (objeto3 == 1)&& (objeto4 == 1) && (objeto5 == 1))
{
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE); 
motor4.run(RELEASE);
delay(1000);
motor4.run(BACKWARD);
motor2.run(BACKWARD); //Lógica invertida FORWARD
etapa++;
}  
}


       
//Função das rotas
void rota1() //1 COM 1 = 1 e C
{
 if(tipoPista == 1) // Pista da Esquerda
    switch(etapa)
    {
      case 1:
        //Acelerar
       parafrente();
      break;

      case 2:
        //Pular a curva a esquerda
       pularcurvaesquerda();
      break;

      case 3:
        //Pular curva a esquerda
        pularcurvaesquerda();
      break;

      case 4:
        //Fazer curva esquerda
        parareiresquerda();
      break;

      case 5:
         //Parar e girar para o servo
        servoesquerda(); 
      break;
      
      case 6:
         //Acelerar
        parafrente(); 
      break;
      case 7:
         //Fazer curva a direita
        curvadireitaespecial();
      break;
      case 8:
         //Acelerar
        parafrente();
      break;   
      case 9:
         //Fazer curva a direita
        curvadireitaespecial();
      break;
      case 10:
         //Acelerar
        parafrente();
      break;            
}      
 else if(tipoPista == 2) // Pista da Direita
  {
    switch(etapa)
    {
      case 1:
        //Acelerar
        parafrente();
      break;

      case 2:
        //Pular primeira curva
        pularcurvadireita();
      break;

      case 3:
        //Pular segunda curva
       pularcurvadireita();
      break;

      case 4:
        //Fazer curva direita
        parareirdireita();
      break;

      case 5:
         //Parar e girar para o servo
        servodireita();
      break;
      case 6:
        //Acelerar
        parafrente();
      break;
      case 7:
         //Fazer curva a esquerda
        curvaesquerdaespecial();
      break;
      case 8:
         //Acelerar
        parafrente();
      break;
      case 9:
         //Fazer curva a direita
        curvaesquerdaespecial();
      break;
       case 10:
         //Acelerar
        parafrente();
      break;     
    }
  }
}

void rota2() //1 COM 2 = 1 e B
{
 if(tipoPista == 1) // Pista da Esquerda
 
    switch(etapa)
    {
      case 1:
        //Acelerar
       parafrente();
      break;

      case 2:
        //Pular a curva a esquerda
       pularcurvaesquerda();
      break;

      case 3:
        //Pular curva a esquerda
        pularcurvaesquerda();
      break;

      case 4:
        //Fazer curva esquerda
        parareiresquerda();
      break;

      case 5:
         //Parar e girar para o servo
        servoesquerda(); 
      break;
      
      case 6:
         //Acelerar
        parafrente(); 
      break;
      case 7:
         //Fazer curva a direita
        curvadireitaespecial();
      break;
      case 8:
         //Acelerar
        parafrente();
      break;   
      case 9:
         //Fazer curva a esquerda
        curvaesquerdaespecial();
      break;
      case 10:
         //Acelerar
        parafrente();
      break;
      case 11:
         //Fazer curva a direita
        curvadireita();
      break;
      case 12:
         //Acelerar
        parafrente();
      break;
      case 13:
         //Fazer curva a direita
        curvadireita();
      break;
      case 14:
         //Acelerar
        parafrente();
      break;                  
}      
 else if(tipoPista == 2) // Pista da Direita
  {
    switch(etapa)
    {
      case 1:
        //Acelerar
        parafrente();
      break;

      case 2:
        //Pular primeira curva
        pularcurvadireita();
      break;

      case 3:
        //Pular segunda curva
       pularcurvadireita();
      break;

      case 4:
        //Fazer curva direita
        parareirdireita();
      break;

      case 5:
         //Parar e girar para o servo
        servodireita();
      break;
      case 6:
        //Acelerar
        parafrente();
      break;
      case 7:
         //Fazer curva a esquerda
        curvaesquerdaespecial();
      break;
      case 8:
         //Acelerar
        parafrente();
      break;
      case 9:
         //Fazer curva a direita
        curvadireita();
      break;
       case 10:
         //Acelerar
        parafrente();
      break;
      case 11:
         //Fazer curva a esquerda
        curvaesquerda();
      break;
      case 12:
         //Acelerar
        parafrente();
      break;
      case 13:
         //Fazer curva a esquerda
        curvaesquerda();
      break;
      case 14:
         //Acelerar
        parafrente();
      break;            
    }
  }
}

void rota3() //1 COM 3 = 1 e A
{
 if(tipoPista == 1) // Pista da Esquerda
 
    switch(etapa)
    {
      case 1:
        //Acelerar
       parafrente();
      break;

      case 2:
        //Pular a curva a esquerda
       pularcurvaesquerda();
      break;

      case 3:
        //Pular curva a esquerda
        pularcurvaesquerda();
      break;

      case 4:
        // curva esquerda
        parareiresquerda();
      break;

      case 5:
         //Parar e girar para o servo
        servoesquerda(); 
      break;
      
      case 6:
         //Acelerar
        parafrente(); 
      break;
      case 7:
         //Fazer curva a direita
        curvadireitaespecial();
      break;
      case 8:
         //Acelerar
        parafrente();
      break;   
      case 9:
         //Fazer curva a esquerda
        curvaesquerda();
      break;
      case 10:
         //Acelerar
        parafrente();
      break;
      case 11:
         //Fazer curva a direita
        curvadireita();
      break;
      case 12:
         //Acelerar
        parafrente();
      break;
      case 13:
        //Pular a curva a direita
       pularcurvadireita();
      break;
        case 14:
         //Fazer curva a direita
        parafrente();
      break; 
       case 15:
         //Fazer curva a direita
        curvadireita();
      break;                  
}      
 else if(tipoPista == 2) // Pista da Direita
  {
    switch(etapa)
    {
      case 1:
        //Acelerar
        parafrente();
      break;

      case 2:
        //Pular primeira curva
        pularcurvadireita();
      break;

      case 3:
        //Pular segunda curva
       pularcurvadireita();
      break;

      case 4:
        //Fazer curva direita
        parareirdireita();
      break;

      case 5:
         //Parar e girar para o servo
        servodireita();
      break;
      case 6:
        //Acelerar
        parafrente();
      break;
      case 7:
         //Fazer curva a esquerda
        curvaesquerdaespecial();
      break;
      case 8:
         //Acelerar
        parafrente();
      break;
      case 9:
         //Fazer curva a direita
        curvadireita();
      break;
       case 10:
         //Acelerar
        parafrente();
      break;
      case 11:
         //Fazer curva a esquerda
        curvaesquerda();
      break;
      case 12:
         //Acelerar
        parafrente();
      break;
        case 13:
        //Pular a curva a direita
       pularcurvaesquerda();
      break;
        case 14:
         //Fazer curva a direita
        parafrente();
      break; 
       case 15:
         //Fazer curva a direita
        curvaesquerda();
      break;                        
    }
  }
}
void rota4() //2 COM 1 = 2 e C
{
 if(tipoPista == 1) // Pista da Esquerda
 
    switch(etapa)
    {
   case 1:
        //Acelerar
       parafrente();
      break;

      case 2:
        //Pular a curva a esquerda
       pularcurvaesquerda();
      break;

      case 3:
        //Fazer curva esquerda
        parareiresquerda();
      break;

      case 4:
         //Parar e girar para o servo
        servoesquerda(); 
      break;

      case 5:
        //Acelerar
        parafrente(); 
      break;
      
      case 6:
            //Fazer curva a direita
        curvadireitaespecial();
      break;
      case 7:
        //Acelerar
        parafrente();
      break;
      case 8:
         //Pular curva a direita
        pularcurvadireita();
      break;   
      case 9:
         //Fazer curva a direita
        curvadireitaespecial();
      break;
      case 10:
         //Acelerar
        parafrente();
      break;                               
}      
 else if(tipoPista == 2) // Pista da Direita
  {
    switch(etapa)
    {
    case 1:
        //Acelerar
       parafrente();
      break;

      case 2:
        //Pular a curva a esquerda
       pularcurvadireita();
      break;

      case 3:
        //Fazer curva esquerda
        parareirdireita();
      break;

      case 4:
         //Parar e girar para o servo
        servodireita(); 
      break;

      case 5:
        //Acelerar
        parafrente(); 
      break;
      
      case 6:
            //Fazer curva a direita
        curvaesquerdaespecial();
      break;
      case 7:
        //Acelerar
        parafrente();
      break;
      case 8:
         //Pular curva a esquerda
        pularcurvaesquerda();
      break;   
      case 9:
         //Fazer curva a direita
        curvaesquerdaespecial();
      break;
      case 10:
         //Acelerar
        parafrente();
      break;                         
    }
  }
}
void rota5() //2 COM 2 = 2 e B
{
 if(tipoPista == 1) // Pista da Esquerda
 
    switch(etapa)
    {
   case 1:
        //Acelerar
       parafrente();
      break;

      case 2:
        //Pular a curva a esquerda
       detectalado();
       pularcurvaesquerda();
      break;

      case 3:
        //Fazer curva esquerda
        parareiresquerda();
      break;

      case 4:
         //Parar e girar para o servo
        servoesquerda(); 
      break;

      case 5:
        //Acelerar
        parafrente(); 
      break;
      
      case 6:
            //Fazer curva a direita
        curvadireitaespecial();
      break;
      case 7:
        //Acelerar
        parafrente();
      break;
      case 8:
         //Pular curva a direita
        pularcurvadireita();
      break;   
      case 9:
         //Fazer curva a direita
        curvaesquerdaespecial();
      break;
      case 10:
         //Acelerar
        parafrente();
      break; 
      case 11:
         //Fazer curva a direita
        curvadireita();
      break;
      case 12:
         //Acelerar
        parafrente();
      break; 
     case 13:
         //Fazer curva a direita
        curvadireita();
      break;
      case 14:
         //Acelerar
        parafrente();
      break; 
                      
}      
 else if(tipoPista == 2) // Pista da Direita
  {
    switch(etapa)
    {
        case 1:
        //Acelerar
       parafrente();
      break;

      case 2:
        //Pular a curva a esquerda
       detectalado();
       pularcurvadireita();
      break;

      case 3:
        //Fazer curva esquerda
        parareirdireita();
      break;

      case 4:
         //Parar e girar para o servo
        servodireita(); 
      break;

      case 5:
        //Acelerar
        parafrente(); 
      break;
      
      case 6:
            //Fazer curva a direita
        curvaesquerdaespecial();
      break;
      case 7:
        //Acelerar
        parafrente();
      break;
      case 8:
         //Pular curva a direita
        pularcurvaesquerda();
      break;   
      case 9:
         //Fazer curva a direita
        curvadireitaespecial();
      break;
      case 10:
         //Acelerar
        parafrente();
      break; 
      case 11:
         //Fazer curva a direita
        curvaesquerda();
      break;
      case 12:
         //Acelerar
        parafrente();
      break; 
     case 13:
         //Fazer curva a direita
        curvaesquerda();
      break;
      case 14:
         //Acelerar
        parafrente();
      break;   
    }
  }
}
void rota6() //3 COM 2 = 2 e A
{
 if(tipoPista == 1) // Pista da Esquerda
 
    switch(etapa)
    {
   case 1:
        //Acelerar
       parafrente();
      break;
    case 2:
        //Pular
       pularcurvaesquerda();
      break;
      case 3:
         //Fazer curva esquerda
        parareiresquerda();
      break;

      case 4:
  //Parar e girar para o servo
        servoesquerda();
      break;

      case 5:
         //Acelerar
        parafrente(); 
      break;

      case 6:
        //Fazer curva a direita
        curvadireitaespecial() ;
      break;
      
      case 7:
         //Acelerar
        parafrente();
      break;
      case 8:
         //Pular curva a direita
        pularcurvadireita();
      break;
      case 9:
         //Fazer curva a direita
        curvaesquerdaespecial();
      break;
      case 10:
         //Acelerar
        parafrente();
      break; 
      case 11:
         //Fazer curva a direita
        curvadireita();
      break;
      case 12:
         //Acelerar
        parafrente();
      break; 
     case 13:
         //Fazer curva a direita
        pularcurvadireita();
      break;
      case 14:
         //Fazer curva a direita
        pularcurvadireita();
      break;
      case 15:
         //Fazer curva a direita
        curvadireita();
      break;
       case 16:
         //Acelerar
        parafrente();
      break;  
                      
}      
 else if(tipoPista == 2) // Pista da Direita
  {
    switch(etapa)
    {
           case 1:
        //Acelerar
       parafrente();
      break;
    case 2:
        //Pular
       pularcurvadireita();
      break;
      case 3:
         //Fazer curva esquerda
        parareirdireita();
      break;

      case 4:
  //Parar e girar para o servo
        servodireita();
      break;

      case 5:
         //Acelerar
        parafrente(); 
      break;

      case 6:
        //Fazer curva a direita
        curvaesquerdaespecial() ;
      break;
      
      case 7:
         //Acelerar
        parafrente();
      break;
      case 8:
         //Pular curva a direita
        pularcurvaesquerda();
      break;   
      case 9:
         //Fazer curva a direita
        curvadireitaespecial();
      break;
      case 10:
         //Acelerar
        parafrente();
      break; 
      case 11:
         //Fazer curva a direita
        curvaesquerda();
      break;
      case 12:
         //Acelerar
        parafrente();
      break; 
     case 13:
         //Fazer curva a direita
        pularcurvaesquerda();
      break;
      case 14:
         //Fazer curva a direita
        pularcurvaesquerda();
      break;
      case 15:
         //Fazer curva a direita
        curvaesquerda();
      break;
       case 16:
         //Acelerar
        parafrente();
      break;  
                      
} 
    }
  }
void rota7() //3 COM 1 = 3 e C
{
 if(tipoPista == 1) // Pista da Esquerda
 
    switch(etapa)
    {
   case 1:
        //Acelerar
       parafrente();
      break;

      case 2:
       //Fazer curva esquerda
        parareiresquerda();
      break;

      case 3:
        //Parar e girar para o servo
        servoesquerda(); 
      break;

      case 4:
         //Acelerar
        parafrente() ;
      break;

      case 5:
         //Fazer curva a direita
        curvadireitaespecial();
      break;
      
      case 6:
            //Acelerar
        parafrente();
      break;
      case 7:
        //Pular
        pularcurvadireita();
      break;
      case 8:
         //Pular curva a direita
        pularcurvadireita();
      break;   
      case 9:
            //Acelerar
        parafrente();
      break;
      case 10:
         //Acelerar
        curvadireita();
      break;
      case 11:
            //Acelerar
        parafrente();
      break;                               
}      
 else if(tipoPista == 2) // Pista da Direita
  {
    switch(etapa)
    {
    case 1:
        //Acelerar
       parafrente();
      break;

      case 2:
       //Fazer curva esquerda
        parareirdireita();
      break;

      case 3:
        //Parar e girar para o servo
        servodireita(); 
      break;

      case 4:
         //Acelerar
        parafrente() ;
      break;

      case 5:
         //Fazer curva a direita
        curvaesquerdaespecial();
      break;
      
      case 6:
            //Acelerar
        parafrente();
      break;
      case 7:
        //Pular
        pularcurvaesquerda();
      break;
      case 8:
         //Pular curva a direita
        pularcurvaesquerda();
      break;   
      case 9:
            //Acelerar
        parafrente();
      break;
      case 10:
         //Acelerar
        curvaesquerda();
      break;
      case 11:
            //Acelerar
        parafrente();
      break;                                        
    }
  }
}

void rota8() //3 COM 2 = 3 e B 
{
 if(tipoPista == 1) // Pista da Esquerda
 
    switch(etapa)
    {
   case 1:
        //Acelerar
       parafrente();
      break;

      case 2:
       //Fazer curva esquerda
        parareiresquerda();
      break;

      case 3:
        //Parar e girar para o servo
        servoesquerda(); 
      break;

      case 4:
         //Acelerar
        parafrente() ;
      break;

      case 5:
         //Fazer curva a direita
        curvaesquerdaespecial();
      break;
      
      case 6:
            //Acelerar
        parafrente();
      break;
      case 7:
        //Pular
        pularcurvadireita();
      break;
      case 8:
         //Pular curva a direita
        pularcurvadireita();
      break;   
      case 9:
            //Acelerar
        parafrente();
      break;
      case 10:
         //Acelerar
        curvaesquerdaespecial();
      break;
      case 12:
            //Acelerar
        parafrente();
      break; 
      case 13:
            //Acelerar
        curvadireita();
      break;   
     case 14:
            //Acelerar
        parafrente();
      break; 
                                    
}      
 else if(tipoPista == 2) // Pista da Direita
  {
    switch(etapa)
    {
      case 1:
        //Acelerar
       parafrente();
      break;

      case 2:
       //Fazer curva esquerda
        parareirdireita();
      break;

      case 3:
        //Parar e girar para o servo
        servodireita(); 
      break;

      case 4:
         //Acelerar
        parafrente() ;
      break;

      case 5:
         //Fazer curva a direita
        curvadireitaespecial();
      break;
      
      case 6:
            //Acelerar
        parafrente();
      break;
      case 7:
        //Pular
        pularcurvaesquerda();
      break;
      case 8:
         //Pular curva a direita
        pularcurvaesquerda();
      break;   
      case 9:
            //Acelerar
        parafrente();
      break;
      case 10:
         //Acelerar
        curvaesquerdaespecial();
      break;
      case 12:
            //Acelerar
        parafrente();
      break; 
      case 13:
            //Acelerar
        curvaesquerda();
      break; 
           case 14:
            //Acelerar
        parafrente();
      break; 
    }
  }
}
void rota9() //3 COM 3 = 3 e A 
{
 if(tipoPista == 1) // Pista da Esquerda
 
    switch(etapa)
    {
   case 1:
        //Acelerar
       parafrente();
      break;

      case 2:
       //Fazer curva esquerda
        parareiresquerda();
      break;

      case 3:
        //Parar e girar para o servo
        servoesquerda(); 
      break;

      case 4:
         //Acelerar
        parafrente() ;
      break;

      case 5:
         //Fazer curva a direita
        curvadireitaespecial();
      break;
      
      case 6:
            //Acelerar
        parafrente();
      break;
      case 7:
        //Pular
        pularcurvadireita();
      break;
      case 8:
         //Pular curva a direita
        pularcurvadireita();
      break;   
      case 9:
            //Acelerar
        parafrente();
      break;
      case 10:
         //Acelerar
        curvaesquerdaespecial();
      break;
      case 12:
            //Acelerar
        parafrente();
      break; 
      case 13:
            //Acelerar
        pularcurvadireita();
      break;   
      case 14:
            //Acelerar
        parafrente();
      break; 
      case 15:
         //Acelerar
        curvadireita();
      break;
     case 16:
            //Acelerar
        parafrente();
      break; 
                                  
}      
 else if(tipoPista == 2) // Pista da Direita
  {
    switch(etapa)
    {
      case 1:
        //Acelerar
       parafrente();
      break;

      case 2:
       //Fazer curva esquerda
        parareirdireita();
      break;

      case 3:
        //Parar e girar para o servo
        servodireita(); 
      break;

      case 4:
         //Acelerar
        parafrente() ;
      break;

      case 5:
         //Fazer curva a direita
        curvadireitaespecial();
      break;
      
      case 6:
            //Acelerar
        parafrente();
      break;
      case 7:
        //Pular
        pularcurvadireita();
      break;
      case 8:
         //Pular curva a direita
        pularcurvadireita();
      break;   
      case 9:
            //Acelerar
        parafrente();
      break;
      case 10:
         //Acelerar
        curvaesquerdaespecial();
      break;
      case 12:
            //Acelerar
        parafrente();
      break; 
      case 13:
            //Acelerar
        pularcurvadireita();
      break;   
      case 14:
            //Acelerar
        parafrente();
      break; 
      case 15:
         //Acelerar
        curvaesquerda();
      break;
     case 16:
            //Acelerar
        parafrente();
      break; 
    }
  }
}


void setup() 
  // put your setup code here, to run once:
  {
// Pinos de entradas
pinMode(S1,INPUT);
pinMode(S2,INPUT);
pinMode(S3,INPUT);
// Motores
motor1.setSpeed(125);
motor2.setSpeed(125);
motor3.setSpeed(125);
motor4.setSpeed(125);
//Bluetooth 
Serial.begin(9600);
mySerial.begin(9600);
//Servo
servo1.attach(10);
  }
void loop() 
{ 
detectalado();  
le_bluetooth();  
switch(X)
    {
      case 'a': // Pista 1, Caminho C
        rota1();
      break;

      case 'b': // Pista 1, Caminho B
       rota2();
      break;

      case 'c': // Pista 1, Caminho A
        rota3();
      break;

      case 'd': // Pista 2, Caminho C
        rota4();
      break;

      case 'e': // Pista 2, Caminho B
        rota5();
      break;

      case 'f': // Pista 2, Caminho A
        rota6();
      break;

      case 'g': // Pista 3, Caminho C
        rota7();
      break;

      case 'h': // Pista 3, Caminho B
        rota8();
      break;

      case 'i': // Pista 3, Caminho A
        rota9();
      break;

      default:
       //parafrente();
      break;
    }
}  
