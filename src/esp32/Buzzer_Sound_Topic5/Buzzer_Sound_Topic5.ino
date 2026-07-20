/* 
  Hedwig's Theme - Corrected Pitch & Rhythm
  Wiring: S Pin -> Connect to ESP32 Pin 13
*/

const int buzzerPin = 13; 

// Base Pitches (Lowered back down, resolving correctly)
#define NOTE_D4  294
#define NOTE_G4  392
#define NOTE_AS4 466
#define NOTE_A4  440
#define NOTE_D5  587
#define NOTE_C5  523
#define NOTE_F4  349
#define NOTE_GS4 415
#define REST      0

// Adjusted tempo to lock into the true 3/8 swing meter
int tempo = 124; 

// The corrected motif: Notice the downward ending (F4 then D4) 
// and fixed note weights (-8 means a dotted eighth note)
int melody[] = {
  NOTE_D4, 8,                        // Upbeat pickup
  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4, // Phrase 1
  NOTE_G4, 2,  NOTE_D5, 4,
  NOTE_C5, -2,
  NOTE_A4, -2,
  
  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4, // Phrase 2 (Resolves DOWN)
  NOTE_F4, 2,  NOTE_GS4, 4,             // Corrected transition notes
  NOTE_D4, -2,                          // Drops low to finish the motif correctly!
  REST, 2                               // Breath rest before repeating
};

int totalNotes = sizeof(melody) / sizeof(melody[0]);

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // A whole note length calculation based on our 3/8 base rhythm
  int wholenote = (60000 * 4) / tempo;

  for (int thisNote = 0; thisNote < totalNotes; thisNote = thisNote + 2) {
    int currentNote = melody[thisNote];
    int noteDivider = melody[thisNote + 1];
    int noteDuration = 0;

    // Strict musical timing for standard vs. dotted values
    if (noteDivider > 0) {
      noteDuration = (wholenote) / noteDivider;
    } else if (noteDivider < 0) {
      noteDuration = (wholenote) / abs(noteDivider) * 1.5; // Dotted calculations
    }

    if (currentNote != REST) {
      // 85% note duration leaves a crisp staccato gap, essential for the magical feel
      tone(buzzerPin, currentNote, noteDuration * 0.85);
    } else {
      noTone(buzzerPin);
    }

    delay(noteDuration);
    noTone(buzzerPin);
  }

  // Exact 2-second wait between loops
  delay(2000); 
}
