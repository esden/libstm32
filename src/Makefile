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

objects= stm32_adc.o   stm32_bkp.o  stm32_dbgmcu.o \
         stm32_fsmc.o  stm32_lib.o  stm32_rtc.o \
	 stm32_tim.o   stm32_can.o  stm32_dma.o \
	 stm32_gpio.o  stm32_nvic.o stm32_sdio.o \
	 stm32_usart.o stm32_adc.o  stm32_crc.o \
	 stm32_exti.o  stm32_i2c.o  stm32_pwr.o \
	 stm32_spi.o   stm32_wwdg.o stm32_dac.o \
	 stm32_flash.o stm32_iwdg.o stm32_rcc.o \
	 stm32_systick.o

all: libstm32.a

libstm32.a: ${objects}
	${AR} ${ARFLAGS} $@ $^

clean:
	rm -rf *.o *.a
