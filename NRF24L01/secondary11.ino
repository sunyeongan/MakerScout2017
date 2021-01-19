#include <SPI.h>
#include <nRF24L01.h> 
#include <RF24.h> 

#define CE_PIN 7
#define CSN_PIN 8
RF24 radio(CE_PIN, CSN_PIN);

const uint64_t pipe = 0x7878787878LL;

int transmitterId;

int push = 3;

void setup() 
{
  radio.begin();
  radio.openWritingPipe(pipe);
  
  transmitterId = 1;
  
  pinMode(push, INPUT);
}

void loop()
{
  if(digitalRead(push)==HIGH)
  {
    radio.write(&transmitterId, 2);
  }
}
