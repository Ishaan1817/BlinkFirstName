
const int ledPin = LED_BUILTIN;  //Selected pin for builtin LED
const int buttonPin = 2;  //Pin for push button

// Morse code representation of the letters in your first name
const char* morseI = "..";
const char* morseS = "...";
const char* morseH = "....";
const char* morseA = ".-";
const char* morseA2 = ".-"; // Repeating "A" for "ISHAAN"
const char* morneN = "-.";

// Delay times for dot, dash, and space in Morse code
const int dotDelay = 500;
const int dashDelay = 3 * dotDelay;
const int letterSpaceDelay = 3 * dotDelay;
const int wordSpaceDelay = 7 * dotDelay;

// Variables to track button state
int buttonState = HIGH;
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  

  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
       
        blinkMorse(morseI);
        blinkMorse(morseS);
        blinkMorse(morseH);
        blinkMorse(morseA);
        blinkMorse(morseA2);
        blinkMorse(morneN);
        
        // Add a word space at the end
        delay(wordSpaceDelay);
        
        
        digitalWrite(ledPin, LOW);
        buttonState = HIGH;
        lastButtonState = HIGH;
      }
    }
  }

  lastButtonState = reading;
}

void blinkMorse(const char* morseCode) {
  for (int i = 0; morseCode[i] != '\0'; i++) {
    if (morseCode[i] == '.') {
      digitalWrite(ledPin, HIGH);
      delay(dotDelay);
      digitalWrite(ledPin, LOW);
      delay(dotDelay);
    } else if (morseCode[i] == '-') {
      digitalWrite(ledPin, HIGH);
      delay(dashDelay);
      digitalWrite(ledPin, LOW);
      delay(dotDelay);
    }
  }

  delay(letterSpaceDelay);
}
