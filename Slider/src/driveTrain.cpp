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
    BackL.rotateFor(-1*deg,vex::rotationUnits::deg,false);
    FrontL.rotateFor(-1*deg, vex::rotationUnits::deg,false);
    BackR.rotateFor(deg,vex::rotationUnits::deg,false);
    FrontR.rotateFor(deg,vex::rotationUnits::deg,true);
}

void DriveTrain::stop(){
    FrontL.stop();
    FrontR.stop();
    BackL.stop();
    BackR.stop();
}