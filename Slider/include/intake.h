class Intake{
    private:
        Intake();
        
    public:
        int position = 0; //which level is the lift on currernly?
        static Intake* getInstance(); //singleton again
        void nextPos(); //change state
        void prevPos(); //change state
        void updateState(); //move
        int getPos();
};