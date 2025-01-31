#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <html.h>

//Put function declarations here:
int myFunction(int, int);

//Sets Up the LED
int ledPin1 = 13;
int ledPin2 = 12;
int ledPin3 = 14;
int ledPin4 = 27;
int ledPin5 = 26;
int ledPin6 = 25;
int ledPin7 = 33;
int ledPin8 = 32;
int pinArray[] = {13, 12, 14, 27, 26, 25, 33, 32};
String userInput;
boolean runLoop;

// Sets the network connection Specs
const char* ssid = "mman"; // Change it to Own Device
cons`t char* password = "LongLane123"; // Change it to own Device

//Opens Port for the Web Server at port 80
AsyncWebServer server(80);

void setup() {

  // Connect to Wi-Fi (takes the const from above and uss them)
  WiFi.begin(ssid, password);
  // Starts a While Loop
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  
  // Define a route to serve the HTML page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    Serial.println("ESP32 Web Server: New request received:");  // for debugging
    Serial.println("GET /");        // for debugging

    // Sets Up the Website To Input binary Number
    request->send(200, "text/html",HTML_STRING);});

  // Start the server
  server.begin();
  
  delay(1000);

  // Print the ESP32's IP address
  Serial.print("ESP32 Web Server's IP address: ");
  Serial.println(WiFi.localIP());

Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);

  for (int i = 0; i <= 8; i++) {
    digitalWrite(pinArray[i], HIGH);
    delay(100);
    digitalWrite(pinArray[i], LOW);
  }

  runLoop = false;
  
  Serial.println("please Enter a number between 1 and 255");
  Serial.print("ESP32 Web Server's IP address: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
if (Serial.available())
  {
    Serial.println("Start");
    userInput = Serial.readString();
    Serial.print("You Typed: ");
    Serial.println(userInput);

    runLoop = true;
  }

  while (runLoop == true) {

      int userInputInt = userInput.toInt();

      if (userInputInt >= 256 || userInputInt <= 0) {
        Serial.println("Error - Your Number is to HIGH or to LOW, Please Try Again");
        userInputInt = 0;
        runLoop = false;    
        Serial.println("please Enter a number between 1 and 255");
        break;
      }
    
      for (int i = 0; i < 8; i++)
      {

        if (userInputInt > 0) {
          int light = userInputInt % 2;

          if (light == 1){
            digitalWrite(pinArray[i], HIGH);
            Serial.println("High");
          } else if (light == 0){
            digitalWrite(pinArray[i], LOW);
            Serial.println("Low");
          }

          userInputInt /= 2;
        } else {
          digitalWrite(pinArray[i], LOW);
        }
      }
    Serial.println("please Enter a number between 1 and 255");
    runLoop = false;    
    }

}