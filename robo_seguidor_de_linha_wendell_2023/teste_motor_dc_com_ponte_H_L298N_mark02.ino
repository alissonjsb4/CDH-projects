#define velmotor 2//2
#define mla 4//4
#define mlb 5//5
#define tmp 1000
int vel=255;

void setup() {
 pinMode(velmotor, OUTPUT);
 pinMode(mla, OUTPUT);
 pinMode(mlb, OUTPUT);
 digitalWrite(mla,LOW);
 digitalWrite(mlb,LOW);
 digitalWrite(velmotor,vel);
 
}

void loop() {
  vel = 150;
  analogWrite(velmotor,vel);
  
  digitalWrite(mla,LOW);
  digitalWrite(mlb,HIGH);
  delay(tmp);

  digitalWrite(mla,LOW);
  digitalWrite(mlb,LOW);
  delay(100);

  digitalWrite(mla,LOW);
  digitalWrite(mlb,HIGH);
  delay(tmp);
}
