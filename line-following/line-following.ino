int ir_right=7;
int ir_left=6;

int read_right=0;
int read_left=0;

int pwm1 = 9; 
int motor_r = 10; //right motors fwd pwm2 pwm1
int motor_l = 11; //left motors fwd dir1 pwm2
int dir2 = 12; //dir1

int gospeed = 50;
int turnspeed = 80;

int r = 2;
int g = 3;
int yleft = 4;
int yright = 5;

void LEFT_TURN(void);
void RIGHT_TURN(void);
void STOP(void);
void GO(void);

void setup() {
  // put your setup code here, to run once:

  pinMode(pwm1,OUTPUT);
  pinMode(motor_r,OUTPUT);
  pinMode(motor_l,OUTPUT);
  pinMode(dir2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  while(1){
    read_right=digitalRead(ir_right);
    read_left=digitalRead(ir_left);

    if(read_left==1 && read_right==1)
    STOP();

    else if(read_left==1 && read_right==0)
    LEFT_TURN();

    else if(read_left==0 && read_right==1)
    RIGHT_TURN();

    else if(read_left==0 && read_right==0)
    GO();
  }
}
void GO(void){
  analogWrite(motor_l,gospeed);
  analogWrite(motor_r,gospeed);
  analogWrite(g,150);
  analogWrite(r,0);
  analogWrite(yleft,0);
  analogWrite(yright,0);

  
}

void LEFT_TURN(void){
  analogWrite(motor_l,turnspeed);
  analogWrite(motor_r,0);
  analogWrite(yleft, 150);
  analogWrite(yright,0);
  analogWrite(r,0);
  analogWrite(g,150);
  
  }


void RIGHT_TURN(void){
  analogWrite(motor_r,turnspeed);
  analogWrite(motor_l,0);
  analogWrite(yleft, 0);
  analogWrite(yright,150);
  analogWrite(r,0);
  analogWrite(g,150);
  
}

void STOP(void){
  analogWrite(motor_r,0);
  analogWrite(motor_l,0);
  analogWrite(yleft, 0);
  analogWrite(yright,0);
  analogWrite(r,150);
  analogWrite(g,0);

  
}
