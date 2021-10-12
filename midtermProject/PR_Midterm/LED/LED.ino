
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h>
#endif


#define PIN        6 


#define NUMPIXELS 64 


Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 

void setup() {

  pixels.begin(); 
}

void loop() {
  //pixels.clear(); 
  /*
  for(int i=0; i<NUMPIXELS; i++) { 

    pixels.setPixelColor(i*2, pixels.Color(188,205,243));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
  }
  */
  pixels.clear(); 
   delay(DELAYVAL);
   pixels.setPixelColor(9, pixels.Color(188,205,243));
   pixels.setPixelColor(10, pixels.Color(188,205,243));
   pixels.setPixelColor(13, pixels.Color(188,205,243));
   pixels.setPixelColor(14, pixels.Color(188,205,243));
   pixels.setPixelColor(17, pixels.Color(188,205,243));
   pixels.setPixelColor(18, pixels.Color(188,205,243));
   pixels.setPixelColor(21, pixels.Color(188,205,243));
   pixels.setPixelColor(22, pixels.Color(188,205,243));
   pixels.setPixelColor(42, pixels.Color(188,205,243));
   pixels.setPixelColor(43, pixels.Color(188,205,243));
   pixels.setPixelColor(44, pixels.Color(188,205,243));
   pixels.setPixelColor(45, pixels.Color(188,205,243));
  // pixels.setPixelColor(50, pixels.Color(188,205,243));
   pixels.setPixelColor(51, pixels.Color(188,205,243));
   pixels.setPixelColor(52, pixels.Color(188,205,243));
   //pixels.setPixelColor(53, pixels.Color(188,205,243));
   pixels.show();
   
   pixels.clear(); 
    delay(DELAYVAL);
   pixels.setPixelColor(9, pixels.Color(255,0,0));
   pixels.setPixelColor(10, pixels.Color(255,0,0));
   pixels.setPixelColor(13, pixels.Color(255,0,0));
   pixels.setPixelColor(14, pixels.Color(255,0,0));
   pixels.setPixelColor(17, pixels.Color(255,0,0));
   pixels.setPixelColor(18, pixels.Color(255,0,0));
   pixels.setPixelColor(21, pixels.Color(255,0,0));
   pixels.setPixelColor(22, pixels.Color(255,0,0));
   pixels.setPixelColor(42, pixels.Color(255,0,0));
   pixels.setPixelColor(43, pixels.Color(255,0,0));
   pixels.setPixelColor(44, pixels.Color(255,0,0));
   pixels.setPixelColor(45, pixels.Color(255,0,0));
 //  pixels.setPixelColor(50, pixels.Color(255,0,0));
   pixels.setPixelColor(51, pixels.Color(255,0,0));
   pixels.setPixelColor(52, pixels.Color(255,0,0));
   //pixels.setPixelColor(53, pixels.Color(255,0,0));
   pixels.show();
}
