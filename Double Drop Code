#include "Adafruit_NeoPixel.h"
#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(11, 3, NEO_GRB + NEO_KHZ800);

int ofst=6;
int i=-2;
void setup() {
  pixels.begin();
  pixels.show();
}
void loop() {
i=++i;
  for (int mult=0; mult<10; mult++){
  	for (int a=0; a<3; a++){
      if (((i-(mult*ofst)-a)>-1) && ((i-(mult*ofst)-a)<15)){
        pixels.setPixelColor(i-(mult*ofst)-a, pixels.Color(0,50,155));
      }
    }
    if (((i-(mult*ofst)+1)>-1) && ((i-(mult*ofst)-3)<17)){
  		pixels.setPixelColor(i-(mult*ofst)+1, pixels.Color(0,0,0));
    	pixels.setPixelColor(i-(mult*ofst)-3, pixels.Color(0,0,0)); 
    }
    pixels.show();
  	delay(100);
    
  }
  }
