#include <Adafruit_CircuitPlayground.h>
#include "function.h"
#include "pitches.h"

//Variables
float X, Y, Z = 0;
float squat_num = 0;
float* SQUAT;
float situp_num = 0;
float* SITUP;
float pushup_num = 0;
float* PUSHUP;
float jumpjack_num = 0;
float* JACKS;
int state = 0;
int* STATE;
int movement = 0;
int* MOVEMENT;
bool start = false;
const int numNotes = 8;           // number of notes we are playing
int melody[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4 }; // specific notes in the melody
int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4 };// note durations: 4 = quarter note, 8 = eighth note, etc.:

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  STATE = &state;
  SQUAT = &squat_num;
  PUSHUP = &pushup_num;
  SITUP = &situp_num;
  JACKS = &jumpjack_num;
  MOVEMENT = &movement;
  CircuitPlayground.setPixelColor(movement, 0, 255, 0);
}

void loop() {
   if (CircuitPlayground.rightButton()==1){ 
    //select exercise
    if (movement <3){ 
      CircuitPlayground.setPixelColor(movement, 0, 0, 0);
      movement++;
    }else{ 
      CircuitPlayground.setPixelColor(movement, 0, 0, 0);
      movement = 0; 
      }
     CircuitPlayground.setPixelColor(movement, 0, 255, 0);
    delay(500);
   }
    
  if (CircuitPlayground.leftButton()==1){
      start = !start;
      delay(500);
  }
  
  if (start == false){
      CircuitPlayground.setPixelColor(4, 255, 0, 0);
  }else{
      CircuitPlayground.setPixelColor(4, 0, 0, 255);
  }

  if (start == true){
    //start the exercise
    acc_read(); //read accelerametor 
    if (movement == 0){ //squat excercise
      sound(squat(X,SQUAT, STATE));
      increment(movement, squat_num);
    }else if (movement == 1){ //situp excercise
      sound(situp(X, Y, STATE, SITUP));
      increment(movement, situp_num);
    }else if (movement == 2){ //pushup excercise
      sound(pushup(X, Y, STATE, PUSHUP));
      increment(movement, pushup_num);
    }else if (movement == 3){ //jumping jacks excercise
        sound(jjacks(X, Y, Z, STATE,JACKS));
        increment(movement, jumpjack_num);
    }
    if ((squat_num >=20)&&(situp_num >=20)&&(pushup_num>=20)&&(jumpjack_num>=20)){
      victory_music();
      start = false;
    }
  }
  display(movement);
}//main loop closed

void sound(int num){
  //play beeping sound when one repetition is complete
  if (num == 2){
    CircuitPlayground.playTone(500, 100);
  }
}

void acc_read(){
  //read in the accelerametor 
  X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();
  Z = CircuitPlayground.motionZ();
}

void increment(int movement, float number){
  //ligh up Green Neopixel if complete one set
  if (number/2 == 10){
      if (movement == 0){
        CircuitPlayground.setPixelColor(9, 0, 0, 255);
      }else if (movement == 1){
        CircuitPlayground.setPixelColor(8, 0, 0, 255);
      }else if (movement == 2){
        CircuitPlayground.setPixelColor(7, 0, 0, 255);
      }else if (movement == 3){
        CircuitPlayground.setPixelColor(6, 0, 0, 255);
  }
    }  
}

void display(int movement){
  //print the current values for each movement
  Serial.print("X: ");
  Serial.print(X);
  Serial.print("  Y: ");
  Serial.print(Y);
  Serial.print("  Z: ");
  Serial.println(Z);
  Serial.print("movement:");
  Serial.println(movement);
  if (movement == 0){
    Serial.print("squat number: ");
    Serial.println(truncf(squat_num/2));
  }else if (movement == 1){
    Serial.print("situp number: ");
    Serial.println(truncf(situp_num/2));
  }else if (movement == 2){
    Serial.print("push number: ");
    Serial.println(truncf(pushup_num/2));
  }else if (movement == 3){
    Serial.print("jumping jacks number: ");
    Serial.println(truncf(jumpjack_num/2));
  }
}

void victory_music(){
  //play this music when the workout is finished.
  //code from https://www.arduino.cc/en/Tutorial/ToneMelody.
  for (int thisNote = 0; thisNote < numNotes; thisNote++) { // play notes of the melody
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      CircuitPlayground.playTone(melody[thisNote], noteDuration);
      // to distinguish the notes, set a minimum time between them.
      //   the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      }
}
