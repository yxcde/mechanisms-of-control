// Dimm an LED from 0 to full brightness once a Potentiometer is above it's half-way point.  

int ledPin = 11; // Use pin 11 for LED to be able to dimm it 

void setup() {
  pinMode(ledPin, OUTPUT);  // set our ledPin (pin no. 11) to be an output
  pinMode(A0, INPUT);       // ensure A0 works as an input
}

void loop() {
  int potentiometer = analogRead(A0); // read an analog value from pin A0
  // check if the potentimeter is turned up half way and only do something after it has been turned up half way
  if (potentiometer > 511){ 
    // map the value from the potentiometer to the brightness of the LED
    int mapped = map(potentiometer, 511, 1023, 0, 255);
    analogWrite(ledPin, mapped);
  } else {
    // if the potentimeters positions is in the lower half keep the LED switched off
    digitalWrite(ledPin, LOW); 
  }
  
}
