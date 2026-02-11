/*Master UNO SPI*/
/*Headers by User*/
#include <SPI.h>

/*Definitions by User*/
#define SS1 10

/*Variables by User*/
char letters[3] = {'A','B','C'};
int counter = 0;
uint8_t MasterReceive;
char MasterSend;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Start Serial Port at 9600 baud rate Serial baud rate is not related to SPI clock speed.
  pinMode(SS1,OUTPUT);
  SPI.begin();                            //Begins the SPI commnuication
  SPI.setClockDivider(SPI_CLOCK_DIV128);    //Sets clock for SPI communication at 8 (16/8=2Mhz)
  digitalWrite(SS1,HIGH);                  // Setting SS1 as HIGH (So master doesnt connnect with slave)

}

void loop() {
  // Select a letter to be sent.
  if (counter < 3){
    MasterSend = letters[counter++];
  }
  else{
    counter = 0;
    MasterSend = letters[counter++];
  }

  digitalWrite(SS1,LOW); // Pull SS1 low for communication.

  MasterReceive = SPI.transfer(MasterSend); // Transfer MasterSend to slave, and store  SPDR Data from slave into MasterReceive.
  delay(50); // Make sure stm32 is ready
  //Serial.print(MasterSend);

  switch(MasterReceive){
    case 0x1:
      Serial.println("We received:A");
      break;
    case 0x2:
      Serial.println("We received:B");
      break;
    case 0x3:
      Serial.println("We received:C");
      break;
    default:
      Serial.print("What: "); Serial.println(MasterReceive);
      break;
  }
  digitalWrite(SS1, HIGH);
  delay(1000);

}
