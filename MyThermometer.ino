// Original code by ELEGOO
// Modified code by Camilo Morales

// LiquidCrystal.h allows us to display the temperature on our LCD.
#include <LiquidCrystal.h>

// The resistance from our thermistor is read by pin A0.
int tempPin = 0;

// Initialize the index of our first data point.
int timeCounter = 0;

// Associates pins 7, ..., 12 to inputs on the LCD.
//                RS E  D4 D5  D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup()
{
  // Tells our Arduino that our display has 16 columns and 2 rows.
  lcd.begin(16, 2);

  // For printing in the serial monitor...
  Serial.begin(9600);
}
void loop()
{
  int tempReading = analogRead(tempPin);

  // tempK converts our resistance in ohms into temperature in Kelvins.
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));

  // Approximate temperature in Kelvins...
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );

  float tempC = tempK - 273.15;             // Convert Kelvin to Celcius
  float tempF = (tempC * 9.0) / 5.0 + 32.0; // Convert Celcius to Fahrenheit

  lcd.setCursor(0, 0);

  // Display the temperature in Fahrenheit.
  lcd.print("Temp         F  ");
  lcd.setCursor(6, 0);                      // Sets the cursor position to column 5 in the first row.
  lcd.print(tempF);                         // Display the termperature on the LCD.

  // Printing the termperatures at given times in the serial monitor.
  Serial.println("");
  Serial.print(timeCounter);
  Serial.print(", ");
  Serial.println(tempF);

  // Time intervals between data collection.
  delay(1000*5);

  timeCounter += 2;
}