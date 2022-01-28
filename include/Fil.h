class Fil{

    private: 
        int Broche1, Broche2, Broche3, Broche4, Broche5, Broche6, Broche7, Broche8; 

    public : 
    
    Fil(){};
    
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
    Fil(int Broche1, int Broche2, int Broche3, int Broche4, int Broche5, int Broche6, int Broche7, int Broche8);

    void InputMode();

    void OutputMode();

    void EnvoiSignal(int Broche);

    int ReceipSignal(int Broche);

    bool TestReceipSignal(int Broche);

};