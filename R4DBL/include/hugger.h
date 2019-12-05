class Hugger{
    private:
        Hugger();
        bool atMax = false;
        int OPEN_STATE = 120;
        int position = 0;
    public:
        static Hugger* getInstance(); //singleton again
        void open(); //change state
        void close(); //change state
        void updateState(); //move
        void setPos(int);
};