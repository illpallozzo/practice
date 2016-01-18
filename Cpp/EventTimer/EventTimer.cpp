#include "EventTimer.h"

EventTimer::EventTimer() {
    current = millis();

    for(int i=0;i<MAXCOMMANDS;++i) {
      Command cmd = Command();
      registerEventTimer(cmd);
    }
}

        // this will only register the MAXCOMMANDS number of
	//             listeners and   forget any further registrations

bool EventTimer::registerEventTimer(Command commander) {

    for(int i=0;i<MAXCOMMANDS;++i) {
        if(timers[i].lastTrigger() == 0) {
            timers[i] = commander;
            return true;
        }
    }
    return false;
}

unsigned long EventTimer::getRemaining(){
    unsigned long remaining = MAXWAIT;

    for(int i = 0;i<MAXCOMMANDS;++i) {
        unsigned long compare = timers[i].nextTrigger();

        if(timers[i].lastTrigger() == 0) {
            //do nothing right now (null command)

        } else if(compare < remaining) {
            remaining = compare;

        }  else  {
           //nothing to do here right now (catch all)
        }
    }
    return remaining;
}

int EventTimer::waitRemaining() {
    unsigned long waitTime = getRemaining();

    delay(waitTime );
    return update();
}

int EventTimer::update() {
    int triggerCount = 0;
    int triggered = 0;
    current = millis();

    for(int i=0;i<MAXCOMMANDS;++i) {
        unsigned long compare = timers[i].nextTrigger();
        compare += current;

        if((timers[i].lastTrigger() != 0) && (compare < current)) {
            ++triggerCount;
            triggered =  timers[i].trigger();
        }
    }
    return triggerCount;
}
