#include "api.h"   
#include "main.h"
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

enum Drive_Type {
    Tank,
    Arcade
};


enum class Error {
    Normal
};

class Robot {
public:
    Robot();
    void initialize(const std::vector<std::int8_t>& left_ports, const std::vector<std::int8_t>& right_ports, std::uint8_t Some_gyro_port, pros::Controller& controller, Drive_Type drive_type = Tank);
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
    void update_Driver_ctrl();
    int Error_Handler_Task();
private:
    pros::MotorGroup left_mg;
    pros::MotorGroup right_mg;
    pros::ADIAnalogIn left_encoder;
    pros::ADIAnalogIn right_encoder;
    pros::ADIAnalogIn gyro_sensor;
    pros::Controller* main_controller = nullptr;
    Drive_Type bot_drive_type;
    Error Bot_State = Error::Normal;
};
    
void Robot::initialize(const std::vector<std::int8_t>& left_ports, const std::vector<std::int8_t>& right_ports, std::uint8_t Some_gyro_port, pros::Controller& controller, Drive_Type drive_type) {
    main_controller = &controller;
    bot_drive_type = drive_type;
}
void Robot::update_Driver_ctrl(){
    if (main_controller == nullptr) return;
    switch (bot_drive_type) {
        case Tank: {
            int left_move = main_controller->get_analog(ANALOG_LEFT_Y);  
            int right_move = main_controller->get_analog(ANALOG_RIGHT_Y);  
            left_mg.move(left_move); 
            right_mg.move(right_move);     
            break;
        }
        case Arcade: {
            int dir = main_controller->get_analog(ANALOG_LEFT_Y);    
            int turn = main_controller->get_analog(ANALOG_RIGHT_X);  
            left_mg.move(dir - turn);                      
            right_mg.move(dir + turn);                     
            break; 
        }
    }
}


int Robot::Error_Handler_Task() {
    while (true) {
        switch (Bot_State) {
            case Error::Normal:
                break;
        }
        
        pros::delay(20);
    return 0; 
    }
}