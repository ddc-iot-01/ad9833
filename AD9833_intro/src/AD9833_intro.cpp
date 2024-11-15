/* 
 * Project myProject
 * Author: Your Name
 * Date: 
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"
#include "AD9833.h"
#include "math.h"

SYSTEM_MODE(SEMI_AUTOMATIC);

const int AD9833_FSYNC = D5;
const int MASTER_CLOCK = 25000000;
const int MODE_SINE = 0;
unsigned long frequency;
unsigned long t;

AD9833 sineGen(AD9833_FSYNC, MASTER_CLOCK);

void setup() {
  Serial.begin(9600);
  Serial.printf("Starting Serial Monitor...\n");
  delay(5000);

  frequency = 1000; // initial frequency 1KHz

  sineGen.reset(1);           // Place ad9833 into reset
  sineGen.setFreq(frequency); // Set initial frequency to 1 KHz
  sineGen.setPhase(0);        // Set initial phase offset to 0
  sineGen.setFPRegister(1);
  sineGen.setFreq(frequency);
  sineGen.setPhase(0);
  sineGen.setFPRegister(0);
  sineGen.mode(MODE_SINE);    // Set output mode to sine wave
  sineGen.reset(0);           // Take ad9833 out of reset



}

void loop() {


  frequency = (int)(1000. * sin(millis()/2000.) + 10000.);

  sineGen.setFreq(frequency);

  // for(int i = 1; i <= 10; i++){
  //   sineGen.setFreq(frequency * i);
  //   delay(1000);
  // }

}
