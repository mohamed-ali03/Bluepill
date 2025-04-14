#include "IR_Receiver.h"

static uint32_t decode_nec(uint32_t *signal){
  uint32_t result = 0;
  for (uint8_t i = NEC_BIT_START; i < NEC_BIT_END; i++)
  {
	uint32_t duration = signal[i];
	result <<= 1;
	if (duration > NEC_1_MIN && duration < NEC_1_MAX)
	  result |= 1;
	else if (duration > NEC_0_MIN && duration < NEC_0_MAX)
	  result |= 0;
  }
  return result;
}



uint32_t process_ir_signal(uint32_t *signal,uint32_t *size){
  HAL_NVIC_DisableIRQ(EXTI9_5_IRQn);
  uint32_t code = decode_nec(signal);
  char msg[20] = {0};
  sprintf(msg, "0x%08lX\r\n", code);
  CDC_Transmit_FS((uint8_t *)msg, strlen(msg));

  for(int i = 0 ; i < 34 ; i++){

	  char msg[30] = {0};
	  int x = 2;
	  if (signal[i] > 1600 && signal[i] < 2400)
		  x = 1;
	  else if (signal[i] > 400 && signal[i] < 1200)
		  x = 0;
	  sprintf(msg, "%d : %d --> %d\r\n",i,(int)signal[i],x);
	  CDC_Transmit_FS((uint8_t *)msg, strlen(msg));
	  HAL_Delay(10);
	  signal[i] = 0;
  }
  char separate[]="------------------------------------------------------\r\n";
  CDC_Transmit_FS((uint8_t *)separate, strlen(separate));
  *size = 0;
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
  return code ;
}






