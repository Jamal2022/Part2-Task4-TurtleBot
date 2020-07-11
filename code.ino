const int pingPin = 13;
 
int inPinForward = 2;
int inPinBackward = 3;
int inPinRight = 4;
int inPinLeft = 5;
// establish variables for duration of the ping, and the distance result
// in inches and centimeters:
long duration, inches, cm;


void setup()
{
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  //PushButton
  pinMode(inPinForward, INPUT);
  pinMode(inPinBackward, INPUT);
  pinMode(inPinRight, INPUT);
  pinMode(inPinLeft, INPUT);
  Serial.begin(9600);
}

void Backward(){
  digitalWrite(9, HIGH);
  }

void Forward(){
  digitalWrite(8, HIGH);
  digitalWrite(10, HIGH);
  }
  
void Right(){
  digitalWrite(8, LOW);
  digitalWrite(10, HIGH);
  }

void Left(){
  digitalWrite(8, HIGH);
  digitalWrite(10, LOW);
  }

void Stop(){
  digitalWrite(8, LOW);
  digitalWrite(10, LOW);
  }
void loop()
{
  // establish variables for duration of the ping, and the distance result
  // in inches and centimeters:
  long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  /*Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();*/

  //delay(100);
  if(cm > 10){
    Right();
    Serial.println("Sensor");
    }
  else{
      if (digitalRead(inPinForward)==LOW){
        Forward();
        Serial.println("Forward");
      }
      else if (digitalRead(inPinBackward)==LOW){
        Backward();
        Serial.println("Backward");
      }
      else if (digitalRead(inPinRight)==LOW){
        Right();
        Serial.println("Right");
      }
      else if (digitalRead(inPinLeft)==LOW){
        Left();
        Serial.println("Left");
      }
      else{
      Stop();
      }
    }
  
}
long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are 73.746
  // microseconds per inch (i.e. sound travels at 1130 feet per second).
  // This gives the distance travelled by the ping, outbound and return,
  // so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
