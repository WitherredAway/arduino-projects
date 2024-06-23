const int zero = 2;
const int one = 3;
const int two = 4;
const int three = 5;

void clearLeds() {
  digitalWrite(zero, LOW);
  digitalWrite(one, LOW);
  digitalWrite(two, LOW);
  digitalWrite(three, LOW);
}

void setup() {
  pinMode(zero, OUTPUT);
  pinMode(one, OUTPUT);
  pinMode(two, OUTPUT);
  pinMode(three, OUTPUT);

}

void loop() {
  // 0
  delay(1000);
  clearLeds();

  // 1
  digitalWrite(zero, HIGH);
  delay(1000);
  clearLeds();

  // 2
  digitalWrite(one, HIGH);
  delay(1000);
  clearLeds();

  // 3
  digitalWrite(zero, HIGH);
  digitalWrite(one, HIGH);
  delay(1000);
  clearLeds();

  // 4
  digitalWrite(two, HIGH);
  delay(1000);
  clearLeds();

  // 5
  digitalWrite(two, HIGH);
  digitalWrite(zero, HIGH);
  delay(1000);
  clearLeds();

  // 6
  digitalWrite(two, HIGH);
  digitalWrite(one, HIGH);
  delay(1000);
  clearLeds();

  // 7
  digitalWrite(two, HIGH);
  digitalWrite(one, HIGH);
  digitalWrite(zero, HIGH);
  delay(1000);
  clearLeds();

  // 8
  digitalWrite(three, HIGH);
  delay(1000);
  clearLeds();

  // 9
  digitalWrite(three, HIGH);
  digitalWrite(zero, HIGH);
  delay(1000);
  clearLeds();

  // 10
  digitalWrite(three, HIGH);
  digitalWrite(one, HIGH);
  delay(1000);
  clearLeds();

  // 11
  digitalWrite(three, HIGH);
  digitalWrite(one, HIGH);
  digitalWrite(zero, HIGH);
  delay(1000);
  clearLeds();

  // 12
  digitalWrite(three, HIGH);
  digitalWrite(two, HIGH);
  delay(1000);
  clearLeds();

  // 13
  digitalWrite(three, HIGH);
  digitalWrite(two, HIGH);
  digitalWrite(zero, HIGH);
  delay(1000);
  clearLeds();

  // 14
  digitalWrite(three, HIGH);
  digitalWrite(two, HIGH);
  digitalWrite(one, HIGH);
  delay(1000);
  clearLeds();

  // 15
  digitalWrite(three, HIGH);
  digitalWrite(two, HIGH);
  digitalWrite(one, HIGH);
  digitalWrite(zero, HIGH);
  delay(1000);
  clearLeds();
}
