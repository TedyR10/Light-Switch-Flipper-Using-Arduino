#include "Stepper.h"
#include "IRremote.h"
#include <Servo.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

Servo myservo;
/*----- Variables, Pins -----*/
int receiver = 5;         // Signal Pin of IR receiver to Arduino Digital Pin 5
IRrecv irrecv(receiver);  // create instance of 'irrecv'
decode_results results;   // create instance of 'decode_results'

void setup() {
  irrecv.enableIRIn();  // Start the receiver
  myservo.attach(3);    // Attach the servo to pin 6
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("Hello there!");
  delay(1000);
  lcd.clear();
}

void loop() {
  if (irrecv.decode(&results))  // have we received an IR signal?
  {
    switch (results.value)

    {

      case 0xFFA857:        // VOL+ button pressed
        myservo.write(68);
        delay(200);  // Move the servo
        lcd.print("Light ON");
        delay(1000);  // Wait a second and clear the screen
        lcd.clear();
        break;

      case 0xFFE01F:         // VOL- button pressed
        myservo.write(115); // Move the servo
        delay(200);
        lcd.print("Light OFF");
        delay(1000);  // Wait a second and clear the screen
        lcd.clear();
        break;
    }

    irrecv.resume();  // receive the next value
  }


} /* --end main loop -- */
