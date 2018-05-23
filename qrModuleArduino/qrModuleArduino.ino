#include <Servo.h>

Servo servol;           // Controls steering
Servo esc;              // Controls power train

int SpectrumLeft[7];    // 7 frequencies
int SpectrumRight[7];   // 7 frequencies
int SpectrumBand;
int SpectrumStrobe = 9; // Strobe for the MSGEQ7 chip
int SpectrumReset  = 10;// Reset for the MSGEQ7 chip

int threshold      = 700;

int car_cha_a      = 0;
int car_cha_b      = 0;
int car_cha_c      = 0;
int car_cha_d      = 0;

bool DEBUG         = true;

void setup ()
{
  Serial.begin(9600);
  pinMode(SpectrumReset, OUTPUT);
  pinMode(SpectrumStrobe, OUTPUT);
  servol.attach(3);
  esc.attach(5);
}

void loop ()
{
  // Read in the data from MSGEQ7
  digitalWrite(SpectrumReset, HIGH);
  digitalWrite(SpectrumReset, LOW);
  delayMicroseconds(30);
  for(SpectrumBand = 0; SpectrumBand < 7; SpectrumBand++)
  {
    digitalWrite(SpectrumStrobe, HIGH);
    digitalWrite(SpectrumStrobe, LOW);
    delayMicroseconds(30);
    SpectrumLeft[SpectrumBand] = analogRead(4);
    SpectrumRight[SpectrumBand] = analogRead(5);
  }

  for(SpectrumBand = 0; SpectrumBand < 2; SpectrumBand++)
  {
    if (DEBUG) {
        Serial.print(SpectrumLeft[SpectrumBand]);
        Serial.print(" ");
        Serial.print(SpectrumRight[SpectrumBand]);
        Serial.print("|");
    }
    if (SpectrumBand == 0) {
       car_cha_a = SpectrumLeft[SpectrumBand];
       car_cha_b = SpectrumRight[SpectrumBand];
    } else if (SpectrumBand == 1) {
       car_cha_c = SpectrumLeft[SpectrumBand];
       car_cha_d = SpectrumRight[SpectrumBand];
    }
  }
  processData(  car_cha_a > threshold,
                car_cha_b > threshold,
                car_cha_c > threshold,
                car_cha_d > threshold);
  delay(4);
}

void setSpeed(int speed){
  int angle = map(speed, 0, 100, 65, 95); //Set servo to a position for different speed
  esc.write(angle);
}

void processData(bool cha, bool chb, bool chc, bool chd) {
    if (!cha) { // low
        servol.write(100); //Center position
        if (DEBUG) Serial.print("Center");
    } else {
       // left and right
      if (chb) {
          servol.write(150); // Right position
          if (DEBUG) Serial.print("Right");
      } else {
          servol.write(65); // Left position
          if (DEBUG) Serial.print("Left");
      }
    }

    if (!chc) {
      // Stop
      setSpeed(50); // Stop
      if (DEBUG) Serial.print(" Stop");
    } else {
      if (chd) {
        // Forward for high
        setSpeed(0); // Forward
        if (DEBUG) Serial.print(" Forward");
      } else {
        // Reverse for low
        setSpeed(100); // Reverse
        if (DEBUG) Serial.print(" Reverse");
      }
    }
    if (DEBUG) Serial.println("");
}
