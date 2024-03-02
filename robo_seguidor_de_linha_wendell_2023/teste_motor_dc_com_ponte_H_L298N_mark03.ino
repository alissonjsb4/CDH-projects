#define velmotorD 2 // Motor direito
#define velmotorE 3 // Motor esquerdo
#define mEa 4 // Motor esquerdo 
#define mEb 5 // Motor esquerdo
#define mDa 6 // Motor direito
#define mDb 7 // Motor direito

int velD = 130; //Motor Direito
//Motor D com problema em aceitar velocidades abaixo de 128
int velE = 145; //Motor Esquerdo

void setup() {
  pinMode(velmotorD, OUTPUT);
  pinMode(velmotorE, OUTPUT);
  pinMode(mEa, OUTPUT);
  pinMode(mEb, OUTPUT);
  digitalWrite(mEa, LOW);
  digitalWrite(mEb, LOW);
  pinMode(mDa, OUTPUT);
  pinMode(mDb, OUTPUT);
  digitalWrite(mDa, LOW);
  digitalWrite(mDb, LOW);

  digitalWrite(velmotorD, velD);
  digitalWrite(velmotorE, velE);
  Serial.begin(9600);
}

void loop() {
  andar(velD,velE,0,1,0,1); //Para frente
//  delay(2000);
//  andar(velD,velE,0,0,0,0); //Parada
//  delay(2000);
//  andar(velD,velE,1,0,0,0); //Roda o motor da Direita para tras
//  delay(2000);
//  andar(velD,velE,0,0,0,0); //Parada
//  delay(2000);
//  andar(velD,velE,0,0,1,0); //Roda o motor da Esquerda para tras
//  delay(2000);
//  andar(velD,velE,0,0,0,0); //Parada
//  delay(2000);
//  andar(velD,velE,1,0,1,0); //Para trás
//  delay(2000);
//  andar(velD,velE,0,0,0,0); //Parada
//  delay(2000);
}
void andar(int velocidadeD, int velocidadeE, int motorDa,int motorDb,int motorEa,int motorEb) {
  analogWrite(velmotorD, velocidadeD);
  analogWrite(velmotorE, velocidadeE);
  // muda o estado do Motor Direito 
  digitalWrite(mDa, motorDa);
  digitalWrite(mDb, motorDb);
  // muda o estado do Motor Esquerdo
  digitalWrite(mEa, motorEa);
  digitalWrite(mEb, motorEb);
}
