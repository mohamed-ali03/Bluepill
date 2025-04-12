#include "motor.h"
const float pi = 3.14159265359;
const int motor_speed = 600 ; //rpm
const float wheel_dimeter = 6.5; // cm
const float perimeter = pi*wheel_dimeter; // cm

void move_forward(Motor_Config *motor){
	stop_moving(motor);
	HAL_Delay(50);
	HAL_GPIO_WritePin(motor->port, motor->IN1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(motor->port, motor->IN2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(motor->port, motor->IN3, GPIO_PIN_SET);
	HAL_GPIO_WritePin(motor->port, motor->IN4, GPIO_PIN_RESET);
}
void move_backward(Motor_Config *motor){
	stop_moving(motor);
	HAL_Delay(50);
	HAL_GPIO_WritePin(motor->port, motor->IN1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(motor->port, motor->IN2, GPIO_PIN_SET);
	HAL_GPIO_WritePin(motor->port, motor->IN3, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(motor->port, motor->IN4, GPIO_PIN_SET);
}
void rotate_right(Motor_Config *motor){
	stop_moving(motor);
	HAL_Delay(50);
	HAL_GPIO_WritePin(motor->port, motor->IN1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(motor->port, motor->IN2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(motor->port, motor->IN3, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(motor->port, motor->IN4, GPIO_PIN_SET);
}
void rotate_left(Motor_Config *motor){
	stop_moving(motor);
	HAL_Delay(50);
	HAL_GPIO_WritePin(motor->port, motor->IN1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(motor->port, motor->IN2, GPIO_PIN_SET);
	HAL_GPIO_WritePin(motor->port, motor->IN3, GPIO_PIN_SET);
	HAL_GPIO_WritePin(motor->port, motor->IN4, GPIO_PIN_RESET);
}
void turn_right(Motor_Config *motor){
	stop_moving(motor);
	HAL_Delay(50);
	rotate_right(motor);
	HAL_Delay(200);
	stop_moving(motor);
}
void turn_left(Motor_Config *motor){
	stop_moving(motor);
	HAL_Delay(50);
	rotate_left(motor);
	HAL_Delay(200);
	stop_moving(motor);
}
void stop_moving(Motor_Config *motor){
	HAL_GPIO_WritePin(motor->port, motor->IN1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(motor->port, motor->IN2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(motor->port, motor->IN3, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(motor->port, motor->IN4, GPIO_PIN_RESET);
}
