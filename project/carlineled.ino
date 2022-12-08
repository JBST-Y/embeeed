#include <ESP8266WiFi.h>

const char* ssid = "juns";
const char* password = "10101010";



WiFiServer server(80);

void setup() {

  Serial.begin(115200);
  delay(10);

  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);

    
  }
  
  // Start the server
  server.begin();

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  client.flush();

   Serial.println(WiFi.localIP());
  
  if (req.indexOf("/gpio/0") != -1){
    pinMode(16, OUTPUT);
    digitalWrite(16, 1); 
    digitalWrite(5, 0);
    digitalWrite(4, 0); 
  }
  else if (req.indexOf("/gpio/1") != -1){
    pinMode(5, OUTPUT);
    digitalWrite(16, 0); 
    digitalWrite(5, 1);
    digitalWrite(4, 0); 
  }
  else if (req.indexOf("/gpio/2") != -1){
    pinMode(4, OUTPUT);
    digitalWrite(16, 0); 
    digitalWrite(5, 0);
    digitalWrite(4, 1); 
  }
  else {
    Serial.println("invalid request");
    client.stop();
    return;
  }

  // Set GPIO2 according to the request
  // digitalWrite(2, val);
  
  // client.flush();

  // Send the response to the client

  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed
}