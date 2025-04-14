
#ifndef _IR_RECEIVER_
#define _IR_RECEIVER_

/*--------------------------------------Includes--------------------------------------*/
#include "stm32f1xx_hal.h"
#include <stdbool.h>
/*--------------------------------------Macros--------------------------------------*/
#define NEC_BIT_START 3
#define NEC_BIT_END   34
#define NEC_1_MIN     1600
#define NEC_1_MAX     2400
#define NEC_0_MIN     400
#define NEC_0_MAX     1200
/*--------------------------------------Variables--------------------------------------*/

/*--------------------------------------Functions--------------------------------------*/
uint32_t process_ir_signal(uint32_t *signal,uint32_t *size);
#endif
