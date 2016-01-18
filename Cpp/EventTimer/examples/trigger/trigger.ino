#include "EventTimer.h"
#include "Command.h"
#include "Led2x7bit.h"


EventTimer et;
Led2x7bit ledOut = Led2x7bit(5,6,7,13);

void setup()
{
   Serial.begin(9600);
   Serial.println("started");
   
  et = EventTimer();
  delay(100);

  for(int i=0;i<11;++i) {
    unsigned long interval = (1100UL + (i * 430UL));
    Command cmd = Command(interval, i);
    Serial.print("    interval  ><>  ");
    Serial.println(interval);
    Serial.println(et.registerEventTimer(cmd) ? "go" : "fail");
  }
  Serial.println("init-ed");
}

void loop()
{  
  int recentTrigger;
  while(1) { 
    recentTrigger = et.update();
    long remains = et.getRemaining();
    while(remains > 5) {
      remains -= 10
      ledOut.display(recentTrigger);
    } 
  }
}
