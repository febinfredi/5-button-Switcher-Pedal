#include <espnow.h>
#include <ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//LiquidCrystal_I2C object
LiquidCrystal_I2C lcd(0x27, 20, 4); //(address, cols, rows)

//lcd graphic character - switch pressed
byte sw_pressed[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

//lcd graphic character (top left) - switch depressed
byte sw_depressed_tl[8] = {
  B11111,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000
};

//lcd graphic character (top right) - switch depressed
byte sw_depressed_tr[8] = {
  B11111,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001
};

//lcd graphic character (bottom left) - switch depressed
byte sw_depressed_bl[8] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B11111
};

//lcd graphic character (bottom right) - switch depressed
byte sw_depressed_br[8] = {
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B11111
};

//lcd graphic for button 1 pressed
void btn1_pressed(){
  lcd.setCursor(1,0);
  lcd.write(byte(0));
  lcd.setCursor(2,0);
  lcd.write(byte(0));
  lcd.setCursor(1,1);
  lcd.write(byte(0));
  lcd.setCursor(2,1);
  lcd.write(byte(0));

  lcd.setCursor(5,0);
  lcd.write(byte(1));
  lcd.setCursor(6,0);
  lcd.write(byte(2));
  lcd.setCursor(5,1);
  lcd.write(byte(3));
  lcd.setCursor(6,1);
  lcd.write(byte(4));

  lcd.setCursor(9,0);
  lcd.write(byte(1));
  lcd.setCursor(10,0);
  lcd.write(byte(2));
  lcd.setCursor(9,1);
  lcd.write(byte(3));
  lcd.setCursor(10,1);
  lcd.write(byte(4));

  lcd.setCursor(13,0);
  lcd.write(byte(1));
  lcd.setCursor(14,0);
  lcd.write(byte(2));
  lcd.setCursor(13,1);
  lcd.write(byte(3));
  lcd.setCursor(14,1);
  lcd.write(byte(4));

  lcd.setCursor(17,0);
  lcd.write(byte(1));
  lcd.setCursor(18,0);
  lcd.write(byte(2));
  lcd.setCursor(17,1);
  lcd.write(byte(3));
  lcd.setCursor(18,1);
  lcd.write(byte(4));
}

//lcd graphic for button 2 pressed
void btn2_pressed(){
  lcd.setCursor(1,0);
  lcd.write(byte(1));
  lcd.setCursor(2,0);
  lcd.write(byte(2));
  lcd.setCursor(1,1);
  lcd.write(byte(3));
  lcd.setCursor(2,1);
  lcd.write(byte(4));

  lcd.setCursor(5,0);
  lcd.write(byte(0));
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.setCursor(5,1);
  lcd.write(byte(0));
  lcd.setCursor(6,1);
  lcd.write(byte(0));

  lcd.setCursor(9,0);
  lcd.write(byte(1));
  lcd.setCursor(10,0);
  lcd.write(byte(2));
  lcd.setCursor(9,1);
  lcd.write(byte(3));
  lcd.setCursor(10,1);
  lcd.write(byte(4));

  lcd.setCursor(13,0);
  lcd.write(byte(1));
  lcd.setCursor(14,0);
  lcd.write(byte(2));
  lcd.setCursor(13,1);
  lcd.write(byte(3));
  lcd.setCursor(14,1);
  lcd.write(byte(4));

  lcd.setCursor(17,0);
  lcd.write(byte(1));
  lcd.setCursor(18,0);
  lcd.write(byte(2));
  lcd.setCursor(17,1);
  lcd.write(byte(3));
  lcd.setCursor(18,1);
  lcd.write(byte(4));
}

//lcd graphic for button 3 pressed
void btn3_pressed(){
  lcd.setCursor(1,0);
  lcd.write(byte(1));
  lcd.setCursor(2,0);
  lcd.write(byte(2));
  lcd.setCursor(1,1);
  lcd.write(byte(3));
  lcd.setCursor(2,1);
  lcd.write(byte(4));

  lcd.setCursor(5,0);
  lcd.write(byte(1));
  lcd.setCursor(6,0);
  lcd.write(byte(2));
  lcd.setCursor(5,1);
  lcd.write(byte(3));
  lcd.setCursor(6,1);
  lcd.write(byte(4));

  lcd.setCursor(9,0);
  lcd.write(byte(0));
  lcd.setCursor(10,0);
  lcd.write(byte(0));
  lcd.setCursor(9,1);
  lcd.write(byte(0));
  lcd.setCursor(10,1);
  lcd.write(byte(0));

  lcd.setCursor(13,0);
  lcd.write(byte(1));
  lcd.setCursor(14,0);
  lcd.write(byte(2));
  lcd.setCursor(13,1);
  lcd.write(byte(3));
  lcd.setCursor(14,1);
  lcd.write(byte(4));

  lcd.setCursor(17,0);
  lcd.write(byte(1));
  lcd.setCursor(18,0);
  lcd.write(byte(2));
  lcd.setCursor(17,1);
  lcd.write(byte(3));
  lcd.setCursor(18,1);
  lcd.write(byte(4));
}

//lcd graphic for button 4 pressed
void btn4_pressed(){
  lcd.setCursor(1,0);
  lcd.write(byte(1));
  lcd.setCursor(2,0);
  lcd.write(byte(2));
  lcd.setCursor(1,1);
  lcd.write(byte(3));
  lcd.setCursor(2,1);
  lcd.write(byte(4));

  lcd.setCursor(5,0);
  lcd.write(byte(1));
  lcd.setCursor(6,0);
  lcd.write(byte(2));
  lcd.setCursor(5,1);
  lcd.write(byte(3));
  lcd.setCursor(6,1);
  lcd.write(byte(4));

  lcd.setCursor(9,0);
  lcd.write(byte(1));
  lcd.setCursor(10,0);
  lcd.write(byte(2));
  lcd.setCursor(9,1);
  lcd.write(byte(3));
  lcd.setCursor(10,1);
  lcd.write(byte(4));

  lcd.setCursor(13,0);
  lcd.write(byte(0));
  lcd.setCursor(14,0);
  lcd.write(byte(0));
  lcd.setCursor(13,1);
  lcd.write(byte(0));
  lcd.setCursor(14,1);
  lcd.write(byte(0));

  lcd.setCursor(17,0);
  lcd.write(byte(1));
  lcd.setCursor(18,0);
  lcd.write(byte(2));
  lcd.setCursor(17,1);
  lcd.write(byte(3));
  lcd.setCursor(18,1);
  lcd.write(byte(4));
}

//lcd graphic for button 5 pressed
void btn5_pressed(){
  lcd.setCursor(1,0);
  lcd.write(byte(1));
  lcd.setCursor(2,0);
  lcd.write(byte(2));
  lcd.setCursor(1,1);
  lcd.write(byte(3));
  lcd.setCursor(2,1);
  lcd.write(byte(4));

  lcd.setCursor(5,0);
  lcd.write(byte(1));
  lcd.setCursor(6,0);
  lcd.write(byte(2));
  lcd.setCursor(5,1);
  lcd.write(byte(3));
  lcd.setCursor(6,1);
  lcd.write(byte(4));

  lcd.setCursor(9,0);
  lcd.write(byte(1));
  lcd.setCursor(10,0);
  lcd.write(byte(2));
  lcd.setCursor(9,1);
  lcd.write(byte(3));
  lcd.setCursor(10,1);
  lcd.write(byte(4));

  lcd.setCursor(13,0);
  lcd.write(byte(1));
  lcd.setCursor(14,0);
  lcd.write(byte(2));
  lcd.setCursor(13,1);
  lcd.write(byte(3));
  lcd.setCursor(14,1);
  lcd.write(byte(4));

  lcd.setCursor(17,0);
  lcd.write(byte(0));
  lcd.setCursor(18,0);
  lcd.write(byte(0));
  lcd.setCursor(17,1);
  lcd.write(byte(0));
  lcd.setCursor(18,1);
  lcd.write(byte(0));
}

//lcd graphic for no button pressed
void no_btn_pressed(){
  lcd.setCursor(1,0);
  lcd.write(byte(1));
  lcd.setCursor(2,0);
  lcd.write(byte(2));
  lcd.setCursor(1,1);
  lcd.write(byte(3));
  lcd.setCursor(2,1);
  lcd.write(byte(4));

  lcd.setCursor(5,0);
  lcd.write(byte(1));
  lcd.setCursor(6,0);
  lcd.write(byte(2));
  lcd.setCursor(5,1);
  lcd.write(byte(3));
  lcd.setCursor(6,1);
  lcd.write(byte(4));

  lcd.setCursor(9,0);
  lcd.write(byte(1));
  lcd.setCursor(10,0);
  lcd.write(byte(2));
  lcd.setCursor(9,1);
  lcd.write(byte(3));
  lcd.setCursor(10,1);
  lcd.write(byte(4));

  lcd.setCursor(13,0);
  lcd.write(byte(1));
  lcd.setCursor(14,0);
  lcd.write(byte(2));
  lcd.setCursor(13,1);
  lcd.write(byte(3));
  lcd.setCursor(14,1);
  lcd.write(byte(4));

  lcd.setCursor(17,0);
  lcd.write(byte(1));
  lcd.setCursor(18,0);
  lcd.write(byte(2));
  lcd.setCursor(17,1);
  lcd.write(byte(3));
  lcd.setCursor(18,1);
  lcd.write(byte(4));
}

//receivers addresses
uint8_t rxAddress0[] = {0x48, 0x3F, 0xDA, 0x47, 0x08, 0x61};
uint8_t rxAddress1[] = {0x84, 0xF3, 0xEB, 0x91, 0x9E, 0x99};

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

//callback when data is sent
void cbSent(uint8_t *mac_addr, uint8_t status) {
  char macStr[18];
  Serial.print("Packet to ");
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  Serial.print(macStr);
  Serial.print(" send status:\t");

  if (status != 0) {
    Serial.println("Delivery Fail");
  }
  else{
    Serial.println("Delivery Success");
  }
}


//function to clear row
void clearLCDRow(int row)
{               
        lcd.setCursor(0, row);
        for(int col = 0; col < 20; col++)
        {
                lcd.print(" ");
        }
}


//function to store pushbutton data and to print correct lcd graphic
void getPbData(){
  if (digitalRead(D2)==LOW){  //if pb1 pressed
    pbData.pb0 = true;
    pbData.pb1 = false;
    pbData.pb2 = false;
    pbData.pb3 = false;
    pbData.pb4 = false;
    btn1_pressed();
    clearLCDRow(3);
    lcd.setCursor(2, 3);
    lcd.print("Start coming in");

  }

  else if (digitalRead(D1)==LOW){  //if pb2 pressed
    pbData.pb0 = false;
    pbData.pb1 = true;
    pbData.pb2 = false;
    pbData.pb3 = false;
    pbData.pb4 = false;
    btn2_pressed();
    clearLCDRow(3);
    lcd.setCursor(7, 3);
    lcd.print("Groove");
  }

  else if (digitalRead(D5)==LOW){  //if pb3 pressed
    pbData.pb0 = false;
    pbData.pb1 = false;
    pbData.pb2 = true;
    pbData.pb3 = false;
    pbData.pb4 = false;
    btn3_pressed();
    clearLCDRow(3);
    lcd.setCursor(5, 3);
    lcd.print("Tom Groove");
  }

  else if (digitalRead(D6)==LOW){  //if pb4 pressed
    pbData.pb0 = false;
    pbData.pb1 = false;
    pbData.pb2 = false;
    pbData.pb3 = true;
    pbData.pb4 = false;
    btn4_pressed();
    clearLCDRow(3);
    lcd.setCursor(7, 3);
    lcd.print("Build");
  }

  else if (digitalRead(D7)==LOW){  //if pb5 pressed
    pbData.pb0 = false;
    pbData.pb1 = false;
    pbData.pb2 = false;
    pbData.pb3 = false;
    pbData.pb4 = true;
    btn5_pressed();
    clearLCDRow(3);
    lcd.setCursor(2, 3);
    lcd.print("Start dying down");
  }
}


void setup() {

  Serial.begin(115200);

  //I2C
  Wire.begin(D3, D4);   //i2c(sda,scl) 

  //LCD
  lcd.begin(20,4);      //begin LiquidCrystal_I2C object (cols, rows)
  lcd.backlight();      //turn on backlight
  lcd.home();           //position cursor at (0,0) coordinate
  
  //store custom characters
  lcd.createChar(0, sw_pressed);
  lcd.createChar(1, sw_depressed_tl);
  lcd.createChar(2, sw_depressed_tr);
  lcd.createChar(3, sw_depressed_bl);
  lcd.createChar(4, sw_depressed_br);
  
  //setting input pins
  pinMode(D2, INPUT_PULLUP); //pb0
  pinMode(D1, INPUT_PULLUP); //pb1
  pinMode(D5, INPUT_PULLUP); //pb2
  pinMode(D6, INPUT_PULLUP); //pb3
  pinMode(D7, INPUT_PULLUP); //pb4

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
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  //callback function
  esp_now_register_send_cb(cbSent);
  
  //add receiver device 1
  while (esp_now_add_peer(rxAddress0, ESP_NOW_ROLE_SLAVE, 1, NULL, 0) != 0) {
    Serial.println("Failed adding PEER 1");
    lcd.setCursor(0, 1);
    lcd.print("Add PEER 1: Fail");
  }
  Serial.println("Success adding PEER 1");
  lcd.setCursor(0, 1);
  lcd.print("Add PEER 1: Success");

  delay(1000);

  //add receiver device 2
  while (esp_now_add_peer(rxAddress1, ESP_NOW_ROLE_SLAVE, 1, NULL, 0) != 0) {
    Serial.println("Failed adding PEER 2");
    lcd.setCursor(0, 2);
    lcd.print("Add PEER 2: Fail");
  }
  Serial.println("Success add PEER 2");
  lcd.setCursor(0, 2);
  lcd.print("Add PEER 2: Success");

  delay(1000);
  
  lcd.clear();
  no_btn_pressed();  
}


void loop() {

  //if any button pressed 
  if ((digitalRead(D2)==LOW) || (digitalRead(D1)==LOW) || (digitalRead(D2)==LOW) || (digitalRead(D5)==LOW) || (digitalRead(D6)==LOW) || (digitalRead(D7)==LOW)) {
    getPbData();                                                      //get the pb data and the correct graphics   
    esp_now_send(rxAddress0, (uint8_t *) &pbData, sizeof(pbData));    //send to rx device 1
    esp_now_send(rxAddress1, (uint8_t *) &pbData, sizeof(pbData));    //send to rx device 1
  }
 
  Serial.println(pbData.pb0);
  Serial.println(pbData.pb1);
  Serial.println(pbData.pb2);
  Serial.println(pbData.pb3);
  Serial.println(pbData.pb4);
  Serial.println();
  Serial.println();
}