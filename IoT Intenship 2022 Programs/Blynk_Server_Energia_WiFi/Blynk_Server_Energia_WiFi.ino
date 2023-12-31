//Connection With Blynk Server

/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example shows how to use Energia with WiFi
  to connect your project to Blynk. Tested with:
    TI MSP430F5529 + CC3100
    TI CC3200-LaunchXL
    RedBearLab CC3200
    RedBearLab WiFi Mini w/ CC3200
    RedBearLab WiFi Micro w/ CC3200

  Requires Energia IDE: http://energia.nu/download/

  Feel free to apply it to any other example. It's simple!
 *************************************************************/
#define BLYNK_TEMPLATE_ID "TMPLS_SfwQef"
#define BLYNK_DEVICE_NAME "IOTSADS"
#define BLYNK_AUTH_TOKEN "SbH_gMgvCTPWSX3rlrQ7SOI5NfFUKpK1"


/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "dlink";
char pass[] = "";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
