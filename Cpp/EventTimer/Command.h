#ifndef COMMAND_H
#define COMMAND_H

#include "Arduino.h"

class Command
{
  private:
    unsigned long interval;
    unsigned long last;
    int outputNum;

  public:
    Command();
    Command(unsigned long triggerInterval, int number);
    void setInterval(unsigned long triggerInterval);
    int trigger();
    int trigger(int number);
    unsigned long nextTrigger();
    unsigned long lastTrigger();
};

#endif