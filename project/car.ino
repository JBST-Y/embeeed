#include <ESP8266WiFi.h>
#include <Servo.h> 

const char* ssid = "juns";
const char* password = "10101010";

Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
#define Motor_1_pin 14      // 오른쪽 모터 제어선 IN1
#define Motor_2_pin 12     // 오른쪽 모터 제어선 IN2



WiFiServer server(80);

void setup() {

  Serial.begin(9600);
  delay(10);

  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);

    
  }

    myservo.attach(2);  // attaches the servo on GIO2 to the servo object        // 출력모드로 설정
  pinMode(Motor_1_pin, OUTPUT);
  pinMode(Motor_2_pin, OUTPUT);
  
  // Start the server
  server.begin();

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  int pos ;
  int mode =0;
  int count;
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  //Wait until the client sends some data
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  client.flush();

  Serial.println(WiFi.localIP());

  if (req.indexOf("/gpio/0") != -1){ //정지
    mode = 0;
  }   
  else if (req.indexOf("/gpio/1") != -1){  //천천히 직진
    mode = 1;
  }
  else if (req.indexOf("/gpio/2") != -1){ //빠르게 직진
    mode =2;
  }
  else if (req.indexOf("/gpio/3") != -1){  //좌회전 각도 낮게
    mode =3; 
  }
  else if (req.indexOf("/gpio/4") != -1){ //좌회전 각도 높게
    mode =4;
  }
  else {
    Serial.println("invalid request");
    client.stop();
    mode =0;
    return;
  }

  if(mode == 0){ //정지
    digitalWrite(Motor_1_pin, LOW);
    digitalWrite(Motor_2_pin, LOW);
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
  else if(mode == 1){ //천천히 직진
    for(count = 0; count<=130; count+=1){
      //Wait until the client sends some dat
        myservo.write(96);
        digitalWrite(Motor_1_pin, HIGH);
        digitalWrite(Motor_2_pin, LOW); 
        delay(15);
        digitalWrite(Motor_1_pin, LOW);
        digitalWrite(Motor_2_pin, LOW);          
                    // tell servo to go to position in variable 'pos' 
        delay(15);                       // waits 15ms for the servo to reach the position 
    }
  }
  else if(mode == 2){ //빠르게 직진
    for(count = 0; count<=200; count+=1){
      //Wait until the client sends some data
      myservo.write(96);
        digitalWrite(Motor_1_pin, HIGH);
        digitalWrite(Motor_2_pin, LOW);
        delay(15);
        digitalWrite(Motor_1_pin, LOW);
        digitalWrite(Motor_2_pin, LOW);             
                    // tell servo to go to position in variable 'pos' 
        delay(15);                       // waits 15ms for the servo to reach the position 
    }
  }
  else if(mode == 3){ //좌회전 각도 낮게
    for(pos = 95; pos>=50; pos-=1)     // goes from 180 degrees to 0 degrees 
    {    
      digitalWrite(Motor_1_pin, HIGH);
      digitalWrite(Motor_2_pin, LOW);                  
                  // tell servo to go to position in variable 'pos' 
      delay(15);                       // waits 15ms for the servo to reach the position 
      myservo.write(pos);    
          
      digitalWrite(Motor_1_pin, LOW);
      digitalWrite(Motor_2_pin, LOW);
      delay(15);

      }
      for(pos = 50; pos<=95; pos+=1)     // goes from 180 degrees to 0 degrees 
    {    
          
      digitalWrite(Motor_1_pin, HIGH);
      digitalWrite(Motor_2_pin, LOW);                  
                  // tell servo to go to position in variable 'pos' 
      delay(15);                       // waits 15ms for the servo to reach the position 
      myservo.write(pos);    
      digitalWrite(Motor_1_pin, LOW);
      digitalWrite(Motor_2_pin, LOW);
      delay(15);

      }
  }
  else if(mode == 4){ //좌회전 각도 높게
    for(pos = 95; pos>=40; pos-=1)     // goes from 180 degrees to 0 degrees 
    {    
      digitalWrite(Motor_1_pin, HIGH);
      digitalWrite(Motor_2_pin, LOW);                  
                  // tell servo to go to position in variable 'pos' 
      delay(15);                       // waits 15ms for the servo to reach the position 
      myservo.write(pos);    
          
      digitalWrite(Motor_1_pin, LOW);
      digitalWrite(Motor_2_pin, LOW);
      delay(15);

      }
     for(pos = 40; pos<=95; pos+=1)     // goes from 180 degrees to 0 degrees 
    {    
          
      digitalWrite(Motor_1_pin, HIGH);
      digitalWrite(Motor_2_pin, LOW);                  
                  // tell servo to go to position in variable 'pos' 
      delay(15);                       // waits 15ms for the servo to reach the position 
      myservo.write(pos);    
      digitalWrite(Motor_1_pin, LOW);
      digitalWrite(Motor_2_pin, LOW);
      delay(15);

      }
  }
  // Set GPIO2 according to the request
  // digitalWrite(2, val);
  
  // client.flush();

  // Send the response to the client

  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed
}