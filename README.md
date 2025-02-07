# ESP32-DTB-Converter-1

This is a continuation of my first project:
https://github.com/MickyDa1/Binary-Light-Display-Using-Arduino-Uno-R3/

With this project, I wanted to take my first project and change it slightly to make it availalbe have it functional from another device using my mobile hotspot.

The first thing I did was to switch out the Arduino Uno R3 with the Arduino ESP32. This was quite simple however I tested each light with a simple "Blink" task to ensure that they were all working before continuing the work. 

I then adjusted the inital functions set up to the different Pins, Set the connection specs which I have changed (once I completed the project) and set the web server to open up on port 80

I then put the following changes into effect in the "Void Setup()
- brought the network connectivity information into 
- started a while loop which whilst the connection was not established printed "Connecting to the WiFi"
- defined the route and began the server in which I printed the ESP32 IP adress to the serial monitor

I then created a C file which housed all of my HTML work, the reason I did not make it inital a HTML file was because it needed a C aspect included to thought it would be easier to do it this way.

I then took out the old input syntax (mainly being a user input box and a button) and added a form, The staff memeber supporting me during this project suggested this would be a better idea

I then added code which checks if the input1 (From the HTML.h file) is there, Checks if it has input and if it is true then it will activate the loop once the software has got there, otherwise it wont and the code will be useless.

I then changed the Baud rate in the software from 9600 to 115200 to increase the transmission rate

I finally Changed the const char* username and password to generic versions to keep my hotspot details private.
