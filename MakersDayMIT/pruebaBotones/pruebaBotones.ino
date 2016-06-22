startButton=13;
señalBoton1=12;
señalBoton2=7;
led11=11;
led12=10;
led13=9;
buzzer1=8;
led21=6;
led22=5;
led23=4;
buzzer2=3;
buzzer=2;
void setup() {
  pinMode(buzzer,OUTPUT);
  pinMode(startButton,INPUT);
  pinMode(señalBoton1,INPUT);
  pinMode(led11,OUTPUT);
  pinMode(led12,OUTPUT);
  pinMode(led13,OUTPUT);
  pinMode(buzzer1,OUTPUT);
  pinMode(señalBoton2,INPUT);
  pinMode(led21,OUTPUT);
  pinMode(led22,OUTPUT);
  pinMode(led23,OUTPUT);
  pinMode(buzzer2,OUTPUT);
  Serial.begin(9600);
}
int cont1=0;
int cont2=0;
int currentState=0;
int lastState=0;
int currentStart=0;
int lastStart=0;
boolean ganador=false;
void loop() {
  currentStart=digitalRead(startButton);
  if (currentStart!=lastStart){    
    juega1();
    juega2();
  }
  if (ganador){
    digitalWrite(buzzer,HIGH);
    cont1=0;
    cont2=0;
    ganador=false;
  }
  lastStart=currentStart;
}

void juega1(){
  currentState=digitalRead(señalBoton1);
  if (currentState!=lastState){
    cont1++;
  }
  if (cont1<=20){
    digitalWrite(led11,HIGH);
  }
  else{
    if (cont1<=30){
      digitalWrite(led12,HIGH);
      digitalWrite(led11,LOW);
    }
    else{
      if (cont1<=40){
        digitalWrite(led13,HIGH);
        digitalWrite(led12,LOW);
      }
      else{
        digitalWrite(led13,LOW);
        if (!ganador){
          digitalWrite(buzzer1,HIGH);
          delay(5000);
          ganador=true;
          digitalWrite(buzzer1,LOW);
        }
      }      
    }
  }
  if(cont1<10){
    digitalWrite(led11,LOW);
    digitalWrite(led12,LOW);
    digitalWrite(led13,LOW);
  }
  lastState=currentState;
  Serial.println(cont1);
}

void juega2(){
  currentState=digitalRead(señalBoton2);
  if (currentState!=lastState){
    cont2++;
  }
  if (cont2<=20){
    digitalWrite(led21,HIGH);
  }
  else{
    if (cont2<=30){
      digitalWrite(led22,HIGH);
      digitalWrite(led21,LOW);
    }
    else{
      if (cont2<=40){
        digitalWrite(led23,HIGH);
        digitalWrite(led22,LOW);
      }
      else{
        digitalWrite(led23,LOW);
        if (!ganador){
          digitalWrite(buzzer2,HIGH);
          delay(5000);
          ganador=true;
          digitalWrite(buzzer2,LOW);
        }
      }      
    }
  }
  if(cont2<10){
    digitalWrite(led21,LOW);
    digitalWrite(led22,LOW);
    digitalWrite(led23,LOW);
  }
  lastState=currentState;
  Serial.println(cont2);
}

