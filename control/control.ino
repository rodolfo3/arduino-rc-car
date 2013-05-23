// the setup routine runs once when you press reset:
int a9, a10, a11, a12;

void setup() {                
  // initialize the digital pin as an output.
  pinMode(9, OUTPUT);     
  pinMode(10, OUTPUT);     
  pinMode(11, OUTPUT);     
  pinMode(12, OUTPUT);     

  Serial.begin(9600);
  
  a9 = HIGH;
  a10 = HIGH;
  a11 = HIGH;
  a12 = HIGH;
}

// the loop routine runs over and over again forever:
void loop() {
  while (Serial.available() > 0) {
    int value = Serial.read() - 48;
    a9 = value & 0b0001  ? LOW : HIGH;
    a10 = value & 0b0010 ? LOW : HIGH;
    a11 = value & 0b0100 ? LOW : HIGH;
    a12 = value & 0b1000 ? LOW : HIGH;

    Serial.println(value, DEC);
  }
  
  digitalWrite(9, a9);
  digitalWrite(10, a10);
  digitalWrite(11, a11);
  digitalWrite(12, a12);  
}
