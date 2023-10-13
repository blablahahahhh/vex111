/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Administrator                                             */
/*    Created:      2023/10/12 21:33:34                                       */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here


int main() {
   
    vex::motor LeftMotor(0);
    vex::motor RightMotor(1);

    // LeftMotor.spin(fwd, 90, rpm);
    // RightMotor.spin(fwd, -30, rpm);
    // this_thread::sleep_for(10800);

    // LeftMotor.spin(fwd, 30, rpm);
    // RightMotor.spin(fwd, -90, rpm);
    // this_thread::sleep_for(10800);
    
    double n1 = 20;//内圆轮转速
    double w1 = n1*2*M_PI/60;//内圆轮角速度
    double vL = 0.105*w1/2;//内圆轮线速度
    double vR = vL*400/15;//外圆轮线速度
    double w2 = vR/(0.105/2);//外圆轮角速度
    double n2 = w2*60/(2*M_PI); //外圆轮转速
    double R =0.5;//圆环外圆半径
    double t =3500;//2*M_PI*R*1000/vR;//延时时间

    LeftMotor.spin(vex::directionType::fwd, n1, vex::velocityUnits::rpm);
    RightMotor.spin(vex::directionType::fwd, -n2, vex::velocityUnits::rpm);
    this_thread::sleep_for(3500);

    LeftMotor.spin(vex::directionType::fwd, n2, vex::velocityUnits::rpm);
    RightMotor.spin(vex::directionType::fwd, -n1, vex::velocityUnits::rpm);
    this_thread::sleep_for(3200);

    LeftMotor.stop();
    RightMotor.stop();

    return 0;
}

 