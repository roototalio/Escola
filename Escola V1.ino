#include <Servo.h>
#include <SoftwareSerial.h> //INCLUSÃO DE BIBLIOTECA
#define SERVO 9 // Porta Digital 6 PWM
#define Led 4
#define Led2 5
#define Led3 6
#define Led4 7
SoftwareSerial bluetooth(2, 3);
Servo s; // Variável Servo
int pos; // Posição Servo

char val;
String Cled;
int valor = 500;
void setup ()
{
  s.attach(SERVO);
  bluetooth.begin(9600);
  Serial.begin(9600);
  s.write(86); // Inicia motor na posição zero
  pinMode(Led, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
  
}

void loop()
{
  
  
  if(bluetooth.available())
{

     val =   bluetooth.read();

     Cled = val;
     
     Serial.println(val);
      
     if(Cled == "A"){
       digitalWrite(Led, !digitalRead(Led));
       delay(valor);
     }else if(Cled == "B"){
      digitalWrite(Led2, !digitalRead(Led2));
      delay(valor); 
     }else if(Cled == "C"){
      digitalWrite(Led3, !digitalRead(Led3));
      delay(valor);
     }else if(Cled == "D"){
      digitalWrite(Led4, !digitalRead(Led4));
      delay(valor);
     }else{

     if(val == '1'){
      delay(15);
      s.write(180);
     }else if(val == '2'){
      delay(15);
      s.write(0);
     }else if(val == '0'){
      delay(15);
      s.write(87);
     }
     }
     
val = '0';
Cled = "";
   
}


 
}
