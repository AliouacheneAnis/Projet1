#include<Fil.h>
#include<Arduino.h>

    Fil::Fil(int Broche1, int Broche2, int Broche3, int Broche4, int Broche5, int Broche6, int Broche7, int Broche8){

        this->Broche1 = Broche1;
        this->Broche2 = Broche2;
        this->Broche3 = Broche3;
        this->Broche4 = Broche4;
        this->Broche5 = Broche5;
        this->Broche6 = Broche6;
        this->Broche7 = Broche7;
        this->Broche8 = Broche8;
    };

    void Fil::InputMode(){

        pinMode(Broche1, INPUT);
        pinMode(Broche2, INPUT);
        pinMode(Broche3, INPUT);
        pinMode(Broche4, INPUT);
        pinMode(Broche5, INPUT);
        pinMode(Broche6, INPUT);
        pinMode(Broche7, INPUT);
        pinMode(Broche8, INPUT);
      };

    void Fil::OutputMode(){
        
        pinMode(Broche1, OUTPUT);
        pinMode(Broche2, OUTPUT);
        pinMode(Broche3, OUTPUT);
        pinMode(Broche4, OUTPUT);
        pinMode(Broche5, OUTPUT);
        pinMode(Broche6, OUTPUT);
        pinMode(Broche7, OUTPUT);
        pinMode(Broche8, OUTPUT);
    };

    void Fil::EnvoiSignal( int Broche ){
      digitalWrite(Broche, HIGH); 
    };

    int Fil::ReceipSignal(int Broche){
        return digitalRead(Broche);
    };

    bool Fil::TestReceipSignal (int Broche){
        int Val = ReceipSignal(Broche);
        if (Val != HIGH) 
            return false;
        else 
            return true; 
    };
