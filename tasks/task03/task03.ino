unsigned int delay0 = 10000;
unsigned int delay1 = 1000;
unsigned int delay2 = 500;
unsigned int delay3 = 100;
unsigned int delay4 = 50;

unsigned int previous0 = 0;
unsigned int previous1 = 0;
unsigned int previous2 = 0;
unsigned int previous3 = 0;
unsigned int previous4 = 0;


void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() { 
  unsigned int currentMicros = micros();
  if (currentMicros - previous0 >= delay0) {
      PORTD ^= (1 << PD3);
      previous0 = currentMicros;
  } 
  if (currentMicros - previous1 >= delay1) {
      PORTD ^= (1 << PD5);
      previous1 = currentMicros;
  } 
  if (currentMicros - previous2 >= delay2) {
      PORTD ^= (1 << PD6);
      previous2 = currentMicros;
  } 
  if (currentMicros - previous3 >= delay3) {
      PORTB ^= (1 << PB1);
      previous3 = currentMicros;
  } 
  if (currentMicros - previous4 >= delay4) {
      PORTB ^= (1 << PB2);
      previous4 = currentMicros;
  } 
}