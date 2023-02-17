const int frontTrigPin = 23;
const int frontEchoPin = 22;
const int leftTrigPin = 19;
const int leftEchoPin = 18;
const int rightTrigPin = 17;
const int rightEchoPin = 16;

//define sound speed in cm/uS
#define SOUND_SPEED 0.034

long duration;
float distanceCm;
float distanceInch;

// Side: 1, 2, 3 corresponds to left, front, right
float distance(int side)
{
  int trigPin;
  int echoPin;
  switch(side)
  {
    case 1:
      trigPin = leftTrigPin;
      echoPin = leftEchoPin;
      break;

    case 2:
      trigPin = frontTrigPin;
      echoPin = frontEchoPin;
      break;
    
    case 3:
      trigPin = rightTrigPin;
      echoPin = rightEchoPin;
      break;

    // Error
    default: 
      Serial.println("Error: invalid dist");
      return 9999;
  }

  // Clear the trig pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  return duration * SOUND_SPEED/2;
}

void setup() {
  Serial.begin(115200); // Starts the serial communication
  pinMode(frontTrigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(frontEchoPin, INPUT); // Sets the echoPin as an Input
  pinMode(leftTrigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(leftEchoPin, INPUT); // Sets the echoPin as an Input
  pinMode(rightTrigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(rightEchoPin, INPUT); // Sets the echoPin as an Input
}

void loop() {
  // Prints the distance in the Serial Monitor
  Serial.print("Distance left (cm): ");
  Serial.println(distance(3));
  
  delay(1000);
}
