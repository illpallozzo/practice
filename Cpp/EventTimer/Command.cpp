#include "Command.h"

Command::Command() {
    outputNum = 0;
    interval = 0UL;
    last = 0UL;
}

Command::Command(unsigned long triggerInterval, int number) {
    outputNum = number;
    interval = triggerInterval;
    last = millis();

    //Serial.print(outputNum);
    //Serial.println("  <<<  Registered");
}

void Command::setInterval(unsigned long triggerInterval) {
    interval = triggerInterval;
    last = millis();
}

int Command::trigger() {
    //Serial.print(" trigger on >> : ");
    //Serial.print(outputNum);
    //Serial.print(" :  << interval >>  ");
    //Serial.print(interval);
    //Serial.print("  :  << since last  >>  ");
    //Serial.println(millis() - last);

    last = millis();
    return outputNum;
}

unsigned long Command::nextTrigger() {
    unsigned long current = millis();
    long difference = current - last;
    return (interval - difference);
}

int Command::trigger(int number) {return number + trigger();}
unsigned long Command::lastTrigger() {return last;}
