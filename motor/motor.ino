const int DIR = 32;
const int STEP = 33;
const int steps_per_rev = 200;  // For one full rotation. DO NOT CHANGE this value!!!

void move()
{
  digitalWrite(DIR, LOW);
  while(1)
  {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(2000);
    digitalWrite(STEP, LOW);
    delayMicroseconds(2000);
    delay(3000);
  }
}

void setup()
{
  Serial.begin(115200);
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);
}

void loop()
{
  // CW: HIGH
  // digitalWrite(DIR, LOW);
  // Serial.println("Spinning Clockwise...");
  
  for(int i = 0; i<steps_per_rev; i++)
  {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(1000);
    digitalWrite(STEP, LOW);
    delayMicroseconds(1000);
  }
  delay(3000); 
  // move();

  
  // ACW: HIGH
  // digitalWrite(DIR, LOW);
  // Serial.println("Spinning Anti-Clockwise...");

  // for(int i = 0; i<steps_per_rev; i++)
  // {
  //   digitalWrite(STEP, HIGH);
  //   delayMicroseconds(1000);
  //   digitalWrite(STEP, LOW);
  //   delayMicroseconds(1000);
  // }
  // delay(1000);
}