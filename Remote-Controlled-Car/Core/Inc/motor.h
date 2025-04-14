
#ifndef _MOTOR_
#define _MOTOR_

/*-----------------------Includes-----------------------*/
#include "stm32f1xx_hal.h"
/*-----------------------Variables-----------------------*/
typedef struct {
	GPIO_TypeDef *port;
	uint16_t IN1;
	uint16_t IN2;
	uint16_t IN3;
	uint16_t IN4;
}Motor_Config;
/*-----------------------Functions-----------------------*/
void move_forward(Motor_Config *motor);
void move_backward(Motor_Config *motor);
void rotate_right(Motor_Config *motor);
void rotate_left(Motor_Config *motor);
void turn_right(Motor_Config *motor);
void turn_left(Motor_Config *motor);
void turn_40_degree_right(Motor_Config *motor);
void turn_40_degree_left(Motor_Config *motor);
void turn_opposite(Motor_Config *motor);
void stop_moving(Motor_Config *motor);
#endif
