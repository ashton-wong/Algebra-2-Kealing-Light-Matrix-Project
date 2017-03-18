#include "Adafruit_NeoPixel.h"
#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(7, 3, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.show();
}

void loop() {
  
  for(int i=-1;i<9;i++){
    pixels.setPixelColor(i, pixels.Color(255,0,255)); //  imposta il colore per ogni led.
    pixels.setPixelColor(i+1, pixels.Color(255,0,255));
    pixels.setPixelColor(i-1, pixels.Color(255,0,255));
    pixels.setPixelColor(i+2, pixels.Color(0,0,0));
    pixels.setPixelColor(i-2, pixels.Color(0,0,0));
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(500); // Delay for a period of time (in milliseconds).
    }
}
