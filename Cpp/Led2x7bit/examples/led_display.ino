/*
 connect pins 5 and 6 to digit primaries
 connect 7-13 as display lines 
 */
 
int led = 5;
int ledRangeLo = 5;
int ledRangeHi = 13;
int digit1 = 6;
int digit2 = 5;
int loBit = 7;
int hiBit = 13;
int outputInt = 0x00;
long last_count = millis();


void bitDisplay(int inputInt, int digit)
{
  byte displayByte = 0x00;
  digitalWrite(digit, HIGH);
  switch(inputInt & 0x0f)
    {
      case 0:
        displayByte = B00111111;
      break;
      case 1:
        displayByte = B00000110;
      break;
      case 2:
        displayByte = B01011011;
      break;
      case 3:
        displayByte = B01001111;
      break;
      case 4:
        displayByte = B01100110;
      break;  
      case 5:  
        displayByte = B01101101;  
      break;  
      case 6:
        displayByte = B01111101;
      break;
      case 7:
        displayByte = B00000111;
      break;
      case 8:
        displayByte = B01111111;
      break;
      case 9:
        displayByte = B01100111;
      break;
      case 10://a
        displayByte = B01110111;
      break;
      case 11://b
        displayByte = B01111100;
      break;
      case 12://c
        displayByte = B01011000;
      break;
      case 13://d
        displayByte = B01011110;
      break;
      case 14://e
        displayByte = B01111001;
      break;
      case 15://f
        displayByte = B01110001;
      break;
      default:
        displayByte = B00000000;
  }
  for(int x = loBit; x<=hiBit; ++x)
  {
    digitalWrite(x,displayByte & 0x01? LOW : HIGH);
    displayByte >>= 1;
  }
  delay(5);
  digitalWrite(digit,LOW);
}

// the setup routine runs once when you press reset:
void setup() 
{                
  // initialize the digital pin as an output.
  for(led=ledRangeLo; led<= ledRangeHi; ++led)
  {
    pinMode(led, OUTPUT);
    digitalWrite(led,LOW);
  }
}

// the loop routine runs over and over again forever:
void loop() 
{
  while(1)
  {
    bitDisplay(outputInt & 0x0f, digit1);
    bitDisplay((outputInt & 0x0f0) >> 4, digit2);
    if((millis() - last_count) > 250)
    {
      ++outputInt;
      if(outputInt > 0xff)
      {
       outputInt = 0x00; 
      }
      last_count = millis();
    }
  }
}
