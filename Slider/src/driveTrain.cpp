#include "vex.h"

DriveTrain::DriveTrain(){}

DriveTrain* DriveTrain::getInstance(){                                                                                
    static DriveTrain instance;
    return &instance; //returns a pointer to the single instance                                                            
}       

void DriveTrain::setDrivePower(int power){
    BackL.spin(directionType::fwd,power,velocityUnits::pct);
    BackR.spin(directionType::fwd,power,velocityUnits::pct);
    FrontL.spin(directionType::fwd,power,velocityUnits::pct);
    FrontR.spin(directionType::fwd,power,velocityUnits::pct);
}

void DriveTrain::turnLeft(int deg){
    int turn = deg * ROTATE_1_DEG;
    BackL.rotateFor(-1*turn,vex::rotationUnits::deg,false);
    FrontL.rotateFor(-1*turn, vex::rotationUnits::deg,false);
    BackR.rotateFor(turn,vex::rotationUnits::deg,false);
    FrontR.rotateFor(turn,vex::rotationUnits::deg,true);
}

void DriveTrain::turnRight(int deg){
    int turn = deg * ROTATE_1_DEG;
    BackL.rotateFor(turn,vex::rotationUnits::deg,false);
    FrontL.rotateFor(turn, vex::rotationUnits::deg,false);
    BackR.rotateFor(-1*turn,vex::rotationUnits::deg,false);
    FrontR.rotateFor(-1*turn,vex::rotationUnits::deg,true);
}

void DriveTrain::stop(){
    FrontL.stop();
    FrontR.stop();
    BackL.stop();
    BackR.stop();
}