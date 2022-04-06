#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
WiFiClient client;
WiFiServer server(80);
#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
SoftwareSerial mySerial(2, 0);
#else
#define mySerial Serial1
#endif
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
//===========  Datos de la RED WiFi =========== 

#define WIFI_SSID "ISTLTPUNTO2" // Nombre del wifi
#define WIFI_PASSWORD "ADISTLT2022" // Contraseña del wifi

//===========  ===========  =========== 
//Autentificacion 
#define FIREBASE_HOST "huellasdactilales-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "pXSZoaBxCNlcf0aISMk09p9O2KtN0L3Rz13yUQhr"
FirebaseData fbdo;
#define Cerradura 5
#define led_verde  12 //D6
#define led_rojo  14 //D5
#define led_azul  13 //D7
String dato ="";
uint8_t id;
int huella;
int huellaE;
int accion=0;
void setup(){
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("------------------------------------");
  Serial.print("Conectando a su red Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();

  server.begin();
  Serial.println("Servidor Iniciado");
  Serial.print("Conectado con la IP: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  String path = "/Test";
  Serial.println("------------------------------------");
  pinMode(Cerradura, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  pinMode(led_azul, OUTPUT);
  finger.begin(57600);
  if (finger.verifyPassword()) {
    Serial.println("Sensor de huellas dactilares encontrado!");
    digitalWrite(led_verde,HIGH);
    delay(90);
  } else {
    Serial.println("No encontré el sensor de huellas dactilares:(");
    while (1) {
    digitalWrite(led_rojo,HIGH);
    delay(90);
     }
  }   
}
void loop(){   
  getFingerprintIDez();
  delay(50);
   client = server.available();
   if (!client) 
   return; 
   dato = checkClient(); 
  
//=====================================================================================================
   if (dato == "Agregar"){
   Serial.println("Listo para agregar una huella digital!");
   Serial.println("Esperando el número de ID (de 1 a 127) para guardar la huella...");   
   }
   if ( dato == "Mostrar") {
    Mostrar();
   }

  if (dato == "Eliminar"){
      Serial.println("Esperando el número ID (de 1 a 127) que desea eliminar...");
  } 

  if (dato == "Borrar"){
  Serial.println("\n\nPra eliminar todas las plantillas de huellas digitales!");
  Serial.println("Presione en 'Confirmar' ");
  }   
  
  if (dato == "Y"){
    BorrarTodo();
  }
//////////////////////////////////////////////////////////////////////////////////////////
//////////
////////// 
//=============================NUMERO DE HUELLAS PARA AGREGAR=============================
//////////
//////////
////////////////////////////////////////////////////////////////////////////////////////// 
  if (dato == "uno"){   
    huella= 1;
   Agregar();
  }
  if (dato == "dos"){   
    huella= 2;
   Agregar();
  }
  if (dato == "tres"){   
    huella= 3;
   Agregar();
  }
  if (dato == "cuatro"){   
    huella= 4;
   Agregar();
  }
  if (dato == "cinco"){   
    huella= 5;
   Agregar();
  }
  if (dato == "seis"){   
    huella= 6;
   Agregar();
  }
  if (dato == "siete"){   
    huella= 7;
   Agregar();
  }
  if (dato == "ocho"){   
    huella= 8;
   Agregar();
  }
  if (dato == "nueve"){   
    huella= 9;
   Agregar();
  }
  if (dato == "dies"){   
    huella= 10;
   Agregar();
  }
  if (dato == "once"){   
    huella= 11;
   Agregar();
  }
  if (dato == "doce"){   
    huella= 12;
   Agregar();
  }
  if (dato == "trece"){   
    huella= 13;
   Agregar();
  }
  if (dato == "catorce"){   
    huella= 14;
   Agregar();
  }
  if (dato == "quince"){   
    huella= 15;
   Agregar();
  }
  if (dato == "dieciseis"){   
    huella= 16;
   Agregar();
  }
  if (dato == "diecisiete"){   
    huella= 17;
   Agregar();
  }
  if (dato == "dieciocho"){   
    huella= 18;
   Agregar();
  }
  if (dato == "diecinueve"){   
    huella= 19;
   Agregar();
  }
  if (dato == "veinte"){   
    huella= 20;
   Agregar();
  }

  //20==============================================================================================30
  
  if (dato == "veinteuno"){   
    huella= 21;
   Agregar();
  }
  if (dato == "veintedos"){   
    huella= 22;
   Agregar();
  }
  if (dato == "veintetres"){   
    huella= 23;
   Agregar();
  }
  if (dato == "veintecuatro"){   
    huella= 24;
   Agregar();
  }
  if (dato == "veintecinco"){   
    huella= 25;
   Agregar();
  }
  if (dato == "veinteseis"){   
    huella= 26;
   Agregar();
  }
  if (dato == "veintesiete"){   
    huella= 27;
   Agregar();
  }
  if (dato == "veinteocho"){   
    huella= 28;
   Agregar();
  }
  if (dato == "veintenueve"){   
    huella= 29;
   Agregar();
  }
  if (dato == "treinta"){   
    huella= 30;
   Agregar();
  }
  
  //30==============================================================================================40

  if (dato == "treintauno"){   
    huella= 31;
   Agregar();
  }
  if (dato == "treintados"){   
    huella= 32;
   Agregar();
  }
  if (dato == "treintatres"){   
    huella= 33;
   Agregar();
  }
  if (dato == "treintacuatro"){   
    huella= 34;
   Agregar();
  }
  if (dato == "treintacinco"){   
    huella= 35;
   Agregar();
  }
  if (dato == "treintaseis"){   
    huella= 36;
   Agregar();
  }
  if (dato == "treintasiete"){   
    huella= 37;
   Agregar();
  }
  if (dato == "treintaocho"){   
    huella= 38;
   Agregar();
  }
  if (dato == "treintanueve"){   
    huella= 39;
   Agregar();
  }
  if (dato == "cuarenta"){   
    huella= 40;
   Agregar();
  }
 
  //40==============================================================================================50

  if (dato == "cuarentauno"){   
    huella= 41;
   Agregar();
  }
  if (dato == "cuarentados"){   
    huella= 42;
   Agregar();
  }
  if (dato == "cuarentatres"){   
    huella= 43;
   Agregar();
  }
  if (dato == "cuarentacuatro"){   
    huella= 44;
   Agregar();
  }
  if (dato == "cuarentacinco"){   
    huella= 45;
   Agregar();
  }
  if (dato == "cuarentaseis"){   
    huella= 46;
   Agregar();
  }
  if (dato == "cuarentasiete"){   
    huella= 47;
   Agregar();
  }
  if (dato == "cuarentaocho"){   
    huella= 48;
   Agregar();
  }
  if (dato == "cuarentanueve"){   
    huella= 49;
   Agregar();
  }
  if (dato == "cincuenta"){   
    huella= 50;
   Agregar();
  }

  //50==============================================================================================60

   if (dato == "cincuentauno"){   
    huella= 51;
   Agregar();
  }
  if (dato == "cincuentados"){   
    huella= 52;
   Agregar();
  }
  if (dato == "cincuentatres"){   
    huella= 53;
   Agregar();
  }
  if (dato == "cincuentacuatro"){   
    huella= 54;
   Agregar();
  }
  if (dato == "cincuentacinco"){   
    huella= 55;
   Agregar();
  }
  if (dato == "cincuentaseis"){   
    huella= 56;
   Agregar();
  }
  if (dato == "cincuentasiete"){   
    huella= 57;
   Agregar();
  }
  if (dato == "cincuentaocho"){   
    huella= 58;
   Agregar();
  }
  if (dato == "cincuentanueve"){   
    huella= 59;
   Agregar();
  }
  if (dato == "sesenta"){   
    huella= 60;
   Agregar();
  }

//////////////////////////////////////////////////////////////////////////////////////////
//////////
////////// 
  //=============================NUMERO DE HUELLAS PARA ELIMINAR=============================
//////////
//////////
//////////////////////////////////////////////////////////////////////////////////////////

  if (dato == "unoE"){   
    huellaE= 1;
   Eliminar();
  }
  if (dato == "dosE"){   
    huellaE= 2;
   Eliminar();
  }
  if (dato == "tresE"){   
    huellaE= 3;
   Eliminar();
  }
  if (dato == "cuatroE"){   
    huellaE= 4;
   Eliminar();
  }
  if (dato == "cincoE"){   
    huellaE= 5;
   Eliminar();
  }
  if (dato == "seisE"){   
    huellaE= 6;
   Eliminar();
  }
  if (dato == "sieteE"){   
    huellaE= 7;
   Eliminar();
  }
  if (dato == "ochoE"){   
    huellaE= 8;
   Eliminar();
  }
  if (dato == "nueveE"){   
    huellaE= 9;
   Eliminar();
  }
  if (dato == "diesE"){   
    huellaE= 10;
   Eliminar();
  }
  if (dato == "onceE"){   
    huellaE= 11;
   Eliminar();
  }
  if (dato == "doceE"){   
    huellaE= 12;
   Eliminar();
  }
  if (dato == "treceE"){   
    huellaE= 13;
   Eliminar();
  }
  if (dato == "catorceE"){   
    huellaE= 14;
   Eliminar();
  }
  if (dato == "quinceE"){   
    huellaE= 15;
   Eliminar();
  }
  if (dato == "dieciseisE"){   
    huellaE= 16;
   Eliminar();
  }
  if (dato == "diecisieteE"){   
    huellaE= 17;
   Eliminar();
  }
  if (dato == "dieciochoE"){   
    huellaE= 18;
   Eliminar();
  }
  if (dato == "diecinueveE"){   
    huellaE= 19;
   Eliminar();
  }
  if (dato == "veinteE"){   
    huellaE= 20;
   Eliminar();
  }

  //20==============================================================================================30
  
  if (dato == "veinteunoE"){   
    huellaE= 21;
   Agregar();
  }
  if (dato == "veintedosE"){   
    huellaE= 22;
   Agregar();
  }
  if (dato == "veintetresE"){   
    huellaE= 23;
   Agregar();
  }
  if (dato == "veintecuatroE"){   
    huellaE= 24;
   Agregar();
  }
  if (dato == "veintecincoE"){   
    huellaE= 25;
   Agregar();
  }
  if (dato == "veinteseisE"){   
    huellaE= 26;
   Agregar();
  }
  if (dato == "veintesieteE"){   
    huellaE= 27;
   Agregar();
  }
  if (dato == "veinteocho"){   
    huellaE= 28;
   Agregar();
  }
  if (dato == "veintenueveE"){   
    huellaE= 29;
   Agregar();
  }
  if (dato == "treintaE"){   
    huellaE= 30;
   Agregar();
  }
  
  //30==============================================================================================40

  if (dato == "treintaunoE"){   
    huellaE= 31;
   Agregar();
  }
  if (dato == "treintadosE"){   
    huellaE= 32;
   Agregar();
  }
  if (dato == "treintatresE"){   
    huellaE= 33;
   Agregar();
  }
  if (dato == "treintacuatroE"){   
    huellaE= 34;
   Agregar();
  }
  if (dato == "treintacincoE"){   
    huellaE= 35;
   Agregar();
  }
  if (dato == "treintaseisE"){   
    huellaE= 36;
   Agregar();
  }
  if (dato == "treintasieteE"){   
    huellaE= 37;
   Agregar();
  }
  if (dato == "treintaochoE"){   
    huellaE= 38;
   Agregar();
  }
  if (dato == "treintanueveE"){   
    huellaE= 39;
   Agregar();
  }
  if (dato == "cuarentaE"){   
    huellaE= 40;
   Agregar();
  }
 
  //40==============================================================================================50

  if (dato == "cuarentaunoE"){   
    huellaE= 41;
   Agregar();
  }
  if (dato == "cuarentadosE"){   
    huellaE= 42;
   Agregar();
  }
  if (dato == "cuarentatresE"){   
    huellaE= 43;
   Agregar();
  }
  if (dato == "cuarentacuatroE"){   
    huellaE= 44;
   Agregar();
  }
  if (dato == "cuarentacincoE"){   
    huellaE= 45;
   Agregar();
  }
  if (dato == "cuarentaseisE"){   
    huellaE= 46;
   Agregar();
  }
  if (dato == "cuarentasieteE"){   
    huellaE= 47;
   Agregar();
  }
  if (dato == "cuarentaochoE"){   
    huellaE= 48;
   Agregar();
  }
  if (dato == "cuarentanueveE"){   
    huellaE= 49;
   Agregar();
  }
  if (dato == "cincuentaE"){   
    huellaE= 50;
   Agregar();
  }

  //50==============================================================================================60

   if (dato == "cincuentaunoE"){   
    huellaE= 51;
   Agregar();
  }
  if (dato == "cincuentadosE"){   
    huellaE= 52;
   Agregar();
  }
  if (dato == "cincuentatresE"){   
    huellaE= 53;
   Agregar();
  }
  if (dato == "cincuentacuatroE"){   
    huellaE= 54;
   Agregar();
  }
  if (dato == "cincuentacincoE"){   
    huellaE= 55;
   Agregar();
  }
  if (dato == "cincuentaseisE"){   
    huellaE= 56;
   Agregar();
  }
  if (dato == "cincuentasieteE"){   
    huellaE= 57;
   Agregar();
  }
  if (dato == "cincuentaochoE"){   
    huellaE= 58;
   Agregar();
  }
  if (dato == "cincuentanueveE"){   
    huellaE= 59;
   Agregar();
  }
  if (dato == "sesentaE"){   
    huellaE= 60;
   Agregar();
  }

}
//////////
//////////
////////////////////////////////////////////////////////////////////////////////////////// 
String checkClient (void)
{
  while(!client.available()) delay(1); 
  String request = client.readStringUntil('\r');
  request.remove(0, 5);
  request.remove(request.length()-9,9);
  return request;
}

//////////
//////////
////////////////////////////////////////////////////////////////////////////////////////// 

 void Agregar (){
  
  id = huella;
  switch (id) {
  case 0:
   Serial.println("Continuar");
   break;
   
  case 1:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
  
  case 2:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 3:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 4:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 5:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 6:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 7:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 8:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 9:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 10:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 11:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 12:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 13:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 14:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 15:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 16:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 17:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 18:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 19:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 20:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  
  //20==============================================================================================30
  
  case 21:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
  
  case 22:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 23:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 24:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 25:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 26:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 27:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 28:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 29:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 30:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;

  //30==============================================================================================40
  
  case 31:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 32:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 33:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 34:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 35:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 36:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 37:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 38:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 39:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 40:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
  

  //40==============================================================================================50

  case 41:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
  
  case 42:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 43:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 44:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 45:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 46:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 47:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 48:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 49:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 50:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;

  //50==============================================================================================60
  
  case 51:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 52:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 53:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 54:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 55:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 56:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 57:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 58:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 59:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
   
  case 60:
   id = huella;
   Serial.println(huella);
   Serial.print("Añadiendo ID #");
   Serial.println(id);
   getFingerprintEnroll();
   break;
  }
        
 }

//////////
//////////
//////////////////////////////////////////////////////////////////////////////////////////  
  
uint8_t getFingerprintEnroll() {

  int p = -1;
  Serial.print("Coloque el dedo en el sensor para guardar como huella #"); Serial.println(id);
  accion=1;
  Firebase.setDouble(fbdo, "Realizar" , (accion));
  digitalWrite(led_verde,LOW);
  digitalWrite(led_azul,HIGH);
  
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image tomada");
      
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Error de comunicación");
      accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion));
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Error de imagen");
      accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion));
      break;
    default:
      Serial.println("Error desconocido");
      accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion));
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(1);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Imagen convertida");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Imagen demasiado desordenada");
      accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion)); 
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Error de comunicación");
      accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion)); 
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("No se pudieron encontrar las funciones de huellas dactilares");
      accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion));
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("No se pudieron encontrar las funciones de huellas dactilares");
      accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion));
      return p;
    default:
      Serial.println("Error desconocido");
      accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion));
      return p;
  }

  Serial.println("Quite el dedo");
  accion=2;
  Firebase.setDouble(fbdo, "Realizar" , (accion));
  digitalWrite(led_azul,LOW);
  digitalWrite(led_verde,HIGH);
  delay(3000);
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }
  Serial.print("ID "); Serial.println(id);
  p = -1;
  Serial.println("Coloque el mismo dedo de nuevo");
  accion=3;
  Firebase.setDouble(fbdo, "Realizar" , (accion));
      digitalWrite(led_azul,HIGH);
      digitalWrite(led_rojo,LOW);
      digitalWrite(led_verde,LOW);
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Imagen tomada");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Error de comunicación");
      accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion));
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Error de imagen");
      accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion));
      break;
    default:
      Serial.println("Error desconocido");
      accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion));
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(2);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Imagen convertida");
      
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion));
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion));
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion));
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion));
      return p;
    default:
      Serial.println("Unknown error");
      accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion));
      return p;
  }

  // OK converted!
  Serial.print("Creando modelo para #");  Serial.println(id);

  p = finger.createModel();
  if (p == FINGERPRINT_OK) {
    Serial.println("Los datos coinciden!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion));
    return p;
  } else if (p == FINGERPRINT_ENROLLMISMATCH) {
    Serial.println("Las huellas dactilares no coinciden");
    accion=4;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
    digitalWrite(led_verde,LOW);
    digitalWrite(led_azul,LOW);
    for(int a=0; a<=7; a++){
    digitalWrite(led_rojo,HIGH);
    delay(100);
    digitalWrite(led_rojo,LOW);
    delay(100);
    }
    digitalWrite(led_rojo,LOW);
    digitalWrite(led_verde,HIGH);
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
    
    return p;
  } else {
    Serial.println("Unknown error");
    accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion));
    return p;
  }

  Serial.print("ID "); Serial.println(id);
  p = finger.storeModel(id);
  if (p == FINGERPRINT_OK) {
    Serial.println("Agregada con exito!");
    digitalWrite(led_azul,LOW);
    accion=5;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
    for(int a=0; a<=9; a++){
    digitalWrite(led_verde,HIGH);
    delay(50);
    digitalWrite(led_verde,LOW);
    delay(50);
    } 
    digitalWrite(led_verde,HIGH);
    delay(5000);
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion));
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println("Could not store in that location");
    accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion));
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println("Error writing to flash");
    accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion));
    return p;
  } else {
    Serial.println("Unknown error");
    accion=0;
      Firebase.setDouble(fbdo, "Realizar" , (accion));
    return p;
  }

  

  return true;
}

//////////
//////////
//////////////////////////////////////////////////////////////////////////////////////////  

void Mostrar (){
   finger.getTemplateCount();
   Serial.print("El sensor contiene "); 
   Serial.print(finger.templateCount); 
   Serial.println(" plantillas");
}

//////////
//////////
//////////////////////////////////////////////////////////////////////////////////////////  

 void BorrarTodo (){
  while (1) {
    if (dato =="Y"){
      Serial.read() >= 'Y';  
    }
   {
      break;
    }
 }

  finger.emptyDatabase();
  digitalWrite(led_verde,LOW);
  Serial.println("Ahora la base de datos está vacía :)");
  digitalWrite(led_rojo,HIGH);
  delay(300);
  digitalWrite(led_rojo,LOW);
  delay(300);
  digitalWrite(led_rojo,HIGH);
  delay(300);
  digitalWrite(led_rojo,LOW);
  delay(300);
  digitalWrite(led_rojo,HIGH);
  delay(300);
  digitalWrite(led_rojo,LOW);
  delay(300);
  digitalWrite(led_verde,HIGH);
}

//////////
//////////
//////////////////////////////////////////////////////////////////////////////////////////  

void Eliminar(){
  id = huellaE;
  switch (id) {
  case 0:
   Serial.println("Continuar");
   break;
   
  case 1:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
  
  case 2:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 3:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 4:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 5:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminandoo ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 6:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 7:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 8:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 9:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 10:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 11:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 12:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 13:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 14:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 15:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 16:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 17:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 18:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 19:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 20:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
        

  //20==============================================================================================30

    case 21:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
  
  case 22:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 23:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 24:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 25:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminandoo ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 26:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 27:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 28:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 29:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 30:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
//30==============================================================================================40

    case 31:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
  
  case 32:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 33:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 34:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 35:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminandoo ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 36:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 37:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 38:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 39:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 40:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;

//40==============================================================================================50

    case 41:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
  
  case 42:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 43:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 44:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 45:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminandoo ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 46:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 47:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 48:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 49:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 50:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;

//50==============================================================================================60

    case 51:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
  
  case 52:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 53:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 54:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 55:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminandoo ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 56:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 57:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 58:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 59:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
   
  case 60:
   id = huellaE;
   Serial.println(huellaE);
   Serial.print("Eliminando ID #");
   Serial.println(id);
   deleteFingerprint(id);
   break;
}
}

//////////
//////////
////////////////////////////////////////////////////////////////////////////////////////// 

uint8_t deleteFingerprint(uint8_t id) {
  uint8_t p = -1;

  p = finger.deleteModel(id);

  if (p == FINGERPRINT_OK) {
    Serial.println("Huella eliminada!");
    accion=6;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
    digitalWrite(led_verde,LOW);
    for(int a=0; a<=9; a++){
    digitalWrite(led_rojo,HIGH);
    delay(50);
    digitalWrite(led_rojo,LOW);
    delay(50);
    }
    digitalWrite(led_rojo,LOW);
    digitalWrite(led_verde,HIGH);
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
    
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    accion=7;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println("No se pudo borrar la huella");
    accion=7;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println("Error writing to flash");
    accion=7;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
  } else {
    Serial.print("Unknown error: 0x"); Serial.println(p, HEX);
    accion=7;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
  }

  return p;
}



void abrirPuerta() {
  Serial.println(" HUELLA AUTORIZADA  "); 
  digitalWrite(Cerradura,HIGH);
  digitalWrite(led_verde,LOW);
    for(int a=0; a<=15; a++){
    digitalWrite(led_azul,HIGH);
    delay(50);
    digitalWrite(led_azul,LOW);
    delay(50);
    }
  delay(300);
  digitalWrite(Cerradura,LOW);
  digitalWrite(led_verde,HIGH);
}

void No_Registrado() {      // Activa el Buzzer 2 veces por tarjeta no autorizada
  Serial.println(" HUELLA NO REGISTRADA  "); 
  digitalWrite(Cerradura,LOW);
  accion=8;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
    digitalWrite(led_verde,LOW);
    for(int a=0; a<=25; a++){
    digitalWrite(led_rojo,HIGH);
    delay(40);
    digitalWrite(led_rojo,LOW);
    delay(40);
    }
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
    digitalWrite(led_verde,HIGH);
}


////////////////////////////////////////////////////////////////////////////////////////// 
//////////
//////////
////////////////Lectura///////////////////////
//////////
//////////
////////////////////////////////////////////////////////////////////////////////////////// 

int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK) { 
    No_Registrado();
    return -1;
  }


  // Si hay coincidencias de huella
  Serial.print("ID #"); Serial.print(finger.fingerID); 
  Serial.print(" coincidencia del "); Serial.println(finger.confidence);
   if(finger.fingerID==1){ 
    accion=10;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
    
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));  
   }
   if(finger.fingerID==2){
     accion=20;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==3){
     accion=30;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==4){
     accion=40;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==5){
     accion=50;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==6){
     accion=60;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==7){
     accion=70;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==8){
     accion=80;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==9){
     accion=90;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==10){
     accion=100;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }

   if(finger.fingerID==11){ 
    accion=110;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));  
   }
   if(finger.fingerID==12){
     accion=120;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==13){
     accion=130;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==14){
     accion=140;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==15){
     accion=150;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==16){
     accion=160;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==17){
     accion=170;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==18){
     accion=180;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==19){
     accion=190;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==20){
     accion=200;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }





   if(finger.fingerID==21){ 
    accion=210;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
    
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));  
   }
   if(finger.fingerID==22){
     accion=220;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==23){
     accion=230;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==24){
     accion=240;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==25){
     accion=250;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==26){
     accion=260;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==27){
     accion=270;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==28){
     accion=280;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==29){
     accion=290;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==30){
     accion=300;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }

   if(finger.fingerID==31){ 
    accion=310;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));  
   }
   if(finger.fingerID==32){
     accion=320;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==33){
     accion=330;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==34){
     accion=340;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==35){
     accion=350;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==36){
     accion=360;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==37){
     accion=370;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==38){
     accion=380;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==39){
     accion=390;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==40){
     accion=400;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }




   if(finger.fingerID==41){ 
    accion=410;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
    
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));  
   }
   if(finger.fingerID==42){
     accion=420;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==43){
     accion=430;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==44){
     accion=440;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==45){
     accion=450;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==46){
     accion=460;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==47){
     accion=470;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==48){
     accion=480;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==49){
     accion=490;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==50){
     accion=500;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }

   if(finger.fingerID==51){ 
    accion=510;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));  
   }
   if(finger.fingerID==52){
     accion=520;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==53){
     accion=530;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==54){
     accion=540;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==55){
     accion=550;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==56){
     accion=560;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==57){
     accion=570;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==58){
     accion=580;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==59){
     accion=590;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }
   if(finger.fingerID==60){
     accion=600;
    Firebase.setDouble(fbdo, "Realizar" , (accion)); 
     abrirPuerta();
    accion=0;
    Firebase.setDouble(fbdo, "Realizar" , (accion));
     
   }

//////////
//////////
//////////////////////////////////////////////////////////////////////////////////////////  
  return finger.fingerID; 
}
//////////                              FIN                                        //////////
////////////////////                                                  ////////////////////
//////////////////////////////////////////////////////////////////////////////////////////  
