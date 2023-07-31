#define in 5
#define out 3
int a=0,b=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  a = digitalRead(in);
  b = digitalRead(out);
  Serial.print("Iin");
  Serial.println(a);
  Serial.print("oout");
  Serial.println(b);
  
}
