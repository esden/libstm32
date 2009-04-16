##
# Copyright (c) 2009 Piotr Esden-Tempski <piotr@esden.net>
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
##

arch_prefix?=arm-none-eabi
compiler_prefix?=${arch_prefix}-
CC=${compiler_prefix}gcc
AR=${compiler_prefix}ar
CFLAGS=-I../include -fno-common -Os -g -mcpu=cortex-m3 -mthumb
ARFLAGS=rcsv

objects= stm32f10x_adc.o   stm32f10x_bkp.o  stm32f10x_dbgmcu.o \
         stm32f10x_fsmc.o  stm32f10x_lib.o  stm32f10x_rtc.o \
	 stm32f10x_tim.o   stm32f10x_can.o  stm32f10x_dma.o \
	 stm32f10x_gpio.o  stm32f10x_nvic.o stm32f10x_sdio.o \
	 stm32f10x_usart.o stm32f10x_adc.o  stm32f10x_crc.o \
	 stm32f10x_exti.o  stm32f10x_i2c.o  stm32f10x_pwr.o \
	 stm32f10x_spi.o   stm32f10x_wwdg.o stm32f10x_dac.o \
	 stm32f10x_flash.o stm32f10x_iwdg.o stm32f10x_rcc.o \
	 stm32f10x_systick.o

all: libstm32.a

libstm32.a: ${objects}
	${AR} ${ARFLAGS} $@ $^

clean:
	rm -rf *.o *.a
