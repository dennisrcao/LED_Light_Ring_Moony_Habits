// Sonic Arts Workshops - Exercise 8c: Serial Input 3 - Computer-controlled RGB LED brightness & color mixing
//
// Get blink rate from serial data input
//
// http://sonicartsworkshops.wordpress.com/
// Steven M. Miller - March 2013

/*
 The circuit:
  - Common-cathode RGB LED connected between ground and digital pins 3, 5 & 6 through 220-330Ω resistors
    - Cathode connected to ground
    - Red anode connected to digital pin 3 through 220-330Ω resistor
    - Green anode connected to digital pin 5 through 220-330Ω resistor
    - Blue anode connected to digital pin 6 through 220-330Ω resistor
  (see illustration for Ex. 8)
*/

const char HEADER = 'H';          // Message header byte
const int TOTAL_BYTES = 4;        // Total number of bytes in the message (1 header & 3 data bytes)
const int redPin = 3;             // Declare constant for digital pin 3
const int greenPin = 5;           // Declare constant for digital pin 5
const int bluePin = 6;            // Declare constant for digital pin 6
                          
void setup()
{
  Serial.begin(115200);           // Initialize the serial connection and begin transfer at a rate of 115200 baud
  pinMode(redPin, OUTPUT);        // Set red pin as an output
  pinMode(greenPin, OUTPUT);      // Set green pin as an output
  pinMode(bluePin, OUTPUT);       // Set blue pin as an output
}


void loop() {
  if (Serial.available() >= TOTAL_BYTES) {    // Is there at least a full-message worth of data bytes waiting at the serial buffer?
                                              // If so, proceed
    if (Serial.read() == HEADER) {            // Read the first byte: is it the header byte?
                                              // If so, proceed
      int redVal = Serial.read();             // Read the next data byte and store it in the red value variable
      analogWrite(redPin, redVal);            // Set the PWM value on the red pin equal to the data value
      Serial.println(redVal);
      int greenVal = Serial.read();           // Read the next data byte and store it in the green value variable
      analogWrite(greenPin, greenVal);        // Set the PWM value on the green pin equal to the data value
            Serial.println(greenVal);

      int blueVal = Serial.read();            // Read the next data byte and store it in the blue value variable
      analogWrite(bluePin, blueVal);          // Set the PWM value on the blue pin equal to the data value
                  Serial.println(blueVal);

    }
  }
}
