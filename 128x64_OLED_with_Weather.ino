// This is based on DTH22 Module sensor, Weather application display on 0.96 OLED 128x64 along with Arduino NANO on 19 March 2022 by Syed Abid Ali 
// 0.96" OLED PIN Config to Arduino Nano Shield
// GND Pin  ===> GND
// VDD Pin  ===> 5V
// SCK Pin  ===> SCL
// SDA Pin  ===> SDA

// DHT 22 PIN Config to Arduino Nano Shield
// + Pin  ===> 5V
// OUT Pin  ===> D10
// - Pin  ===> GND


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/Tiny3x3a2pt7b.h>
#include <DHT.h>;

#define OLED_RESET 4
Adafruit_SSD1306 Display(OLED_RESET);

//Constants
#define DHTPIN 10     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

//Variables
//int chk;
int h;  //Stores humidity value
int t; //Stores temperature value

void setup() {
  dht.begin();
  Display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x64)
  //Display.setFont(&Tiny3x3a2pt7b);
  Display.clearDisplay();
}

void loop() {

  h = dht.readHumidity();
  t = dht.readTemperature();
  
  Display.setTextSize(2);
  Display.setTextColor(WHITE);
  Display.setCursor(0, 1);
  Display.print(F("TMP: " ));
  Display.print(t);
  Display.println(F(" C"));

  Display.setCursor(0, 17);
  Display.print(F("HMD: " ));
  Display.print(h);
  Display.print(F(" %"));
  delay(1000); 
  
  Display.display();

}
