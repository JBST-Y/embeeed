/*
 *  This sketch demonstrates how to set up a simple HTTP-like server.
 *  The server will set a GPIO pin depending on the request
 *    http://server_ip/gpio/0 will set the GPIO2 low,
 *    http://server_ip/gpio/1 will set the GPIO2 high
 *  server_ip is the IP address of the ESP8266 module, will be 
 *  printed to Serial when the module is connected.
 */

#include <ESP8266WiFi.h>

#define MOTOR_A_PWM 12 // A_IA: 6 Motor for PWM Speed
#define MOTOR_A_DIR 14 // A_IB: 5 Motor for Direction

#define MOTOR_B_PWM 4 // A_IA: 2 Motor for PWM Speed
#define MOTOR_B_DIR 13 // A_IB: 8 Motor for Direction

// the actual values for "fast" and "slow" depend on the motor
#define PWM_SLOW 50  
#define PWM_FAST 200 

int trigPin = 16;  // D0
int echoPin = 5; // D1

const char* ssid = "juns";
const char* password = "10101010";

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");

    

    pinMode(echoPin, INPUT);   // echoPin 입력
    pinMode(trigPin, OUTPUT);  // trigPin 출력
    digitalWrite( MOTOR_A_DIR, LOW );
    digitalWrite( MOTOR_A_PWM, LOW );
    digitalWrite( MOTOR_B_DIR, LOW );
    digitalWrite( MOTOR_B_PWM, LOW );
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

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
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  
  // Match the request
  int val;
  if (req.indexOf("/gpio/0") != -1){
    
    //val = 0;
    pinMode( MOTOR_A_DIR, OUTPUT );
    pinMode( MOTOR_A_PWM, OUTPUT );
    pinMode( MOTOR_B_DIR, OUTPUT );
    pinMode( MOTOR_B_PWM, OUTPUT );

    move_fast();
        delay(3000);


  }
  else if (req.indexOf("/gpio/1") != -1){
    
    pinMode( MOTOR_A_DIR, OUTPUT );
    pinMode( MOTOR_A_PWM, OUTPUT );
    pinMode( MOTOR_B_DIR, OUTPUT );
    pinMode( MOTOR_B_PWM, OUTPUT );
    move_slow();

    //val = 1;
        delay(3000);

  }
  else if (req.indexOf("/gpio/2") != -1){
    
    //val = 2;
    pinMode( MOTOR_A_DIR, OUTPUT );
    pinMode( MOTOR_A_PWM, OUTPUT );
    pinMode( MOTOR_B_DIR, OUTPUT );
    pinMode( MOTOR_B_PWM, OUTPUT );

    move_stop();

    delay(3000);
    
  }
  else if (req.indexOf("/gpio/3") != -1){
    
    //val = 3;

    
  }
  
  else {
    Serial.println("invalid request");
    client.stop();
    return;
  }
    
    switch (val){
        case (0): move_fast();  break;
        case (1): move_slow();  break;
        case (2): move_stop();  break;
        case (3): move_left();  break;

    }
    
    

    
  // Set GPIO2 according to the request
  // digitalWrite(2, val);
  
  // client.flush();

  // Prepare the response
  //String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nGPIO is now ";
  //s += (val)?"high":"low";
  //s += "</html>\n";

  // Send the response to the client
  //client.print(s);
  //delay(1);
  //Serial.println("Client disonnected");

  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed
}

void move_fast()
{
digitalWrite( MOTOR_A_DIR, HIGH );  // 오른쪽 모터
analogWrite( MOTOR_A_PWM, 255-PWM_FAST ); 

digitalWrite( MOTOR_B_DIR, HIGH ); // 왼쪽 모터 
analogWrite( MOTOR_B_PWM, 255-PWM_FAST );
}

void move_slow()
{
digitalWrite( MOTOR_A_DIR, HIGH ); 
analogWrite( MOTOR_A_PWM, 255-PWM_SLOW ); 

digitalWrite( MOTOR_B_DIR, HIGH ); 
analogWrite( MOTOR_B_PWM, 255-PWM_SLOW ); 
}

void move_stop()
{
digitalWrite( MOTOR_A_DIR, LOW);
digitalWrite( MOTOR_A_PWM, LOW);

digitalWrite( MOTOR_B_DIR, LOW);
digitalWrite( MOTOR_B_PWM, LOW);
}

void move_left()
{
digitalWrite( MOTOR_A_DIR, HIGH ); 
analogWrite( MOTOR_A_PWM, 0 ); 

analogWrite( MOTOR_B_DIR, 0);
digitalWrite( MOTOR_B_PWM, 100); 

}
