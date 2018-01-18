// Matriz com os pinos onde o LED RGB vai ser conectado 
int matrizPinodosLEDS[] = {   2,3,4}; 

// Uma variável booleana para indicar se o sensor foi calibrado 
boolean balanco = false; 

//Matriz de floats para armazenar o valor das cores 
float matrizCores[] = {   0,0,0}; 
float matrizBranco[] = {   0,0,0}; 
float matrizPreto[] = {   0,0,0}; 

//Variável para armazenar a média das leitura 
int mediaLeituras; 

void setup()
{   

//Declaração dos pinos como de saída   
pinMode(2,OUTPUT);//LED VERMELHO   
pinMode(3,OUTPUT);//LED GREENN   
pinMode(4,OUTPUT);//LED BLUE   //Inicia a comunicação serial   

Serial.begin(9600); 

} 

void loop()
{   

// Verifica se o Balanco de branco foi calibrado   
checaBalanco();    
//Checa qual é a cor   
checaCores();   
// Imprime na Serial o valor das cores   
mostraCores(); 
}

// Verifica se o Balanco de branco foi calibrado
void checaBalanco() {   
//checa se o balanço de branco foi feito   
if(balanco == false){     
confBalanco();   
} 

} 

//Configura o balanco de Branco 
void confBalanco(){   

//Calibrando o branco!   
Serial.println("Calibrando o branco");   
delay(5000);   
for(int i = 0;i<=2;i++){     
digitalWrite(matrizPinodosLEDS[i],HIGH);     
delay(100);     
mediaSensor(5);               
matrizBranco[i] = mediaLeituras;     
digitalWrite(matrizPinodosLEDS[i],LOW);     
delay(100);   
}   

//Calibrando o preto!   
Serial.println("Calibrando o preto");   
delay(5000);   
for(int i = 0;i<=2;i++){     
digitalWrite(matrizPinodosLEDS[i],HIGH);     
delay(100);     
mediaSensor(5);     
matrizPreto[i] = mediaLeituras;     
digitalWrite(matrizPinodosLEDS[i],LOW);     
delay(100);   
}   

//Avisa que a calibragem foi feita   
Serial.println("Sensor Calibrado");   
balanco = true;   
delay(3000); } 

//Checa a cor 
void checaCores(){   
for(int i = 0;i<=2;i++){     
digitalWrite(matrizPinodosLEDS[i],HIGH);     
delay(100);     
mediaSensor(5);                       
matrizCores[i] = mediaLeituras;             
float cinzaDif = matrizBranco[i] - matrizPreto[i];     
matrizCores[i] = (matrizCores[i] - matrizPreto[i])/(cinzaDif)*255;      
digitalWrite(matrizPinodosLEDS[i],LOW);     
delay(100);   
} 

} 


void mediaSensor(int vezes){   
int leituras;   
int somatorio=0;   
for(int i = 0;i < vezes;i++){     
leituras = analogRead(0);     
somatorio = leituras + somatorio;     
delay(10);   
}   
mediaLeituras = (somatorio)/vezes; 
} 

void mostraCores(){   
Serial.print("R = ");   
Serial.println(int(matrizCores[0]));   
Serial.print("G = ");   
Serial.println(int(matrizCores[1]));   
Serial.print("B = ");   
Serial.println(int(matrizCores[2])); 

}