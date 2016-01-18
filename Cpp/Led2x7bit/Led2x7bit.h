#ifndef LED2X7BIT
#define LED2X7BIT

#include "Arduino.h"

#define NUMSET {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67, 0x77,  0x7c,  0x58,  0x5e,  0x79,  0x71,  0x00}

static int numberSet[17] = NUMSET;//     = {B00111111, B00000110, 		B01011011, B01001111, B01100110, B01101101, B01111101, 		B00000111, B01111111, B01100111, B01110111, B01111100, 		B01011000, B01011110, B01111001, B01110001, B00000000};

class Led2x7bit 
{
  private:
    
    int charFirst;
    int charLast;
    int ledFirst;
    int ledLast;
    int outputInt;

    void bitDisplay(char inputInt, int digit);

  public:
    Led2x7bit(int left, int right, int bit1, int bit2);
    void display(int value);
};

#endif