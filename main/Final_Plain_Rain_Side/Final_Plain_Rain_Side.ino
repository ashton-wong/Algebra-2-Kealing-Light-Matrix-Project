#include <Adafruit_NeoPixel.h>
// Add an if i = 0 and this is not the first time, check k- the i reset value and go up
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(450, 3, NEO_GRB + NEO_KHZ800);  //44 Needs to be changed to 330 when running reg. code. Pin (3) matters too
void setup() {
  pixels.begin();
  pixels.show();
  pixels.setBrightness(10);
  Serial.begin(115200);
  delay(100);
} //void setup()
int iStart = 0; //Only exists for testing
int length = 45; //Please only change these void loop variables and the delay, no other code
int rain_space = 9; //should always be less than length (otherwise this code is inefficient for the purpose)
int clm_num = 10;
int offst = 0;
int rand1 = 0;
int rand2 = 0;
int rand1prev = 0;
int rand2prev = 0;
bool serialon = false;
void loop() {

  //If anyone cares about having a start up animation, ask me and I will add a boolean here
  int camera [10] = {45,45,45,45,45,45,45,45,45,45}; // each of these values is the y value of the edge divided to split into 45 parts, x values in (divided by 10), May not be needed and could be defined alongside sereal

  int random [10] = {0,3,4,2,0,5,2,5,1,3};
  int ran = 0;
  int offset [4] = {5,3,0,1};

  int topRed = 71; //71
  int topGreen = 116; //116
  int topBlue = 255; //255

  int botRed = 51; //51
  int botGreen = 106; //106
  int botBlue = 72; //72

  int midRed = 71; //71
  int midGreen = 116; //116
  int midBlue = 156; //156
  for(int i=iStart; i>-2; i++){
    for (int l=0; l<clm_num; l++){
      if (serialon) {
        while (Serial.available() == 0) {//Wait for connection
        }
        int inChar = length - (int)Serial.read();
        camera [l] = inChar;
      }
    }
    int kStart = floor(i/rain_space); //I need this to find a value close to what k should be so the arduino does less work (I would like help)
    for (int j=0; j<clm_num; j++){
      offst = offset [(3*j)%4];
      for(int k=kStart; k>-2; k++){
        if (i == 89) {
          i=-2; //resets i
          k=-3;
        } else {
          if (k == -1) {
            k++;
          }
          if ((k>=0)&& (k <= floor(length/rain_space))) {
            srand((j%10)+(k%10)+(rand1prev%10)+(rand2prev%10));
          }else{
            srand((j%10)+(k%10)+(rand1%10)+(rand2%10));
          }
          ran = random[rand()%10];
          int pixelPlace = i-(k*rain_space + ran) + length -offst;
          if (j%2 == 0) {
            if ((pixelPlace > camera [j])&&(pixelPlace<=length)) {
                for(int l=camera [j]; l<length; l++){
                  pixels.setPixelColor((j*length)+l, pixels.Color(0,0,0));
                }
            } if ((pixelPlace >= camera [j]) && (pixelPlace <= camera [j] + 2)) {//length is an arbitrary location where the rain stops. Cough Cough Hint Hint
              pixels.setPixelColor((j*length)+pixelPlace-3, pixels.Color(0,0,0));
              if (pixelPlace <= camera [j] +1) {
                pixels.setPixelColor((j*length)+pixelPlace-2, pixels.Color(topRed,topGreen,topBlue));
                if (pixelPlace <= camera [j]) {
                  pixels.setPixelColor((j*length)+pixelPlace-1, pixels.Color(midRed,midGreen,midBlue));
                }
              }
            } else if (pixelPlace >= 0 && pixelPlace<= camera [j]-1) {
              pixels.setPixelColor((j*length)+pixelPlace, pixels.Color(botRed,botGreen,botBlue));
              if ((pixelPlace) >= 1) {
                pixels.setPixelColor((j*length)+pixelPlace-1, pixels.Color(midRed,midGreen,midBlue));
                if (pixelPlace >= 2) {
                  pixels.setPixelColor((j*length)+pixelPlace-2, pixels.Color(topRed,topGreen,topBlue));
                  if (pixelPlace >= 3) {
                    pixels.setPixelColor((j*length)+pixelPlace-3, pixels.Color(0,0,0));
                  }
                }
              }
            } else if (pixelPlace < 0){
              k=-3;
            } 
          }
          if (j%2 == 1) {//could be else, kept for readability
            if ((pixelPlace > camera [j])&&(pixelPlace<=length)) {
              for(int l=camera [j]; l<length; l++){
                pixels.setPixelColor(((j+1)*length-1)-l, pixels.Color(0,0,0));
              }
            } if (pixelPlace >= camera [j] && pixelPlace <= camera [j] + 2) { //length is an arbitrary location where the rain stops. Cough Cough Hint Hint
              pixels.setPixelColor(((j+1)*length-1)- pixelPlace +3, pixels.Color(0,0,0));
              if (pixelPlace <= camera [j] +1) {
                pixels.setPixelColor(((j+1)*length-1)-pixelPlace+2, pixels.Color(topRed,topGreen,topBlue));
                if (pixelPlace <= camera [j]) {
                  pixels.setPixelColor(((j+1)*length-1)-pixelPlace+1, pixels.Color(midRed,midGreen,midBlue));
                }
              }
            } else if (pixelPlace >= 0 && pixelPlace <= camera [j]-1) {
              pixels.setPixelColor(((j+1)*length-1)- pixelPlace , pixels.Color(botRed,botGreen,botBlue));
              if (pixelPlace >= 1) {
                pixels.setPixelColor(((j+1)*length-1)- pixelPlace +1, pixels.Color(midRed,midGreen,midBlue));
                if (pixelPlace >= 2) {
                  pixels.setPixelColor(((j+1)*length-1)- pixelPlace +2, pixels.Color(topRed,topGreen,topBlue));
                  if (pixelPlace >= 3){
                    pixels.setPixelColor(((j+1)*length-1)- pixelPlace +3, pixels.Color(0,0,0));
                  }
                }
              }
            } else  if (pixelPlace < 0){
              k=-3;
            } 
          }
        }
      }
    }
    //delay(10); // Delay for a period of time (in milliseconds).
    pixels.show();
    iStart=-1; //Only for testing
    if (i==-3) {
      rand1prev = rand1;
      rand2prev = rand2;
      rand1++;
      if (rand1==10) {
        rand2++;
        rand1 = 0;
        if (rand2==10) {
          rand2=0;
        }
      }
    } 
  } //for(int i=0; i<length; i++)
}//void loop(
