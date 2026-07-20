#include <Adafruit_NeoPixel.h>

#define DATA_PIN     13  // Connects to the 'S' pin of your 4-LED board
#define NUM_LEDS      4  // Your board contains exactly 4 LEDs

// Initialize the 6812 / NeoPixel strip configuration
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, DATA_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();           // Start communication with the module
  strip.setBrightness(60); // Set moderate brightness (0 - 255) to protect your eyes
  strip.show();            // Initialize all pixels to "off"
}

void loop() {
  // Step sequentially through each of the 4 LEDs
  for (int i = 0; i < NUM_LEDS; i++) {
    
    strip.clear(); // Turn off previous pixels first
    
    // Choose colors dynamically based on which LED index is currently active
    if (i == 0) {
      strip.setPixelColor(i, strip.Color(255, 0, 0));     // LED 1: Pure Red
    } else if (i == 1) {
      strip.setPixelColor(i, strip.Color(0, 255, 0));     // LED 2: Pure Green
    } else if (i == 2) {
      strip.setPixelColor(i, strip.Color(0, 0, 255));     // LED 3: Pure Blue
    } else if (i == 3) {
      strip.setPixelColor(i, strip.Color(255, 255, 255)); // LED 4: Pure White
    }
    
    strip.show();   // Send data packet out to the hardware
    delay(500);     // Wait half a second before jumping to the next LED
  }
}
