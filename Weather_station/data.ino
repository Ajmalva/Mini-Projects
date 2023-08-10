#include <ESP8266WiFi.h>;

#include <WiFiClient.h>;

#include <ThingSpeak.h>;
#include<dht.h>


#define dht_apin 2 // Analog Pin sensor is connected to
 
dht DHT;

const char* ssid = "ViV0"; //Your Network SSID

const char* password = "12345678"; //Your Network Password

int val;

int val2;


WiFiClient client;

unsigned long myChannelNumber = 1987849; //Your Channel Number (Without Brackets)

const char * myWriteAPIKey = "KS4GBTSNGWH1XSXB"; //Your Write API Key

void setup()

{

Serial.begin(9600);

delay(10);

// Connect to WiFi network

WiFi.begin(ssid, password);



ThingSpeak.begin(client);

}



void loop()

{
     DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    
    delay(5000);//Wait 5 seconds before accessing sensor again.

val =DHT.temperature; //Read Analog values and Store in val variable
val2 =DHT.humidity; //Read Analog values and Store in val variable

Serial.print(val); //Print on Serial Monitor

delay(1000);

ThingSpeak.writeField(myChannelNumber, 2,val, myWriteAPIKey); //Update in ThingSpeak

ThingSpeak.writeField(myChannelNumber, 1,val2, myWriteAPIKey); //Update in ThingSpeak


delay(100);

}
