/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : stm32f10x_lib.h
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
#ifndef __STM32F10x_LIB_H
#define __STM32F10x_LIB_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x/map.h"

#ifdef _ADC
  #include "stm32f10x/adc.h"
#endif /*_ADC */

#ifdef _BKP
  #include "stm32f10x/bkp.h"
#endif /*_BKP */

#ifdef _CAN
  #include "stm32f10x/can.h"
#endif /*_CAN */

#ifdef _CRC
  #include "stm32f10x/crc.h"
#endif /*_CRC */

#ifdef _DAC
  #include "stm32f10x/dac.h"
#endif /*_DAC */

#ifdef _DBGMCU
  #include "stm32f10x/dbgmcu.h"
#endif /*_DBGMCU */

#ifdef _DMA
  #include "stm32f10x/dma.h"
#endif /*_DMA */

#ifdef _EXTI
  #include "stm32f10x/exti.h"
#endif /*_EXTI */

#ifdef _FLASH
  #include "stm32f10x/flash.h"
#endif /*_FLASH */

#ifdef _FSMC
  #include "stm32f10x/fsmc.h"
#endif /*_FSMC */

#ifdef _GPIO
  #include "stm32f10x/gpio.h"
#endif /*_GPIO */

#ifdef _I2C
  #include "stm32f10x/i2c.h"
#endif /*_I2C */

#ifdef _IWDG
  #include "stm32f10x/iwdg.h"
#endif /*_IWDG */

#ifdef _NVIC
  #include "stm32f10x/nvic.h"
#endif /*_NVIC */

#ifdef _PWR
  #include "stm32f10x/pwr.h"
#endif /*_PWR */

#ifdef _RCC
  #include "stm32f10x/rcc.h"
#endif /*_RCC */

#ifdef _RTC
  #include "stm32f10x/rtc.h"
#endif /*_RTC */

#ifdef _SDIO
  #include "stm32f10x/sdio.h"
#endif /*_SDIO */

#ifdef _SPI
  #include "stm32f10x/spi.h"
#endif /*_SPI */

#ifdef _SysTick
  #include "stm32f10x/systick.h"
#endif /*_SysTick */

#ifdef _TIM
  #include "stm32f10x/tim.h"
#endif /*_TIM */

#ifdef _USART
  #include "stm32f10x/usart.h"
#endif /*_USART */

#ifdef _WWDG
  #include "stm32f10x/wwdg.h"
#endif /*_WWDG */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void debug(void);

#endif /* __STM32F10x_LIB_H */

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
