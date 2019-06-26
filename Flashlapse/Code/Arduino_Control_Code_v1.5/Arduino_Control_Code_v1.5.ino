#include <Adafruit_NeoPixel.h>

#define COMMANDSIZE 7
#define LED_PIN 6
#define NUMPIXELS 58
#define BRIGHTNESS 50

#define MOTORPIN1 8
#define MOTORPIN2 9
#define MOTORPIN3 10
#define MOTORPIN4 11
#define STEPS 2038

bool inputComplete = false;  // whether the string is complete
int commands[COMMANDSIZE];
char sz[] = "0~00~00~000~000~000~000";
String serialResponse = "";

double rpm = 5;
int delayTime = 0;
int currentStep = 0;

Adafruit_NeoPixel strip(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show();

  pinMode(MOTORPIN1, OUTPUT);
  pinMode(MOTORPIN2, OUTPUT);
  pinMode(MOTORPIN3, OUTPUT);
  pinMode(MOTORPIN4, OUTPUT);
  getdelay();

  colorWipeMotors(strip.Color(100, 50, 50), 3);
  colorWipeMotors(strip.Color(50, 100, 50), 3);
  colorWipeMotors(strip.Color(50, 50, 100), 3);
  colorWipeMotors(strip.Color(0, 0, 0), 1);
  resetMotors();
  getdelay();

}

void loop() {

}
