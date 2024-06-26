#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//#include <LiquidCrystal.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// // Declaration for SSD1306 display connected using I2C
// #define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
 #define SCREEN_ADDRESS 0x3C
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Declaration for SSD1306 display connected using software SPI:
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);


void setup()
{
  Serial.begin(9600);
  
  // initialize the OLED object
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Uncomment this if you are using SPI
  if(!display.begin(SSD1306_SWITCHCAPVCC)) {
   Serial.println(F("SSD1306 allocation failed"));
   for(;;); // Don't proceed, loop forever
  }

  // Clear the buffer.
  display.clearDisplay();


  // // Display Text
  display.setTextSize(1);
  display.setTextColor(WHITE);

  //display.drawLine(120, 60, 120, 5, WHITE);



  // display.setCursor(0,28);
  // display.println("Hello world!");
  // display.display();
  // delay(2000);
  // display.clearDisplay();

  // Display Inverted Text
  // display.setTextColor(BLACK, WHITE); // 'inverted' text
  // display.setCursor(0,28);
  // display.println("Hello world!");
  // display.display();
  // delay(2000);
  // display.clearDisplay();

  // // Changing Font Size
  // display.setTextColor(WHITE);
  // display.setCursor(0,24);
  // display.setTextSize(2);
  // display.println("Hello!");
  // display.display();
  // delay(2000);
  // display.clearDisplay();


  // Display ASCII Characters



  display.setCursor(0,24);
  display.setTextSize(2);
  display.write(1);
  display.display();
  display.startscrollright(0x00, 0x0f);
  delay(7600);
  display.clearDisplay();


  display.setCursor(0,24);
  display.write(3);
  display.display();
  display.startscrollright(0x00, 0x0f);
  delay(7600);
  display.clearDisplay();


  display.display();

  // // Scroll full screen
  // display.setCursor(0,0);
  // display.setTextSize(1);
  // display.println("Full");
  // display.println("screen");
  // display.println("scrolling!");
  // display.display();
  // display.startscrollright(0x00, 0x07);
  // delay(2000);
  // display.stopscroll();
  // delay(1000);
  // display.startscrollleft(0x00, 0x07);
  // delay(2000);
  // display.stopscroll();
  // delay(1000);    
  // display.startscrolldiagright(0x00, 0x07);
  // delay(2000);
  // display.startscrolldiagleft(0x00, 0x07);
  // delay(2000);
  // display.stopscroll();
  // display.clearDisplay();

  // // Scroll part of the screen
  // display.setCursor(0,0);
  // display.setTextSize(1);
  // display.println("Scroll");
  // display.println("some part");
  // display.println("of the screen.");
  // display.display();
  // display.startscrollright(0x00, 0x00);
}

void loop() {
}