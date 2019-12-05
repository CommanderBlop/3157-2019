class DriveTrain{
    private:
        DriveTrain(); //Singleton setup
        int ROTATE_1_DEG;
        int ROTATE_360_DEG;
    public:
        static DriveTrain* getInstance();
        void setDrivePower(int power); //power in %
        void turnLeft(int deg, int power);  //in motor rotaion deg
        void turnRight(int deg, int power);
        void stop(); //stop breakType is break
        void moveForward(int degree, int power);
};