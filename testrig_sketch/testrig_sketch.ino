/*
  This uses something like blink to cycle through the 32 leds  
  Turns on an LED on for a half  second, then off for a half second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards. 
// Pin 11 has the LED on Teensy 2.0
// Pin 6  has the LED on Teensy++ 2.0
// Pin 13 has the LED on Teensy 3.0
// name the connections from the arduion mega to the 26 pin header on the test rig 

#define LONG_DELAY  2000
#define SHORT_DELAY 500

int L01 = 17;
int L02 = 18;
int L03 = 19;
int L04 = 20;
int L05 = 21;
int L06 = 22;
int L07 = 23;
int L08 = 24;
int L09 = 25;
int L10 = 26;
int L11 = 27;
int L12 = 28;
int L13 = 29;
int L14 = 2;
int L15 = 3;
int L16 = 4;
int L17 = 5;
int L18 = 6;
int L19 = 7;
int L20 = 8;
int L21 = 9;
int L22 = 10;
int L23 = 11;
int L24 = 14;
int L25 = 15;
int L26 = 16;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(L01, OUTPUT);     
  pinMode(L02, OUTPUT);     
  pinMode(L03, OUTPUT);     
  pinMode(L04, OUTPUT);     
  pinMode(L05, OUTPUT);     
  pinMode(L06, OUTPUT);     
  pinMode(L07, OUTPUT);     
  pinMode(L08, OUTPUT);     
  pinMode(L09, OUTPUT);     
  pinMode(L10, OUTPUT);     
  pinMode(L11, OUTPUT);     
  pinMode(L12, OUTPUT);     
  pinMode(L13, OUTPUT);     
  pinMode(L14, OUTPUT);     
  pinMode(L15, OUTPUT);     
  pinMode(L16, OUTPUT);     
  pinMode(L17, OUTPUT);     
  pinMode(L18, OUTPUT);     
  pinMode(L19, OUTPUT);     
  pinMode(L20, OUTPUT);     
  pinMode(L21, OUTPUT);     
  pinMode(L22, OUTPUT);     
  pinMode(L23, OUTPUT);     
  pinMode(L24, OUTPUT);     
  pinMode(L25, OUTPUT);     
  pinMode(L26, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(20, LOW);    // turn the LED off by making the voltage LOW
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p02, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p03, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p04, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p05, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p06, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p07, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p08, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p09, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p10, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p11, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p12, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p13, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p14, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p15, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p16, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p17, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p18, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p19, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p20, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p21, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p22, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p23, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p24, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p25, LOW);
  delay(SHORT_DELAY);               // wait for SHORT_DELAY seconds
  digitalWrite(20way_p26, LOW);
  delay(LONG_DELAY);               // wait for SHORT_DELAY seconds
// make this into a variable for future versions with user selectable delay
//periods
}
