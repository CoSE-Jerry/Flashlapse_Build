#include <Adafruit_NeoPixel.h>
#include <Stepper.h>

#define STEPS_PER_MOTOR_REVOLUTION 32

#define STEPS_PER_OUTPUT_REVOLUTION 32 * 64

#define PIN 6  


#define NUM_LEDS 58

#define BRIGHTNESS 50

#define THIRD NUM_LEDS/3

#define HALF NUM_LEDS/2

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int serial_CMD;

boolean empty;

int current_CMD;

Stepper small_stepper(STEPS_PER_MOTOR_REVOLUTION, 8, 10, 9, 11);

int  Steps2Take;

void setup() {
  
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show();
  Serial.begin(9600);

  colorWipe(strip.Color(100, 50, 50), 3); // Red
  colorWipe(strip.Color(50, 100, 50), 3); // Green
  colorWipe(strip.Color(50, 50, 100), 3); // Blue
  colorWipe(strip.Color(0, 0, 0), 1); // Blue

  rotatetest();
}



void loop() {
  serial_read();

  if (serial_CMD == 48)
  {
    reset();
  }

  if (serial_CMD == 49)
  {
    full_red();
  }

  if (serial_CMD == 50)
  {
    full_green();
  }

  if (serial_CMD == 51)
  {
    full_blue();
  }

  if (serial_CMD == 52)
  {
    full_white();
  }

  if (serial_CMD == 65)
  {
    left_none();
  }

  if (serial_CMD == 97)
  {
    left_red();
  }

  if (serial_CMD == 98)
  {
    left_green();
  }

  if (serial_CMD == 99)
  {
    left_blue();
  }

  if (serial_CMD == 120)
  {
    left_white();
  }

  if (serial_CMD == 66)
  {
    right_none();
  }

  if (serial_CMD == 121)
  {
    right_white();
  }


  if (serial_CMD == 100)
  {
    right_red();
  }

  if (serial_CMD == 101)
  {
    right_green();
  }

  if (serial_CMD == 102)
  {
    right_blue();
  }

  if (serial_CMD == 103)
  {
    gravi_red();
    current_CMD = 103;
  }

  if (serial_CMD == 104)
  {
    gravi_green();
    current_CMD = 104;
  }

  if (serial_CMD == 105)
  {
    gravi_blue();
    current_CMD = 105;
  }

  if (serial_CMD == 106)
  {
    gravi_white();
    current_CMD = 106;
  }

  if (serial_CMD == 107)
  {
    germi_red();
  }

  if (serial_CMD == 108)
  {
    germi_green();
  }

  if (serial_CMD == 109)
  {
    germi_blue();
  }

  if (serial_CMD == 110)
  {
    germi_white();
  }

  if (serial_CMD == 111)
  {
    barri_red();
  }

  if (serial_CMD == 112)
  {
    barri_green();
  }

  if (serial_CMD == 113)
  {
    barri_blue();
  }

  if (serial_CMD == 114)
  {
    barri_white();
  }

  if (serial_CMD == 115)
  {
    disco();
    current_CMD = 115;
  }

  if (serial_CMD == 122)
  {
    rotate();
  }
  


}

int serial_read()
{
  if (Serial.available())
  {
    serial_CMD = (int)Serial.read();
  }
  //  Serial.println(serial_CMD);

  return (int)Serial.read();

}

void Advanced_Barrier_Assay()
{
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    if (i > THIRD + 1 && i < 2 * THIRD - 1)
      strip.setPixelColor(i, 255, 255, 255);
  }
  strip.show();

}

void reset() {

  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 0, 0);
  }
  strip.show();

}

void full_red()
{

  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 255, 0, 0);
  }
  strip.show();
  empty = false;
}

void full_green()
{
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 255, 0);
  }
  strip.show();
  empty = false;

}

void full_blue()
{

  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 0, 255);
  }
  strip.show();
  empty = false;

}

void full_white()
{

  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 70, 70, 70);
  }
  strip.show();
  empty = false;

}

void right_none()
{ if (empty == false)
  {
    reset();
    empty = true;

  }
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    if (i < HALF)
    { strip.setPixelColor(i, 0, 0, 0);
    }
  }
  strip.show();

}

void right_red()
{ if (empty == false)
  {
    reset();
    empty = true;

  }
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    if (i < HALF)
    { strip.setPixelColor(i, 255, 0, 0);
    }
  }
  strip.show();

}

void right_green()
{ if (empty == false)
  {
    reset();
    empty = true;

  }
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    if (i < HALF)
    { strip.setPixelColor(i, 0, 255, 0);
    }
  }
  strip.show();

}

void right_blue()
{ if (empty == false)
  {
    reset();
    empty = true;

  }
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    if (i < HALF)
    { strip.setPixelColor(i, 0, 0, 255);
    }
  }
  strip.show();

}

void right_white()
{ if (empty == false)
  {
    reset();
    empty = true;

  }
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    if (i < HALF)
    { strip.setPixelColor(i, 70, 70, 70);
    }
  }
  strip.show();

}


void left_none()
{ if (empty == false)
  {
    reset();
    empty = true;

  }
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    if (i >= HALF)
    { strip.setPixelColor(i, 0, 0, 0);
    }
  }
  strip.show();

}

void left_white()
{ if (empty == false)
  {
    reset();
    empty = true;
  }
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    if (i >= HALF)
    { strip.setPixelColor(i, 70, 70, 70);
    }
  }
  strip.show();
}

void left_red()
{ if (empty == false)
  {
    reset();
    empty = true;
  }
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    if (i >= HALF)
    { strip.setPixelColor(i, 255, 0, 0);
    }
  }
  strip.show();
}

void left_green()
{ if (empty == false)
  {
    reset();
    empty = true;
  }
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    if (i >= HALF)
    { strip.setPixelColor(i, 0, 255, 0);
    }
  }
  strip.show();
}

void left_blue()
{ if (empty == false)
  {
    reset();
    empty = true;
  }
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    if (i >= HALF)
    { strip.setPixelColor(i, 0, 0, 255);
    }
  }
  strip.show();
}

void rotate()
{
  Steps2Take  =  STEPS_PER_OUTPUT_REVOLUTION / 4 ; // Rotate CW 1 turn
  small_stepper.setSpeed(700);
  small_stepper.step(Steps2Take);
  serial_CMD = 0;

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void rotatetest()
{
  Steps2Take  =  STEPS_PER_OUTPUT_REVOLUTION ; // Rotate CW 1 turn
  small_stepper.setSpeed(700);
  small_stepper.step(Steps2Take/4);
  small_stepper.step(-(Steps2Take/4));
  serial_CMD = 0;

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

boolean waits(int seconds) {
  for (int i = 0; i < seconds; i++)
  {
    delay(1000);
    if (Serial.available())
    {
      serial_CMD = (int)Serial.read();
      if (serial_CMD != current_CMD)
      {
        return false;
      }

    }
    Serial.println (i);
  }
  return true;
}

boolean waitm(int minutes) {
  for (int i = 0; i < minutes; i++)
  {
    Serial.println (i);
    boolean temp = waits(60);
    if (temp == false)
    { return false;
    }
    
  }
}



boolean waith(int hours) {
  for (int i = 0; i < hours; i++)
  {
    Serial.println (i);
    boolean temp = waitm(60);
    if (temp == false)
    { return false;
    }
  }
}

void gravi_red() {
  reset();
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    if (i > THIRD - 1 && i < 2 * THIRD + 1)
      strip.setPixelColor(i, 255, 255, 255);
  }
  strip.show();

  boolean temp = waitm(10*60);
  if (temp == false)
  {
    reset();
    return;

  }

  rotate();
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 100, 0, 0);
  }
  strip.show();
  waith(12);
}

void gravi_green() {
  reset(); 
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    if (i > THIRD - 1 && i < 2 * THIRD + 1)
      strip.setPixelColor(i, 255, 255, 255);
  }
  strip.show();

  boolean temp = waith(12);
  if (temp == false)
  {
    reset();
    return;
  }

  rotate();
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 100, 0);
  }
  strip.show();
  waith(12);
}

void gravi_blue() {
  reset();
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    if (i > THIRD - 1 && i < 2 * THIRD + 1)
      strip.setPixelColor(i, 255, 255, 255);
  }
  strip.show();

  boolean temp = waith(12);
  if (temp == false)
  {
    reset();
    return;
  }

  rotate();
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 0, 100);
  }
  strip.show();
  waith(12);
}

void gravi_white() {
  reset();
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    if (i > THIRD - 1 && i < 2 * THIRD + 1)
      strip.setPixelColor(i, 255, 255, 255);
  }
  strip.show();

  boolean temp = waith(12);
  if (temp == false)
  {
    reset();
    return;
  }

  rotate();
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 100, 100, 100);
  }
  strip.show();
  waith(12);
}

void germi_red() {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 100, 0, 0);
  }
  empty = false;
  strip.show();
}

void germi_green() {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 100, 0);
  }
  empty = false;
  strip.show();
}

void germi_blue() {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 0, 100);
  }
  empty = false;
  strip.show();
}

void germi_white() {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 100, 100, 100);
  }
  empty = false;
  strip.show();
}

void barri_red() {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    if (i > THIRD - 1 && i < 2 * THIRD + 1)
      strip.setPixelColor(i, 255, 0, 0);
    else {
      strip.setPixelColor(i, 0, 0, 0);
    }
  }
  empty = false;
  strip.show();
}

void barri_green() {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    if (i > THIRD - 1 && i < 2 * THIRD + 1)
      strip.setPixelColor(i, 0, 255, 0);
    else {
      strip.setPixelColor(i, 0, 0, 0);
    }
  }
  empty = false;
  strip.show();
}

void barri_blue() {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    if (i > THIRD - 1 && i < 2 * THIRD + 1)
      strip.setPixelColor(i, 0, 0, 255);
    else {
      strip.setPixelColor(i, 0, 0, 0);
    }
  }
  empty = false;
  strip.show();
}

void barri_white() {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    if (i > THIRD - 1 && i < 2 * THIRD + 1)
      strip.setPixelColor(i, 255, 255, 255);
    else {
      strip.setPixelColor(i, 0, 0, 0);
    }
  }
  empty = false;
  strip.show();
}


void disco() {
  if (colorWipe(strip.Color(255, 0, 0), 50) == false)
  { return;
  }
  if (colorWipe(strip.Color(0, 255, 0), 50) == false)
  { return;
  }
  if (colorWipe(strip.Color(0, 0, 255), 50) == false)
  { return;
  }
  if (theaterChase(strip.Color(127, 127, 127), 50) == false)
  { return;
  }
  if (theaterChase(strip.Color(127, 0, 0), 50) == false)
  { return;
  }
  if (theaterChase(strip.Color(0, 0, 127), 50) == false)
  { return;
  }

  if (rainbowCycle(20) == false)
  { return;
  }

  if (theaterChaseRainbow(50) == false)
  { return;
  }

}


boolean colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    if (Serial.available())
    {
      serial_CMD = (int)Serial.read();
      if (serial_CMD != current_CMD)
      {
        return false;
      }

    }
    delay(wait);
  }
}

boolean rainbow(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i + j) & 255));
    }
    strip.show();
    delay(wait);
    if (Serial.available())
    {
      serial_CMD = (int)Serial.read();
      if (serial_CMD != current_CMD)
      {
        return false;
      }

    }
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
boolean rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
    if (Serial.available())
    {
      serial_CMD = (int)Serial.read();
      if (serial_CMD != current_CMD)
      {
        return false;
      }

    }
  }
}

//Theatre-style crawling lights.
boolean theaterChase(uint32_t c, uint8_t wait) {
  for (int j = 0; j < 10; j++) { //do 10 cycles of chasing
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, c);  //turn every third pixel on
      }
      strip.show();
      if (Serial.available())
      {
        serial_CMD = (int)Serial.read();
        if (serial_CMD != current_CMD)
        {
          return false;
        }

      }
      delay(wait);

      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
boolean theaterChaseRainbow(uint8_t wait) {
  for (int j = 0; j < 256; j++) {   // cycle all 256 colors in the wheel
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, Wheel( (i + j) % 255)); //turn every third pixel on
      }
      strip.show();

      delay(wait);
      if (Serial.available())
      {
        serial_CMD = (int)Serial.read();
        if (serial_CMD != current_CMD)
        {
          return false;
        }

      }
      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

