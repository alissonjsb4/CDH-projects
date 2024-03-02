//----Configuração motores----//
#define velmotorD 2 // Motor direito
#define velmotorE 3 // Motor esquerdo
#define mEa 4 // Motor esquerdo 
#define mEb 5 // Motor esquerdo
#define mDa 6 // Motor direito
#define mDb 7 // Motor direito

//Motor D com problema em aceitar velocidades abaixo de 128
int velD = 130; //Motor Direito
int velE = 130; //Motor Esquerdo
//----------------------------//

//----Configuração sensores reflexivos infravermelho----//
//OLHANDO DE TRAS PARA FRENTE
#define infraEsquerdo 8 // 1 da esquerda para direita
#define infraMeio 9 // 2 da esquerda para direita
#define infraDireito 10 // 3 da esquerda para direita
//OLHANDO DE TRAS PARA FRENTE
int leitura = 0;
int leituraEsquerda = 0; // 1 da esquerda para direita
int leituraMeio = 0; // 2 da esquerda para direita
int leituraDireita = 0; // 3 da esquerda para direita
//-----------------------------------------------------//
//----------Matriz que representa o percurso --------------//
int mapaDaPista[3]={-1,-1,-1};
//--------------------------------------------------------//
//----Variavel de tempo----//
int passoDeReta = 25; // Tempo em que motor vai ficar acionado para retas
int passoDeCurva = 45; // Tempo em que motor vai ficar acionado para curvas
int tempDeParada = 130;
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
  pinMode(infraEsquerdo, INPUT);
  pinMode(infraMeio, INPUT);
  pinMode(infraDireito, INPUT);
  //-----------------------------------------------------//
}

void loop() {
  estadoInicial();
  estadoAtual();
  Serial.print(mapaDaPista[0]);
  Serial.print(" ");
  Serial.print(mapaDaPista[1]);
  Serial.print(" ");
  Serial.println(mapaDaPista[2]);
}
void estadoInicial(){
  atualizarMapa();
  while(mapaDaPista[0] == -1 || mapaDaPista[1] == -1 || mapaDaPista[2] == -1){
    frente();
    atualizarMapa();
  }  
  
}
void estadoAtual(){
    atualizarMapa(); 
//-----------------Casos Comuns----------------------// 
    if(mapaDaPista[0] == 0 && mapaDaPista[1] == 0 && mapaDaPista[2] == 0){
      frente();
    }
    if(mapaDaPista[0] == 7 && mapaDaPista[1] == 7 && mapaDaPista[2] == 7){
      frente();
    }
    else if(mapaDaPista[0] == 2 && mapaDaPista[1] == 2 && mapaDaPista[2] == 2){
      frente();
    }
    else if(mapaDaPista[0] == 0 && mapaDaPista[1] == 2 && mapaDaPista[2] == 2){
      frente();
    }
    else if(mapaDaPista[0] == 0 && mapaDaPista[1] == 0 && mapaDaPista[2] == 2){
      frente();
    }
    else if(mapaDaPista[0] == 2 && mapaDaPista[1] == 0 && mapaDaPista[2] == 2){
      frente();
    }
    else if(mapaDaPista[0] == 2 && mapaDaPista[1] == 2 && mapaDaPista[2] == 0){
      frente();
    }
    else if(mapaDaPista[0] == 2 && mapaDaPista[1] == 0 && mapaDaPista[2] == 0){
      frente();
    }
    else if(mapaDaPista[0] == 4 && mapaDaPista[1] == 4 && mapaDaPista[2] == 4){
      direita();
    }
    else if(mapaDaPista[0] == 4 && mapaDaPista[1] == 4 && mapaDaPista[2] == 2){
      direita();
    }
    else if(mapaDaPista[0] == 4 && mapaDaPista[1] == 2 && mapaDaPista[2] == 4){
      direita();
    }
    else if(mapaDaPista[0] == 4 && mapaDaPista[1] == 4 && mapaDaPista[2] == 2){
      direita();
    }
    else if(mapaDaPista[0] == 4 && mapaDaPista[1] == 2 && mapaDaPista[2] == 2){
      direita();
    }
    else if(mapaDaPista[0] == 0 && mapaDaPista[1] == 4 && mapaDaPista[2] == 4){
      direita();
    }
    else if(mapaDaPista[0] == 2 && mapaDaPista[1] == 2 && mapaDaPista[2] == 4){
      direita();
    }
    else if(mapaDaPista[0] == 2 && mapaDaPista[1] == 4 && mapaDaPista[2] == 4){
      direita();
    }
    else if(mapaDaPista[0] == 6 && mapaDaPista[1] == 6 && mapaDaPista[2] == 6){
      direita();
    }
    else if(mapaDaPista[0] == 6 && mapaDaPista[1] == 2 && mapaDaPista[2] == 6){
      direita();
    }
    else if(mapaDaPista[0] == 6 && mapaDaPista[1] == 6 && mapaDaPista[2] == 2){
      direita();
    }
    else if(mapaDaPista[0] == 6 && mapaDaPista[1] == 2 && mapaDaPista[2] == 2){
      direita();
    }
    else if(mapaDaPista[0] == 2 && mapaDaPista[1] == 2 && mapaDaPista[2] == 6){
      direita();
    }
    else if(mapaDaPista[0] == 2 && mapaDaPista[1] == 6 && mapaDaPista[2] == 6){
      direita();
    }
    else if(mapaDaPista[0] == 4 && mapaDaPista[1] == 6 && mapaDaPista[2] == 2){
      direita();
    }
    else if(mapaDaPista[0] == 0 && mapaDaPista[1] == 0 && mapaDaPista[2] == 6){
      direita();
    }
    else if(mapaDaPista[0] == 6 && mapaDaPista[1] == 6 && mapaDaPista[2] == 4){
      direita();
    }
    else if(mapaDaPista[0] == 4 && mapaDaPista[1] == 6 && mapaDaPista[2] == 6){
      direita();
    }
    if(mapaDaPista[0] == 7 && mapaDaPista[1] == 7 && mapaDaPista[2] == 6){
      direita();
    }
    if(mapaDaPista[0] == 6 && mapaDaPista[1] == 6 && mapaDaPista[2] == 7){
      direita();
    }
    else if(mapaDaPista[0] == 2 && mapaDaPista[1] == 2 && mapaDaPista[2] == 6){
      direita();
    }
    else if(mapaDaPista[0] == 1 && mapaDaPista[1] == 1 && mapaDaPista[2] == 1){
      esquerda();
    }
    else if(mapaDaPista[0] == 1 && mapaDaPista[1] == 1 && mapaDaPista[2] == 2){
      esquerda();
    }
    else if(mapaDaPista[0] == 1 && mapaDaPista[1] == 2 && mapaDaPista[2] == 2){
      esquerda();
    }
    else if(mapaDaPista[0] == 2 && mapaDaPista[1] == 2 && mapaDaPista[2] == 1){
      frente();
    }
    else if(mapaDaPista[0] == 2 && mapaDaPista[1] == 1 && mapaDaPista[2] == 1){
      frente();
    }
    else if(mapaDaPista[0] == 3 && mapaDaPista[1] == 3 && mapaDaPista[2] == 3){
      esquerda();
    }
    else if(mapaDaPista[0] == 3 && mapaDaPista[1] == 3 && mapaDaPista[2] == 2){
      esquerda();
    }
    else if(mapaDaPista[0] == 3 && mapaDaPista[1] == 2 && mapaDaPista[2] == 2){
      esquerda();
    }
    else if(mapaDaPista[0] == 3 && mapaDaPista[1] == 3 && mapaDaPista[2] == 1){
      esquerda();
    }
    else if(mapaDaPista[0] == 0 && mapaDaPista[1] == 3 && mapaDaPista[2] == 3){
      esquerda();
    }
    else if(mapaDaPista[0] == 2 && mapaDaPista[1] == 2 && mapaDaPista[2] == 3){
      esquerda();
    }
    else if(mapaDaPista[0] == 2 && mapaDaPista[1] == 3 && mapaDaPista[2] == 3){
      esquerda();
    }
    else if(mapaDaPista[0] == 1 && mapaDaPista[1] == 3 && mapaDaPista[2] == 2){
      esquerda();
    }
//-----------------Casos De 90 gruas----------------------// 
    else if(mapaDaPista[0] == 0 && mapaDaPista[1] == 1 && mapaDaPista[2] == 2){
      esquerda90graus();
    }
    else if(mapaDaPista[0] == 0 && mapaDaPista[1] == 3 && mapaDaPista[2] == 2){
      esquerda90graus();
    }
    else if(mapaDaPista[0] == 0 && mapaDaPista[1] == 4 && mapaDaPista[2] == 2){
      direita90graus();
    }
    else if(mapaDaPista[0] == 0 && mapaDaPista[1] == 6 && mapaDaPista[2] == 2){
      direita90graus();
    }
    else if(mapaDaPista[0] == 7 && mapaDaPista[1] == 3 && mapaDaPista[2] == 2){
      esquerda90graus();
    }
    else if(mapaDaPista[0] == 7 && mapaDaPista[1] == 6 && mapaDaPista[2] == 2){
      direita90graus();
    }
//-------------Caso de Cruz--------------//
    else if(mapaDaPista[0] == 2 && mapaDaPista[1] == 7 && mapaDaPista[2] == 2){
      frente();
    }
    else if(mapaDaPista[0] == 7 && mapaDaPista[1] == 7 && mapaDaPista[2] == 2){
      frente();
    }
    else if(mapaDaPista[0] == 2 && mapaDaPista[1] == 7 && mapaDaPista[2] == 2){
      frente();
    }
//-------------Caso de corte na pista--------------//
    else if(mapaDaPista[0] == 2 && mapaDaPista[1] == 0 && mapaDaPista[2] == 0){
      frente();
    }
    else if(mapaDaPista[0] == 0 && mapaDaPista[1] == 0 && mapaDaPista[2] == 2){
      frente();
    }
    else if(mapaDaPista[0] == 2 && mapaDaPista[1] == 0 && mapaDaPista[2] == 2){
      frente();
    }
}
void atualizarMapa(){
  for(int j = 2; j > 0; j--){
    mapaDaPista[j]=mapaDaPista[j-1]; //Atualização do historico
  }
//OLHANDO DE TRAS PARA FRENTE
   mapaDaPista[0]= digitalRead(infraEsquerdo) * 1 + digitalRead(infraMeio) * 2 + digitalRead(infraDireito) * 4; //Primeira leitura convertendo para um numero inteiro
}
void parar(){
  mover(velD, velE, 0, 0, 0, 0); //Parando
  delay(tempDeParada);
}
void frente(){
  mover(velD, velE, 0, 1, 0, 1); // Frente
  delay(passoDeReta);
  parar();
  atualizarMapa();    
}
void recuar(){
  mover(velD, velE, 1, 0, 1, 0); // re
  delay(passoDeReta);
  atualizarMapa();    
}
void direita(){
  mover(velD, velE, 0, 1, 0, 0); //Roda o motor da Direita para frente  
  delay(passoDeCurva);
  parar();    
  atualizarMapa();    
}
void direita90graus(){
  //passoDeCurva = 250;
  mover(velD, velE, 0, 1, 0, 0); //Roda o motor da Direita para frente  
  delay(250);    
  atualizarMapa();    
}
void esquerda(){
  mover(velD, velE, 0, 0, 0, 1); //Roda o motor da Esquerda para frente
  delay(passoDeCurva);
  parar();      
  atualizarMapa();    
}
void esquerda90graus(){
  //passoDeCurva = 250;
  mover(velD, velE, 0, 0, 0, 1); //Roda o motor da Esquerda para frente
  delay(250);    
  atualizarMapa();    
}

void mover(int velocidadeD, int velocidadeE, int motorDa, int motorDb, int motorEa, int motorEb) {
  analogWrite(velmotorD, velocidadeD);
  analogWrite(velmotorE, velocidadeE);
  // muda o estado do Motor Direito
  digitalWrite(mDa, motorDa);
  digitalWrite(mDb, motorDb);
  // muda o estado do Motor Esquerdo
  digitalWrite(mEa, motorEa);
  digitalWrite(mEb, motorEb);
}