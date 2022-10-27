#include <OneWire.h>
#include <DallasTemperature.h>


#define ONE_WIRE_BUS 4  //pino que recebe os dados do sensor
 
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

float pinosensor =4; //variavel que define a porta do sensor
int linha = 0; //variavel que se refere as linhas do excel
unsigned long tempoAnterior = 0; //variavel de controle de tempo
const long tempoNecessario = 1000; //tempo em milissegundos do intervalo a ser executado
  
void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(115200); //Inicia a serial
  //Inicia o objeto da biblioteca do Dallas
  sensors.begin();
  Serial.println("CLEARDATA"); //reset da comunicação serial
  Serial.println("Tempo, Valor"); //Nomeia as colunas
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long millisAtual = millis(); //tempo atual em milissegundos
  //logica de verificacao de tempo
  if(millisAtual - tempoAnterior > tempoNecessario){
    tempoAnterior = millisAtual; //salva o tempo atual
    sensors.requestTemperaturesByIndex(0);  //Envia o comando para obter temperaturas
    float leitura=sensors.getTempCByIndex(0); //define a temperatura em graus celsius
    Serial.println(leitura); //mostra a temperarura na tela
    linha++; //incrementa a linha do excel para que a leitura pule de linha
    Serial.print("DATA, TIME,"); //inicia a impressao dos dados
  }
}
