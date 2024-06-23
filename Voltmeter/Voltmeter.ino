int readPin = A0;
int readVal;
float V2;
int delayMs = 100;

float originalV = 5.;
float maxRead = 1023.;

void setup() {
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  readVal = analogRead(readPin);
  V2 = (originalV / maxRead) * readVal;
  Serial.println(V2);
  delay(delayMs);
}
