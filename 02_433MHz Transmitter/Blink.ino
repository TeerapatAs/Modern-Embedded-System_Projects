/*FOR STM32 BLUE_PILL, Acting as Transmitter*/
#include <RH_ASK.h>

RH_ASK rf_driver(2000,PA10,PA9); // build the object name "rf_driver" //inputs: speed, RxPin, TxPin

/*User Messages*/ /*Static Memory*/
int readValue_x;
int readValue_y;
String transmit;
/*End User Messages*/

// the setup function runs once when you press reset or power the board
void setup() {
  rf_driver.init();
  pinMode(LED_BUILTIN, OUTPUT);// initialize digital pin LED_BUILTIN as an output.
  // ADC
  pinMode(PA0,INPUT);
  pinMode(PA1,INPUT);
}

// the loop function runs over and over again forever
void loop() {
  /*Read Data*/
  readValue_x = int((analogRead(PA0)-2047) * 100 / 2047);
  readValue_y = int((analogRead(PA1)-2047) * 100 / 2047);
  transmit = (String(readValue_x) + "," + String(readValue_y)); // ensure msg's array end with null /0 

  /*Send Data: Built in function in Radiohead Lib*/
  // Need to cast pointer first, RadioHead doesn't understand type String
  const char* msg = transmit.c_str();
  rf_driver.send((uint8_t *) msg, strlen(msg)); //inputs: pointer (cast pointer /w uint8_t) , and  bytes length
  rf_driver.waitPacketSent();  
  delay(1000);

}

