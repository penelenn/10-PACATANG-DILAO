const int sensorPin1 = A0; 
const int sensorPin2 = A1;
const int sensorPin3 = A2;
int sensorValue1 = 0;   
int sensorValue2 = 0;
int sensorValue3 = 0;
float Vin = 5;
float Vout1 = 0;  
float Vout2 = 0;
float Vout3 = 0;
float Rref1 = 1000; 
float Rref2 = 1000;
float Rref3 = 1000;
float r1=0,r2=0,r3=0;
float ra=0,rb=0,rc=0;
void setup ()
{
  Serial.begin(9600);      // Initialize serial communications at 9600 bps
}
void getR1(){
  sensorValue1 = analogRead(sensorPin1);
  Vout1 = (Vin * sensorValue1) / 1023;    
  ra = Rref1 * (1 / ((Vin / Vout1) - 1));  
  Serial.print("Resistor A: ");                  
  Serial.println(ra);                
  delay(1000);
  }
  void getR2(){
  sensorValue2 = analogRead(sensorPin2);
  Vout2 = (Vin * sensorValue2) / 1023;    
  rb = Rref2 * (1 / ((Vin / Vout2) - 1));  
  Serial.print("Resistor B: ");                  
  Serial.println(rb);                     // Give calculated resistance in Serial Monitor
  delay(1000);
  }
  void getR3(){
  sensorValue3 = analogRead(sensorPin3);
  Vout3 = (Vin * sensorValue3) / 1023;    
  rc = Rref3 * (1 / ((Vin / Vout3) - 1));  
  Serial.print("Resistor C: ");                  
  Serial.println(rc);                     // Give calculated resistance in Serial Monitor
    delay(1000);
  }
void loop ()
{
  Serial.println("------------------------------------------");
  Serial.println("Y to Delta");
  Serial.println("Reading Resistors. . . . ");
  getR1();
  getR2();
  getR3();
  Serial.println("Computing.....");
  delay(2000);
    r1=((ra*rb)+(rb*rc)+(rc*ra))/ra;
    r2=((ra*rb)+(rb*rc)+(rc*ra))/rb;
    r3=((ra*rb)+(rb*rc)+(rc*ra))/rc;
    Serial.print("Resistor 1:");
    Serial.println(r1);
    Serial.print("Resistor 2:");
    Serial.println(r2);
    Serial.print("Resistor 3:");
    Serial.println(r3);
   
delay(2000);
}
