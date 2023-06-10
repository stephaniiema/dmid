int dbutton = 12;
// int aout = A5;
int an0max = 0;
int an0min = 1023;
int an1max = 0;
int an1min = 1023;
int an2max = 0;
int an2min = 1023;
int an3max = 0;
int an3min = 1023;
int an4max = 0;
int an4min = 1023;
int an5max = 0;
int an5min = 1023;
void setup() {
  // put your setup code here, to run once:
  // Serial.begin(9600);
  Serial.begin(115200);
  digitalWrite(LED_BUILTIN, HIGH);
}

int soft = 0;
void loop() {
  // need to map vals to one byte to work right????
  int photoMin = 0;
  int photoMax = 500;
  int bendRMin = 100;
  int bendRMax = 190;
  int bendLMin = 130;
  int bendLMax = 180;
  int softMin = 500;
  int softMax = 1023;
  int an0 = analogRead(A0); // photoresistor
  Serial.write(map(constrain(an0, photoMin, photoMax), photoMin, photoMax, 0, 254));
  int an1 = analogRead(A1); // FSR L
  Serial.write(map(an1, 0, 1023, 0, 254));
  int an2 = analogRead(A2); // FSR R
  Serial.write(map(an2, 0, 1023, 0, 254));
  int an3 = analogRead(A3); // bend R
  Serial.write(map(constrain(an3, bendRMin, bendRMax), bendRMin, bendRMax, 0, 254));
  int an4 = analogRead(A4); // bend L
  Serial.write(map(constrain(an4, bendLMin, bendLMax), bendLMin, bendLMax, 0, 254));
  int an5 = analogRead(A5); //softpot
  if (an5 > softMin){
    soft = an5;
  }
  Serial.write(map(constrain(soft, softMin, softMax), softMin, softMax, 0, 254));

  int button = digitalRead(dbutton);
  Serial.write(button);
  Serial.write(255); // terminating signal
}
