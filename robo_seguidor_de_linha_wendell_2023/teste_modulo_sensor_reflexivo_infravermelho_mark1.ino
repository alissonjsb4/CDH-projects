//----Configuração motores----//
#define velmotorD 2 // Motor direito
#define velmotorE 3 // Motor esquerdo
#define mEa 4 // Motor esquerdo 
#define mEb 5 // Motor esquerdo
#define mDa 6 // Motor direito
#define mDb 7 // Motor direito

int velD = 130; //Motor Direito
//Motor D com problema em aceitar velocidades abaixo de 128
int velE = 145; //Motor Esquerdo
//----------------------------//

//----Configuração sensores reflexivos infravermelho----//
#define infra1 8
#define infra2 9
#define infra3 10
//-----------------------------------------------------//
void setup() {
  Serial.begin(9600);
  //----Configuração motores----//
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
  //----------------------------//
  //----Configuração sensores reflexivos infravermelho----//
  pinMode(infra1,INPUT);
  pinMode(infra2,INPUT);
  pinMode(infra3,INPUT);
  //-----------------------------------------------------//  
}

void loop() {
  Serial.print("motor 1: ");
  Serial.println(digitalRead(infra1));
  Serial.print("motor 2: ");
  Serial.println(digitalRead(infra2));
  Serial.print("motor 3: ");
  Serial.println(digitalRead(infra3));
  delay(2000);

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
