#include <WiFi.h>
#include <WiFiCracker.h>

WiFiCracker cracker; 

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  
cracker.crack("PowerSolution", "p@wers0lution2020"); 

  while (!WiFi.isConnected()) {
    delay(500);
    Serial.print(".");
  }


  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  
}

void loop() {
  if (cracker.isCracked()) {
    Serial.println("Password cracked!");
    cracker.getPassword();
    return;
  }
}
