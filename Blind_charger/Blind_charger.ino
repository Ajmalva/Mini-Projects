int charge;
int full;
int disconnet;
int buzzerPin = 10;
int pirSensorPin = 2;
int crg = 5;
int dis = 6;
int ful = 7;

void setup() {
  Serial.begin(9600);
  charge = 0;
  full = 0;
  disconnet = 0;
  pinMode(buzzerPin, OUTPUT);
  pinMode(crg, OUTPUT);
  pinMode(dis, OUTPUT);
  pinMode(ful, OUTPUT);
  pinMode(pirSensorPin, INPUT);
}

void loop() {
  int offset = 100;
  int Volt = analogRead(A0);
  double Vo = map(Volt, 0, 1024, 0, 2500) - offset;
  Vo /= 100;
  //   Serial.print("V = ");
  //   Serial.print(Vo);
  //   Serial.print("V");
  //   delay(1000);

  float current = 0;
  for (int i = 0; i < 1000; i++) {
    current = current + (.0264 * analogRead(A1) - 13.51) / 100;
    delay(1);
  }
  //   Serial.print("     I = ");
  //   Serial.print(current);
  //   Serial.println(" A");
  //   delay(1000);

  if (current < 0.01 && Vo < 0.01) {
    if (disconnet != 1) {
      //sound 2 beep
      digitalWrite(buzzerPin, HIGH);
      delay(1000);
      digitalWrite(buzzerPin, LOW);
      delay(1000);
      digitalWrite(buzzerPin, HIGH);
      delay(1000);
      digitalWrite(buzzerPin, LOW);
      //light
      digitalWrite(crg, LOW);
      digitalWrite(dis, HIGH);
      digitalWrite(ful, LOW);
      disconnet = 1;
      full = 0;
      charge = 0;
      Serial.println("disconnet");
    }
  }
  if (current < 0.01 && Vo > 0.01) {
    //Motion notification
    if (digitalRead(pirSensorPin) == HIGH) {
      Serial.println("Motion Active");
      //sound 3 beep
      digitalWrite(buzzerPin, HIGH);
      delay(1000);
      digitalWrite(buzzerPin, LOW);
      delay(1000);
      digitalWrite(buzzerPin, HIGH);
      delay(1000);
      digitalWrite(buzzerPin, LOW);
      delay(1000);
      digitalWrite(buzzerPin, HIGH);
      delay(1000);
      digitalWrite(buzzerPin, LOW);
    }
    if (full != 1) {
      //sound 3 beep
      digitalWrite(buzzerPin, HIGH);
      delay(1000);
      digitalWrite(buzzerPin, LOW);
      delay(1000);
      digitalWrite(buzzerPin, HIGH);
      delay(1000);
      digitalWrite(buzzerPin, LOW);
      delay(1000);
      digitalWrite(buzzerPin, HIGH);
      delay(1000);
      digitalWrite(buzzerPin, LOW);
      //light
      digitalWrite(crg, LOW);
      digitalWrite(dis, LOW);
      digitalWrite(ful, HIGH);
      disconnet = 0;
      full = 1;
      charge = 0;
      Serial.println("full Charge");
    }
  }
  if (current > 0.01 && Vo > 0.01) {
    if (charge != 1) {
      //sound 1 beep
      digitalWrite(buzzerPin, HIGH);
      delay(1000);
      digitalWrite(buzzerPin, LOW);
      //light
      digitalWrite(crg, HIGH);
      digitalWrite(dis, LOW);
      digitalWrite(ful, LOW);
      disconnet = 0;
      full = 0;
      charge = 1;
      Serial.println("charging");
    }
  }
}