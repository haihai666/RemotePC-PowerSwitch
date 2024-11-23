// Include the necessary libraries for WiFi and web server
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Define the WiFi network credentials
const char* ssid = "your_SSID"; // WiFi SSID
const char* password = "your_PASSWORD"; // WiFi Password

// Set the pin connected to the relay module
const int relayPin = 5; // Change this according to the relay pin used

// Create a web server object on port 80
ESP8266WebServer server(80);

// Function to handle the Power ON request
void handlePowerOn() {
  digitalWrite(relayPin, HIGH);  // Activate relay to power on the PC
  server.send(200, "text/html", "<html><body><h1>PC Power ON</h1></body></html>");
}

// Function to handle the Force Shutdown request (simulate long press)
void handleForceShutdown() {
  digitalWrite(relayPin, LOW); // Simulate pressing the power button
  delay(8000);  // Hold the power button for 8 seconds to force shutdown
  digitalWrite(relayPin, HIGH);  // Release the button (shutdown)
  server.send(200, "text/html", "<html><body><h1>PC Force Shutdown</h1></body></html>");
}

// Function to initialize WiFi and start the server
void setup() {
  // Start the serial communication for debugging
  Serial.begin(115200);
  
  // Connect to WiFi network
  WiFi.begin(ssid, password);
  
  // Wait until the ESP8266 connects to the WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  // Print the ESP8266 IP address after successful connection
  Serial.println("Connected to WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  
  // Initialize the relayPin as an output
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Set relay to HIGH (initially off)

  // Define the routes for the web server
  server.on("/poweron", HTTP_GET, handlePowerOn);
  server.on("/shutdown", HTTP_GET, handleForceShutdown);

  // Start the web server
  server.begin();
}

// Main loop to handle incoming web requests
void loop() {
  server.handleClient();  // Listen for incoming HTTP requests
}
