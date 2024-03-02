//----Configuração motores----//
#define velmotorD 2 // Motor direito
#define velmotorE 3 // Motor esquerdo
#define mEa 4 // Motor esquerdo 
#define mEb 5 // Motor esquerdo
#define mDa 6 // Motor direito
#define mDb 7 // Motor direito

//Motor D com problema em aceitar velocidades abaixo de 128
int velD = 140; //Motor Direito
int velE = 200; //Motor Esquerdo
//----------------------------//

//----Configuração sensores reflexivos infravermelho----//
#define infraEsquerdo 8 // 1 da esquerda para direita
#define infraMeio 9 // 2 da esquerda para direita
#define infraDireita 10 // 3 da esquerda para direita

//int leitura1 = 0; // 1 da esquerda para direita
//int leitura2 = 0; // 2 da esquerda para direita
//int leitura3 = 0; // 3 da esquerda para direita
//-----------------------------------------------------//
//----------Matriz que representa o percurso --------------//
int mapaDaPista[3][3]={{-1,-1,-1},
                       {-1,-1,-1},
                       {-1,-1,-1}};
//--------------------------------------------------------//
//----Variavel de tempo----//
int passoDeReta = 30; // Tempo em que motor vai ficar acionado para retas
int passoDeCurva = 30; // Tempo em que motor vai ficar acionado para curvas
int tempDeParada = 300;
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
  analogWrite(mEa, velD);
  analogWrite(mEb, velE);
  //----------------------------//
  //----Configuração sensores reflexivos infravermelho----//
  pinMode(infra1, INPUT);
  pinMode(infra2, INPUT);
  pinMode(infra3, INPUT);
  //-----------------------------------------------------//
}

void loop() {
  atualizarMapa();

  int leitura[3];
  leitura[0] = (mapaDaPista[0][2] * 4) + (mapaDaPista[0][1] * 2) + (mapaDaPista[0][0] * 1); //convertendo para um numero inteiro
  leitura[1] = (mapaDaPista[1][2] * 4) + (mapaDaPista[1][1] * 2) + (mapaDaPista[1][0] * 1); //convertendo para um numero inteiro
  leitura[2] = (mapaDaPista[2][2] * 4) + (mapaDaPista[2][1] * 2) + (mapaDaPista[2][0] * 1); //convertendo para um numero inteiro
  
  andar(velD, velE, 0, 0, 0, 0); //Parando
  delay(tempDeParada);
 
  if (leitura[0] == 0 && leitura[1] == 0 && leitura[2] == 0) { 
    andar(velD, velE, 0, 1, 0, 1); 
    delay(passoDeReta);
  }
  if (leitura == 1) { // Anda para esquerda
    andar(velD, velE, 0, 1, 0, 0); //Roda o motor da Direita para frente 
    delay(passoDeCurva);
  }
  if (leitura == 3) { // Anda para esquerda
    andar(velD, velE, 0, 1, 0, 0); //Roda o motor da Direita para frente 
    delay(passoDeCurva);
  }
  if (leitura == 4) { // Anda para direita
    andar(velD, velE, 0, 0, 0, 1); //Roda o motor da Esquerda para frente
    delay(passoDeCurva);
  }
  if (leitura == 5 ) { //Para frente
    andar(velD, velE, 0, 1, 0, 1); 
    delay(passoDeReta);
  }
  if (leitura == 6 ) { // Anda para direita
    andar(velD, velE, 0, 0, 0, 1); //Roda o motor da Esquerda para frente
    delay(passoDeCurva);
  }
  if (leitura == 7 ) { // Stop
    andar(velD, velE, 0, 1, 0, 1); 
    delay(passoDeReta);
  }

}
void andar(int velocidadeD, int velocidadeE, int motorDa, int motorDb, int motorEa, int motorEb) {
  analogWrite(velmotorD, velocidadeD);
  analogWrite(velmotorE, velocidadeE);
  // muda o estado do Motor Direito
  digitalWrite(mDa, motorDa);
  digitalWrite(mDb, motorDb);
  // muda o estado do Motor Esquerdo
  digitalWrite(mEa, motorEa);
  digitalWrite(mEb, motorEb);
}
void atualizarMapa(){
  for(int j = 2; j > 0; j--){
    for(int i = 0; i < 3; i++){
      mapaDaPista[j][i]=mapaDaPista[j-1][i];
    }
  }
//OLHANDO DE TRAS PARA FRENTE
   mapaDaPista[0][0]= digitalRead(infraEsquerdo);
   mapaDaPista[0][1]= digitalRead(infraMeio);
   mapaDaPista[0][2]= digitalRead(infraDireito);
  }