#include <Arduino.h>
#include <Wire.h>
#include <EEPROM.h>
// Hardware Specific Libraries.
#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

// Define the touch screen.
MCUFRIEND_kbv tft;

// Define touch screen variables.
#define MINPRESSURE 200
#define MAXPRESSURE 1000

void setup() {
    Serial.begin(9600);
    uint16_t ID = tft.readID();
    Serial.print("TFT ID = 0x");
    Serial.println(ID, HEX);
    if (ID == 0xD3D3) ID = 0x9486; // write-only shield
    tft.begin(ID);
    tft.setRotation(0);            
    tft.fillScreen(BLACK);
    // Hello WOrld
    tft.setTextSize(3);
    tft.setTextWrap(true);
    printCenter(3, "Hello World!");
}

/*
Print a simple string in the center of the screen.
*/
void printCenter(int textSize, String str) {
    
    tft.setCursor((tft.width() / 2)-(strlen(str.c_str())*pow(textSize, 2)), tft.height()/2);
    tft.print(str);
}

void loop() {
    Serial.println("Hello World!");
    delay(2000);
}