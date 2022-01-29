/*
  Titre      : Testeur RJ45
  Auteur     : Anis Aliouachene
  Date       : 28/01/2022
  Description: Un microcontroleur qui teste si un cable RJ45 est fonctionnel ou non  
  Version    : 0.0.1
*/


#include <Arduino.h>
#include<Cable.h>

// Cote 1 OUTPUT
const int FILS_ORANGE_BLANC = 15;
const int FILS_ORANGE = 2;
const int FILS_VERT_BLANC = 4;
const int FILS_VERT = 19;
const int FILS_BLUE_BLANC = 18;
const int FILS_BLUE= 5;
const int FILS_MARRON_BLANC = 21;
const int FILS_MARRON = 22;

// Cote 2 INPUT
const int FILS_ORANGE_BLANC_2= 32;
const int FILS_ORANGE_2= 33;
const int FILS_VERT_BLANC_2= 25;
const int FILS_VERT_2= 14;
const int FILS_BLUE_BLANC_2= 27;
const int FILS_BLUE_2= 26;
const int FILS_MARRON_BLANC_2= 12;
const int FILS_MARRON_2= 13;

// Declaration deux objet de class cable
Cable Cote1(FILS_ORANGE_BLANC, FILS_ORANGE, FILS_VERT_BLANC, FILS_VERT, FILS_BLUE_BLANC, FILS_BLUE, FILS_MARRON_BLANC, FILS_MARRON); 
Cable Cote2(FILS_ORANGE_BLANC_2, FILS_ORANGE, FILS_VERT_BLANC_2, FILS_VERT_2, FILS_BLUE_BLANC_2, FILS_BLUE_2, FILS_MARRON_BLANC_2, FILS_MARRON_2);

// variable boolean pour fonctionnement  
bool Fonctionnement; 

void setup() {
  
  // Configuration des broches de chaque objet 
  Cote1.OutputMode();
  Cote2.InputMode(); 
  Serial.begin(9600);

}

void loop() {

  // Initialisation
   Fonctionnement = true; 
   
   // Envoi et Reception des signal entre les broches
   Cote1.EnvoiSignal(FILS_ORANGE_BLANC); 
   Cote2.ReceipSignal(FILS_ORANGE_BLANC_2); 
   Fonctionnement = Cote2.TestReceipSignal(FILS_ORANGE_BLANC_2); 

   Cote1.EnvoiSignal(FILS_ORANGE); 
   Cote2.ReceipSignal(FILS_ORANGE_2); 
   Fonctionnement = Cote2.TestReceipSignal(FILS_ORANGE_2); 

   Cote1.EnvoiSignal(FILS_VERT_BLANC); 
   Cote2.ReceipSignal(FILS_VERT_BLANC_2); 
   Fonctionnement = Cote2.TestReceipSignal(FILS_VERT_BLANC_2); 

   Cote1.EnvoiSignal(FILS_VERT); 
   Cote2.ReceipSignal(FILS_VERT_2);
   Fonctionnement = Cote2.TestReceipSignal(FILS_VERT_2); 

   Cote1.EnvoiSignal(FILS_BLUE_BLANC); 
   Cote2.ReceipSignal(FILS_BLUE_BLANC_2);
   Fonctionnement = Cote2.TestReceipSignal(FILS_BLUE_BLANC_2);  

   Cote1.EnvoiSignal(FILS_BLUE); 
   Cote2.ReceipSignal(FILS_BLUE_2);
   Fonctionnement = Cote2.TestReceipSignal(FILS_BLUE_2);  
   
   Cote1.EnvoiSignal(FILS_MARRON_BLANC); 
   Cote2.ReceipSignal(FILS_MARRON_BLANC_2); 
   Fonctionnement = Cote2.TestReceipSignal(FILS_MARRON_BLANC_2); 

   Cote1.EnvoiSignal(FILS_MARRON); 
   Cote2.ReceipSignal(FILS_MARRON_2); 
   Fonctionnement = Cote2.TestReceipSignal(FILS_MARRON_2); 

  // Affichage si le cable est fonctionnel 
  if (Fonctionnement)
  {
    Serial.println("Le cable est fonctionnel");
    delay(1000);
  }
  else {
    Serial.println("Le cable n'est pas fonctionnel");
    delay(1000);
  }

}
