#include<Cable.h>
#include<Arduino.h>
    
    // constrecteur 
    Cable::Cable(int Broche1, int Broche2, int Broche3, int Broche4, int Broche5, int Broche6, int Broche7, int Broche8){

        this->Broche1 = Broche1;
        this->Broche2 = Broche2;
        this->Broche3 = Broche3;
        this->Broche4 = Broche4;
        this->Broche5 = Broche5;
        this->Broche6 = Broche6;
        this->Broche7 = Broche7;
        this->Broche8 = Broche8;
    };

    // Fonctions 
    void Cable::InputMode(){

        pinMode(Broche1, INPUT);
        pinMode(Broche2, INPUT);
        pinMode(Broche3, INPUT);
        pinMode(Broche4, INPUT);
        pinMode(Broche5, INPUT);
        pinMode(Broche6, INPUT);
        pinMode(Broche7, INPUT);
        pinMode(Broche8, INPUT);
      };

    void Cable::OutputMode(){
        
        pinMode(Broche1, OUTPUT);
        pinMode(Broche2, OUTPUT);
        pinMode(Broche3, OUTPUT);
        pinMode(Broche4, OUTPUT);
        pinMode(Broche5, OUTPUT);
        pinMode(Broche6, OUTPUT);
        pinMode(Broche7, OUTPUT);
        pinMode(Broche8, OUTPUT);
    };

    void Cable::EnvoiSignal( int Broche ){
      digitalWrite(Broche, HIGH); 
    };

    int Cable::ReceipSignal(int Broche){
        return digitalRead(Broche);
    };

    bool Cable::TestReceipSignal (int Broche){
        int Val = ReceipSignal(Broche);
        if (Val != HIGH) 
            return false;
        else 
            return true; 
    };

    void Cable::initialisation(){
        
        digitalWrite(this->Broche1, LOW);
        digitalWrite(this->Broche2, LOW);
        digitalWrite(this->Broche3, LOW);
        digitalWrite(this->Broche4, LOW);
        digitalWrite(this->Broche5, LOW);
        digitalWrite(this->Broche6, LOW);
        digitalWrite(this->Broche7, LOW);
        digitalWrite(this->Broche8, LOW);
    };
