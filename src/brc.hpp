#include "api.h"   
#include "main.h"




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
    //Robot
    //creates a unified interface especially for the drivetrain
    //also have an error holder.

public:

    Robot(pros::MotorGroup &left_motor_group, pros::MotorGroup &right_motor_group, pros::Controller &controller, Drive_Type drive_type);
    //Here is how this works:
    //there is a pointer to the left and right motor group, and a pointer to the controller, and a drive type
    //your claim would be like this:
    //{
    //pros::Controller master(pros::E_CONTROLLER_MASTER);
    //pros::MotorGroup Left_Drivetrain = LEFT_MOTOR_PORTS;
    //pros::MotorGroup Right_Drivetrain = RIGHT_MOTOR_PORTS;
    //Robot Your_Bot_Name(Left_Drivetrain, Right_Drivetrain, master, Tank);
    //}
    //for drive type explanation, see the update_Driver_ctrl function

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
    //update_Driver_ctrl: update the driver control, this function should be called in the main loop
    //for drive type explanation:
    //Tank: left stick controls left side, right stick controls right side
    //Arcade: left stick controls forward/backward, right stick controls turning

    Error Bot_State = Error::Normal;
    int Error_Handler_Task();
private:
    pros::MotorGroup* Left_Drivetrain = nullptr;
    pros::MotorGroup* Right_Drivetrain = nullptr;
    pros::Controller* main_controller = nullptr;
    Drive_Type bot_drive_type;
};

Robot::Robot(pros::MotorGroup& left_motor_group, pros::MotorGroup& right_motor_group, pros::Controller& controller, Drive_Type drive_type = Tank) {
    Left_Drivetrain = &left_motor_group;
    Right_Drivetrain = &right_motor_group;
    main_controller = &controller;
    bot_drive_type = drive_type;
	// Correct: Captures 'this' so the task knows which Robot instance to use
    pros::Task error_task([this] { this->Error_Handler_Task(); });
}

void Robot::update_Driver_ctrl(){
    if (main_controller == nullptr) return;
    switch (bot_drive_type) {
        case Tank: {
            int left_move = main_controller->get_analog(ANALOG_LEFT_Y);  
            int right_move = main_controller->get_analog(ANALOG_RIGHT_Y);  
            Left_Drivetrain->move(left_move); 
            Right_Drivetrain->move(right_move);
            break;
        }
        case Arcade: {
            int dir = main_controller->get_analog(ANALOG_LEFT_Y);    
            int turn = main_controller->get_analog(ANALOG_RIGHT_X);  
            Left_Drivetrain->move(dir - turn);                      
            Right_Drivetrain->move(dir + turn);                     
            break; 
        }
    }
}
int Robot::Error_Handler_Task(){
    while (true) {
        switch (Bot_State) {
            case Error::Normal:
            pros::lcd::print(0, 0, "Normal");
                break;
        }
        
        pros::delay(20);
    }
    return 0; 
}
