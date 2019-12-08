class SetUpScreen{
    public:
        SetUpScreen();
        void displayMain(); 
        void displayAuton(); 
        void waitForInput(int Screen);
        void selectAuton(int x, int y);
};

void displayFinalScreen();

void autonomous(void);

void pre_auton();