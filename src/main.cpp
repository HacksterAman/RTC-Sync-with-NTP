#include <Wire.h>   // I2C communication library
#include <DS3231.h> // RTC library for DS3231
#include <WiFi.h>   // Wi-Fi library
#include <time.h>   // Time library for NTP

// Wi-Fi credentials
const char *ssid = "SSID";
const char *password = "PASSWORD";

DS3231 rtc;
DateTime currentTime;
bool rtcTimeSet = false;

// Function to connect to Wi-Fi
void connectToWiFi()
{
  Serial.print("Connecting to WiFi ");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" CONNECTED");
}

// Function to set RTC time from NTP server
void setRTCFromNTP()
{
  configTime(0, 0, "time.nist.gov"); // Configure NTP server
  struct tm timeinfo;

  // Get time from NTP server
  if (!getLocalTime(&timeinfo))
  {
    Serial.println("Failed to obtain time from NTP Server");
    return;
  }

  // Apply GMT offset
  int offsetHours = 5;
  int offsetMinutes = 30;
  timeinfo.tm_hour += offsetHours;
  timeinfo.tm_min += offsetMinutes;

  // Set RTC time using Unix time
  time_t epochTime = mktime(&timeinfo);
  rtc.setEpoch(epochTime);
  Serial.println("RTC time set from NTP Server");
  rtcTimeSet = true;
}

void setup()
{
  Serial.begin(115200); // Start serial communication
  Wire.begin();         // Initialize I2C for RTC
  connectToWiFi();      // Connect to Wi-Fi

  while (!rtcTimeSet)
  {
    setRTCFromNTP(); // Set RTC time
    delay(3000);
  }
}

void loop()
{
  currentTime = RTClib::now(); // Get current time from RTC

  // Display date and time
  Serial.print("Current Date and Time: ");
  Serial.print(currentTime.year());
  Serial.print("/");
  Serial.print(currentTime.month());
  Serial.print("/");
  Serial.print(currentTime.day());
  Serial.print(" ");
  Serial.print(currentTime.hour());
  Serial.print(":");
  Serial.print(currentTime.minute());
  Serial.print(":");
  Serial.print(currentTime.second());
  Serial.println();

  delay(1000); // Wait for 1 second before next read
}
