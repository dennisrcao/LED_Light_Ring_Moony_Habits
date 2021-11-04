#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif


int ledPin = 6;  //DataLine for RGB Values
int soundDetectedPin = A0; // Microphone Input
//int intensity =0;


int fadeAmount = 1;
int multiplier = 0.5;


int brightness = 0;
int brightnessLow = 50;
int brightnessMin = 15;
int brightnessMax = 255;



unsigned long time;
//initialize colors
int R = 220;
int G = 0;
int B = 240;
int averageSound = 30;
//set the interval of color change 60000 =1 min
int interval  = 3000;
int colorState = 0;
long previousMillis = 0 ; //  will store last time LED was updated


//initialize LED strip
//95 = number of pixels
//ledPin = input on arduino board
//NEO_GRB + NEO_KHZ800 = look above
Adafruit_NeoPixel strip = Adafruit_NeoPixel(99, ledPin, NEO_GRB + NEO_KHZ800);
unsigned long currentMillis = millis();


void setup()
{
  Serial.begin(9600);
  pinMode (ledPin, OUTPUT);
  // put your setup code here, to run once:
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}


void loop() {
  int soundVal;
  currentMillis = millis();
  soundVal = analogRead(0); //connect mic sensor to Analog 0
  //Serial.println(soundVal, DEC); //print the sound value to serial
  // Serial.println ("colorState:  " );
  // Serial.println(colorState); //print the sound value to serial


  // Serial.println ("previousMillis :  " );
  // Serial.println(previousMillis); //print the sound value to serial

  //if (currentMillis - previousMillis > interval) {
  if (millis() % interval == 0) {
    colorState = colorState + 1;
    if (colorState == 1) {
      // 100 20 20 - purple **

      R = 220;
      G = 0;
      B = 240;
      //colorState = colorState + 1;
    } else if (colorState == 2) {
      // 100 20 20 - purple **

      R = 220;
      G = 0;
      B = 240;
      // colorState = colorState + 1;
    } else if (colorState == 3) {

      //240,20,20 - warm red **
      R = 100;
      G = 100;
      B = 100;
      //colorState = colorState + 1;
    } else if (colorState == 4) {
      // 130,20,20 - warm light orange **
      R = 0;
      G = 180;
      B = 90 ;
      //colorState = colorState + 1;
    } else if (colorState == 5) {
      // 240 120 100 - white **
      R = 0;
      G = 180;
      B = 100;
      //colorState = colorState + 1;
    } else if (colorState == 6) {

      // 220,0,240 - purple/white
      R = 0;
      G = 160;
      B = 160;
      //colorState = colorState + 1;
    } else if (colorState == 7) {

      // 46,46,215 - cool blue **
      R = 60;
      G = 20;
      B = 80 ;
      //colorState = colorState + 1;
    } else if (colorState == 8) {

      // 220,0,240 - purple/white
      R = 100;
      G = 20;
      B = 20 ;
      // colorState = colorState + 1;
    } else {
      //colorState = 0;
      // 240 120 100 - white **
      R = 130;
      G = 20;
      B = 20;
      colorState = colorState + 1;
    }

    if (colorState > 8) {
      colorState = 0;
    }
  }

  setLedColor(R, G, B);  //This writes the color to the color loop
  Serial.println ("colorState:  " );
  Serial.println(colorState); //print the sound value to serial



  if (soundVal > 0 && soundVal < brightnessMax) {

    brightness = brightness * soundVal + fadeAmount;
    strip.setBrightness(brightness);
    strip.show(); 
  } else if (soundVal > brightnessMax) {

    brightness = brightnessMax;
    strip.setBrightness(brightness);
    strip.show();

  } else if (soundVal == 0) {
    brightness = brightnessMin;
    strip.setBrightness(brightness);
    strip.show();

  } else {
    brightness = brightness * soundVal * fadeAmount;
    strip.setBrightness(brightnessLow);
    strip.show();
  }

  delay(10);
}

void setLedColor(int val1, int val2, int val3) {
  for (int i = 0; i < strip.numPixels(); i++) {
    //set color per pixel
    strip.setPixelColor(i, val1, val2, val3);
  }
}




