// functional connections
#define MOTOR_A_PWM 15 // A_IA: 6 Motor for PWM Speed 왼쪽
#define MOTOR_A_DIR 13 // A_IB: 5 Motor for Direction

#define MOTOR_B_PWM 4 // A_IA: 2 Motor for PWM Speed 오른쪽
#define MOTOR_B_DIR 5 // A_IB: 7 Motor for Direction

// the actual values for "fast" and "slow" depend on the motor
#define PWM_SLOW 10  
#define PWM_SLOW2 25  
#define PWM_SLOW3 50  
#define PWM_SLOW4 75  
#define PWM_SLOW5 100  
#define PWM_SLOW6 125  
#define PWM_SLOW7 150  
#define PWM_SLOW8 175  
#define PWM_FAST 200 

// int trigPin = 16;  // D0
// int echoPin = 5; // D1


void setup()
{
  Serial.begin( 9600 );
  pinMode( MOTOR_A_DIR, OUTPUT );
  pinMode( MOTOR_A_PWM, OUTPUT );
  pinMode( MOTOR_B_DIR, OUTPUT );
  pinMode( MOTOR_B_PWM, OUTPUT );

  // pinMode(echoPin, INPUT);   // echoPin 입력
  // pinMode(trigPin, OUTPUT);  // trigPin 출력


  
}

void move_fast()
{

  digitalWrite( MOTOR_A_DIR, HIGH ); //꺼짐
  analogWrite( MOTOR_A_PWM, HIGH ); // 0
  digitalWrite( MOTOR_B_DIR, LOW );
  analogWrite( MOTOR_B_PWM, LOW ); //0
  delay(1000);
  digitalWrite( MOTOR_A_DIR, LOW );  // 왼쪽
  analogWrite( MOTOR_A_PWM, 255-PWM_FAST ); 

  digitalWrite( MOTOR_B_DIR, HIGH ); // 오른쪽 
  analogWrite( MOTOR_B_PWM, 255-PWM_FAST );
  // digitalWrite( MOTOR_A_DIR, HIGH );
  // analogWrite( MOTOR_A_PWM, LOW ); // 0
  // digitalWrite( MOTOR_B_DIR, HIGH );
  // analogWrite( MOTOR_B_PWM, HIGH ); //0
}

void move_slow()
{
  digitalWrite( MOTOR_A_DIR, LOW );
  analogWrite( MOTOR_A_PWM, LOW );
  digitalWrite( MOTOR_B_DIR, LOW );
  analogWrite( MOTOR_B_PWM, LOW );
  delay(1000);
  digitalWrite( MOTOR_A_DIR, HIGH ); 
  analogWrite( MOTOR_A_PWM, 255-PWM_SLOW ); 

  digitalWrite( MOTOR_B_DIR, HIGH ); 
  analogWrite( MOTOR_B_PWM, 255-PWM_SLOW ); 
}

void move_slow2()
{
  digitalWrite( MOTOR_A_DIR, LOW );
  analogWrite( MOTOR_A_PWM, LOW );
  digitalWrite( MOTOR_B_DIR, LOW );
  analogWrite( MOTOR_B_PWM, LOW );
  delay(1000);
  digitalWrite( MOTOR_A_DIR, HIGH ); 
  analogWrite( MOTOR_A_PWM, 255-PWM_SLOW2 ); 

  digitalWrite( MOTOR_B_DIR, HIGH ); 
  analogWrite( MOTOR_B_PWM, 255-PWM_SLOW2 ); 

}
void move_slow3()
{
  digitalWrite( MOTOR_A_DIR, LOW );
  analogWrite( MOTOR_A_PWM, LOW );
  digitalWrite( MOTOR_B_DIR, LOW );
  analogWrite( MOTOR_B_PWM, LOW );
  delay(1000);
  digitalWrite( MOTOR_A_DIR, HIGH ); 
  analogWrite( MOTOR_A_PWM, 255-PWM_SLOW3 ); 

  digitalWrite( MOTOR_B_DIR, HIGH ); 
  analogWrite( MOTOR_B_PWM, 255-PWM_SLOW3 ); 

}
void move_slow4()
{
  digitalWrite( MOTOR_A_DIR, LOW );
  analogWrite( MOTOR_A_PWM, LOW );
  digitalWrite( MOTOR_B_DIR, LOW );
  analogWrite( MOTOR_B_PWM, LOW );
  delay(1000);
  digitalWrite( MOTOR_A_DIR, HIGH ); 
  analogWrite( MOTOR_A_PWM, 255-PWM_SLOW4 ); 

  digitalWrite( MOTOR_B_DIR, HIGH ); 
  analogWrite( MOTOR_B_PWM, 255-PWM_SLOW4 ); 

}
void move_slow5()
{
  digitalWrite( MOTOR_A_DIR, LOW );
  analogWrite( MOTOR_A_PWM, LOW );
  digitalWrite( MOTOR_B_DIR, LOW );
  analogWrite( MOTOR_B_PWM, LOW );
  delay(1000);
  digitalWrite( MOTOR_A_DIR, HIGH ); 
  analogWrite( MOTOR_A_PWM, 255-PWM_SLOW5 ); 

  digitalWrite( MOTOR_B_DIR, HIGH ); 
  analogWrite( MOTOR_B_PWM, 255-PWM_SLOW5 ); 

}
void move_slow6()
{
  digitalWrite( MOTOR_A_DIR, LOW );
  analogWrite( MOTOR_A_PWM, LOW );
  digitalWrite( MOTOR_B_DIR, LOW );
  analogWrite( MOTOR_B_PWM, LOW );
  delay(1000);
  digitalWrite( MOTOR_A_DIR, HIGH ); 
  analogWrite( MOTOR_A_PWM, 255-PWM_SLOW6 ); 

  digitalWrite( MOTOR_B_DIR, HIGH ); 
  analogWrite( MOTOR_B_PWM, 255-PWM_SLOW6 ); 

}
void move_slow7()
{
  digitalWrite( MOTOR_A_DIR, LOW );
  analogWrite( MOTOR_A_PWM, LOW );
  digitalWrite( MOTOR_B_DIR, LOW );
  analogWrite( MOTOR_B_PWM, LOW );
  delay(1000);
  digitalWrite( MOTOR_A_DIR, HIGH ); 
  analogWrite( MOTOR_A_PWM, 255-PWM_SLOW7 ); 

  digitalWrite( MOTOR_B_DIR, HIGH ); 
  analogWrite( MOTOR_B_PWM, 255-PWM_SLOW7 ); 

}
void move_slow8()
{
  digitalWrite( MOTOR_A_DIR, LOW );
  analogWrite( MOTOR_A_PWM, LOW );
  digitalWrite( MOTOR_B_DIR, LOW );
  analogWrite( MOTOR_B_PWM, LOW );
  delay(1000);
  digitalWrite( MOTOR_A_DIR, HIGH ); 
  analogWrite( MOTOR_A_PWM, 255-PWM_SLOW8 ); 

  digitalWrite( MOTOR_B_DIR, HIGH ); 
  analogWrite( MOTOR_B_PWM, 255-PWM_SLOW8 ); 

}

void move_stop()
{
  digitalWrite( MOTOR_A_DIR, LOW);
  analogWrite( MOTOR_A_PWM, LOW);
  digitalWrite( MOTOR_B_DIR, LOW);
  analogWrite( MOTOR_B_PWM, LOW);

}


void move_left()
{
  digitalWrite( MOTOR_A_DIR, LOW );
  analogWrite( MOTOR_A_PWM, LOW );
  digitalWrite( MOTOR_B_DIR, LOW );
  analogWrite( MOTOR_B_PWM, LOW );
  delay(1000);
  digitalWrite( MOTOR_A_DIR, HIGH); 
  analogWrite( MOTOR_A_PWM, 125); // 왼쪽 

  digitalWrite( MOTOR_B_DIR, HIGH );  // 오른쪽 
  analogWrite( MOTOR_B_PWM, 55 ); 
}

void move_left2()
{
  digitalWrite( MOTOR_A_DIR, LOW );
  analogWrite( MOTOR_A_PWM, LOW );
  digitalWrite( MOTOR_B_DIR, LOW );
  analogWrite( MOTOR_B_PWM, LOW );
  delay(1000);
  digitalWrite( MOTOR_A_DIR, HIGH); 
  analogWrite( MOTOR_A_PWM, 150); // 왼쪽 

  digitalWrite( MOTOR_B_DIR, HIGH );  // 오른쪽 
  analogWrite( MOTOR_B_PWM, 55 ); 
}

void move_left3()
{
  digitalWrite( MOTOR_A_DIR, LOW );
  analogWrite( MOTOR_A_PWM, LOW );
  digitalWrite( MOTOR_B_DIR, LOW );
  analogWrite( MOTOR_B_PWM, LOW );
  delay(100);
  digitalWrite( MOTOR_A_DIR, HIGH); 
  analogWrite( MOTOR_A_PWM, 125); // 왼쪽 

  digitalWrite( MOTOR_B_DIR, HIGH );  // 오른쪽 
  analogWrite( MOTOR_B_PWM, 55 ); 
}

void move_left4()
{
  digitalWrite( MOTOR_A_DIR, LOW );
  analogWrite( MOTOR_A_PWM, LOW );
  digitalWrite( MOTOR_B_DIR, LOW );
  analogWrite( MOTOR_B_PWM, LOW );
  delay(1000);
  digitalWrite( MOTOR_A_DIR, HIGH); 
  analogWrite( MOTOR_A_PWM, 200); // 왼쪽 

  digitalWrite( MOTOR_B_DIR, HIGH );  // 오른쪽 
  analogWrite( MOTOR_B_PWM, 55 ); 

}

//후진 
//analogWrite( MOTOR_A_DIR, 0);
//digitalWrite( MOTOR_A_PWM, HIGH);


void loop()
{
  // long duration, distance;
  // digitalWrite(trigPin, HIGH);                        // trigPin에서 초음파 발생(echoPin도 HIGH)
  // delayMicroseconds(10);
  // digitalWrite(trigPin, LOW);
  // duration = pulseIn(echoPin, HIGH);                  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  // distance = ((float)(340 * duration) / 10000) / 2; 
  // Serial.print("distance:");                          // 물체와 초음파 센서간 거리를 표시
  // Serial.print(distance);
  // Serial.println(" cm");
  // delay(500);


  move_fast();
  delay(1000);

  // move_slow();
  // delay(1000);
  // move_slow2();
  // delay(1000);
  // move_slow3();
  // delay(1000);
  // move_slow4();
  // delay(1000);
  // move_slow5();
  // delay(1000);
  // move_slow6();
  // delay(1000);
  // move_slow7();
  // delay(1000);
  // move_slow8();
  // delay(1000);

  // move_stop();
  // delay(1000);

  // move_left();
  // delay(3000);
  //  move_left2();
  //  delay(1000);
  //  move_left3();
  //  delay(1000);
  // move_left4();
  // delay(3000);

  // move_stop();
  // delay(1000);


}