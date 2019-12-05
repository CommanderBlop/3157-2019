class DriveTrain{
    private:
        DriveTrain(); //Singleton setup
        double ROTATE_360_DEG = 900;
    public:
        static DriveTrain* getInstance();
        void setDrivePower(int power); //power in %
        void turnLeft(int deg, int power);
        void turnRight(int deg, int power);
        void stop(); //stop breakType is break
        void moveForward(int deg, int power);
        void moveBackward(int deg, int power);
};