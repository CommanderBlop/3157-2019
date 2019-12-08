class Intake{
    private:
        Intake();
        int position = 0; //which level is the lift on currernly?
    public:
        static Intake* getInstance(); //singleton again
        void nextPos(); //change state
        void prevPos(); //change state
        void updateState(); //move
};