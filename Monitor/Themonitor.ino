#define HRM_PIN 36       // ECG signal input on SENSOR_VP (GPIO36)
#define BUZZER_PIN 26    // GPIO26 for buzzer
#define RED_PIN 14       // GPIO14 for Red LED
#define GREEN_PIN 27     // GPIO27 for Green LED
#define YELLOW_PIN 25    // GPIO25 for Yellow LED

unsigned long lastPeakTime = 0; // Time of the last detected peak
unsigned long currentTime = 0;
int threshold = 4000; // Threshold for peak detection 
int lastValue = 0;

void setup() {
  Serial.begin(115200); 
  pinMode(HRM_PIN, INPUT); 
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);

  Serial.println("Heart Rate Monitor with LEDs and Buzzer");
}

void loop() {
  int ecgValue = analogRead(HRM_PIN); 
  currentTime = millis();            

  // Peak detection: Current value exceeds the threshold and is greater than the last value
  if (ecgValue > threshold && ecgValue > lastValue) {
    unsigned long timeSinceLastPeak = currentTime - lastPeakTime; 
    if (timeSinceLastPeak > 500) { 
      lastPeakTime = currentTime; 
      float bpm = 60000.0 / timeSinceLastPeak; 

      Serial.print("Heart Rate: ");
      Serial.print(bpm);
      Serial.println(" BPM");

      if (bpm < 40) { // Low heart rate
        digitalWrite(BUZZER_PIN, HIGH); 
        digitalWrite(RED_PIN, LOW);
        digitalWrite(GREEN_PIN, LOW);
        digitalWrite(YELLOW_PIN, HIGH);
      } else if (bpm >= 40 && bpm <= 100) { // Normal heart rate
        digitalWrite(BUZZER_PIN, LOW); 
        digitalWrite(RED_PIN, LOW);
        digitalWrite(GREEN_PIN, HIGH);
        digitalWrite(YELLOW_PIN, LOW);
      } else { // High heart rate
        digitalWrite(BUZZER_PIN, HIGH); 
        digitalWrite(RED_PIN, HIGH);
        digitalWrite(GREEN_PIN, LOW);
        digitalWrite(YELLOW_PIN, LOW);
      }
    }
  }

  lastValue = ecgValue; 
  delay(10); 
}
