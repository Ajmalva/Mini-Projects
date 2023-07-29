#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>



// Set these to run example.
#define FIREBASE_HOST "datatest-f1b73-default-rtdb.asia-southeast1.firebasedatabase.app"
#define FIREBASE_AUTH "615JT7QoWIYYEYhxNxMVS7aqCaiJOQ4qRp7kXOl2"
#define WIFI_SSID "Keralavision FTTh250"
#define WIFI_PASSWORD "ajmal9286"

//Define Firebase Data objects
FirebaseData firebaseData1;
//FirebaseData firebaseData2;

//GPIO4 or D2 for LED
const int swPin = 5;  //GPIO5 or D1 for Switch
bool swState = false;
String path = "/";
String nodeID = "Node1";      //This is this node ID to receive control
 //This is other node ID to control

void setup()
{

    Serial.begin(9600);

    

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(300);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();

    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Firebase.reconnectWiFi(true);

    if (!Firebase.beginStream(firebaseData1, path + "/" + nodeID))
    {
        Serial.println("Could not begin stream");
        Serial.println("REASON: " + firebaseData1.errorReason());
        Serial.println();
    }
    else
    {
      Serial.println("begin stream");
      }

      pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
}

void loop()
{
    if (!Firebase.readStream(firebaseData1))
    {
        Serial.println();
        Serial.println("Can't read stream data");
        Serial.println("REASON: " + firebaseData1.errorReason());
        Serial.println();
    }

    if (firebaseData1.streamTimeout())
    {
        Serial.println();
        Serial.println("Stream timeout, resume streaming...");
        Serial.println();
    }

    if (firebaseData1.streamAvailable())
    {
      Serial.println(firebaseData1.dataType());
        if (firebaseData1.dataType() == "boolean")
        {
          Serial.println(firebaseData1.boolData());
            if (firebaseData1.boolData()==1)
                {
                  Serial.println("Set " + nodeID + " to High");
                  digitalWrite(LED_BUILTIN, LOW);
                }
            else
                {
                Serial.println("Set " + nodeID + " to Low");
                digitalWrite(LED_BUILTIN, HIGH);}
                
        }
    }
}
