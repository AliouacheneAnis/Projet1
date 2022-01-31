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

//Variable pour tester quelle broche recois le signal 
int Valeur1, Valeur2, Valeur3; 

// variable boolean pour fonctionnement  
bool Fonctionnement; 


void setup() {
  
  // Configuration des broches de chaque objet 
  Cote1.OutputMode();
  Cote2.InputMode(); 
  Serial.begin(9600);
}

void loop() {
  
  // Envoi et Reception des signal entre les broches pour savoir de quel type il est 
  Cote1.EnvoiSignal(BROCHE_1);
  Valeur1 = Cote2.ReceipSignal(BROCHE_1_2); 
  Valeur2 = Cote2.ReceipSignal(BROCHE_3_2);
   
   // Test si le cable est Droit 
   if (Valeur1 == 1){
            
            // Des Conditions If pour tester tous les broches si le signal passe entre eux 
            Serial.println("TEST 1 OK");
            Cote1.setTypeCable("Droit");

            Cote1.EnvoiSignal(BROCHE_2); 
            Fonctionnement= Cote2.TestReceipSignal(BROCHE_2_2); 
            if (Fonctionnement) 
            {
                  Serial.println("TEST 2 OK");
                  delay(1000);

                  Cote1.EnvoiSignal(BROCHE_3);
                  Fonctionnement= Cote2.TestReceipSignal(BROCHE_3_2); 
                  if (Fonctionnement) {

                        Serial.println("TEST 3 OK");
                        delay(1000);

                        Cote1.EnvoiSignal(BROCHE_4); 
                        Fonctionnement= Cote2.TestReceipSignal(BROCHE_4_2); 
                        if (Fonctionnement) 
                        {
                            Serial.println("TEST 4 OK");
                            delay(1000);

                            Cote1.EnvoiSignal(BROCHE_5); 
                            Fonctionnement= Cote2.TestReceipSignal(BROCHE_5_2);    
                            if (Fonctionnement) {

                                Serial.println("TEST 5 OK");
                                delay(1000);

                                Cote1.EnvoiSignal(BROCHE_6); 
                                Fonctionnement= Cote2.TestReceipSignal(BROCHE_6_2);  
                                if (Fonctionnement) {
                                    Serial.println("TEST 6 OK"); 
                                    delay(1000);

                                    Cote1.EnvoiSignal(BROCHE_7); 
                                    Fonctionnement= Cote2.TestReceipSignal(BROCHE_7_2);  
                                    if (Fonctionnement) {

                                         Serial.println("TEST 7 OK");
                                         delay(1000);

                                         Cote1.EnvoiSignal(BROCHE_8); 
                                         Fonctionnement= Cote2.TestReceipSignal(BROCHE_8_2);
                                         if (Fonctionnement){
                                            Serial.println("TEST 8 OK");
                                            Serial.println("Le cable est Fonctionnel"); 
                                            Serial.print("Le type de Cable est : "); 
                                            Serial.println(Cote1.getTypeCable());

                                         } 
                                         else {
                                           Serial.println("TEST 8 Failed"); 
                                           Serial.println("Le cable n'est pas Fonctionnel"); 
                                         }        

                                    delay(1000);
                                    }
                                    else {
                                         Serial.println("TEST 7 Failed");
                                         Serial.println("Le cable n'est pas Fonctionnel"); 
                                    }
                                      
                                }
                                else {
                                  Serial.println("TEST 6 Failed");
                                  Serial.println("Le cable n'est pas Fonctionnel"); 
                                }

                            } 
                            else{
                              Serial.println("TEST 5 Failed");
                              Serial.println("Le cable n'est pas Fonctionnel"); 
                            }             
                        }
                        else {
                          Serial.println("TEST 4 Failed");
                          Serial.println("Le cable n'est pas Fonctionnel"); 
                        } 
                         
                  } 
                  else {
                    Serial.println("TEST 3 Failed");
                    Serial.printf("Le cable n'est pas fonctionnel");
                  }
            }
            else {
                    Serial.println("TEST 2 Failed");
                    Serial.println("Le cable n'est pas fonctionnel");
            }

  // Test si le cable est croise 
  } else if (Valeur2 == 1){
        
            Cote1.setTypeCable("Croise");
            Serial.println("TEST 1 OK");

            Cote1.EnvoiSignal(BROCHE_2); 
            Fonctionnement= Cote2.TestReceipSignal(BROCHE_6_2);  
            if (Fonctionnement) 
            {
                  Serial.println("TEST 2 OK");
                  delay(1000);

                  Cote1.EnvoiSignal(BROCHE_3); 
                  Fonctionnement= Cote2.TestReceipSignal(BROCHE_1_2); 
                  if (Fonctionnement) {

                        Serial.println("TEST 3 OK");
                        delay(1000);

                        Cote1.EnvoiSignal(BROCHE_4); 
                        Fonctionnement= Cote2.TestReceipSignal(BROCHE_4_2); 
                        if (Fonctionnement) 
                        {
                            Serial.println("TEST 4 OK");
                            delay(1000);

                            Cote1.EnvoiSignal(BROCHE_5); 
                            Fonctionnement= Cote2.TestReceipSignal(BROCHE_5_2);    
                            if (Fonctionnement) {

                                Serial.println("TEST 5 OK");
                                delay(1000);

                                Cote1.EnvoiSignal(BROCHE_6); 
                                Fonctionnement= Cote2.TestReceipSignal(BROCHE_2_2);  
                                if (Fonctionnement) {
                                     Serial.println("TEST 6 OK"); 
                                    delay(1000);

                                    Cote1.EnvoiSignal(BROCHE_7); 
                                    Fonctionnement= Cote2.TestReceipSignal(BROCHE_7_2);  
                                    if (Fonctionnement) {

                                         Serial.println("TEST 7 OK");
                                         delay(1000);

                                         Cote1.EnvoiSignal(BROCHE_8); 
                                         Fonctionnement= Cote2.TestReceipSignal(BROCHE_8_2);
                                         if (Fonctionnement){
                                            Serial.println("TEST 8 OK");
                                            Serial.println("Le cable est Fonctionnel"); 
                                            Serial.print("Le type de Cable est : "); 
                                            Serial.println(Cote1.getTypeCable());
                                         } 
                                         else {
                                           Serial.println("TEST 8 Failed"); 
                                           Serial.println("Le cable n'est pas Fonctionnel"); 
                                         }
                                              
                                    delay(1000);
                                    }
                                    else {
                                         Serial.println("TEST 7 Failed");
                                         Serial.println("Le cable n'est pas Fonctionnel"); 
                                    }
                                      
                                }
                                else {
                                  Serial.println("TEST 6 Failed");
                                  Serial.println("Le cable n'est pas Fonctionnel"); 
                                }

                            } 
                            else{
                              Serial.println("TEST 5 Failed");
                              Serial.println("Le cable n'est pas Fonctionnel"); 
                            }             
                        }
                        else {
                          Serial.println("TEST 4 Failed");
                          Serial.println("Le cable n'est pas Fonctionnel"); 
                        } 
                         
                  } 
                  else {
                    Serial.println("TEST 3 Failed");
                    Serial.printf("Le cable n'est pas fonctionnel");
                  }
            }
            else {
                    Serial.println("TEST 2 Failed");
                    Serial.println("Le cable n'est pas fonctionnel");
            }

          delay(1000);
        
  } else {
        Serial.println("TEST 1 Failed");
        Serial.println("Le cable n'est pas fonctionnel");
  }
  
  Cote1.initialisation();
  Serial.println("----------------------------------------------------");
  delay(2000);
}

