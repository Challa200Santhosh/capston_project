#include <WiFi.h>
#include <Wire.h>
#include <DHT.h>

#define DHTPIN 15
#define DHTTYPE DHT22
#define FAN_PIN 5
#define HEATER_PIN 18


const char* ssid = "VPG@3";
const char* password = "vpg@3003";
WiFiServer server(80);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);
    Wire.begin();
    dht.begin();

    pinMode(FAN_PIN, OUTPUT);
    pinMode(HEATER_PIN, OUTPUT);

    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Connected!");
    server.begin();
    Serial.println("Server started");
    Serial.println(WiFi.localIP());
}

void loop() {
    WiFiClient client = server.available();
    if (client) {
        Serial.println("New Client Connected");
        String request = client.readStringUntil('\r');
        client.flush();

        float humidity = dht.readHumidity();
        float temperature = dht.readTemperature();

        if (isnan(humidity) || isnan(temperature)) {
            Serial.println("DHT22 error!");
            return;
        }

        if (temperature > 35) {  
            digitalWrite(FAN_PIN, HIGH);
            Serial.println("Fan ON");
        } else {
            digitalWrite(FAN_PIN, LOW);
            Serial.println("Fan OFF");
        }

        if (temperature < 25) {  
            digitalWrite(HEATER_PIN, HIGH);
            Serial.println("Heater ON");
        } else {
            digitalWrite(HEATER_PIN, LOW);
            Serial.println("Heater OFF");
        }

        client.println("HTTP/1.1 200 OK");
        client.println("Content-type:text/html");
        client.println("Connection: close");
        client.println();
        client.println("<html><body>");
        client.println("<h1>Solar Dryer Monitoring</h1>");
        client.println("<p>Temperature: " + String(temperature) + " C</p>");
        client.println("<p>Humidity: " + String(humidity) + " %</p>");
        client.println("</body></html>");
        client.println();
        delay(2500);
    }
}
