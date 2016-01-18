#ifndef EVENTTIMER_H
#define EVENTTIMER_H

#include "Arduino.h"
#include "Command.h"

#define MAXWAIT 1000UL;
#define MAXCOMMANDS 10
class EventTimer
{
    private:
      unsigned long current;
      Command timers[MAXCOMMANDS];
        
    public:       
      EventTimer();
      bool registerEventTimer(Command commander);
      unsigned long getRemaining();
      int waitRemaining();
      int update();
};

#endif