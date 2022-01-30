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
const int BROCHE_1 = 15;
const int BROCHE_2 = 2;
const int BROCHE_3 = 4;
const int BROCHE_4 = 5;
const int BROCHE_5 = 18;
const int BROCHE_6 = 19;
const int BROCHE_7 = 21;
const int BROCHE_8 = 22;

// Cote 2 INPUT
const int BROCHE_1_2= 32;
const int BROCHE_2_2= 33;
const int BROCHE_3_2= 25;
const int BROCHE_4_2= 26;
const int BROCHE_5_2= 27;
const int BROCHE_6_2= 14;
const int BROCHE_7_2= 12;
const int BROCHE_8_2= 13;

// Declaration deux objet de class cable
Cable Cote1(BROCHE_1, BROCHE_2, BROCHE_3, BROCHE_4, BROCHE_5, BROCHE_6, BROCHE_7, BROCHE_8); 
Cable Cote2(BROCHE_1_2, BROCHE_2_2, BROCHE_3_2, BROCHE_4_2, BROCHE_5_2, BROCHE_6_2, BROCHE_7_2, BROCHE_8_2);

// variable boolean pour fonctionnement  
bool Fonctionnement; 
int Valeur1, Valeur2;

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
  Cote1.EnvoiSignal(BROCHE_1);
  Serial.println(Valeur1);  
  Serial.println(Valeur2); 
  Serial.println("Debut");  
 

  Valeur1 = Cote2.ReceipSignal(BROCHE_1_2);
  Valeur2 = Cote2.ReceipSignal(BROCHE_3_2); 
  Serial.println(Valeur1);  
  Serial.println(Valeur2);  
  delay(1000); 
   
   if ( Valeur1 == 1){
            
            Serial.println("Le cable est de type Droit"); 

            Cote1.EnvoiSignal(BROCHE_2); 
            Cote2.ReceipSignal(BROCHE_2_2); 
            Fonctionnement= Cote2.TestReceipSignal(BROCHE_2_2);  
            if (Fonctionnement)  
              Serial.println("TEST 2 OK");
            else 
              Serial.println("TEST 2 Failed");

            delay(1000);

            Cote1.EnvoiSignal(BROCHE_3); 
            Cote2.ReceipSignal(BROCHE_3_2); 
            Fonctionnement= Cote2.TestReceipSignal(BROCHE_3_2); 
            if (Fonctionnement)  
              Serial.println("TEST 3 OK");
            else 
              Serial.println("TEST 3 Failed");


          delay(1000);
          Cote1.EnvoiSignal(BROCHE_4); 
          Cote2.ReceipSignal(BROCHE_4_2);
          Fonctionnement= Cote2.TestReceipSignal(BROCHE_4_2); 
          if (Fonctionnement) 
              Serial.println("TEST 4 OK");
          else 
              Serial.println("TEST 4 Failed");

          delay(1000);
          Cote1.EnvoiSignal(BROCHE_5); 
          Cote2.ReceipSignal(BROCHE_5_2);
          Fonctionnement= Cote2.TestReceipSignal(BROCHE_5_2);     
          if (Fonctionnement) 
              Serial.println("TEST 5 OK");
          else 
              Serial.println("TEST 5 Failed");

          delay(1000);
          Cote1.EnvoiSignal(BROCHE_6); 
          Cote2.ReceipSignal(BROCHE_6_2);
          Fonctionnement= Cote2.TestReceipSignal(BROCHE_6_2);  
          if (Fonctionnement) 
             Serial.println("TEST 6 OK"); 
          else 
             Serial.println("TEST 6 Failed");

          delay(1000);
          Cote1.EnvoiSignal(BROCHE_7); 
          Cote2.ReceipSignal(BROCHE_7_2); 
          Fonctionnement= Cote2.TestReceipSignal(BROCHE_7_2);  
          if (Fonctionnement) 
            Serial.println("TEST 7 OK");
          else 
            Serial.println("TEST 7 Failed");

          delay(1000);
          Cote1.EnvoiSignal(BROCHE_8); 
          Cote2.ReceipSignal(BROCHE_8_2); 
          Fonctionnement= Cote2.TestReceipSignal(BROCHE_8_2); 
          if (Fonctionnement) 
            Serial.println("TEST 8 OK");
          else 
            Serial.println("TEST 8 Failed");   

          delay(1000);
               
  } else if ( Valeur2 == 1){ 
         

         Serial.println("Le cable est de type croise");  
          
          Serial.println(Valeur1);  
          Serial.println(Valeur2); 
          delay(1000);

          Cote1.EnvoiSignal(BROCHE_2); 
          Cote2.ReceipSignal(BROCHE_6_2); 
          Fonctionnement = Cote2.TestReceipSignal(BROCHE_6_2);  
          if (Fonctionnement)  
            Serial.println("TEST 2 OK");
          else 
            Serial.println("TEST 2 Failed");

          Serial.println(Valeur1);  
          Serial.println(Valeur2); 
          delay(1000);
          Cote1.EnvoiSignal(BROCHE_3); 
          Cote2.ReceipSignal(BROCHE_1_2); 
          Fonctionnement= Cote2.TestReceipSignal(BROCHE_1_2); 
          if (Fonctionnement)  
            Serial.println("TEST 3 OK");
          else 
            Serial.println("TEST 3 Failed");

 
          Serial.println(Valeur1);  
          Serial.println(Valeur2); 
          delay(1000);
          Cote1.EnvoiSignal(BROCHE_4); 
          Cote2.ReceipSignal(BROCHE_4_2);
          Fonctionnement= Cote2.TestReceipSignal(BROCHE_4_2); 
          if (Fonctionnement) 
              Serial.println("TEST 4 OK");
          else 
              Serial.println("TEST 4 Failed");


          Serial.println(Valeur1);  
          Serial.println(Valeur2); 
          delay(1000);
          Cote1.EnvoiSignal(BROCHE_5); 
          Cote2.ReceipSignal(BROCHE_5_2);
          Fonctionnement= Cote2.TestReceipSignal(BROCHE_5_2);     
          if (Fonctionnement) 
              Serial.println("TEST 5 OK");
          else 
              Serial.println("TEST 5 Failed");


          Serial.println(Valeur1);  
          Serial.println(Valeur2); 
          delay(1000);
          Cote1.EnvoiSignal(BROCHE_6); 
          Cote2.ReceipSignal(BROCHE_2_2);
          Fonctionnement= Cote2.TestReceipSignal(BROCHE_2_2);  
          if (Fonctionnement) 
             Serial.println("TEST 6 OK"); 
          else 
             Serial.println("TEST 6 Failed");
            

          Serial.println(Valeur1);  
          Serial.println(Valeur2); 
          delay(1000);
          Cote1.EnvoiSignal(BROCHE_7); 
          Cote2.ReceipSignal(BROCHE_7_2); 
          Fonctionnement= Cote2.TestReceipSignal(BROCHE_7_2);  
          if (Fonctionnement) 
            Serial.println("TEST 7 OK");
          else 
            Serial.println("TEST 7 Failed");
            

          Serial.println(Valeur1);  
          Serial.println(Valeur2); 
          delay(1000);
          
          Cote1.EnvoiSignal(BROCHE_8); 
          Cote2.ReceipSignal(BROCHE_8_2); 
          Fonctionnement= Cote2.TestReceipSignal(BROCHE_8_2); 
          if (Fonctionnement) 
            Serial.println("TEST 8 OK");
          else 
            Serial.println("TEST 8 Failed"); 

          Serial.println(Valeur1);  
          Serial.println(Valeur2); 
          delay(1000);
   }

  Valeur2 = Cote2.ReceipSignal(BROCHE_3_2);    
  Serial.println(Valeur1);  
  Serial.println(Valeur2); 
  Serial.println("retest");
  Serial.println("----------------------------------------------------");
  Cote1.initialisation();
   delay(2000);
}
