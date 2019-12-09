#include "WiFiEsp.h"; //INCLUSÃO DA BIBLIOTECA
#include "SoftwareSerial.h";//INCLUSÃO DA BIBLIOTECA
#include "WiffiClass.h";



SoftwareSerial Serial1(6, 7); 
WiFiEspServer server(80); //CONEXÃO REALIZADA NA PORTA 80
RingBuffer buf(8); //BUFFER PARA AUMENTAR A VELOCIDADE E REDUZIR A ALOCAÇÃO DE MEMÓRIA




  
WiffiObject wf(Serial1, server);

void setup(){
  char ssid[] = "rep_NETVIRTUA_02_2.4G";
  char pass[] = "148477427";
  pinMode(LED_BUILTIN, OUTPUT); //DEFINE O PINO COMO SAÍDA (LED_BUILTIN = PINO 13)
  digitalWrite(LED_BUILTIN, LOW); //PINO 13 INICIA DESLIGADO
  Serial.begin(9600); //INICIALIZA A SERIAL
  Serial1.begin(9600); //INICIALIZA A SERIAL PARA O ESP8266
  WiFi.init(&Serial1); //INICIALIZA A COMUNICAÇÃO SERIAL COM O ESP8266
  WiFi.config(IPAddress(192,168,0,35)); //COLOQUE UMA FAIXA DE IP DISPONÍVEL DO SEU ROTEADOR
  
  //INÍCIO - VERIFICA SE O ESP8266 ESTÁ CONECTADO AO ARDUINO, CONECTA A REDE SEM FIO E INICIA O WEBSERVER
  if(WiFi.status() == WL_NO_SHIELD){
    while (true);
  }
  while(wf.status != WL_CONNECTED){
    wf.status = WiFi.begin(ssid, pass);
  }
  server.begin();

  Wire.begin();
  Wire.beginTransmission(0x68);
  Wire.write(0x6B); 
   
  //Inicializa o MPU-6050
  Wire.write(0); 
  Wire.endTransmission(true);   

}

void loop(){
 wf.update(server, buf);
}
