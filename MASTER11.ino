
#include <SPI.h>
#include <nRF24L01.h> 
#include <RF24.h> 

#define CE_PIN 9
#define CSN_PIN 10
RF24 radio(CE_PIN, CSN_PIN);

const uint64_t pipe = 0x7878787878LL;

int transmitterId;

bool A=false;

int agrtotal =0;

void setup() 
{
  radio.begin(); 
  radio.openReadingPipe(1,pipe);
  radio.startListening(); 
  
  Serial.begin(9600);


}

void loop() 
{ 
  if (radio.available()) 
   {
    radio.read(&transmitterId, 2);
   Serial.println(transmitterId);
   }
    
}
