#include "EventTimer.h"
#include "Command.h"

#define PASS  			HIGH
#define PRIME			LOW

#define ON 				LOW
#define OFF 			HIGH
#define FIRST 			5
#define SECOND 		6

EventTimer et1;
int led;
int digit[2];
int circleLED;
int duration;
int flash;
int pace;
bool etReg;
  
void setup()
{
   Serial.begin(9600);
   Serial.println("started");
   
  et1 = EventTimer();
  digit = {FIRST,SECOND};
  circleLED = 0;
  etReg = true;
  duration = 120;
  flash = 20;
  pace = duration;
  
  for(led = 5; led <= 13; ++led) {
    pinMode(led, OUTPUT);
  }
  
  clearDisplay();
  delay(100);
  

  
  if(etReg) 
  {
    for(int i=0;i<7;++i) {
      unsigned long interval = (3300UL + ((i * 2700) * 1UL));
      Command cmd = Command(interval, (i + 7));
      Serial.print("    interval  ><>  ");
      Serial.println(interval);
      etReg = et1.registerEventTimer(cmd);
      delay(100);
    }
  }
  
  Serial.println("init-ed");
}

void loop()
{
  while(1) {
    pace = duration;
     
    if(led = et1.update()) {
      digitalWrite(digit[0],PRIME);
      digitalWrite(led,ON);
      delay(flash);
      pace -= flash;
    }
    clearDisplay();
    digit = secondLEDout;
    digitalWrite(digit[1],PRIME);
    circleLED = (circleLED +1) % 6;
    digitalWrite(circleLED + 7, ON);
    delay(pace);
    clearDisplay();
  }
}

void clearDisplay(){
  digitalWrite(digit[0],PASS);
  digitalWrite(digit[1],PASS);

  for(led = 5; led <= 13; ++led) {
    digitalWrite(led,OFF);
  }
  delay(3);
}
