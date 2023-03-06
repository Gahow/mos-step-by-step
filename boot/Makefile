OBJS = entry.o main.o

CC = mips-linux-gnu-gcc
LD = mips-linux-gnu-ld
CFLAGS	= -nostdlib -fno-builtin -ffreestanding
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -mxgot -fno-pic
CFLAGS += -march=r3000 -mfp32

LINKER = linker.ld
IMAGE = kernel.img

all: $(OBJS) $(LINKER)
	$(LD) -T $(LINKER) -o $(IMAGE) $(OBJS)

entry.o: entry.S
	$(CC) $(CFLAGS) -c -o $@ $<

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $<

run: all
	gxemul -T -C R3000 -M 64 -E testmips $(IMAGE)

clean:
	rm -vf $(OBJS) $(IMAGE)

.PHONY: clean
