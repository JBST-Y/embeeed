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
    pinMode(15, OUTPUT);
    pinMode(5, OUTPUT);
    digitalWrite(2, 0);
    digitalWrite(5, 1);
    digitalWrite(13, 0);
    digitalWrite(15, 1); 
    digitalWrite(16, 0); 
  }   
    else if (req.indexOf("/gpio/1") != -1){  
    pinMode(15, OUTPUT);
    pinMode(16, OUTPUT); 
    digitalWrite(5, 0);
    digitalWrite(16, 1);
  }
    else if (req.indexOf("/gpio/2") != -1){
    pinMode(1, OUTPUT);
    pinMode(15, OUTPUT);
    digitalWrite(1, 1); 
    digitalWrite(16, 0);
  }
    else if (req.indexOf("/gpio/3") != -1){
    pinMode(2, OUTPUT);
    pinMode(12, OUTPUT);
    digitalWrite(2, 1);
    digitalWrite(1, 0); 
    digitalWrite(12, 1);
    digitalWrite(15, 0); 

  }
    else if (req.indexOf("/gpio/4") != -1){
    pinMode(2, OUTPUT);
    pinMode(14, OUTPUT);
    digitalWrite(12, 0);
    digitalWrite(14, 1);
  }
    else if (req.indexOf("/gpio/5") != -1){
    pinMode(2, OUTPUT);
    pinMode(13, OUTPUT);
    digitalWrite(13, 1);
    digitalWrite(14, 0);
  }
    else if (req.indexOf("/gpio/6") != -1){
    pinMode(3, OUTPUT);
    digitalWrite(3, 1); 
    digitalWrite(9, 0);
    digitalWrite(10, 0); 
  }
  else if (req.indexOf("/gpio/7") != -1){
    pinMode(9, OUTPUT);
    digitalWrite(3, 0); 
    digitalWrite(9, 1);
    digitalWrite(10, 0); 
  }
  else if (req.indexOf("/gpio/8") != -1){
    pinMode(10, OUTPUT);
    digitalWrite(3, 1); 
    digitalWrite(9, 0);
    digitalWrite(10, 0); 
  }
    else if (req.indexOf("/gpio/9") != -1){
    pinMode(9, OUTPUT);
    pinMode(15, OUTPUT);
    pinMode(16, OUTPUT);
    digitalWrite(0, 0);
    digitalWrite(4, 0); 
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    digitalWrite(7, 0); 
    digitalWrite(8, 0);
    digitalWrite(9, 1);
    digitalWrite(10, 0); 
    digitalWrite(11, 0);
    digitalWrite(12, 0);
    digitalWrite(13, 0);
    digitalWrite(14, 0);
    digitalWrite(15, 1); 
    digitalWrite(16, 1);
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