#include <Servo.h> 
 int PrimeiroAndar = 8;
 int SegundoAndar = 9;
 int TerceiroAndar = 10;
 int BotaoSubida = 2;
 int BotaoDescida = 3;
 int pos = 0;   
Servo myservo;  

void setup(){ 
  pinMode(BotaoSubida,INPUT);
  pinMode(BotaoDescida,INPUT);
  pinMode(PrimeiroAndar,OUTPUT);
  pinMode(SegundoAndar ,OUTPUT);
  pinMode(TerceiroAndar,OUTPUT);
  myservo.attach(11);
  
  digitalWrite(PrimeiroAndar,HIGH);
 
  attachInterrupt(digitalPinToInterrupt(BotaoSubida),Subida,FALLING);
  attachInterrupt(digitalPinToInterrupt(BotaoDescida),Descida,FALLING);
} 

void loop() { 
  myservo.write(pos); 

}


void Subida(){
    if (pos==0){
   digitalWrite(PrimeiroAndar,LOW);
   digitalWrite(SegundoAndar,HIGH);
    for (pos = 0; pos <90; pos += 1) { 
   			 myservo.write(pos);  
 			 delay(15);
 	 }
  }else if (pos==90){
  	 digitalWrite(SegundoAndar,LOW);
      digitalWrite(TerceiroAndar,HIGH);
   	 for (pos = 90; pos <180; pos += 1) { 
   			 myservo.write(pos);  
 			 delay(15);
       
 	 }
  }
  
}


void Descida(){
   if (pos==180){
   digitalWrite(TerceiroAndar,LOW);
    for (pos = 180; pos >90; pos -= 1) { 
   			 myservo.write(pos);  
 			 delay(15);
       digitalWrite(SegundoAndar,HIGH);
 	 }
  }else if (pos==90){
   digitalWrite(SegundoAndar,LOW);
    for (pos = 90; pos >0; pos -= 1) { 
   			 myservo.write(pos);  
 			 delay(15);
       digitalWrite(PrimeiroAndar,HIGH);
 	 }
  }
  
  
}