// Pin definitions
// Left sensor
const int trigPin1 = 2;
const int echoPin1 = 3;
const int motor1 = 4;

// Center sensor
const int trigPin2 = 5;
const int echoPin2 = 6;
const int motor2 = 7;

// Right sensor
const int trigPin3 = 8;
const int echoPin3 = 9;
const int motor3 = 10;

long duration;
int distance;

void setup() {
  // Serial for debugging
  Serial.begin(9600);
  
  // Set trig pins as output
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  
  // Set echo pins as input
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  
  // Set motor pins as output
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
}

void loop() {
  // Left
  int distance1 = getDistance(trigPin1, echoPin1);
  if (distance1 > 0 && distance1 <= 50) {
    digitalWrite(motor1, HIGH);
  } else {
    digitalWrite(motor1, LOW);
  }

  // Center
  int distance2 = getDistance(trigPin2, echoPin2);
  if (distance2 > 0 && distance2 <= 50) {
    digitalWrite(motor2, HIGH);
  } else {
    digitalWrite(motor2, LOW);
  }

  // Right
  int distance3 = getDistance(trigPin3, echoPin3);
  if (distance3 > 0 && distance3 <= 50) {
    digitalWrite(motor3, HIGH);
  } else {
    digitalWrite(motor3, LOW);
  }

  delay(100);  // small delay
}

// Function to calculate distance
int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);  // timeout 30ms

  // Calculate distance in cm
  int distance = duration * 0.034 / 2;
  if (duration == 0) return -1; // error
  return distance;
}