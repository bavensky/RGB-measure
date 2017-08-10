// GY-31 TCS3200 color recognition sensor


#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

#define bPause A0

#define S0 13
#define S1 12
#define S2 3
#define S3 2
#define sensorOut 11

int frequency = 0;
int color = 0;
int R, G, B;
boolean state = false;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

}

void loop() {

  //  Serial.print(analogRead(bPause));
  //  Serial.println(state);

  int analog = analogRead(bPause);
  if (analog > 500 && analog < 700) {
    delay(200);
    state = !state;
  }



  if (state == false) {
    readColor();
    lcd.setCursor(0, 0);
    lcd.print("RGB color detect");
    lcd.setCursor(0, 1);
    lcd.print(" R");
    if (R <= 99) lcd.print("0");
    else if (R <= 9) lcd.print("00");
    lcd.print(R);

    lcd.print(" G");
    if (G <= 99) lcd.print("0");
    else if (G <= 9) lcd.print("00");
    lcd.print(G);

    lcd.print(" B");
    if (B <= 99) lcd.print("0");
    else if (B <= 9) lcd.print("00");
    lcd.print(B);
  } else {
    lcd.setCursor(0, 0);
    lcd.print("    Pause >>    ");
  }

  delay(100);
}


// Custom Function - readColor()
//int readColor() {
void readColor() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);


  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  R = frequency;
  //  R = map(frequency, 20, 55, 0, 255);

  // Printing the value on the serial monitor
  //  Serial.print("R= ");//printing name
  //  Serial.print(frequency);//printing RED color frequency
  //  Serial.print("  ");
  delay(50);


  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  G = frequency;
  //  G = map(frequency, 0, 128, 0, 255);

  // Printing the value on the serial monitor
  //  Serial.print("G= ");//printing name
  //  Serial.print(frequency);//printing RED color frequency
  //  Serial.print("  ");
  delay(50);


  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  B = frequency;
  //  B = map(frequency, 0, 128, 0, 255);

  // Printing the value on the serial monitor
  //  Serial.print("B= ");//printing name
  //  Serial.print(frequency);//printing RED color frequency
  //  Serial.println("  ");
  delay(50);


  //  if (R<45 & R>32 & G<65 & G>55) {
  //    color = 1; // Red
  //  }
  //  if (G<55 & G>43 & B<47 & B>35) {
  //    color = 2; // Orange
  //  }
  //  if (R<53 & R>40 & G<53 & G>40) {
  //    color = 3; // Green
  //  }
  //  if (R<38 & R>24 & G<44 & G>30) {
  //    color = 4; // Yellow
  //  }
  //  if (R<56 & R>46 & G<65 & G>55) {
  //    color = 5; // Brown
  //  }
  //  if (G<58 & G>45 & B<40 & B>26) {
  //    color = 6; // Blue
  //  }
  //  return color;
}
