//没写呢别动

//to whom may use this header
//plz give this to the next class

//you might want to change or rewrite, just do it

//I strongly advice not to put all the const here, put it in main

//usually dont use the forward_time modular which is not accurate,
//  also it might run slightly turned
//  yep you can add offset, we give you the function to do that

//in prepare to use this, you would need these constants:
//drivetrain ports(left and right), gyro port, wheel diameter, encoder unit, encoder wheel diameter
//you will need to develop your own function for the mechanical part
//this header is just for the drivetrain, 

#include "api.h"

class Robot {
public:
    Robot();
    void Robot::initialize(const std::vector<std::int8_t>& left_ports, const std::vector<std::int8_t>& right_ports, std::uint8_t Some_gyro_port) ;
    //initialize the robot with the left and right motor ports
    void forward_distance(int distance);
    //forward_distance: move forward a certain distance, the unit is (not sure yet)
    void backward_distance(int distance);
    //backward_distance: move backward a certain distance, the unit is (not sure yet)
    void forward_time(int time, int speed);
    //forward_time: move forward for a certain time, the unit is (not sure yet), speed is from 0 to 127
    void backward_time(int time, int speed);
    //backward_time: move backward for a certain time, the unit is (not sure yet), speed is from 0 to 127
    void turnLeft(int angle);
    void turnRight(int angle);

private:
    pros::MotorGroup left_mg;
    pros::MotorGroup right_mg;
    pros::ADIAnalogIn left_encoder;
    pros::ADIAnalogIn right_encoder;
    pros::ADIAnalogIn gyro_sensor;

};

void Robot::initialize(const std::vector<std::int8_t>& left_ports, const std::vector<std::int8_t>& right_ports, std::uint8_t Some_gyro_port) {

}
