#include <Adafruit_NeoPixel.h>
#define PIN 6
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(330, 3, NEO_GRB + NEO_KHZ800);  //44 Needs to be changed to 330 when running reg. code. Pin (3) matters too
void setup() {
  pixels.begin();
  pixels.show();
} //void setup()
void loop() {
 int length = 33;
 int rain_space = 8;
 int clm_num = 10;
 int random [20] = {0,1,2,0,1,2,0,1,-1,0,0,-1,-2,0,0,0,0,2,-1,0}; //+,- split evenly 10 0's, 6 1's, 4 2's
 int rand = 0;
 for(int i=0; i>-1; i++){ //i never resets
       for (int j=0; j<clm_num; j++){
          for(int k=0; k>-1; k++){
              rand = random [((k+1)*(j+1))%20];
              if (j%2 == 0) {
                if (i-(k*rain_space + rand) >= 0 && i-(k*rain_space + rand)<= length-1) {
                     pixels.setPixelColor((j*length)+(i-(k*rain_space + rand)), pixels.Color(0,0,180));
                     if (i-(k*rain_space + rand) >= 1) {
                         pixels.setPixelColor((j*length)+(i-(k*rain_space + rand))-1, pixels.Color(0,180,0));
                         if (i-(k*rain_space + rand) >= 2) {
                             pixels.setPixelColor((j*length)+(i-(k*rain_space + rand))-2, pixels.Color(180,0,0));
                             if (i-(k*rain_space + rand) >= 3) {
                                  pixels.setPixelColor((j*length)+(i-(k*rain_space + rand))-3, pixels.Color(0,0,0));
                             }
                         }
                     }
                }else if (i-(k*rain_space + rand) >= length && i-(k*rain_space + rand) <= length + 2) {
                     pixels.setPixelColor((j*length)+(i-(k*rain_space + rand))-3, pixels.Color(0,0,0));
                     if (i-(k*rain_space + rand) <= length +1) {
                         pixels.setPixelColor((j*length)+(i-(k*rain_space + rand))-2, pixels.Color(180,0,0));
                         if (i-(k*rain_space + rand) <= length) {
                             pixels.setPixelColor((j*length)+(i-(k*rain_space + rand))-1, pixels.Color(0,180,0));
                        }
                    }
                }else  if (i-(k*rain_space + rand) < 0){
                    k=-2;
                }
            }
              if (j%2 == 1) {//could be else, kept for readability
                  if ((i-(k*rain_space + rand)) >= 0 && i-(k*rain_space + rand) <= length-1) {
                    pixels.setPixelColor(((j+1)*length-1)-(i-(k*rain_space + rand)), pixels.Color(0,0,180));
                    if ((i-(k*rain_space + rand)) >= 1) {
                    pixels.setPixelColor(((j+1)*length-1)-(i-(k*rain_space + rand))+1, pixels.Color(0,180,0));
                          if ((i-(k*rain_space + rand)) >= 2) {
                            pixels.setPixelColor(((j+1)*length-1)-(i-(k*rain_space + rand))+2, pixels.Color(180,0,0));
                            if (i-(k*rain_space + rand) >= 3){
                                  pixels.setPixelColor(((j+1)*length-1)-(i-(k*rain_space + rand))+3, pixels.Color(0,0,0));
                            }
                          }
                    }
                }else if (i-(k*rain_space + rand) >= length && i-(k*rain_space + rand) <= length + 2) {
                      pixels.setPixelColor(((j+1)*length-1)-(i-(k*rain_space + rand))+3, pixels.Color(0,0,0));
                      if (i-(k*rain_space + rand) <= length +1) {
                          pixels.setPixelColor(((j+1)*length-1)-(i-(k*rain_space + rand))+2, pixels.Color(180,0,0));
                          if (i-(k*rain_space + rand) <= length) {
                              pixels.setPixelColor(((j+1)*length-1)-(i-(k*rain_space + rand))+1, pixels.Color(0,180,0));
                        }
                    }
                } else  if (i-(k*rain_space + rand) < 0){
                    k=-2;
                }
            }
        }
    }
       delay(100); // Delay for a period of time (in milliseconds).
       pixels.show();
 } //for(int i=0; i<length; i++)
}//void loop()\
