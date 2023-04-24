#include <WiFiCracker.h>

WiFiCracker::WiFiCracker() {
  cracked = false;
}

void WiFiCracker::crack(const char* ssid, const char* password) {
  // Initialize the variables
  int attempts = 0;
  bool found = false;

  // Start the brute force attack
  while (!found && attempts < 1000000) {
    // Generate a random password
    char randomPassword[10];
    for (int i = 0; i < 10; i++) {
      randomPassword[i] = (char)('a' + rand() % 10);
    }

    // Check if the password is correct
    if (strcmp(randomPassword, password) == 0) {
      // The password is correct!
      found = true;
      cracked = true;
      strcpy(this->password, randomPassword);
    }

    // Increment the number of attempts
    attempts++;
    Serial.print("Total Attp:");
    Serial.println(attempts);
    Serial.print("PAss:");
    Serial.println(randomPassword);
  }
  
}

bool WiFiCracker::isCracked() {
  return cracked;
}

const char* WiFiCracker::getPassword() {
  return password;
}


// Dictionary attack method
// void WiFiCracker::dictionaryAttack(const char* ssid, const char* dictionary) {
//   // Initialize the variables
//   int attempts = 0;
//   bool found = false;

//   // Start the dictionary attack
//   for (char* word : dictionary) {
//     // Check if the password is correct
//     if (strcmp(word, password) == 0) {
//       // The password is correct!
//       found = true;
//       cracked = true;
//       strcpy(this->password, word);
//       break;
//     }

//     // Increment the number of attempts
//     attempts++;
//   }
// }


// Man-in-the-middle attack method
void WiFiCracker::manInTheMiddleAttack(const char* ssid) {
  // Initialize the variables
  WiFiClient client;
  WiFiServer server(80);

  // Start the server
  server.begin();

  // Wait for a client to connect
  while (!client.available()) {
    delay(100);
  }

  // Start the man-in-the-middle attack
  client.print("HTTP/1.1 200 OK\r\n");
  client.print("Content-Type: text/html\r\n\r\n");
  client.print("<html><head><title>WiFi Cracking</title></head><body><h1>WiFi Cracking</h1><p>This is a WiFi cracking tool.</p><form action=\"/crack\" method=\"post\">");
  client.print("<input type=\"text\" name=\"ssid\" value=\"");
  client.print(ssid);
  client.print("\" size=\"32\">");
  client.print("<input type=\"submit\" value=\"Crack\">");
  client.print("</form></body></html>");

  // Wait for the client to submit the form
  while (!client.available()) {
    delay(100);
  }

  // Get the password from the form
  char password[32];
  client.readBytes(password, 32);

  // Crack the password
  crack(ssid, password);

  // Send the result to the client
  client.print("HTTP/1.1 200 OK\r\n");
  client.print("Content-Type: text/plain\r\n\r\n");
  client.print(password);

  // Close the connection
  client.stop();
}

// Wireless network mapping method
// void WiFiCracker::wirelessNetworkMapping() {
//   // Initialize the variables
//   int networks = 0;
//   WiFiScanResults results;

//   // Start the wireless network mapping
//   WiFi.scanNetworks(&results);

//   // Iterate over the results
//   for (WiFiScanResult result : results) {
//     // Print the network information
//     Serial.print("SSID: ");
//     Serial.println(result.SSID);
//     Serial.print("BSSID: ");
//     Serial.println(result.BSSID);
//     Serial.print("Channel: ");
//     Serial.println(result.channel);
//     Serial.print("RSSI: ");
//     Serial.println(result.RSSI);
//     Serial.print("Encryption: ");
//     Serial.println(result.encryption);

//     // Increment the number of networks
//     networks++;
//   }

//   // Print the number of networks
//   Serial.print("Number of networks found: ");
//   Serial.println(networks);
// }

