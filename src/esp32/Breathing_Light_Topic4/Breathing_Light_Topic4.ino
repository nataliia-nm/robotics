const int ledPin = 13; 

// Increase resolution to 12-bit (0 to 4095 steps) for ultra-fine dimming control
const int frequency = 5000;  
const int resolution = 12;   
const int maxPeriod = 4095;  // 2^12 - 1

void setup() {
  ledcAttach(ledPin, frequency, resolution);
}

void loop() {
  // 1. Smoothly Fade In
  for (int i = 0; i <= 100; i++) {
    // Convert 0-100% index into a smooth exponential curve
    int dutyCycle = (pow(i / 100.0, 3) * maxPeriod); 
    ledcWrite(ledPin, dutyCycle);
    delay(20); // Total fade-in time is roughly 2 seconds (100 steps * 20ms)
  }

  // 2. Smoothly Fade Out
  for (int i = 100; i >= 0; i--) {
    // Apply the same curve on the way down so it slows down near zero
    int dutyCycle = (pow(i / 100.0, 3) * maxPeriod); 
    ledcWrite(ledPin, dutyCycle);
    delay(20); 
  }
  
  delay(300); // Tiny rest period at the bottom of the breath
}
