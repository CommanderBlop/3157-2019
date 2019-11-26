class DriveTrain{
    private:
        DriveTrain(); //Singleton setup
        int ROTATE_1_DEG;
    public:
        static DriveTrain* getInstance();
        void setDrivePower(int power); //power in %
        void turnLeft(int deg);  //in motor rotaion deg
        void turnRight(int deg);
        void stop(); //stop breakType is break
};