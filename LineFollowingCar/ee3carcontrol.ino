#define lM 5
#define rM 6
#define ptransL 19
#define ptransC 18
#define ptransR 17
#define ledL 2
#define ledC 3
#define ledR 4
int valR = 0;
int valC = 0;
int valL = 0;
char currState = 'A';
long zeroR;
long zeroC;
long zeroL;

int rPow = 0;
int lPow = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(lM, OUTPUT);
  pinMode(rM, OUTPUT);
  pinMode(ptransL, INPUT);
  pinMode(ptransC, INPUT);
  pinMode(ptransR, INPUT);
  pinMode(ledL, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledR, OUTPUT);
  
  zeroR = 0;
  zeroC = 0;
  zeroL = 0;
  
  for (int i = 0;i<100;i++){
    zeroR += analogRead(ptransR);
    zeroC += analogRead(ptransC);
    zeroL += analogRead(ptransL);
  }
  zeroR /= 100;
  zeroC /= 100;
  zeroL /= 100;
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  valR = analogRead(ptransR);
  valC = analogRead(ptransC);
  valL = analogRead(ptransL);

  

  valR = constrain (map (valR, 0, zeroR, 0, 255), 0, 255);
  valC = constrain (map (valC, 0, zeroC, 0, 255), 0, 255);
  valL = constrain (map (valL, 0, zeroL, 0, 255), 0, 255);

  

  Serial.print("right voltage: "); //white: 1023, black: 1021-1022
  Serial.println(valR);
  //Serial.print("right init: "); //white: 1023, black: 1021-1022
  //Serial.println(zeroR);
  Serial.print("center voltage: ");//white: 1022, black: 1020-1021
  Serial.println(valC);
  //Serial.print("center init: "); //white: 1023, black: 1021-1022
  //Serial.println(zeroC);
  Serial.print("left voltage: "); //white: 1023, black: 1021-1022
  Serial.println(valL);
  //Serial.print("left init: "); //white: 1023, black: 1021-1022
  //uSerial.println(zeroL);
  
  
  // STOP
  // If L, R, C see black
  if ( currState == 'S' || (valR < 200 && valC < 150 && valL < 220)) {
    //Serial.print("STOP // NONE");
    analogWrite(lM, 0);
    analogWrite(rM, 0);
    digitalWrite(ledL, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledR, HIGH); 
    currState = 'S';
  }
  // RIGHT TURN
  // If R sees black, L sees white
  if ( currState == 'R' || (currState != 'S' &&(valR < 200 && valL >= 200))) {
    //Serial.print("RIGHT // RED");
    analogWrite(lM, 140);
    analogWrite(rM, 0);
    digitalWrite(ledR, HIGH);
    digitalWrite(ledL, LOW);
    digitalWrite(ledC, LOW);
    currState = 'R';
  }
  // STRAIGHT LINE
  // If C sees black, R, L see white
  if ( currState == 'A' || (currState != 'S' && (valR >= 200 && valC < 150 && valL >= 220))) {
    //Serial.print("STRAIGHT // GREEN");
    analogWrite(lM, 140);
    analogWrite(rM, 130); 
    digitalWrite(ledL, LOW);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledR, LOW);
    currState = 'A';
  }
  // LEFT TURN
  // If L sees black, R sees white
  if ( currState == 'L' || (currState != 'S' && (valL < 220 && valR >= 200))) {
    //Serial.print("LEFT // BLUE");
    analogWrite(lM, 0);
    analogWrite(rM, 130);
    digitalWrite(ledL, HIGH);
    digitalWrite(ledC, LOW);
    digitalWrite(ledR, LOW);
    currState = 'L';
  }
}

