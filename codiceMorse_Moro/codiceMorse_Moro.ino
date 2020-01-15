
#define sensore A5
#define led 13
int luminosità;
int inizio;

String s;

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
  s = "";
  inizio = 0;
  

}

void loop() {
  // put your main code here, to run repeatedly:
 if

}

void ricevere() {
  luminosità = analogRead(A5);
  if(luminosità >= 500 {
    inizio = millis()
    if(digitalRead(led) == LOW && inizio)
  } 
}
