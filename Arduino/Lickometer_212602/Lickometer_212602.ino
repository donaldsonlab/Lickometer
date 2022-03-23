////////////////////////////////////////////
////// MOST CURRENT VERSION 2/25/21 ///////
//////////////////////////////////////////
#include <Firmata.h>

int IR1 = A0; //Left bottle lick input for Arduino
int IR2 = A1; //Right bottle lick input for Arduino
int IR1_read;
int IR2_read;
byte out1 = 2; //Left bottle lick output for Bonsai
byte out2 = 3;//Right bottle lick output for Bonsai
long startTime;
bool started = false; //Lick flag
int IR1_val;
int IR2_val;
int count = 0;

void setup() {
  Serial.begin(57600);
//  startTime = millis();
//  started = false;
  
  Firmata.setFirmwareVersion(FIRMATA_MAJOR_VERSION, FIRMATA_MINOR_VERSION);
  Firmata.attach(ANALOG_MESSAGE, analogWriteCallback);
  Firmata.begin(57600);
  
  pinMode(IR1, INPUT_PULLUP);
  pinMode(IR2, INPUT_PULLUP);
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
}

void loop() {
  IR1_read = digitalRead(IR1);
  IR2_read = digitalRead(IR2);
//  while(count <75){
//    IR1_read = analogRead(IR1); //read bottle inputs
//    IR2_read = analogRead(IR2);
//    if ((IR1_read >120)){ //if the vole starts licking the left bottle
////      long time1 = millis() - startTime; //Get start time
//      leftValue = 500;
////      String left = "LEFT: ";
////      String result1 = left + time1;
//      Serial.println("HERE 1");
//    }
//      if ((IR2_read >120)){ //if the vole starts licking the left bottle
////      long time2 = millis() - startTime; //Get start time
//      rightValue = 500;
////      String right = "RIGHT: ";
////      String result2 = right + time2;
//      Serial.println("HERE 2");
//    }
//  count += 1;
//  }
if (IR1_read == 0){
  Serial.println("LICK ONE");
  IR1_val = 500;
}
if (IR2_read == 0){
  Serial.println("LICK TWO");
  IR2_val = 500;
}
 Firmata.sendAnalog(out1, IR1_val);
 Firmata.sendAnalog(out2, IR2_val);
  IR1_val = 0;
  IR2_val = 0;
//  count = 0;
//  Serial.println(IR1_read);
//  Serial.println(IR2_read);
//  Serial.println(" ");
}

void analogWriteCallback(byte pin, int value)
{
  pinMode(pin, OUTPUT);
  analogWrite(pin, value);
}
