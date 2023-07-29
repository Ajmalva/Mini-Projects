/*
 * Hello world web server
 * circuits4you.com
 */
 #include<dht.h>


#define dht_apin 2 // Analog Pin sensor is connected to
 
dht DHT;
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

//SSID and Password to your ESP Access Point
const char* ssid = "MyServer";
const char* password = "12345678";

ESP8266WebServer server(80); //Server on port 80

//==============================================================
//     This rutine is exicuted when you open its IP in browser
//==============================================================
void handleRoot() {
  server.send(200, "text/plain", "hello boss!");
}

//===============================================================
//                  SETUP
//===============================================================
String page = "";
double h;
double t;
void setup(void){
  Serial.begin(9600);
  Serial.println("");
  WiFi.mode(WIFI_AP);           //Only Access point
  WiFi.softAP(ssid, password);  //Start HOTspot removing password will disable security

  IPAddress myIP = WiFi.softAPIP(); //Get IP address
  Serial.print("HotSpt IP:");
  Serial.println(myIP);
 
  server.on("/", [](){
    page = "<h1>Sensor to Node MCU Web Server</h1><h3>Data:</h3> <h4>"+String(h)+"</h4><h4>"+String(t)+"</h4>";
    server.send(200, "text/html", page);
  });   //Which routine to handle at root location

  server.begin();                  //Start server
  Serial.println("HTTP server started");
  
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
}
//===============================================================
//                     LOOP
//===============================================================
void loop(void){
  DHT.read11(dht_apin);
    h=DHT.humidity;
    t=DHT.temperature;
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    
    delay(5000);//Wait 5 seconds before accessing sensor again.
  server.handleClient();          //Handle client requests
}
