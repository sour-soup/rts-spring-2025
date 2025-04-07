const int INTERRUPT_PIN = 3;
const int SAMPLE_SIZE = 1000;

volatile uint32_t count = 0;
volatile uint32_t mean_total = 0;
volatile float deviation_total = 0;
uint32_t previous_time = 0;

void setup() {
    Serial.begin(9600);
    pinMode(INTERRUPT_PIN, INPUT);
    attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), onInterrupt, HIGH);
}

void loop() {
    if (count >= SAMPLE_SIZE) {
        noInterrupts();
        print_result();
        count = 0;
        mean_total = 0;
        deviation_total = 0;
        previous_time = micros();
        interrupts();
    }
}

void onInterrupt() {
    uint32_t now = micros();
    uint32_t delta = now - previous_time;
    
    mean_total += delta;
    deviation_total += float(delta) * delta;
    count++;
    
    previous_time = now;
}

void print_result() {
    float mean = mean_total / float(SAMPLE_SIZE);
    float deviation = deviation_total / (SAMPLE_SIZE) - float(mean) * mean;
    
    Serial.print("Mean: ");
    Serial.print(mean);
    Serial.print(" us, Avg. Sq. Deviation: ");
    Serial.print(sqrt(deviation));
    Serial.println(" us");
}