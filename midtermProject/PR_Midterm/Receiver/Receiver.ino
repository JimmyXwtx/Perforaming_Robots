
/*
   reference
   rf24Xmit.ino provided by Prof. Michael Shiloh https://github.com/michaelshiloh/resourcesForClasses/blob/master/src/arduinoSketches/nRF24L01/rf24Xmit/rf24Xmit.ino
   Arduino_NeoPixel_Library_Example_LED_PIN and LED_COUNT
*/
const int CEPIN = 9;
const int CSNPIN = 10;

#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

RF24 radio(CEPIN, CSNPIN);
Servo myservo1;
Servo myservo2;



const byte address[6] = "00001";

// Motor controller pins
const int rightDirPin = 2;
const int rightPWMPin = 4;
const int leftDirPin = 7;
const int leftPWMPin = 8;
int pos = 0;

#define PIN        3


#define NUMPIXELS 64


Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500


void setup() {

  // Motor controller pins
  pinMode(rightDirPin, OUTPUT);
  pinMode(leftDirPin, OUTPUT);
  myservo1.attach(5);
  myservo2.attach(6);
  pixels.begin();

  Serial.begin(115200);

  // RF24 setup
  if (!radio.begin()) {
    Serial.println("radio  initialization failed");
    while (1)
      ;
  } else {
    Serial.println("radio successfully initialized");
  }
  radio.openReadingPipe(0, address);  // Destination address
  radio.setPALevel(RF24_PA_MIN);      // Min or max
  radio.startListening();             // sets  module as receiver
}
void loop() {
  uint8_t pipeNum;
  if (radio.available(&pipeNum))  //Looking for the data.
  {
    int data;

    Serial.print("data available on pipe ");
    Serial.println(pipeNum);

    radio.read(&data, sizeof(data));  //Reading the data
    Serial.print("data = ");
    Serial.println( data);


    switch (data) {
        break;
      /*
        case 0x01:
        stop();

        digitalWrite(leftDirPin, HIGH);
        digitalWrite(leftPWMPin, LOW);

        digitalWrite(rightDirPin, LOW);
        digitalWrite(rightPWMPin, HIGH);

        pixels.clear();
        //delay(DELAYVAL);
        pixels.setPixelColor(9, pixels.Color(255, 0, 0));
        pixels.setPixelColor(10, pixels.Color(255, 0, 0));
        pixels.setPixelColor(13, pixels.Color(255, 0, 0));
        pixels.setPixelColor(14, pixels.Color(255, 0, 0));
        pixels.setPixelColor(17, pixels.Color(255, 0, 0));
        pixels.setPixelColor(18, pixels.Color(255, 0, 0));
        pixels.setPixelColor(21, pixels.Color(255, 0, 0));
        pixels.setPixelColor(22, pixels.Color(255, 0, 0));
        pixels.setPixelColor(42, pixels.Color(255, 0, 0));
        pixels.setPixelColor(43, pixels.Color(255, 0, 0));
        pixels.setPixelColor(44, pixels.Color(255, 0, 0));
        pixels.setPixelColor(45, pixels.Color(255, 0, 0));
        //  pixels.setPixelColor(50, pixels.Color(255,0,0));
        pixels.setPixelColor(51, pixels.Color(255, 0, 0));
        pixels.setPixelColor(52, pixels.Color(255, 0, 0));
        //pixels.setPixelColor(53, pixels.Color(255,0,0));
        pixels.show();


        break;
      */
      case 0x01://Monitor around behaviour
        /*
          Serial.println("forward");
          digitalWrite(rightDirPin, HIGH);
          digitalWrite(rightPWMPin, LOW);
          digitalWrite(leftDirPin, LOW);
          digitalWrite(leftPWMPin, HIGH);
          break;
        */

        digitalWrite(rightDirPin, LOW);
        digitalWrite(rightPWMPin, LOW);
        digitalWrite(leftDirPin, LOW);
        digitalWrite(leftPWMPin, LOW);
        /*
          myservo1.write(90);
          myservo2.write(90);
          delay(15);
          myservo1.write(0);
          myservo2.write(0);
        */
        pixels.clear();
        //delay(DELAYVAL);
        //safe facial expression
        pixels.setPixelColor(9, pixels.Color(188, 205, 243));
        pixels.setPixelColor(10, pixels.Color(188, 205, 243));
        pixels.setPixelColor(13, pixels.Color(188, 205, 243));
        pixels.setPixelColor(14, pixels.Color(188, 205, 243));
        pixels.setPixelColor(17, pixels.Color(188, 205, 243));
        pixels.setPixelColor(18, pixels.Color(188, 205, 243));
        pixels.setPixelColor(21, pixels.Color(188, 205, 243));
        pixels.setPixelColor(22, pixels.Color(188, 205, 243));
        pixels.setPixelColor(42, pixels.Color(188, 205, 243));
        pixels.setPixelColor(43, pixels.Color(188, 205, 243));
        pixels.setPixelColor(44, pixels.Color(188, 205, 243));
        pixels.setPixelColor(45, pixels.Color(188, 205, 243));
        // pixels.setPixelColor(50, pixels.Color(188,205,243));
        pixels.setPixelColor(51, pixels.Color(188, 205, 243));
        pixels.setPixelColor(52, pixels.Color(188, 205, 243));
        //pixels.setPixelColor(53, pixels.Color(188,205,243));
        pixels.show();
        for (pos = 0; pos <= 180; pos += 1) {
          myservo1.write(pos);
          myservo2.write(pos);
          delay(15);
        }
        for (pos = 180; pos >= 0; pos -= 1) {
          myservo1.write(pos);
          myservo2.write(pos);
          delay(15);
        }

        break;


      case 0x04:
        stop();
        //Warning!! Attack
        digitalWrite(leftDirPin, HIGH);
        digitalWrite(leftPWMPin, LOW);

        digitalWrite(rightDirPin, LOW);
        digitalWrite(rightPWMPin, HIGH);

        pixels.clear();

        pixels.setPixelColor(9, pixels.Color(255, 0, 0));
        pixels.setPixelColor(10, pixels.Color(255, 0, 0));
        pixels.setPixelColor(13, pixels.Color(255, 0, 0));
        pixels.setPixelColor(14, pixels.Color(255, 0, 0));
        pixels.setPixelColor(17, pixels.Color(255, 0, 0));
        pixels.setPixelColor(18, pixels.Color(255, 0, 0));
        pixels.setPixelColor(21, pixels.Color(255, 0, 0));
        pixels.setPixelColor(22, pixels.Color(255, 0, 0));
        pixels.setPixelColor(42, pixels.Color(255, 0, 0));
        pixels.setPixelColor(43, pixels.Color(255, 0, 0));
        pixels.setPixelColor(44, pixels.Color(255, 0, 0));
        pixels.setPixelColor(45, pixels.Color(255, 0, 0));
        //  pixels.setPixelColor(50, pixels.Color(255,0,0));
        pixels.setPixelColor(51, pixels.Color(255, 0, 0));
        pixels.setPixelColor(52, pixels.Color(255, 0, 0));
        //pixels.setPixelColor(53, pixels.Color(255,0,0));
        pixels.show();


        break;
      default:
        Serial.println("invalid code");
        pixels.clear();
        stop();
        digitalWrite(rightDirPin, LOW);
        digitalWrite(rightPWMPin, LOW);

        break;
    }
  } else {
    //Serial.println("stop");
    stop();
  }
  delay(5);
}

void stop() {

  digitalWrite(rightDirPin, LOW);
  digitalWrite(rightPWMPin, 0);
  digitalWrite(leftDirPin, LOW);
  digitalWrite(leftPWMPin, 0);
}
