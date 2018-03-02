// buttons. index position refers to LED array
int buttons[] = { 2, 3, 4, 5, 6, 7, 8, 9 };

int num_buttons = 8;

// Master Reset button
int reset = 10;

// LEDs - must have same number of elements as buttons
int leds[] = { 11, 12, A0, A1, A2, A3, A4, A5, A6 };

// Are we latched?
boolean latched = false;
int current_led = 0;

// buzzer
int buzzer = 13;

void setup() {
  int i;
  
  for (i = 0; i < num_buttons; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i],LOW);
  }
  
  pinMode(reset, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
}

// the loop routine runs over and over again forever:
void loop() {
  if (latched) {
    if (digitalRead(reset) == LOW) {
      latched = false;
      digitalWrite(current_led, LOW);
    }
  }
  else {
    int i;
    
    for (i = 0; i < num_buttons; i++) {
      if (digitalRead(buttons[i]) == LOW) {
        // button pressed!
        latched = true;
        digitalWrite(leds[i], HIGH);
        current_led = leds[i];
        // sound buzzer
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        break;
      }
    }
  }
}
