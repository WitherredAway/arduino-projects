int buttonPin = 2;
int potPin = A0;

int onPin = 4;
int redPin = 5;
int greenPin = 6;

float maxDelayMS = 15;
float redDelayMS = maxDelayMS;
float greenDelayMS = maxDelayMS - redDelayMS;

int buttonVal;

int potVal = 0;
int add = 0;

int state = HIGH;
int previous = LOW;

unsigned long time = 0;
unsigned long debounce = 200UL;

void setup()
{
    pinMode(buttonPin,  INPUT_PULLUP);
    pinMode(onPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(redPin, OUTPUT);

    Serial.begin(115200);
}

void loop()
{
    buttonVal = digitalRead(buttonPin);
    if (buttonVal == HIGH && previous == LOW && millis() - time > debounce) {
        state = !state;
        Serial.println(state ? "on" : "off");
        time = millis();
    }

    if (state) {
        potVal = max(0, min(1022, potVal + add));
        if (potVal == 1022) {
            add = -10;
        }
        if (potVal == 0) {
            add = 10;
        }

        greenDelayMS = (maxDelayMS / 1023.) * (potVal % 1023);
        redDelayMS = maxDelayMS - greenDelayMS;

        Serial.println(String(potVal) + ": " + String(redDelayMS) + ", " + String(greenDelayMS));

        digitalWrite(onPin, HIGH);

        // Red
        digitalWrite(redPin, LOW);
        digitalWrite(greenPin, HIGH);
        delay(redDelayMS);

        // Green
        digitalWrite(greenPin, LOW);
        digitalWrite(redPin, HIGH);
        delay(greenDelayMS);
    } else {
        digitalWrite(onPin, LOW);
        digitalWrite(redPin, LOW);
        digitalWrite(greenPin, LOW);
    }

    previous = buttonVal;
}