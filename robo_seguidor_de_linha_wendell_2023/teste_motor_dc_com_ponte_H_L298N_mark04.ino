//----Configuração motores----//
#define velmotorD 2 // Motor direito
#define velmotorE 3 // Motor esquerdo
#define mEa 4 // Motor esquerdo 
#define mEb 5 // Motor esquerdo
#define mDa 6 // Motor direito
#define mDb 7 // Motor direito

int velD = 200; //Motor Direito
//Motor D com problema em aceitar velocidades abaixo de 128
int velE = 200; //Motor Esquerdo
//----------------------------//

//----Configuração sensores reflexivos infravermelho----//
//Olhando de tras do robo
#define infraEsquerdo 8 // 1 da esquerda para direita
#define infraMeio 9 // 2 da esquerda para direita
#define infraDireita 10 // 3 da esquerda para direita

int leituraEsquerda = 0; // 1 da esquerda para direita
int leituraMeio = 0; // 2 da esquerda para direita
int leituraDireita = 0; // 3 da esquerda para direita
//-----------------------------------------------------//

//----Variavel de tempo----//
int passoDeReta = 30; // Tempo em que motor vai ficar acionado para retas
int passoDeCurva = 50; // Tempo em que motor vai ficar acionado para curvas
int tempDeParada = 250;
//-------------------------//
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
  analogWrite(velmotorD, velD);
  analogWrite(velmotorE, velE);
  //----------------------------//
  //----Configuração sensores reflexivos infravermelho----//
  pinMode(infraEsquerdo, INPUT);
  pinMode(infraMeio, INPUT);
  pinMode(infraDireita, INPUT);
  //-----------------------------------------------------//
}

void loop() {
  leituraEsquerda = digitalRead(infraEsquerdo);
  leituraMeio = digitalRead(infraMeio);
  leituraDireita = digitalRead(infraDireita);

  int leitura = (leituraEsquerda * 1) + (leituraMeio * 2) + (leituraDireita * 4); //convertendo para um numero inteiro
  Serial.println(leitura);
  andar(velD, velE, 0, 0, 0, 0); //Parando
  delay(tempDeParada);
 
  if (leitura == 0) { // Frente
    andar(velD, velE, 0, 1, 0, 1); // Frente
    //andar(velD, velE, 1, 1, 1, 1); 
    delay(passoDeReta);
  }
  if (leitura == 1) { // Anda para Direita
    andar(velD, velE, 0, 0, 0, 1); //Roda o motor da Esquerda para frente 
    //andar(128, velE, 1, 0, 0, 1); //Roda o motor da Esquerda para frente e o da Direita para tras
    delay(passoDeCurva);
  }
  if (leitura == 2) { // Frente
    andar(velD, velE, 0, 1, 0, 1); // Frente 
    delay(passoDeCurva);
  }
  if (leitura == 3) { // Anda para Direita
    andar(velD, velE, 0, 0, 0, 1); //Roda o motor da Esquerda para frente
    //andar(128, velE, 1, 0, 0, 1); //Roda o motor da Esquerda para frente e o da Direita para tras
    delay(passoDeCurva);
  }
  if (leitura == 4) { // Anda para Esquerda
    andar(velD, velE, 0, 1, 0, 0); //Roda o motor da Direita para frente 
    //andar(128, velE, 0, 1, 1, 0); //Roda o motor da Direita para frente e o esquero para tras 
    delay(passoDeCurva);
  }
  if (leitura == 6 ) { // Anda para Esquerda
    andar(velD, velE, 0, 1, 0, 0); //Roda o motor da Direita para frente 
    //andar(128, velE, 1, 0, 0, 1); //Roda o motor da Direita para frente e o esquero para tras 
    delay(passoDeCurva);
  }
  if (leitura == 7 ) { //frente
    andar(velD, velE, 0, 1, 0, 1);
    delay(passoDeReta);
  }

}
void andar(int valor_velocidadeD, int valor_velocidadeE, int motorDa, int motorDb, int motorEa, int motorEb) {
  analogWrite(velmotorD, valor_velocidadeD);
  analogWrite(velmotorE, valor_velocidadeE);
  // muda o estado do Motor Direito
  digitalWrite(mDa, motorDa);
  digitalWrite(mDb, motorDb);
  // muda o estado do Motor Esquerdo
  digitalWrite(mEa, motorEa);
  digitalWrite(mEb, motorEb);
}
