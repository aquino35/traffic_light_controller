#include "msp430.h"
// Osvaldo Aquino
// Script for MSP430 one-lane traffic controller 

// TRAFFIC LIGHT 1 = TL1
int TL1_G = 5;     /* Pin P1.0 = 1 -> GREEN */
int TL1_Y = 7;     /* Pin P1.5 = 1 -> YELLOW */
int TL1_R = 9;     /* Pin P1.4 = 1 -> RED */

// TRAFFIC LIGHT 2 = TL2
int TL2_G = 19;     /* Pin P1.7 = 1 -> GREEN */
int TL2_Y = 15;     /* Pin P2.4 = 1 -> YELLOW */
int TL2_R = 13;     /* Pin P2.7 = 1 -> RED */

int traffic_delay = 6000; // delay that is applied before each case switch

void setup() {
  // Setting PINS FOR BOTH TRAFFIC LIGHTS:
  pinMode(TL1_G,OUTPUT),pinMode(TL1_Y, OUTPUT),pinMode(TL1_R, OUTPUT); // TL1
  pinMode(TL2_G,OUTPUT),pinMode(TL2_Y, OUTPUT),pinMode(TL2_R, OUTPUT); // TL2
}

void loop() {traffic_controller();}

void traffic_controller(){
  // Method that handles the states necessary for traffic controller
  int state=1;
  switch(state){
    case 1:
    digitalWrite(TL1_G, HIGH), digitalWrite(TL2_R, HIGH), delay(traffic_delay);

    case 2:
    digitalWrite(TL1_Y, HIGH), digitalWrite(TL1_G, LOW), delay(traffic_delay);

    case 3:
    digitalWrite(TL1_R, HIGH), digitalWrite(TL1_Y, LOW), delay(traffic_delay);
    
    case 4:
    digitalWrite(TL2_G, HIGH), digitalWrite(TL2_R, LOW), delay(traffic_delay);
    
    case 5:
    digitalWrite(TL2_Y, HIGH), digitalWrite(TL2_G, LOW), delay(traffic_delay);
    
    case 6:
    digitalWrite(TL2_R, HIGH), digitalWrite(TL2_Y, LOW), delay(traffic_delay);

    case 7:
    digitalWrite(TL1_R, LOW),digitalWrite(TL1_G, HIGH), delay(traffic_delay);
  }
}