
// functional connections
#define MOTOR_A_PWM 12 // A_IA: 6 Motor for PWM Speed
#define MOTOR_A_DIR 14 // A_IB: 5 Motor for Direction

#define MOTOR_B_PWM 4 // A_IA: 2 Motor for PWM Speed
#define MOTOR_B_DIR 13 // A_IB: 7 Motor for Direction

// the actual values for "fast" and "slow" depend on the motor
#define PWM_SLOW 50  
#define PWM_FAST 200 

int trigPin = 16;  // D0
int echoPin = 5; // D1


void setup()
{
  Serial.begin( 9600 );
  pinMode( MOTOR_A_DIR, OUTPUT );
  pinMode( MOTOR_A_PWM, OUTPUT );
  pinMode( MOTOR_B_DIR, OUTPUT );
  pinMode( MOTOR_B_PWM, OUTPUT );

  pinMode(echoPin, INPUT);   // echoPin 입력
  pinMode(trigPin, OUTPUT);  // trigPin 출력
  digitalWrite( MOTOR_A_DIR, LOW );
  digitalWrite( MOTOR_A_PWM, LOW );
  digitalWrite( MOTOR_B_DIR, LOW );
  digitalWrite( MOTOR_B_PWM, LOW );

  
}

void loop()
{
  long duration, distance;
  digitalWrite(trigPin, HIGH);                        // trigPin에서 초음파 발생(echoPin도 HIGH)
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);                  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  distance = ((float)(340 * duration) / 10000) / 2; 
  Serial.print("distance:");                          // 물체와 초음파 센서간 거리를 표시
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);


move_fast();

delay(3000);


move_slow();

delay(3000);


move_stop();

delay(3000);


move_left();

delay(3000);


move_stop();

delay(1000);


}


void move_fast()
{


digitalWrite( MOTOR_A_DIR, HIGH );  // 왼쪽
analogWrite( MOTOR_A_PWM, 255-PWM_FAST ); 

digitalWrite( MOTOR_B_DIR, HIGH ); // 오른쪽 
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


analogWrite( MOTOR_A_DIR, 50); // 왼쪽 
digitalWrite( MOTOR_A_PWM, HIGH); 


digitalWrite( MOTOR_B_DIR, HIGH );  // 오른쪽 
analogWrite( MOTOR_B_PWM, 0 ); 

}



//후진 
//analogWrite( MOTOR_A_DIR, 0);
//digitalWrite( MOTOR_A_PWM, HIGH); 




