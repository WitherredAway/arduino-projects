int potPin = A0;
int greenPin = 2;
int yellowPin = 3;
int redPin = 4;
float potVal;
float voltage;

void setup() {
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);
  voltage = (5. / 1023.) * potVal;
  Serial.println(voltage);

  if (voltage < 3) {
    digitalWrite(greenPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, LOW);
  }
  if (voltage > 3 && voltage < 5) {
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(redPin, LOW);
  }
  if (voltage == 5) {
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, HIGH);
  }
}
