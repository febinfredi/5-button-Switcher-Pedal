#include <espnow.h>
#include <ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//LiquidCrystal_I2C object
LiquidCrystal_I2C lcd(0x27, 20, 4); //(add, cols, rows)

//structure to store push button data
typedef struct pushButtonPresses {
  bool pb0;
  bool pb1;
  bool pb2;
  bool pb3;
  bool pb4;
} pushButtonPresses;

//'pbData' object of pushButtonPresses struct type
pushButtonPresses pbData;

//callback when data is received
void cbRecv(uint8_t * mac, uint8_t *recvData, uint8_t len) {
  memcpy(&pbData, recvData, sizeof(pbData));
  digitalWrite(LED_BUILTIN, LOW);  //turn ON
  Serial.print("Bytes Recieved: ");
  Serial.println(len);
  printLcdMsg(pbData);
  digitalWrite(LED_BUILTIN, HIGH);  //turn OFF
  //lcd.clear();
}


//function to print message based on the button press
void printLcdMsg(pushButtonPresses pb_data){
  if (pb_data.pb0==1){  //if pb1 pressed
    lcd.clear();
    lcd.setCursor(2, 1);
    lcd.print("Start coming in");
  }

  else if (pb_data.pb1==1){  //if pb2 pressed
    lcd.clear();
    lcd.setCursor(7, 1);
    lcd.print("Groove");
  }

  else if (pb_data.pb2==1){  //if pb3 pressed
    lcd.clear();
    lcd.setCursor(5, 1);
    lcd.print("Tom Groove");
  }

  else if (pb_data.pb3==1){  //if pb4 pressed
    lcd.clear();
    lcd.setCursor(7, 1);
    lcd.print("Build");
  }

  else if (pb_data.pb4==1){  //if pb5 pressed
    lcd.clear();
    lcd.setCursor(2, 1);
    lcd.print("Start dying down");
  }
}


void setup() {

  Serial.begin(115200);

  //I2C
  Wire.begin(D2, D1);   //i2c(sda,scl) 
  lcd.begin(20,4);      //begin LiquidCrystal_I2C object (cols, rows)
  lcd.backlight();      //turn on backlight
  lcd.home();           //position cursor at (0,0) coordinate
  
  pinMode(LED_BUILTIN, OUTPUT);     //Initialize the LED_BUILTIN pin as an output
  digitalWrite(LED_BUILTIN, HIGH);  //turn OFF

  //init WiFi in station mode
  WiFi.mode(WIFI_STA);
 
  while (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    lcd.setCursor(0, 0);
    lcd.print("Error Init ESP-NOW");
  }
  Serial.println("Success initializing ESP-NOW");
  lcd.setCursor(0, 0);
  lcd.print("Ini ESP-NOW: Success");

  delay(1000);

  //set ROLE for this device
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  //callback function
  esp_now_register_recv_cb(cbRecv);
  
  lcd.clear();
}


void loop() {
}