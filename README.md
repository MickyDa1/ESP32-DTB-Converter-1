# ESP32-DTB-Converter-1

This is a continuation of my first project:
https://github.com/MickyDa1/Binary-Light-Display-Using-Arduino-Uno-R3/tree/master

With this project, I wanted to take my first project and change ti slightly to make it availalbe have it functional from another device using my mobile hotspot.

THe first thing I did was to switch out the Arduino Uno R3 with the Arduino ESP32. This was quite simple however I tested each light with a simple "Blink" task to ensure that they were all working before continuing the work. 

I then adjusted the inital functions set up to the different Pins, Set the connection specs which i have changed (once i completed the project) and set the web server to open up on port 80

i then put the following changes into effect in the "Void Setup()
- brought the network connectivity information into 
- started a while loop which whilst the connection was not established printed "Connecting to the WiFi"
- defined the route and began the server in which I printed the ESP32 IP adress to the serial monitor



