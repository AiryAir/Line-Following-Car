int ir_right=7;
int ir_left=6;

int read_right=0;
int read_left=0;

int pwm1 = 9;
int pwm2 = 10;
int dir1 = 11;
int dir2 = 12;

void LEFT_TURN (void);
void RIGHT_TURN (void);
void STOP (void);

 
void setup() {
  // put your setup code here, to run once:

  pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);

  pinMode(ir_left,INPUT);
  pinMode(ir_right,INPUT);



}

void loop() {
  // put your main code here, to run repeatedly:


  analogWrite(pwm1,20);
  analogWrite(pwm2,20);

  while(1){
    read_right=digitalRead(ir_right);
    read_left=digitalRead(ir_left);

    if((read_left==0 && read_right==1)==1)
    LEFT_TURN();

    else if((read_right==0 && read_left==1)==1)
    RIGHT_TURN();

    else if(read_right==0 && read_left==0)
    STOP();
  }
  
}

void LEFT_TURN(void){
  analogWrite(pwm1,21);
  analogWrite(pwm2,0);

    while(1){
    read_right=digitalRead(ir_right);
    read_left=digitalRead(ir_left);

    if((read_left==0 && read_right==1)==1)
    LEFT_TURN();

    else if((read_right==0 && read_left==1)==1)
    RIGHT_TURN();

    else if(read_right==0 && read_left==0)
    STOP();
  }
  
}

void RIGHT_TURN(void){
  analogWrite(pwm1,0);
  analogWrite(pwm2,21);

    while(1){
    read_right=digitalRead(ir_right);
    read_left=digitalRead(ir_left);

    if((read_left==0 && read_right==1)==1)
    LEFT_TURN();

    else if((read_right==0 && read_left==1)==1)
    RIGHT_TURN();
    
    else if(read_right==0 && read_left==0)
    STOP();
  }
  
}

void STOP (void){
  analogWrite(pwm1,0);
  analogWrite(pwm2,0);
  
}
