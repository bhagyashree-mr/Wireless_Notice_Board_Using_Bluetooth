#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27,16,2);//or(0x3F,16,2);

String val ="No Data";
String oldval;
String newval = "No Data";
int i = 0;

void setup()
{
lcd.init();
lcd.backlight();
Serial.begin(9600);
lcd.setCursor(0, 0);
lcd.print("Wireless Notice");
lcd.setCursor(0, 1);
lcd.print(" Board ");
delay(3000);
lcd.clear();
lcd.print("Welcome!");
}

void loop()
{
val = Serial.readString();
val.trim();

if(val != oldval)
{
newval = val;
}
lcd.clear();
lcd.setCursor(i, 0);
lcd.print(newval);
i++;
if(i >= 15)
{
i = 0;
}
val = oldval;
}
