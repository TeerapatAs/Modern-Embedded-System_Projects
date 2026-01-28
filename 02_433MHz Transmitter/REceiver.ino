/*For Arduino UNO, Acting as Receiver*/

/*Include by User*/
#include <RH_ASK.h>
#include <LiquidCrystal_I2C.h>

/*User Private Setup*/
RH_ASK receiver(2000,11,12); // SPEED RX TX
LiquidCrystal_I2C lcd(0x27,16,2); //LCD Address

/*User Private var.*/
String rx_str;
String ry_str;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Testing Substring function
  String msg = "Welcome:Starting,Wait A Moment";
  int index_of_comma = msg.indexOf(",");
  String welcome_msg = msg.substring(0,index_of_comma);
  String wait_msg = msg.substring(index_of_comma+1);

  // LCD init and write
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0); //First Line
  lcd.print(welcome_msg);
  lcd.setCursor(0,1); //Second Line
  lcd.print(wait_msg);
  delay(3000);
  lcd.clear();

  // Receiver
  receiver.init();

  // Test
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  /*Verify the recieved signal*/
  int val = analogRead(A0);
  Serial.println(val);


  /*Buffer Allocation for storing received message*/
  char buffer[12];   // <- 7 digits: RX 3 digits 0-100 + "," + RY 3 digits 0-100
  uint8_t bytes_of_buffer = sizeof(buffer);

  if (receiver.recv((uint8_t *)buffer,&bytes_of_buffer)){ //Don't forget to cast buffer as uint8_t, C++ is strict at type. nOT LIKE IN c
    // IF receive message then...
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    String temp_str_received = String(buffer);
    int index_of_comma = temp_str_received.indexOf(",");
    rx_str = temp_str_received.substring(0,index_of_comma);
    ry_str = temp_str_received.substring(index_of_comma + 1);
     // Clear this stored data after used, Next time I should just make this var global var. ;)
    temp_str_received = "";

  }

  // LCD
  lcd.setCursor(0,0); //First Line
  lcd.print("Rx: ");
  lcd.print(rx_str.toInt());
  lcd.setCursor(0,1); //Sec Line
  lcd.print("Ry: ");
  lcd.print(ry_str.toInt());
  delay(2000);
  lcd.clear();

}
