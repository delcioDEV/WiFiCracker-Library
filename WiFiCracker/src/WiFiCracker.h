// This is the header file for the WiFiCracker class.
// It contains the declarations for the class's methods and variables.

#ifndef WIFI_CRACKER_H
#define WIFI_CRACKER_H

#include <stdint.h>
#include "WiFi.h"
#include "Print.h"
#include "IPAddress.h"
#include "IPv6Address.h"

#include "WiFiType.h"
#include "WiFiSTA.h"
#include "WiFiAP.h"
#include "WiFiScan.h"
#include "WiFiGeneric.h"

#include "WiFiClient.h"
#include "WiFiServer.h"
#include "WiFiUdp.h"

#include <Arduino.h>

// This class represents a WiFi cracker.
// It can be used to crack the password of a wireless network.

class WiFiCracker {
  public:
    // This constructor initializes the class.
    WiFiCracker();

    // This method cracks the password of a wireless network.
    // The `ssid` parameter is the name of the network, and the `password` parameter is the password that is being tried.
    void crack(const char* ssid, const char* password);

    // This method performs a dictionary attack on a wireless network.
    // The `ssid` parameter is the name of the network, and the `dictionary` parameter is a list of words that are being tried.
    void dictionaryAttack(const char* ssid, const char* dictionary);

    // This method performs a man-in-the-middle attack on a wireless network.
    // The `ssid` parameter is the name of the network.
    void manInTheMiddleAttack(const char* ssid);

    // This method maps the wireless networks in the area.
    void wirelessNetworkMapping();

    // This method returns true if the password has been cracked.
    bool isCracked();

    // This method returns the password that was cracked.
    const char* getPassword();

  private:
    // This variable indicates whether or not the password has been cracked.
    bool cracked;

    // This variable stores the password that was cracked.
    char password[32];
};

#endif
