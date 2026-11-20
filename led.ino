#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

// WiFi credentials
const char* ssid = "YOUR WIFI NAME";
const char* pass = "YOUR PASSWORD";

// KiwisIoT Topic ID
const char* topic = "DASHBOARD TOPIC ID";

// LED pins
#define LED1 D1
#define LED2 D2
#define LED3 D3

// Create KiwisIoT object
KiwisIoT kiwisiot(ssid, pass, topic);

// LED control callback
void onControl(String ch, String val) {

  val.trim();

  // LED 1 - Channel 0
  if (ch == "0") {
    if (val == "1") {
      digitalWrite(LED1, HIGH);
      Serial.println("LED 1 ON");
    }
    else if (val == "0") {
      digitalWrite(LED1, LOW);
      Serial.println("LED 1 OFF");
    }
  }

  // LED 2 - Channel 1
  else if (ch == "1") {
    if (val == "1") {
      digitalWrite(LED2, HIGH);
      Serial.println("LED 2 ON");
    }
    else if (val == "0") {
      digitalWrite(LED2, LOW);
      Serial.println("LED 2 OFF");
    }
  }

  // LED 3 - Channel 2
  else if (ch == "2") {
    if (val == "1") {
      digitalWrite(LED3, HIGH);
      Serial.println("LED 3 ON");
    }
    else if (val == "0") {
      digitalWrite(LED3, LOW);
      Serial.println("LED 3 OFF");
    }
  }
}

void setup() {

  Serial.begin(115200);

  // Configure LED pins
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  // Initially all LEDs OFF
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);

  // Initialize KiwisIoT
  kiwisiot.begin();

  // Receive dashboard commands
  kiwisiot.onReceive(onControl);

  Serial.println("KiwisIoT Three LED Control Ready");
}

void loop() {

  // Maintain cloud communication
  kiwisiot.run();
}
