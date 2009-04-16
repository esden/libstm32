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

NAME   = stm_h103_blink_rom

PREFIX  = arm-none-eabi

CC      = $(PREFIX)-gcc
LD      = $(PREFIX)-ld -v
AR      = $(PREFIX)-ar
AS      = $(PREFIX)-as
CP      = $(PREFIX)-objcopy
OD	= $(PREFIX)-objdump
  
CFLAGS  =  -I./ -c -fno-common -O0 -g -mcpu=cortex-m3 -mthumb 
AFLAGS  = -ahls -mapcs-32 -o crt.o
LFLAGS  = -T$(NAME).cmd -nostartfiles
ODFLAGS	= -S

all: images

clean:
	-rm -f main.o $(NAME).out $(NAME).hex $(NAME).bin $(NAME).list $(NAME).srec *~

images: $(NAME).out
	@ echo "...copying"
	$(CP) -Obinary $(NAME).out $(NAME).bin
	$(CP) -Oihex $(NAME).out $(NAME).hex
	$(CP) -Osrec $(NAME).out $(NAME).srec
	$(OD) $(ODFLAGS) $(NAME).out > $(NAME).list

$(NAME).out: main.o $(NAME).cmd 
	@ echo "..linking"
	$(LD) $(LFLAGS) -o $(NAME).out main.o -lstm32

main.o: main.c
	@ echo ".compiling"
	 $(CC) $(CFLAGS) main.c

