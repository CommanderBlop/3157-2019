class Hugger{
    private:
        Hugger();
        int position = 0;
        int OPEN_STATE = 0;
    public:
        static Hugger* getInstance(); //singleton again
        void nextPos(); //change state
        void prevPos(); //change state
        void updateState(); //move
        void setPos(int);
};