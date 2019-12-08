class DriveTrain{
    private:
        DriveTrain(); //Singleton setup
    public:
        static DriveTrain* getInstance();
        void setDrivePower(int power); //power in %
        void turnLeft(int deg);  //in motor rotaion deg
        void stop(); //stop breakType is break
};