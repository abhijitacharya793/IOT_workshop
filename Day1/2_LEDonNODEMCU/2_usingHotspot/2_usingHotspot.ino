#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char *ssid = "test";
const char *password = "passwords";

#define LED 16

ESP8266WebServer server(80);
//---------------------------------------------------------------
//Three pages for turning led on and off
//---------------------------------------------------------------

void handleRoot() {
 Serial.println("You called root page");
 String a = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}

void handleLEDon() { 
 Serial.println("LED on page");
 String a_on = ON_page;
 digitalWrite(LED,LOW); //LED is connected in reverse
 server.send(200, "text/html", s_on); //Send ADC value only to client ajax request
}

void handleLEDoff() { 
 Serial.println("LED off page");
 String a_off = OFF_page;
 digitalWrite(LED,HIGH); //LED off
 server.send(200, "text/html", s_off); //Send ADC value only to client ajax request
}

void setup() {
delay(1000);
Serial.begin(115200);
Serial.println();
Serial.print("Configuring access point...");
WiFi.softAP(ssid, password);
IPAddress myIP = WiFi.softAPIP();
Serial.print("AP IP address: ");
Serial.println(myIP);

//---------------------------------------------------------------
//server.on functions
//---------------------------------------------------------------

server.begin();
Serial.println("HTTP server started");
}

void loop() {
server.handleClient();
}
