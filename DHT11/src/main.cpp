#include <DHT.h>
#include <LiquidCrystal.h>

const int setTime = 500;
const int interval = 1000;
const int eyeOpenDuration = interval * 11 / 12;

const int sensorPin = 2;

DHT dht(sensorPin, DHT11);
int humidity;
int tempC;

const int RS = 7;
const int E = 8;
const int D4 = 9;
const int D5 = 10;
const int D6 = 11;
const int D7 = 12;

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
bool connectedBefore = false;
int displayColumns[] = { 0, 9 };

// Custom character bytes
byte dot[8] = {
    B00011,
    B00011,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
};
byte droplet[8] = {
    B00100,
    B00100,
    B01110,
    B01110,
    B11111,
    B11111,
    B01110,
    B00000,
};
byte openEye[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B01100,
    B01100,
    B00000,
};
byte closedEye[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B01100,
    B00000,
};
byte frown1[8] = {
    B00111,
    B01000,
    B10000,
    B10000,
    B00000,
    B00000,
    B00000,
    B00000,
};
byte frown2[8] = {
    B11111,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
};
byte frown3[8] = {
    B11100,
    B00010,
    B00001,
    B00001,
    B00000,
    B00000,
    B00000,
    B00000,
};
byte smile1[8] = {
    B10000,
    B10000,
    B01000,
    B00111,
    B00000,
    B00000,
    B00000,
    B00000,
};
byte smile2[8] = {
    B00000,
    B00000,
    B00000,
    B11111,
    B00000,
    B00000,
    B00000,
    B00000,
};
byte smile3[8] = {
    B00001,
    B00001,
    B00010,
    B11100,
    B00000,
    B00000,
    B00000,
    B00000,
};

void display(int col, int row, const String element) {
  lcd.setCursor(col, row);
  lcd.print(element);
}

void display(int col, int row, const byte element) {
  lcd.setCursor(col, row);
  lcd.write(element);
}

void display(int col, int row, const byte* element) {
  size_t length = sizeof(element) / sizeof(element[0]);
  lcd.setCursor(col, row);
  for (size_t i = 0; i < length; ++i) {
    lcd.write(element[i]);
  }
}

void displayLines(const int colIndex, const String line1, const String line2 = "") {
  int col = displayColumns[colIndex];
  display(col, 0, line1);
  if (line2) {
    display(col, 1, line2);
  }
}

void displayFace(byte* mouth1, byte* mouth2, byte* mouth3) {
  lcd.createChar(3, mouth1);
  lcd.createChar(4, mouth2);
  lcd.createChar(5, mouth3);
  display(13, 1, byte(3));
  display(14, 1, byte(4));
  display(15, 1, byte(5));

  // Open eyes
  display(13, 0, byte(1));
  display(15, 0, byte(1));
  delay(eyeOpenDuration);

  // Closed eyes
  display(13, 0, byte(2));
  display(15, 0, byte(2));
  delay(interval - eyeOpenDuration);
}

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);

  lcd.createChar(0, dot);
  lcd.createChar(6, droplet);
  lcd.createChar(1, openEye);
  lcd.createChar(2, closedEye);

  Serial.println("Hello, World!");
  displayLines(0, "Hello,", "World!");

  for (int i = 0; i < 3; i++) { // Blink 3 times
    displayFace(smile1, smile2, smile3);
  }
}

void loop() {
  bool connected = dht.read();

  if (connectedBefore != connected) {
    lcd.clear();
    connectedBefore = connected;
  }

  if (!connected) {
    Serial.println("Sensor Not Found");
    displayLines(0, "Sensor Not", "Found");
    displayFace(frown1, frown2, frown3);
    return;
  }

  humidity = round(dht.readHumidity());
  tempC = round(dht.readTemperature());

  String tempString = String(tempC) + char(223) + "C";
  String humidityString = String(humidity) + "%";

  Serial.println(tempString + " — " + humidityString);

  // Temp and Humidity
  displayLines(0, "Temp.", "Humidity");
  displayLines(1, tempString, humidityString);
  lcd.write(byte(6));

  displayFace(smile1, smile2, smile3);
}