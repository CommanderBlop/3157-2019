class SetUpScreen{
    public:
        SetUpScreen();
        void displayMain(); //main screen with 4 buttons (Screen 0)
        void displayAuton(); //auton selection screen (Screen 1)
        void waitForInput(int Screen); //call with screen number when user inputed needed
        void static displayFinalScreen(); //confirmation screen (Screen 2)
        void selectAuton(int x, int y);
};

void autonomous(void);

void pre_auton();