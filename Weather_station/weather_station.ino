

#include<dht.h>
#include <ThingSpeak.h>;

#include <ESP8266WiFi.h>
 
String myWriteAPIKey = "KS4GBTSNGWH1XSXB";     //  Enter your Write API key from ThingSpeak

const char *ssid =  "ViV0";     // replace with your wifi ssid and wpa2 key
const char *pass =  "12345678";
const char* server = "api.thingspeak.com";

#define dht_apin 0          //pin where the dht11 is connected
unsigned long myChannelNumber = 1987849; //Your Channel Number (Without Brackets)
 
dht DHT;

WiFiClient client;
 
void setup() 
{
       Serial.begin(115200);
       delay(10);
      
 
       Serial.println("Connecting to ");
       Serial.println(ssid);
 
 
       WiFi.begin(ssid, pass);
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
      ThingSpeak.begin(client);
 
}
 
void loop() 
{
  DHT.read11(dht_apin);
      float h = DHT.humidity;
      float t = DHT.temperature;
      
              if (isnan(h) || isnan(t)) 
                 {
                     Serial.println("Failed to read from DHT sensor!");
                      return;
                 }

                         if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             ThingSpeak.writeField(myChannelNumber, 1,t, myWriteAPIKey); //Update in ThingSpeak
                        }
          client.stop();
 
          Serial.println("Waiting...");
  
  // thingspeak needs minimum 15 sec delay between updates, i've set it to 30 seconds
  delay(10000);
}
