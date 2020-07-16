#define trigPin 2
#define echoPin 3
int status=0;
int ledPin= 13;  //Connect LEd pin to 6
int duration, distance; //to measure the distance and time taken 

void setup() 
{
        Serial.begin (9600); 
        pinMode(trigPin, OUTPUT); 
        pinMode(echoPin, INPUT);
        pinMode(ledPin, OUTPUT);
}
void loop() {
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(10);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    Serial.print("distance= ");              
        Serial.println(distance);   
  if (distance <= 10) 
       {
         delay(200);
         if(status==0)
         {
              status=1;
              digitalWrite(ledPin,LOW);//relay on
              delay(1500);
              digitalWrite(ledPin,HIGH);//relay off
              delay(1000);
         }
     }
     else
     {
      if(status==1)
      {
        status=0;
        digitalWrite(ledPin,HIGH);
      }
    }
  }
 
