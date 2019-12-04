class Arm {
  private:
    int LOW_TOWER;
    int HIGH_TOWER;
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