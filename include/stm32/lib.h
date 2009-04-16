/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : stm32/lib.h
* Author             : MCD Application Team
* Version            : V2.0.3
* Date               : 09/22/2008
* Description        : This file includes the peripherals header files in the
*                      user application.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32_LIB_H
#define __STM32_LIB_H

/* Includes ------------------------------------------------------------------*/
#include "stm32/map.h"

#ifdef _ADC
  #include "stm32/adc.h"
#endif /*_ADC */

#ifdef _BKP
  #include "stm32/bkp.h"
#endif /*_BKP */

#ifdef _CAN
  #include "stm32/can.h"
#endif /*_CAN */

#ifdef _CRC
  #include "stm32/crc.h"
#endif /*_CRC */

#ifdef _DAC
  #include "stm32/dac.h"
#endif /*_DAC */

#ifdef _DBGMCU
  #include "stm32/dbgmcu.h"
#endif /*_DBGMCU */

#ifdef _DMA
  #include "stm32/dma.h"
#endif /*_DMA */

#ifdef _EXTI
  #include "stm32/exti.h"
#endif /*_EXTI */

#ifdef _FLASH
  #include "stm32/flash.h"
#endif /*_FLASH */

#ifdef _FSMC
  #include "stm32/fsmc.h"
#endif /*_FSMC */

#ifdef _GPIO
  #include "stm32/gpio.h"
#endif /*_GPIO */

#ifdef _I2C
  #include "stm32/i2c.h"
#endif /*_I2C */

#ifdef _IWDG
  #include "stm32/iwdg.h"
#endif /*_IWDG */

#ifdef _NVIC
  #include "stm32/nvic.h"
#endif /*_NVIC */

#ifdef _PWR
  #include "stm32/pwr.h"
#endif /*_PWR */

#ifdef _RCC
  #include "stm32/rcc.h"
#endif /*_RCC */

#ifdef _RTC
  #include "stm32/rtc.h"
#endif /*_RTC */

#ifdef _SDIO
  #include "stm32/sdio.h"
#endif /*_SDIO */

#ifdef _SPI
  #include "stm32/spi.h"
#endif /*_SPI */

#ifdef _SysTick
  #include "stm32/systick.h"
#endif /*_SysTick */

#ifdef _TIM
  #include "stm32/tim.h"
#endif /*_TIM */

#ifdef _USART
  #include "stm32/usart.h"
#endif /*_USART */

#ifdef _WWDG
  #include "stm32/wwdg.h"
#endif /*_WWDG */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void debug(void);

#endif /* __STM32_LIB_H */

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
