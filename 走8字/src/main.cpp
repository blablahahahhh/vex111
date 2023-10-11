/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Administrator                                             */
/*    Created:      2023/10/2 11:13:06                                        */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include"vex.h"
#include "thread"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
                                                                                                                                                                                                                                                                                                 
int main()
{
    vex::motor LeftMotor(0);
    vex::motor RightMotor(1);
    
    int vL = 30;
    int vR = vL*1000/515;
    int w = vL*M_PI/30;
    int t =2*M_PI/w;

    LeftMotor.spin(vex::directionType::fwd, vL, vex::velocityUnits::rpm);
    RightMotor.spin(vex::directionType::fwd, vR, vex::velocityUnits::rpm);
    this_thread::sleep_for(t);

    vR = 30;
    vL = vR*1000/515;
    w = vR*M_PI/30;
    t =2*M_PI/w;

    LeftMotor.spin(vex::directionType::fwd, vL, vex::velocityUnits::rpm);
    RightMotor.spin(vex::directionType::fwd, vR, vex::velocityUnits::rpm);
    this_thread::sleep_for(t);


    return 0;

}


