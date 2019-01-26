#include <Adafruit_CircuitPlayground.h>

float X, Y, Z;

int stepCount=0;
int totalSteps=20; //total steps needed before the sound will go off
int blinkOn = (totalSteps / 10); //totalSteps should be divided by the number of LEDs
int neoPixelTrainStation = 0;

void setup() {
  // put your setup code here, to run once:
      Serial.begin(9600);
      CircuitPlayground.begin();
      CircuitPlayground.clearPixels();

}


void loop() {
  // put your main code here, to run repeatedly:
  
  
  Z = CircuitPlayground.motionZ();

  //if statement controls threshold for when to count a step, based on Z axis motion.
  //Recommend range of (Z < -5) to (Z < 0), depending on range of motion. Hello_Accelerometer
  //helped us determine a basic data pattern when we started the project.
  if (Z < -5) {
    stepCount++;
    Serial.println("  Z:  ");
    Serial.println(Z);
    Serial.println(stepCount);

    //delay between checks
    delay(300);

    if (stepCount > blinkOn){
      Serial.println("one LED lit");
      CircuitPlayground.setPixelColor(neoPixelTrainStation, 255, 0, 0); //red
      neoPixelTrainStation++;
      stepCount=0;
    };

    if (neoPixelTrainStation > 9){
      Serial.println("You're done!");
      CircuitPlayground.playTone(440, 500);
      CircuitPlayground.clearPixels();
      neoPixelTrainStation=0;
    };

    
  };
};
