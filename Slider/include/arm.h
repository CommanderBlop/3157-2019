class Arm {
  private:
    int LOW_TOWER = 2000;
    int HIGH_TOWER = 4000;
    double ARM_SPEED_BUFFER;
    Arm();
  public:
    static Arm* getInstance();
    void move();
    void lowTower();
    void highTower();
    void calcValue();
    void toZero();
    void moveUp();
    void moveDown();
};