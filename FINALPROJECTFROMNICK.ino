
// include the library code:
#include <LiquidCrystal.h>
#include <math.h>

const int buttonPin = 25; // start button pin
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // LCD pins
const int buzzer = 6; // buzzer pin
const int buttonGreen = 7; // green button pin
const int ledGreen = 30; // green LED pin
const int buttonWhite = 10; // white button pin
const int ledWhite = 26; // white LED pin
const int buttonRed = 9; // red button pin
const int ledRed = 32; // red LED pin
const int buttonBlue = 8; // blue button pin
const int ledBlue = 28; // blue LED pin

long lightNum; // integer associated with each light color


int buttonState = 0; // makes initial buttonstate 0
int State = 0; // makes initial state off, if state 1, game is running
int buttonNew; // value to make the toggle start/stop button
int buttonOld = 1; // value to make the toggle start/stop button


LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // setup pins for LCD


void setup() {
  pinMode(buttonPin, INPUT); // Creates inputs and outputs for the various LED/Buttons
  pinMode(ledPin, OUTPUT);
  pinMode(buttonGreen, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(buttonWhite, INPUT);
  pinMode(ledWhite, OUTPUT);
  pinMode(buttonRed, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(buttonBlue, INPUT);
  pinMode(ledBlue, OUTPUT);

  Serial.begin(9600); // Starts the serial communication
  randomSeed(analogRead(0)); // reads static voltage of the air to determine a random seed value of the random number generator

}


void loop() {

  buttonState = digitalRead(buttonPin);

  int greenStatus = digitalRead(buttonGreen); // makes greenstatus equivalent to green button
  int whiteStatus = digitalRead(buttonWhite); // makes white status equivalent to white button
  int redStatus = digitalRead(buttonRed); // makes redstatus equivalent to red button
  int blueStatus = digitalRead(buttonBlue); // makes bluestatus equivalent to blue button

  Serial.print(greenStatus); // serial prints the button values
  Serial.println();
  Serial.print(whiteStatus);
  Serial.println();
  Serial.print(redStatus);
  Serial.println();
  Serial.print(blueStatus);
  Serial.println();

  int timer = 9000;  // creates a timer value of 9000
  int level = 1; // starts the player on "level 1"
  lcd.clear(); // clears the led of anything that could be on it
  buttonNew = digitalRead(buttonPin); // sets the new button as value of start button
  if (buttonOld == 0 && buttonNew == 1) // turns on the game if it was off before
  {
    if (State == 0)
    {
      State = 1; // if the start button has been pressed, the game will turn on

      while (State == 1)


      { for (timer > 0; (timer = timer - level);) // loop, if the timer is above 0, the timer will subtract by the integer amount of what level the player is on
        { lcd.begin(16, 2); // LCD begin writing on top line
          lcd.print("Level: " && level); // writes what level the player is on
          lightNum = random(1, 5); // creates a random integer that corresponds to which light will turn on
          Serial.print(lightNum); // serial monitor will print which value the random number generator creates
          {
            tone(buzzer, 500, 100); // makes a tone 
          }
          for (lightNum == 1; (timer = timer - level);) // if the random integer is 1, this loop will happen. causes timer to decrease by whichever level you are on
          //for example level 1; timer - 1, level 2; timer - 2, etc.
          {


            digitalWrite(ledGreen, HIGH); // determines green light will turn on
            digitalWrite(ledWhite, LOW); // all other lights will turn off
            digitalWrite(ledRed, LOW);
            digitalWrite(ledBlue, LOW);
            lcd.setCursor(0, 1); // sets cursor to bottom line
            lcd.print(timer); // prints the value of timer

            if ((timer == 1000) || (timer == 2000) || (timer == 3000) || (timer == 4000) // createas a tone at each interval of 1000 from the buzzer
                || (timer == 5000) || (timer == 6000) || (timer == 7000) || (timer == 8000) || (timer == 8998))
            {
              tone(buzzer, 500, 100); // buzzer tone is 500hz and lasts for 100 milliseconds
            }

            int greenStatus = digitalRead(buttonGreen); // reads each of the LED pins
            int whiteStatus = digitalRead(buttonWhite);
            int redStatus = digitalRead(buttonRed);
            int blueStatus = digitalRead(buttonBlue);

            Serial.print(greenStatus);
            Serial.println();

            if (greenStatus >= 1) // if played presses the button associated with the green light, this will become true
            {
              level++; // the level value will increase
              timer = 9000; // the timer will be reset
              Serial.print(level); // the serial monitor will print which level the player is now on
              break; // break the loop to go back and create a new random light number
            }
            if ((whiteStatus == 1) || (redStatus == 1) || (blueStatus == 1)) // if the player presses the button associated with any of the other lights,
              // these values will go high
            {
              lcd.setCursor(0, 1); // set LCD curson to bottom line
              lcd.print("You Lose"); // prints you lose on LCD

              tone(buzzer, 100, 1000); // Creates a buzz for 100 hz for 1000 milliseconds
              digitalWrite(ledRed, LOW); 
              delay(1000);
              noTone(buzzer); // turns off the buzzer
              delay(5000);
              State = 0; // resets the game to be turned off
              return 0; // returns to the top of the program

            }
            if (timer <= 0) // if the timer reaches 0
            {
              {
                timer = 0; 
                level = 0; // means player loses


                lcd.setCursor(0, 1); // sets lcd cursor bottom line
                lcd.print("You Lose"); // prints you lose on LCD

                tone(buzzer, 100, 1000); // Creates a buzz for 100 hz for 1000 milliseconds
                digitalWrite(ledRed, LOW);
                delay(1000);
                noTone(buzzer);
                delay(5000);
                State = 0; // puts player out of the game
                return 0;
              }
              
       // THIS IS THE END OF THE FIRST SECTION, ALL SECTIONS AFTER THIS ARE REPEATS WITH DIFFERENT LEDS AND BUTTONS
              
              
              
              
            }
            for (lightNum == 2; (timer = timer - level);)
            {
              digitalWrite(ledWhite, HIGH);
              digitalWrite(ledGreen, LOW);
              digitalWrite(ledRed, LOW);
              digitalWrite(ledBlue, LOW);
              lcd.setCursor(0, 1);
              lcd.print(timer);
              if ((timer == 1000) || (timer == 2000) || (timer == 3000) || (timer == 4000) || (timer == 5000) || (timer == 6000) || (timer == 7000) || (timer == 8000) || (timer == 8998))
              {
                tone(buzzer, 500, 100);
              }
              int greenStatus = digitalRead(buttonGreen);
              int whiteStatus = digitalRead(buttonWhite);
              int redStatus = digitalRead(buttonRed);
              int blueStatus = digitalRead(buttonBlue);

              Serial.print(whiteStatus);
              Serial.println();

              if (whiteStatus >= 1)
              {
                level++;  Serial.print(level);
                timer = 9000;
                return level;
              }
              if ((greenStatus == 1) || (redStatus == 1) || (blueStatus == 1))
              {
                lcd.setCursor(0, 1);
                lcd.print("You Lose");

                tone(buzzer, 100, 1000);
                digitalWrite(ledRed, LOW);
                delay(1000);
                noTone(buzzer);
                delay(5000);
                State = 0;
                return 0;
              }
              if (timer <= 0)
              {
                {
                  timer = 0;
                  level = 0;

                  lcd.setCursor(0, 1);
                  lcd.print("You Lose");
                  digitalWrite(ledRed, LOW);
                  tone(buzzer, 100, 1000);
                  delay(1000);
                  noTone(buzzer);
                  delay(5000);
                  State = 0;
                  return 0;
                }
              }
              for (lightNum == 3; (timer = timer - level);)
              {

                digitalWrite(ledRed, HIGH);
                digitalWrite(ledWhite, LOW);
                digitalWrite(ledGreen, LOW);
                digitalWrite(ledBlue, LOW);
                lcd.setCursor(0, 1);
                lcd.print(timer);
                if ((timer == 1000) || (timer == 2000) || (timer == 3000) || (timer == 4000) || (timer == 5000) || (timer == 6000) || (timer == 7000) || (timer == 8000) || (timer == 8998))
                {
                  tone(buzzer, 500, 100);
                }
                int greenStatus = digitalRead(buttonGreen);
                int whiteStatus = digitalRead(buttonWhite);
                int redStatus = digitalRead(buttonRed);
                int blueStatus = digitalRead(buttonBlue);

                Serial.print(redStatus);
                Serial.println();
                if (redStatus >= 1)
                {
                  level++;  Serial.print(level);
                  timer = 9000;
                  break;
                }
                if ((greenStatus == 1) || (whiteStatus == 1) || (blueStatus == 1))
                {
                  lcd.setCursor(0, 1);
                  lcd.print("You Lose");

                  tone(buzzer, 100, 1000);
                  digitalWrite(ledRed, LOW);
                  delay(1000);
                  noTone(buzzer);
                  delay(5000);
                  State = 0;
                  return 0;
                }
                if (timer <= 0)
                {
                  {
                    timer = 0;

                    lcd.setCursor(0, 1);
                    lcd.print("You Lose");
                    digitalWrite(ledRed, LOW);
                    tone(buzzer, 100, 1000);
                    delay(1000);
                    noTone(buzzer);
                    delay(5000);
                    State = 0;
                    return 0;
                  }
                }
                for (lightNum == 4; (timer = timer - level);)
                {
                  digitalWrite(ledBlue, HIGH);
                  digitalWrite(ledWhite, LOW);
                  digitalWrite(ledGreen, LOW);
                  digitalWrite(ledRed, LOW);
                  lcd.setCursor(0, 1);
                  lcd.print(timer);

                  if ((timer == 1000) || (timer == 2000) || (timer == 3000) || (timer == 4000) || (timer == 5000) || (timer == 6000) || (timer == 7000) || (timer == 8000) || (timer == 8998))
                  {
                    tone(buzzer, 500, 100);
                  }

                  int greenStatus = digitalRead(buttonGreen);
                  int whiteStatus = digitalRead(buttonWhite);
                  int redStatus = digitalRead(buttonRed);
                  int blueStatus = digitalRead(buttonBlue);

                  Serial.print(bluwStatus);
                  Serial.println();
                  if (blueStatus >= 1)
                  {
                    level++; Serial.print(level);
                    timer = 9000;
                    break;
                  }

                  if ((greenStatus == 1) || (whiteStatus == 1) || (redStatus == 1))
                  {
                    lcd.setCursor(0, 1);
                    lcd.print("You Lose");

                    tone(buzzer, 100, 1000);
                    digitalWrite(ledRed, LOW);
                    delay(1000);
                    noTone(buzzer);
                    delay(5000);
                    State = 0;
                    return 0;
                  }

                  if (timer <= 0)
                  {
                    {
                      timer = 0;
                      level = 0;

                      lcd.setCursor(0, 1);
                      lcd.print("You Lose");
                      digitalWrite(ledRed, LOW);
                      tone(buzzer, 100, 1000);
                      delay(1000);
                      noTone(buzzer);
                      delay(5000);
                      State = 0;
                      return 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  buttonOld = buttonNew; // used to check if the start button has been pressed again
  delay(100); // delay to get rid of bounce
}
