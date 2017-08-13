#include <TCS3200.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
#define bPause A0


uint8_t RGBvalue[3];
TCS3200 colSens;

boolean state = false;


void setup()
{
  Serial.begin(115200);
  lcd.begin(16, 2);
  Serial.println("BEGIN");
  colSens.begin();
}

void loop()
{
  int analog = analogRead(bPause);
  if (analog > 500 && analog < 700) {
    delay(200);
    state = !state;
  }
  if (state == false) {
    colSens.loop();
    colSens.getRGB (RGBvalue);
    //colSens.getRGBtoMaxCorrection (RGBvalue);

    int R = RGBvalue[0];
    int G = RGBvalue[1];
    int B = RGBvalue[2];

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


    Serial.print("C:\t");
    Serial.print("\tR:\t"); Serial.print(RGBvalue[0]);
    Serial.print("\tG:\t"); Serial.print(RGBvalue[1]);
    Serial.print("\tB:\t"); Serial.print(RGBvalue[2]);
    Serial.print("\t");
    Serial.println();
  } else {
    lcd.setCursor(0, 0);
    lcd.print("    Pause >>    ");
  }

  delay(100);

}
