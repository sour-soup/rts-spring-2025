const int N = 5;
const int pins[] = { 3, 5, 6, 9, 10 };
const unsigned long pulseDuration[] = { 10000, 1000, 500, 100, 50 };
unsigned long lastToggleTime[N];
bool pinState[N];


void setup() {
  for (int i = 0; i < N; ++i)
    pinMode(pins[i], OUTPUT);
}

void loop() {
  for (int i = 0; i < N; ++i) {
    unsigned long currentTime = micros();
    if (2 * (currentTime - lastToggleTime[i]) >= pulseDuration[i]) {
      pinState[i] ^= 1;
      digitalWrite(pins[i], pinState[i]);
      lastToggleTime[i] = currentTime;
    }
  }
}
