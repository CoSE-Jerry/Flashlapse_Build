#include <Adafruit_NeoPixel.h>
#include <Stepper.h>

#define STEPS_PER_MOTOR_REVOLUTION 32
#define STEPS_PER_OUTPUT_REVOLUTION 32 * 64
#define PIN 6  
#define COMMANDSIZE 7
#define NUM_LEDS 58
#define BRIGHTNESS 50

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

Stepper small_stepper(STEPS_PER_MOTOR_REVOLUTION, 8, 10, 9, 11);

int  Steps2Take;
String serial_CMD;

void setup() {
  
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show();
  Serial.begin(9600);

  rotatetest();
}



void loop() {
  serial_read();
  
}

int serial_read()
{
  if (Serial.available())
  {
    serial_CMD = Serial.readString();
  }

  return (int)Serial.read();

}


void reset() {

  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 0, 0);
  }
  strip.show();

}

void rotate()
{
  Steps2Take  =  STEPS_PER_OUTPUT_REVOLUTION / 4 ; // Rotate CW 1 turn
  small_stepper.setSpeed(700);
  small_stepper.step(Steps2Take);

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

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}
