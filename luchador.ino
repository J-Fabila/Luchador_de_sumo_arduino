/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////PROGRAMA LUCHADOR DE SUMO v2.0/////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//VARIABLES SEGUIDOR DE LINEA
    int sizq;
    int sder;
    int scen;
    int stra;
    char color;
  int paramdist = 30;

  
 int pinecho1 = 2; //8
 int pintrigger1 = 3; //9
 int pintrigger2 = 4; //10
 int pinled = 13;
 int pinecho2 = 5; //7
// VARIABLES PARA CALCULOS
 
    void setup() {
      // put your setup code here, to run once:
      int i;
// put your setup code here, to run once:
pinMode(pinecho1, INPUT);
  pinMode(pinecho2, INPUT);
  pinMode(pintrigger1, OUTPUT);
   pinMode(pintrigger2, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(1, OUTPUT);

#define  in1 8
#define  in2 7
#define  en1 6
#define  en2 11
#define  in3 10
#define  in4 9
/*
    pinMode(A0,  INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    pinMode(A4, INPUT);
    Serial.begin(9600);
*/
//////////////////////////////////////////////////////////
////////////////VARIABLES ULTRASÓNICAS////////////////////
//////////////////////////////////////////////////////////



    }

    void loop() {
int tiempo_1;
int tiempo_2;
int distancia_1;
int distancia_2;
      
/////////////////////////////////////////////////////////
///////////////////SENSOR ULTRASÓNICO////////////////////
/////////////////////////////////////////////////////////

  digitalWrite(pintrigger2, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger2, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(pintrigger2, LOW);
  tiempo_2 = pulseIn(pinecho2, HIGH);
    distancia_2 = tiempo_2 / 58;

      
//////////////////////////////////////////////////////////
////////////////////LEE LOS SENSORES//////////////////////
//////////////////////////////////////////////////////////

    sizq=analogRead(A3);    
    sder=analogRead(A1);
    scen=analogRead(A2);
    stra=analogRead(A0);

///////////////////////////////////////////////////////////
////////IMPRIME A PANTALLA DATOS DE LOS SENSORES///////////
///////////////////////////////////////////////////////////
   /* Serial.print( sizq );
    Serial.print( "  " );
    Serial.print(sder );
    Serial.print( "  " );
    Serial.print(scen);
    Serial.print( "  " );
    Serial.println(stra); // envía valor analógico
    delay(100);  
 // ENVIAR EL RESULTADO AL MONITOR SERIAL
  Serial.print(distancia);
  Serial.println(" cm");
  delay(5); */

if ((stra < 800) &&  (scen < 800 ) && (sder < 800) && (sizq < 800 ))
{

if(distancia_2<paramdist)

{
  distancia_1 = paramdist +50;
  while (distancia_1>paramdist)
  {
////////////////////////////////////////////////////////////
////////////////////////VUELTA DERECHA//////////////////////
////////////////////////////////////////////////////////////

                           digitalWrite(en1, LOW);
                           digitalWrite(in1, HIGH);
                           digitalWrite(in2, LOW);
                         
                           digitalWrite(en2, HIGH);
                           digitalWrite(in4, HIGH);
                           digitalWrite(in3, LOW);
    
   // delay(t); /t = tiempo que tarda en hacermediciones ultrasonicas


  digitalWrite(pintrigger1, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger1, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(pintrigger1, LOW);
    tiempo_1 = pulseIn(pinecho1, HIGH);
    distancia_1 = tiempo_1 / 58;

   
  }
}
else
{
  distancia_1 = paramdist +50;
  while(distancia_1>paramdist)
  {
//////////////////////////////////////////////////////////////
////////////////////////VUELTA IZQUIERDA//////////////////////
//////////////////////////////////////////////////////////////
                  
digitalWrite(en1, HIGH);
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);

digitalWrite(en2, LOW);
digitalWrite(in4, HIGH);
digitalWrite(in3, LOW);
   
   // delay(t); t= tiempo que tarda en hacer medicines ultrasonicas;
   
  digitalWrite(pintrigger1, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger1, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(pintrigger1, LOW);
    tiempo_1 = pulseIn(pinecho1, HIGH);
    distancia_1 = tiempo_1 / 58;  
  }
}
while(distancia_1<=paramdist)
{
  
/////////////////////////////////////////////////////////
/////////////////////CAMINA DERECHO//////////////////////
/////////////////////////////////////////////////////////
        
    digitalWrite(en1, HIGH);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(en2, HIGH);
    digitalWrite(in4, HIGH);
    digitalWrite(in3, LOW);
  
  
  digitalWrite(pintrigger1, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger1, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(pintrigger1, LOW);
    tiempo_1 = pulseIn(pinecho1, HIGH);
    distancia_1 = tiempo_1 / 58;

}
}
else{
 //////////////////////////////////////////////////////////////////
 ////////////////////LEE SENSORES INFRARROJOS//////////////////////
 //////////////////////////////////////////////////////////////////

if (stra < 800 && ( scen > 800  || sder > 800  || sizq > 800 ))
                           {

while(stra < 800 && ( scen > 800  || sder > 800  || sizq > 800 ))
                           {
////////////////////////////////////////////////////////////
////////////////////////CAMINA ATRAS//////////////////////
////////////////////////////////////////////////////////////
                        
                                     
digitalWrite(en1, HIGH);
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH); 

                       digitalWrite(en2, HIGH);
                           digitalWrite(in4, LOW);
                           digitalWrite(in3, HIGH);
                                
//////////////////////////////////////////////////////////
////////////////////LEE LOS SENSORES//////////////////////
//////////////////////////////////////////////////////////

    sizq=analogRead(A3);    
    sder=analogRead(A1);
    scen=analogRead(A2);
    stra=analogRead(A0);
                           }
                            
                           }
                           else{
       if(stra > 800 && ( scen < 800  || sder < 800  || sizq < 800 ))
       {
         while (stra > 800 && ( scen < 800  || sder < 800  || sizq < 800 ))        
            {                         
digitalWrite(en1, HIGH);
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW); 

                       digitalWrite(en2, HIGH);
                           digitalWrite(in4, HIGH);
                           digitalWrite(in3, LOW);
                                                           
//////////////////////////////////////////////////////////
////////////////////LEE LOS SENSORES//////////////////////
//////////////////////////////////////////////////////////

    sizq=analogRead(A3);    
    sder=analogRead(A1);
    scen=analogRead(A2);
    stra=analogRead(A0);
                           }
                           }
    }
 
}
    }
