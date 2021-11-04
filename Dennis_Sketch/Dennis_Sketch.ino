#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

int DataPin = 6;  //DataLine for RGB Values

int R;
int G;
int B;

int brightness = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(99, DataPin, NEO_GRB + NEO_KHZ800);
unsigned long currentMillis = millis();

int MaxToArduinoComm_StartFlag = 0; // flag for whether we've received serial yet
int serialvalue;


void setup() {
  Serial.begin(9600);
  pinMode (DataPin, OUTPUT);
  strip.begin();
  strip.show();
}

void loop() {
      currentMillis = millis();
      
  if (Serial.available())
    {
    serialvalue = Serial.read(); // read a byte of serial data
    R = Serial.read();
        G = Serial.read();
    B = Serial.read();

    
    MaxToArduinoComm_StartFlag = 1; // set the started flag to on
    }


    
  /* if(MaxToArduinoComm_StartFlag)
    { //loop once serial data has been received
    Serial.print(serialvalue); // echo the received serial value
    Serial.println(); // print a line-feed
    countervalue = (countervalue+1)%1000; // increment the counter
    delay(100); // pause
    }
    */
    
    if (serialvalue == 1)
    { 
Serial.print(serialvalue); // print the counter
Serial.print(" "); // print a space
Serial.print(R); // print the random value
Serial.print(" "); // print a space
Serial.print(G); // echo the received serial value
Serial.print(" "); // print a space
Serial.print(B); // echo the received serial value
Serial.println(); // print a line-feed
delay(100); // pause
    }


     /*
    R = random(0, 255); 
    G = random(0, 255); 
    B = random(0, 255); 
    setLedColor(R, G, B);  //This determines color of loop
    brightness = 255; //set to max brightness
    strip.setBrightness(brightness);  //This lights up loop
    strip.show();
    delay(300);
    */
    
    /*
    else  //serialvalue == 0, no threshold
    {
      R = R/2;
      G = G/2;
      B = B/2;
     setLedColor(R, G, B);  //This determines color of loop
      brightness = brightness/2;
      strip.setBrightness(brightness);  //This lights up loop
    strip.show();
    
    delay(50);
     R = R/2;
      G = G/2;
      B = B/2;
     setLedColor(R, G, B);  //This determines color of loop
      brightness = brightness/2;
      strip.setBrightness(brightness);  //This lights up loop
    strip.show();
    
    delay(50);
     R = R/2;
      G = G/2;
      B = B/2;
     setLedColor(R, G, B);  //This determines color of loop
      brightness = brightness/2;
      strip.setBrightness(brightness);  //This lights up loop
    strip.show();
    delay(50);
     
    }
    */
   
 }
   



void setLedColor(int val1, int val2, int val3) {
  for (int i = 0; i < strip.numPixels(); i++) {
    //set color per pixel
    strip.setPixelColor(i, val1, val2, val3);
  }
}
