README for Embedded Fitness Project

This program is a fitness program of 10 repetition of situps, pushups, jumping jacks. The Adafruit Classic Playground microcontroller is 
used to record and detect body movements using the accelerometer.The microcontroller needs to be attached at the tricept area of the arm with usb cable pointing downward.

How to Use it:
Left button (#4) is used to start/stop the exercise, with Neopixel#4 indicating stop with red and start with blue.
The Right button (#19） is used to select which exercise the user to start with. Neopixel #0-#3 is used to indicate selected exercise movemnt squat, situp,pushup, 
and jumping jacks respectively.
Beeping sound is to indicate one repetition of the selected exercise is complete.
The Neopixel #9-#6 is light up to blue to indicate a complete set of 10 repetition is complete for squat, situp,pushup, and jumping jacks respectively.
The program will not stop the user if the user wants to continue when 10 repition is complete. Beeping soud would still indicate a complete movement, but user can not 
know how many completed without looking at the Serial Monitor.
If the user finished 10 repetition of the 4 exercise, the program is stopped and the a music is played to celebrate the progress.

Code:
The program uses 16220 bytes (56%) of program storage space. Maximum is 28672 bytes.
Global variables use 1121 bytes of dynamic memory.

The code is seprated in to four files
fitness.ino is the main file of the program; It contains the setup and main loop and functions that uses the Adafruit_CircuitPlayground.h package.
function.h is the header file for function.c.
function.c contains the 4 functions analyzing the input signal for the 4 exercises.
pitches.h has the notes defined from https://www.arduino.cc/en/Tutorial/ToneMelody, which is used in the fitness.ino as a celebration music for compelte the entire workout.
