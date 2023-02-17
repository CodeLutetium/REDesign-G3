// Motor consts
const int leftDIR = 32;
const int leftStep = 33;
const int rightDIR = 32;
const int rightStep = 33;
const int steps_per_rev = 200;  // For one full rotation. DO NOT CHANGE this value!!!

// Ultrasonic sensor pins
const int frontTrigPin = 23;
const int frontEchoPin = 22;
const int leftTrigPin = 19;
const int leftEchoPin = 18;
const int rightTrigPin = 17;
const int rightEchoPin = 16;

//define sound speed in cm/uS
#define SOUND_SPEED 0.034

// Ultrasonic sensor distance function. Returns distance for the side 
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

void move()
{
  digitalWrite(DIR, LOW);
  while(1)
  {
    digitalWrite(leftStep, HIGH);
    delayMicroseconds(2000);
    digitalWrite(leftStep, LOW);
    delayMicroseconds(2000);
    delay(3000);
  }
}

void setup()
{
  Serial.begin(115200);
  // For motor
  pinMode(leftStep, OUTPUT);
  pinMode(DIR, OUTPUT);
}

void loop()
{
  // CW: HIGH
  // digitalWrite(DIR, LOW);
  // Serial.println("Spinning Clockwise...");
  
  for(int i = 0; i<steps_per_rev; i++)
  {
    digitalWrite(leftStep, HIGH);
    delayMicroseconds(1000);
    digitalWrite(leftStep, LOW);
    delayMicroseconds(1000);
  }
  delay(3000); 
  // move();

  
  // ACW: HIGH
  // digitalWrite(DIR, LOW);
  // Serial.println("Spinning Anti-Clockwise...");

  // for(int i = 0; i<steps_per_rev; i++)
  // {
  //   digitalWrite(leftStep, HIGH);
  //   delayMicroseconds(1000);
  //   digitalWrite(leftStep, LOW);
  //   delayMicroseconds(1000);
  // }
  // delay(1000);
}