#include <stdio.h>
#include <stdlib.h>
#define sensore A5 

int luminosita;
int inizio;
int fine;
int tempo;
String morse;
char app; 
String codice[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
               "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}; //codice morse
                   
char alfabeto[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
                   'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '.'}; //alfabeto
                       

typedef struct nodo {
  String car;
  struct nodo *next;
}Lista;

Lista* lista = NULL;




void setup() {
  // put your setup code here, to run once:
   

  pinMode(sensore, INPUT);
  Serial.begin(9600);
  morse = "";
  tempo = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  while(tempo < 1950) {
    ricevere();
  }
  traduci();
  morse = "";
}

void ricevere() {
  
  luminosita = analogRead(sensore);
  if(luminosita >= 500) {
    inizio = millis();  
  }
  while(luminosita >= 500) {}
  fine = millis();
  tempo = fine - inizio;

   if(tempo >= 450 && tempo <= 550) {
    morse = morse + ".";
  }
  else if(tempo >= 950 && tempo <= 1050) {
    morse = morse + "-";
  }
  else if(tempo >= 1950 && tempo <= 2050) {
    
  }
}

void traduci() {
  
  for(int c = 0; c < codice; c++) {
    if(codice[c] == morse) {
      app = alfabeto[c];
    }
  } 
}

Lista* creaNodo(char app)
{
  Lista* n = (Lista*)malloc(sizeof(Lista));
  n-> car = app;
  n-> next = NULL;
  return n;
}

Lista* insNodoTesta(Lista* l, char app)
{
  Lista* n = creaNodo(app);
  n-> next = NULL;
  return n;
}
