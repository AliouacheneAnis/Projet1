#ifndef CABLE_H
   #define CABLE_H

#include<Arduino.h>
#include<string.h>

class Cable{

    // Declaration des attribue
    private: 
        int Broche1, Broche2, Broche3, Broche4, Broche5, Broche6, Broche7, Broche8; 
        String TypeCable; 
        char NormeCable;

    public : 
    
    // Declaration constrecteur par default 
    Cable(){};
    
    /**
     * @brief Construct a new Fil object
     * 
     * @param Broche1 
     * @param Broche2 
     * @param Broche3 
     * @param Broche4 
     * @param Broche5 
     * @param Broche6 
     * @param Broche7 
     * @param Broche8 
     */
    Cable(int Broche1, int Broche2, int Broche3, int Broche4, int Broche5, int Broche6, int Broche7, int Broche8);
    
    // getters and setters
    void setTypeCable(String Type);
    String getTypeCable();

    void setNormeCable(char Norme);
    char getNormeCable();

    // Fonction setup input 
    void InputMode();

    // Fonction setup Output 
    void OutputMode();

    // Fonction envoi signal 
    void EnvoiSignal(int Broche);
    
    // Fonction Reception Signal 
    int ReceipSignal(int Broche);

    // Fonction test signal 
    bool TestReceipSignal(int Broche);
    
    // initialisation
    void initialisation();

};

    #endif 