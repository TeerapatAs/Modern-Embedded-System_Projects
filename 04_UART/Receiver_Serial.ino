/*For Arduino UNO, Acting as Receiver*/

/*User Private var.*/
char buffer[16];
char received_bytes;
int index = 0;

void setup() {
  // put your setup code here, to run  once:
  Serial.begin(9600);
  
}

void loop() {
while (Serial.available() > 0) {
    // Because Serial is sharing the TX,RX port with USB to com port, we need to check avalibility.
    received_bytes = Serial.read();
  // I'll use index for looping. For loop of UNO's CPU is faster than bit rates, leading to UNO serial port can not read data in time.
    if (received_bytes == '\n') {
        buffer[index] = '\0'; // Terminate the string
        Serial.print("I received: ");
        Serial.println(buffer);
        index = 0; 
    } 

    else{
      buffer[index] = received_bytes;
      index++;
    }
  }
}
