/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>
#include <DHT.h>
#include <displayMenu.h>

#define DHTPIN 6     // what digital pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// set pin numbers:
const int button_UP = 26, button_DW = 27, button_ENT = 28;
int display_from = 0;
int selected_menu = 0;

int buttonStateUP = LOW, lastButtonStateUP = LOW;

int buttonStateDW = LOW, lastButtonStateDW = LOW;
int buttonStateENT = LOW, lastButtonStateENT = LOW;


float h,t;

int target_temp = 0, target_humi = 0; 

int current_menu = 1, next_menu, prev_menu;
  
void setup() {


  // set up the LCD's number of columns and rows:
  lcd.clear();
  lcd.begin(16, 2);

  Serial.begin(9600);
  lcd.print("DHTxx test!");

  dht.begin();
}

void loop() {


  /************
  Read buttons
  ************/
  buttonStateUP = digitalRead(button_UP);
  buttonStateDW = digitalRead(button_DW);
  buttonStateENT = digitalRead(button_ENT);


///////////////////////
  // compare the buttonState to its previous state
  if (buttonStateUP != lastButtonStateUP) {

    if (buttonStateUP == HIGH) {

    } else {

    }
  if (buttonStateDW != lastButtonStateDW) {

    if (buttonStateDW == HIGH) {

    } else {

    }
  if (buttonStateENT != lastButtonStateENT) {

    if (buttonStateENT == HIGH) {

    } else {

    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonStateUP = buttonStateUP;
  lastButtonStateDW = buttonStateDW;
  lastButtonStateENT = buttonStateENT;


//////////////////

  switch (current_menu) {

    case MAINMENU :
      display_menu(MANUAL, display_from);

    case CONTROL :
      display_menu(CONTROL, display_from);


    case MANUAL :
      display_menu(MANUAL, display_from);

    case SETVALUES :
      display_menu(SETVALUES, display_from);


    case TEMPERATURE :
      display_menu(TEMPERATURE, display_from);

    case HUMIDITY :
      display_menu(HUMIDITY, display_from);

    case SET :  

      if (prev_menu = HUMIDITY ){
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("Humi: ");
        lcd.print(h);
        lcd.print(" %\t"); 
        lcd.setCursor(0, 1);
        lcd.print("Set to: ");
        lcd.print(target_humi);
        lcd.print(" %\t");        
      }
      if (prev_menu = TEMPERATURE ){
        lcd.setCursor(0, 0);
        lcd.print("Temp: ");
        lcd.print(t);
        lcd.print(" *C ");
        lcd.setCursor(0, 1);
        lcd.print("Set to: ");
        lcd.print(target_temp);
        lcd.print(" *C ");  
      }

    case BACK :
      if (prev_menu == TEMPERATURE || prev_menu == HUMIDITY){
        next_menu = SETVALUES
      }else{
        next_menu = prev_menu;
      }

    case STANDBY :


  }


      if (buttonStateENT == HIGH){
        if (selected_menu == 0)
          next_menu = SETVALUES;
        if (selected_menu == 1)
          next_menu = CONTROL;
      }

      if ((buttonStateUP == HIGH && buttonStateDW == LOW) && selected_menu < 2) {
        selected_menu += 1;
      }
      if ((buttonStateUP == LOW && buttonStateDW == HIGH) && selected_menu > 0) {
        selected_menu -= 1;
      }

      if (prev_menu == TEMPERATURE || prev_menu == HUMIDITY){
        next_menu = SETVALUES
      }else{
        next_menu = prev_menu;
      }
      






















  delay(2500);
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    //Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print("Humi: ");
  lcd.print(h);
  lcd.print(" %\t");
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" *C ");
}




