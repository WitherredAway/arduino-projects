int yellowLED = 6;
int redLED = 9;

int yellowDelayMs = 500;
int redDelayMs = 500;

int i;
int j;
int yellowBlink = 5;
int redBlink = 3;

void setup() {
    pinMode(yellowLED, OUTPUT);
    pinMode(redLED, OUTPUT);
}

void loop() {
    for (i = 1; i <= yellowBlink; i++) {
        digitalWrite(yellowLED, HIGH);
        delay(yellowDelayMs);
        digitalWrite(yellowLED, LOW);
        delay(yellowDelayMs);
    }

    for (i = 1; i <= redBlink; i++) {
        digitalWrite(redLED, HIGH);
        delay(redDelayMs);
        digitalWrite(redLED, LOW);
        delay(redDelayMs);
    }
}