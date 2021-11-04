#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif


int ledPin = 6;  //DataLine for RGB Values

int R = 200;
int G = 200;
int B = 100;

int value = 0;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(99, ledPin, NEO_GRB + NEO_KHZ800);


void setup() 
{
  // put your setup code here, to run once:
pinMode (ledPin, OUTPUT);
  Serial.begin(9600);
  strip.begin();
  strip.show();   
}

void loop() 
{
  if (Serial.available()) 
    {
      value = Serial.read();
      Serial.println(value);
    } //end serial
      
      setLedColor(R, G, B);  //This writes the color to the color loop
}



void setLedColor(int val1, int val2, int val3) 
{
    for (int i = 0; i < strip.numPixels(); i++)
      {
        //set color per pixel
        strip.setPixelColor(i, val1, val2, val3);
      }
      
}


