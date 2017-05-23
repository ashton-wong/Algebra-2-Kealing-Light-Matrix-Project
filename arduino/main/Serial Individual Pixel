//Reads whatever is inputted onto the serial as coordinates.
//Then plugs the coordinates into the neopixel matrix and turns them on.
//IMPORTANT: USES ASCII CHARACTERS INSTEAD OF NUMBERS.

bool waitforYvalue = false;
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

int inX = -1;
int inY = -1;

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(10, 45, 3,
  NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB + NEO_KHZ800);

const uint16_t rgb[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) };

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(40);
  while (!Serial) {
    //Wait for connection
  }
/*  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(40);
  matrix.setTextColor(colors[0]);*/
}

void loop() {
  // put your main code here, to run repeatedly:
    matrix.drawPixel(inX, inY, rgb[0]);
  matrix.show();
}

void serialEvent() {
  while (Serial.available()) {
    if (not(waitforYvalue)) {
      inX = Serial.read();
      //We are using ascii characters so we can have two digits
      //inX -= 48;
      Serial.print("X value:");
      Serial.println(inX, DEC);
      waitforYvalue = true;
    }
    else {
      inY = Serial.read();
      //Read above
      //inY -= 48;
      Serial.print("Y value:");
      Serial.println(inY, DEC);
      waitforYvalue = false;
    }
  }
}
