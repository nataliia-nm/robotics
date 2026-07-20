// Project 2.2: Table Lamp - Toggle Logic with Debounce
#define btn1 16 
#define led_y 13 
boolean ledState = false;

void setup() {
  pinMode(btn1, INPUT);
  pinMode(led_y, OUTPUT);
  digitalWrite(led_y, LOW);
}

void loop() {
  if (digitalRead(btn1) == 0) { 
    delay(10);
    if (digitalRead(btn1) == 0) { 
      ledState = !ledState;
      digitalWrite(led_y, ledState ? HIGH : LOW);
      while (digitalRead(btn1) == 0) { delay(10); }
    }
  }
}
