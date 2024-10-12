#include <WiFi.h>
#include <FirebaseESP32.h>

// Replace with your network credentials
const char* ssid = "ECB_TEQIP";
const char* password = "";

// Firebase configuration
#define FIREBASE_HOST "project-esp32-9b4e8.firebaseio.com";
#define FIREBASE_AUTH "105208646284370193324";

// Firebase data object
FirebaseData firebaseData;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

void loop() {
  // Example: Send data to Firebase
  if (Firebase.setInt(firebaseData, "/example/int", 123)) {
    Serial.println("Data sent successfully");
  } else {
    Serial.println("Failed to send data");
  }
  delay(10000); // Send data every 10 seconds
}
