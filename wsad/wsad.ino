char inChar; 
int motor_delay = 100;

int LED = 13;
// --------------------------------------------------------------------------- Motors
int motor_left[] = {2,4};
int motor_right[] = {9,8};
int left_enable = 3;
int right_enable = 5;
int motor_speedl = 255;
int motor_speedr = 230;

// --------------------------------------------------------------------------- Setup
void setup() {
Serial.begin(9600);

int i;
for(i = 0; i < 2; i++){
pinMode(motor_left[i], OUTPUT);
pinMode(motor_right[i], OUTPUT);
}
pinMode(LED,OUTPUT);
pinMode(left_enable, OUTPUT);
pinMode(right_enable, OUTPUT);
analogWrite(left_enable, motor_speedl);
analogWrite(right_enable,motor_speedr);
}

// --------------------------------------------------------------------------- Loop
void loop() {
  //drive_forward();
  if (Serial.available() > 0) {
    // get incoming byte:
    inChar = Serial.read();
    switch (inChar) {
      
      case 'w': 
        drive_forward();
        //delay(motor_delay);
        //motor_stop();
        break;
      
      case 's': 
        drive_backward();
        //delay(motor_delay);
        //motor_stop();
        break;
        
      case 'a': 
        turn_left();
        //delay(motor_delay);
        //motor_stop();
        break;
      
      case 'd': 
        turn_right();
        //delay(motor_delay);
        //motor_stop();
        break;
        
       case 'q': 
        full_left();
        //delay(motor_delay);
        //motor_stop();
        break;
        
       case 't': 
        motor_stop();
        //delay(motor_delay);
        //motor_stop();
        break;
        
       case 'e': 
        full_right();
        //delay(motor_delay);
        //motor_stop();
        break;
        
       case 'l': 
        digitalWrite(LED,HIGH);
        delay(2000);
        digitalWrite(LED,LOW);
        break;
    
    }
  }
    
    
}

// --------------------------------------------------------------------------- Drive

void motor_stop(){
digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], LOW); 
Serial.println("Stop");
digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], LOW);
delay(25);
}

void drive_forward(){
digitalWrite(motor_left[0], HIGH); 
digitalWrite(motor_left[1], LOW); 
Serial.println("Forward");
digitalWrite(motor_right[0], HIGH); 
digitalWrite(motor_right[1], LOW); 
}

void drive_backward(){
digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], HIGH); 
Serial.println("Backward");
digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], HIGH); 
}

void turn_left(){
digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], LOW); 
Serial.println("Left");
digitalWrite(motor_right[0], HIGH); 
digitalWrite(motor_right[1], LOW);
}

void turn_right(){
digitalWrite(motor_left[0], HIGH); 
digitalWrite(motor_left[1], LOW); 
Serial.println("Right");
digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], LOW); 
}

void full_left(){
digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], HIGH); 
Serial.println("Full Left");
digitalWrite(motor_right[0], HIGH); 
digitalWrite(motor_right[1], LOW);
}

void full_right(){
digitalWrite(motor_left[0], HIGH); 
digitalWrite(motor_left[1], LOW); 
Serial.println("Full Right");
digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], HIGH); 
}
