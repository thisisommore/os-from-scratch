.PHONY: kernel

CC=/maxpro/unzz/bin/i686-elf-gcc
LD=/maxpro/unzz/bin/i686-elf-ld
OUT=./out
compile: clean out kernel kernel_entry ld_kernel_entry boot_sec

out:
	mkdir ${OUT}
kernel: kernel/kernel.c
	${CC} -ffreestanding -c kernel/kernel.c -o ${OUT}/kernel.o

kernel_entry: 
	nasm kernel/entry.asm -f elf -o ${OUT}/entry.o

ld_kernel_entry: ${OUT}/interrupt.o ${OUT}/entry.o ${OUT}/kernel.o
	${LD} -o ${OUT}/kernel.bin -Ttext 0x2000 ${OUT}/entry.o ${OUT}/kernel.o ${OUT}/interrupt.o --oformat binary

ld_kernel_entry_elf: ${OUT}/entry.o ${OUT}/kernel.o
	${LD} -o ${OUT}/kernel.elf -Ttext 0x2000 ${OUT}/entry.o ${OUT}/kernel.o

${OUT}/interrupt.o: 
	nasm kernel/interrupt/interrupt.asm -f elf -o $@

boot_sec: ${OUT}/kernel.bin
	nasm boot/bootsect.asm -f bin -o ${OUT}/bootsect.bin 
	cat ${OUT}/bootsect.bin ${OUT}/kernel.bin > ${OUT}/os-image.bin 

start: ${OUT}/os-image.bin
	qemu-system-i386 ${OUT}/os-image.bin

debug: ${OUT}/os-image.bin ${OUT}/kernel.elf
	qemu-system-i386 -s ${OUT}/os-image.bin &
	gdb -ex "target remote localhost:1234" -ex "symbol-file ${OUT}/kernel.elf"
clean:
	rm -rf ${OUT}