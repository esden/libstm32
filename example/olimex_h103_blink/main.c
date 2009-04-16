/*
 * Copyright (c) 2009 Piotr Esden-Tempski <piotr@esden.net>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stm32f10x/lib.h>
#include <stm32f10x/map.h>
#include <stm32f10x/rcc.h>
#include <stm32f10x/gpio.h>
#include <stm32f10x/usart.h>

#define STACK_TOP 0x20000800
#define NVIC_CCR ((volatile unsigned long *)(0xE000ED14))

/* Clock initialization routine */
void clk_init (void){
    /* set cloking the controller from internal HSI RC (8 MHz) */
    RCC_HSICmd(ENABLE);
    /* wait until the HSI is ready */
    while(RCC_GetFlagStatus(RCC_FLAG_HSIRDY) == RESET);
    RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI);
    /* enable external high frequency OSC */
    RCC_HSEConfig(RCC_HSE_ON);
    /* wait until the HSE is ready */
    while(RCC_GetFlagStatus(RCC_FLAG_HSERDY) == RESET);
    /* initialize the PLL */
    RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul_9); /* 72MHz */
    RCC_PLLCmd(ENABLE);
    /* wait until the PLL is ready */
    while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
    /* set system clock divders */
    RCC_USBCLKConfig(RCC_USBCLKSource_PLLCLK_1Div5);
    RCC_ADCCLKConfig(RCC_PCLK2_Div8);
    RCC_PCLK2Config(RCC_HCLK_Div1);
    RCC_PCLK1Config(RCC_HCLK_Div2);
    RCC_HCLKConfig(RCC_SYSCLK_Div1);
    /* flash 1 wait state */
    *(vu32 *)0x40022000 = 0x12;
    /* start clocking the system from PLL */
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
}

void my_delay(unsigned long delay ){
    while(delay) delay--;
}

GPIO_InitTypeDef GPIO_InitStructure;

int main(void){

    *NVIC_CCR = *NVIC_CCR | 0x200; /* set STKALIGN in NVIC */
    /* initialize the system clock */
    clk_init();
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOA, ENABLE);
    
    /* configure PC.12 as output push-pull (LED) */
    GPIO_WriteBit(GPIOC,GPIO_Pin_12,Bit_SET);
    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    
    while(1){    
        GPIOC->BRR |= 0x00001000;
        my_delay(400000);
        GPIOC->BSRR |= 0x00001000;
        my_delay(400000);
    }
}

/* Exception handlers */
void nmi_handler(void)
{
    return;
}

void hardfault_handler(void)
{
    return;
}

/* Vector table */
unsigned int * myvectors[4] 
__attribute__ ((section("vectors")))= {
    (unsigned int *)0x20000800,	        /* stack pointer */
    (unsigned int *)main,		/* code entry point */
    (unsigned int *)nmi_handler,	/* NMI handler */
    (unsigned int *)hardfault_handler	/* hard fault handler */
};

