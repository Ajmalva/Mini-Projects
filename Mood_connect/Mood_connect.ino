#include <WiFiManager.h>
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include <WS2812FX.h>

#define LED_COUNT 4
#define LED_PIN 2
 String val;
 int Mod=0;
 int bright=100;
 int sped=1000;
unsigned long col;
volatile bool set=true;


WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// Provide the token generation process info.
#include <addons/TokenHelper.h>

// Provide the RTDB payload printing info and other helper functions.
#include <addons/RTDBHelper.h>

/* 2. Define the API Key */
#define API_KEY "AIzaSyCXzTTckAJmUZnqac0jp3yFIl7HUr4D9HM"

/* 3. Define the RTDB URL */
#define DATABASE_URL "https://moodconnect-d362e-default-rtdb.firebaseio.com" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app

/* 4. Define the user Email and password that alreadey registerd or added in your project */
#define USER_EMAIL "test@user.com"
#define USER_PASSWORD "12345678"

// Define Firebase Data object
FirebaseData fbdo;
FirebaseData stream;

FirebaseAuth auth;
FirebaseConfig config;

String parentPath = "/";
String childPath[2] = {"/aju", "/common"};

//StaticJsonBuffer<200> jsonBuffer;

int count = 0;

volatile bool dataChanged = false;

void streamCallback(MultiPathStreamData stream)
{
  dataChanged = true;
}

void streamTimeoutCallback(bool timeout)
{
  if (timeout)
    Serial.println("stream timed out, resuming...\n");

  if (!stream.httpConnected())
    Serial.printf("error code: %d, reason: %s\n\n", stream.httpCode(), stream.errorReason().c_str());
}

void setup()
{

  Serial.begin(115200);
  
  ws2812fx.init();
  ws2812fx.setColor(0xffffff);
  ws2812fx.setBrightness(100);
  ws2812fx.setSpeed(1000);
  ws2812fx.setMode(FX_MODE_RUNNING_RANDOM);
  ws2812fx.start();

  WiFiManager wM;

  bool res;
    // res = wM.autoConnect(); // auto generated AP name from chipid
     res = wM.autoConnect("Mood Connect"); // anonymous ap
   // res = wM.autoConnect("AutoConnectAP","password"); // password protected ap

    if(!res) {
        Serial.println("Failed to connect");
        ws2812fx.setMode(FX_MODE_STATIC);
        // ESP.restart();
    } 
    else {
        //if you get here you have connected to the WiFi    
        Serial.println("connected...yeey :)");
    }

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the user sign in credentials */
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h

  // To connect without auth in Test Mode, see Authentications/TestMode/TestMode.ino

  Firebase.begin(&config, &auth);

  Firebase.reconnectWiFi(true);

  // Recommend for ESP8266 stream, adjust the buffer size to match your stream data size
#if defined(ESP8266)
  stream.setBSSLBufferSize(2048 /* Rx in bytes, 512 - 16384 */, 512 /* Tx in bytes, 512 - 16384 */);
#endif

  // The data under the node being stream (parent path) should keep small
  // Large stream payload leads to the parsing error due to memory allocation.

  // The MultiPathStream works as normal stream with the payload parsing function.

  if (!Firebase.beginMultiPathStream(stream, parentPath))
    Serial.printf("sream begin error, %s\n\n", stream.errorReason().c_str());

  Firebase.setMultiPathStreamCallback(stream, streamCallback, streamTimeoutCallback);

//  Firebase.getInt(fbdo, F("/test/int")) ? String(fbdo.to<int>()).c_str() : fbdo.errorReason().c_str()
}

void loop()
{
  ws2812fx.service();

  if(set){
    if(millis()>=15016){

      if(Firebase.getString(fbdo, F("/common/color"))){
          String ival=fbdo.to<String>();
          char* end;
          unsigned long col = strtol(ival.c_str(), &end, 0);
           ws2812fx.setColor(col);
            }
            
          if(Firebase.getInt(fbdo, F("/aju/bright"))){
                 bright=fbdo.to<int>();
              ws2812fx.setBrightness(bright);
             }

             if(Firebase.getInt(fbdo, F("/common/effect"))){
                 Mod=fbdo.to<int>();
              ws2812fx.setMode(Mod);
             }

             if(Firebase.getInt(fbdo, F("/aju/speed"))){
                 sped=fbdo.to<int>();
               ws2812fx.setSpeed(sped);
             }
             set=false;
      }
    }

  if (dataChanged)
  {
    dataChanged = false;

          if(Firebase.getString(fbdo, F("/common/color"))){
          String ival=fbdo.to<String>();
          char* end;
          unsigned long col = strtol(ival.c_str(), &end, 0);
           ws2812fx.setColor(col);
         //  Serial.print("set color : ");
         //  Serial.println(ival);
            }
            
          if(Firebase.getInt(fbdo, F("/aju/bright"))){
                 bright=fbdo.to<int>();
              ws2812fx.setBrightness(bright);
             // Serial.print("set brightness: ");
             // Serial.println(bright);
             }

             if(Firebase.getInt(fbdo, F("/common/effect"))){
                 Mod=fbdo.to<int>();
              ws2812fx.setMode(Mod);
             // Serial.print("set mode : ");
             // Serial.println(Mod);
             }

             if(Firebase.getInt(fbdo, F("/aju/speed"))){
                 sped=fbdo.to<int>();
               ws2812fx.setSpeed(sped);
             }
    }
}
