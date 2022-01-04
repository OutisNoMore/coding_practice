all: libTest

libTest.o: libTest.asm
	nasm -s -f elf $< 

libTest: libTest.o
	ld -m elf_i386 $< -o $@

clean:
	rm libTest.o libTest
