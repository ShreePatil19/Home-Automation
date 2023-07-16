#include <IRremote.h>
int RECV_PIN = 10;
int relay1 = 2;
int relay2 = 6;
int relay3 = 4;
int relay4 = 5;

int relayState[] = {0,0,0,0,0}; //the initial state of relays
#define code1 0x40BD00FF
#define code2 0x40BD807F
#define code3 0x40BD40BF
#define code4 0x40BDC03F

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
irrecv.enableIRIn(); // Start the receiver
pinMode(relay1, OUTPUT);
pinMode(relay2, OUTPUT);
pinMode(relay3, OUTPUT);
pinMode(relay4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
switch(value) {
case code1:
Serial.println("relay 1 is working");
if(relayState[1] == 0) {
digitalWrite(relay1, HIGH);
relayState[1] = 1;
}
else {
digitalWrite(relay1, LOW);
relayState[1] = 0;
}
break;
case code2:
Serial.println("relay 2 is working");
if(relayState[2] == 0) {
digitalWrite(relay2, HIGH);
relayState[2] = 1;
} 
else {
digitalWrite(relay2, LOW);
relayState[2] = 0;
}
break;
case code3:
Serial.println("relay 3 is working");
if(relayState[3] == 0) {
digitalWrite(relay3, HIGH);
relayState[3] = 1;
} 
else {
digitalWrite(relay3, LOW);
relayState[3] = 0;
}
break;
case code4:
Serial.println("relay 4 is working");
if(relayState[4] == 0) {
digitalWrite(relay4, HIGH);
relayState[4] = 1;
} else {
digitalWrite(relay4, LOW);
relayState[4] = 0;
}
break;
}
irrecv.resume();
 
  }
}
