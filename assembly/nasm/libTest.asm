; libTest - includes util.asm library and checks that all functions work as intended
; compile with: nasm -f elf libTest.asm
; link with: ld -m elf_i386 libTest.o -o libTest
; execute: ./libTest

%include 'util.asm' ; import library

SECTION .data
msg1 db 'Hello world!', 0Ah, 0h             ; 0h - null terminate
msg2 db 'String of unknown length', 0Ah, 0h ; 0h - null terminate

SECTION .text
global _start

_start:
  mov eax, msg1
  call strprint ; print msg1

  mov eax, msg2
  call strprint ; print msg2

  call quit     ; exit program
