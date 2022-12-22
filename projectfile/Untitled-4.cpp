// functional connections
#define MOTOR_A_PWM 14 // A_IA: 6 Motor for PWM Speed 오른쪽
#define MOTOR_A_DIR 12 // A_IB: 5 Motor for Direction

#define MOTOR_B_PWM 4 // A_IA: 2 Motor for PWM Speed 왼쪽
#define MOTOR_B_DIR 5 // A_IB: 7 Motor for Direction

// the actual values for "fast" and "slow" depend on the motor
#define PWM_10 10  
#define PWM_25 25  
#define PWM_50 50  
#define PWM_75 75  
#define PWM_100 100  
#define PWM_125 125  
#define PWM_150 150  
#define PWM_175 175  
#define PWM_200 200 

void setup()
{
  Serial.begin( 9600 );
  pinMode( MOTOR_A_DIR, OUTPUT );
  pinMode( MOTOR_A_PWM, OUTPUT );
  pinMode( MOTOR_B_DIR, OUTPUT );
  pinMode( MOTOR_B_PWM, OUTPUT );
  digitalWrite( MOTOR_A_DIR, LOW );
  digitalWrite( MOTOR_A_PWM, LOW );
  digitalWrite( MOTOR_B_DIR, LOW );
  digitalWrite( MOTOR_B_PWM, LOW );
 
}


void loop()
{
  digitalWrite( MOTOR_A_DIR, LOW );
  digitalWrite( MOTOR_A_PWM, LOW );
  digitalWrite( MOTOR_B_DIR, LOW );
  digitalWrite( MOTOR_B_PWM, LOW );
  delay( 1000 );
  // set the motor speed and direction
  digitalWrite( MOTOR_A_DIR, HIGH ); // direction = forward
  analogWrite( MOTOR_A_PWM, 50 ); // PWM speed = slow
  digitalWrite( MOTOR_B_DIR, HIGH ); // direction = forward
  analogWrite( MOTOR_B_PWM, 180 ); // PWM speed = slow

}