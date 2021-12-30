#######################################################
We are creating automated aqua farming monitoring system here in our project. Its basically an IoT based project. 
########################################################


## Components Required:
Arduino uno
pH sensor
DTH11
Turbidty sensor
Relay
ESP8266-3(NodeMCU)
Bread Board
LED
Jump wires for connecting the components.

## ML Algorithms:
* In this folder we have the ipynb files for logistic regression and Naïve Bayes algorithms which were used to predict the water quality using the the dataset file Sensor_dataset.csv

## Project Codes:
* In this folder, all the c files that are used in this project are attached.
  The IDE used is Arduino IDE.

## Steps to follow:

# Hadware:

* Take a jumper wire and connect 5v power supply from arduino to bread board, now take another jumper and connect the ground terminal of arduino uno to breadboard again.

* We are doing this step, as we need power supply port and ground port for multiple components.

* Here pH and turbidity sensors are analog sensors so, it should be connected to the analog pins in the Arduino board(A0-A5) and the DTH11 sensor should be connected to digital pin 2 in the Arduino board using breadboard and jump wires.

* Relay is taken as the input to digital pin 7 of Arduino board, LED as the output in the Arduino board and coded the program using if conditions for all three sensors in such a way that the LED glows whenever the digital pin 7 reads high i.e., when the relay is triggered.

* Once that connection is done, install arduino ide software and connect your arduino board with your Laptop[using USB AB cable] where you have installed the arduino ide software. 

* In arduino ide software go to -> tools -> board and make sure your arduino board is connected to the software.

* After the previous step is done each sensor is connected to one ESP8266 to upload the data into ThingSpeak. 

* pH and turbidity sensors shoudl be connected to the A0 pin using breadboard and DTH11 to D4 pin in ESP8266. 

* All three sensors are integrated as shown in Circuit.jpeg image with the help of the Arduino board which is programmed with the Arduino IDE. 

* The codes that are supposed to use are in Project codes file please refer to them.

# ThingSpeak:

* A channel should be created in ThingSpeak platform - for which we need an account in MathWorks.

* Four fields should be created in the channel and name them accordingly.

# Notification:

* In order to get the notification we used IFTTT app in which webhooks and Android sms services are used. There the conditions should be given accordingly and the user get messages whenever the conditions are met.

* We need to create a new Thing HTTP and a new React as well for which a detailed explanation is provided in Video Demonstration.txt file

NOTE: In our project we connected pH sensor and turbidty sensor data pins to Arduino Uno A0 and A3 pins respectively. 
      Similarly DTH11 data pin is connected to Digital pin 2 in Arduino Uno. 

