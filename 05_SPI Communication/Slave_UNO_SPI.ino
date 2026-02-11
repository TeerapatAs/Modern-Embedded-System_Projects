
// Slave Arduino Code:/
//SPI SLAVE (ARDUINO)
//SPI COMMUNICATION BETWEEN TWO ARDUINO 
//CIRCUIT DIGEST
//Pramoth.T
#include<SPI.h>

volatile boolean received;
volatile byte Slavereceived,Slavesend;

void setup()
{
  Serial.begin(9600);
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);                      //Turn on SPI in Slave Mode
  received = false;
  SPI.attachInterrupt();                  //Interuupt ON is set for SPI commnucation
}

ISR (SPI_STC_vect)                        //Inerrrput routine function 
{
  Slavereceived = SPDR;         // Value received from master if store in variable slavereceived
  received = true;
}
void loop()
{ 
  if(received)                            //Logic to SET LED ON OR OFF depending upon the value recerived from master
   {
    received = false;
    Serial.println("UNO get:");Serial.println(Slavereceived);                         //Sends the x value to master via SPDR     
    delay(1000);

  }
}
