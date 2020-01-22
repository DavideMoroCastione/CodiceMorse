
#include <SPI.h>
#include <SD.h>

struct nodo {
  String car;
  struct nodo *tipo
}

#define sensore A5 //pin del sensore di luminosità
#define led 13 //pin del led
int luminosità;
int inizio;//variabile per il calcolo del tempo 
int fine;//variabile per il calcolo del tempo
String app; //stringa di appoggio

void setup() {
  // put your setup code here, to run once:
  String codice[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
                     "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}; //codice morse
                   
  String alfabeto[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", 
                       "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "."}; //alfabeto
                       
  pinMode(led, OUTPUT);
  pinMode(sensore, INPUT);
  Serial.begin(9600);
  luminosità = 0;
  app = "";
}

void loop() {
  // put your main code here, to run repeatedly:

  app = "";
}

void ricevere() {
  luminosità = analogRead(A5);
  if(luminosità >= 500) {
    if(digitalRead(led) == HIGH) {
      inizio = millis()
    }
    else if(digitalRead(led) == LOW) {
      fine = millis();
    }
  }
  if(fine - inizio <= 550 && fine - inizio >= 450) {
    app = app + "."
  }
  else if(fine - inizio <= 1050 && fine - inizio >= 950) {
    app = app + "-"
  }
  else if(fine - inizio <= 2050 && fine - inizio >= 1950) {
    for(int i = 0; i < app.length() - 1; i++) {
      if(app == codice[i])
      {
        
      }
    }
  } 
}
