void setup() {
  pinMode(10,OUTPUT);
  pinMode(11,INPUT);
}

void loop() {
  int sensor = !digitalRead(11);
  digitalWrite(10,sensor);
}
