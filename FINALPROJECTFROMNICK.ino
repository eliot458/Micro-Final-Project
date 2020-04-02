
// include the library code:
#include <LiquidCrystal.h>
#include <math.h>
const int ledPin = 13;
const int buttonPin = 25;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int buzzer = 6;
const int buttonGreen = 7;
const int ledGreen = 30;
const int buttonWhite = 10;
const int ledWhite = 26;
const int buttonRed = 9;
const int ledRed = 32;
const int buttonBlue = 8;
const int ledBlue = 28;

long lightNum;

int timer = 9;
int buttonState = 0;
int State = 0;
int buttonNew;
int buttonOld = 1;


LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
  pinMode(buttonGreen, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(buttonWhite, INPUT);
  pinMode(ledWhite, OUTPUT);
  pinMode(buttonRed, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(buttonBlue, INPUT);
  pinMode(ledBlue, OUTPUT);

  randomSeed(analogRead(0));

}


void loop() {

  buttonState = digitalRead(buttonPin);

  int greenStatus = digitalRead(buttonGreen);
  int whiteStatus = digitalRead(buttonWhite);
  int redStatus = digitalRead(buttonRed);
  int blueStatus = digitalRead(buttonBlue);

  Serial.print(greenStatus);
  Serial.println();
  Serial.print(whiteStatus);
  Serial.println();
  Serial.print(redStatus);
  Serial.println();
  Serial.print(blueStatus);
  Serial.println();

  timer = 9000;
  int level = 1;
  lcd.setCursor(0, 1);
  lcd.clear();
  buttonNew = digitalRead(buttonPin);
  if (buttonOld == 0 && buttonNew == 1)
  {
    if (State == 0)
    {
      State = 1;

      while (State == 1)


      { for (timer > 0; (timer = timer - level);)
        { lcd.begin(16, 2);
          lcd.print("Level: " && level);
          lightNum = random(1, 5);
          Serial.print(lightNum);
          {
            tone(buzzer, 500, 100);
          }
          for (lightNum == 1; (timer = timer - level);)
          {


            digitalWrite(ledGreen, HIGH);
            digitalWrite(ledWhite, LOW);
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

            Serial.print(greenStatus);
            Serial.println();

            if (greenStatus >= 1)
            {
              level++;
              timer = 9000;
              Serial.print(level);
              break;
            }
            if ((whiteStatus == 1) || (redStatus == 1) || (blueStatus == 1))
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

                tone(buzzer, 100, 1000);
                digitalWrite(ledRed, LOW);
                delay(1000);
                noTone(buzzer);
                delay(5000);
                State = 0;
                return 0;
              }
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
  buttonOld = buttonNew;
  delay(100);
}
