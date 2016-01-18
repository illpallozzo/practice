#include "Led2x7bit.h"

Led2x7bit::Led2x7bit(int left, int right, int bit1, int bit2) {
    charFirst = right;
    charLast = left;
    ledFirst = bit1;
    ledLast = bit2;
    outputInt = 0x00;

  for(int led=ledFirst; led<= ledLast; ++led) {
    pinMode(led, OUTPUT);
    digitalWrite(led,LOW);
  }

  pinMode(charFirst, OUTPUT);
  pinMode(charLast, OUTPUT);
  digitalWrite(charFirst, LOW);
  digitalWrite(charLast, LOW);

}

void Led2x7bit::display(int value) {
    bitDisplay((value & 0x0f), charFirst);
    bitDisplay((value & 0xf0) >> 4, charLast);
}


void Led2x7bit::bitDisplay(char inputInt, int digit)
{
  digitalWrite(digit, HIGH);
  byte displayByte = numberSet[inputInt];

  for(int x = ledFirst; x<=ledLast; ++x)
  {
    digitalWrite(x,displayByte & 0x01? LOW : HIGH);
    displayByte >>= 1;
  }
  delay(5);
  digitalWrite(digit,LOW);
}
