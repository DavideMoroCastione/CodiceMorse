
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
  char car;
  struct nodo *next;
}Lista;

Lista* lista = NULL;

//-----------------------------------------------------------
void setup() {
  // put your setup code here, to run once:
  
  pinMode(sensore, INPUT);
  Serial.begin(9600);
  morse = "";
  tempo = 0;
  luminosita = 0;
  inizio = 0;
  fine = 0;
}

//------------------------------------------------------------
void loop() {
  // put your main code here, to run repeatedly:
    ricevere();
}

//-----------------------------------------------------------
void ricevere() {

  while(luminosita < 400) {
    luminosita = analogRead(sensore);
  }
  inizio = millis();  
  while(luminosita >= 400) {
     luminosita = analogRead(sensore);  
  }
  fine = millis();
  tempo = fine - inizio;
  
  if(tempo >= 450 && tempo <= 550) {
    morse = morse + '.';
  }
  else if(tempo >= 950 && tempo <= 1050) {
    morse = morse + '-';
  }
  else if(tempo >= 1950 && tempo <= 2050) {
    traduci();
    if(tempo >= 2300) {
      stampaLista(lista);
      Serial.print('.');
    }
  }
}

//-------------------------------------------------------------
void traduci() {
  
  for(int i = 0; i < 26; i++) {
    if(codice[i] == morse) {
      app = alfabeto[i];
    }
  }
  lista = insNodoCoda(lista, app);
  morse = "";
}

//--------------------------------------------------------------
Lista* creaNodo(char app) {
  
  Lista* n = (Lista*)malloc(sizeof(Lista));
  n->car = app;
  n->next = NULL;
  return n;
}

//---------------------------------------------------------------
Lista* insNodoCoda(Lista* l, char app) {
  
  if(l == NULL) {
    Lista* n = creaNodo(app);
    return n;
  }
  else {
    l->next = insNodoCoda(l->next, app);
    return l;
  }
}

//------------------------------------------------------------------
void stampaLista(Lista* l) {

  Lista* aiuto = l;
  char a;
  
  while(aiuto != NULL) {
    a = aiuto->car;
    Serial.println("--->");
    Serial.print(a);
    aiuto = aiuto->next;
  }
  lista = NULL;
}
