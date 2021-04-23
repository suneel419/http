#include<Arduino.h>
#include<WiFi.h>
#include<HTTPClient.h>

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
Serial.println();

for(uint8_t t=4;t>0;t--)
{
  Serial.printf("[SETUP] Wait %d...\n",t);
  Serial.flush();
  delay(1000);
}
WiFi.begin("sunil","8790225440");
}

void loop() {
  // put your main code here, to run repeatedly:
if(WiFi.status() == WL_CONNECTED)
{
  HTTPClient http;
  Serial.print("[HTTP] begin ...\n");
  http.begin("http://api.thingspeak.com/channels/272149/fields/1");
  //http.begin("https://io.adafruit.com/sunil_419/dashboards/sunil");
  Serial.print("HTTP Get ...\n");
  int httpcode=http.GET();

    Serial.printf("[HTTP] GET... code:%d\n",httpcode);

    if(httpcode==HTTP_CODE_OK)
    {
      String myadata=http.getString();
      Serial.println(myadata);
      
    }
    else
    {
      Serial.printf("[HTTP] GET Failed, Error:%d",httpcode);
      
    }
    http.end();
  delay(15000);
}
}
