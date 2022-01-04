; Hello World Program for a 32 bit linux system using nasm
; Compile with nasm -f elf hello32.asm
; Link with ls -m elf_i386 hello32.o -o hello32
; Run with ./hello32

SECTION .data
msg db 'Hello World!', 0Ah ; 0Ah - line feed or \n

SECTION .text
global _start   ; start of program 

_start:
  mov edx, 13   ; Number of bytes to write 12 chars + 0Ah (line feed)
  mov ecx, msg  ; Memory address of msg into ecx
  mov ebx, 1    ; Write to STDOUT file
  mov eax, 4    ; Invoke SYS_WRITE (opcode 4)
  int 80h       ; call sys interrupt

  ; initiating system exit
  mov ebx, 0    ; error status 0 - no error
  mov eax, 1    ; invoke SYS_EXIT
  int 80h       ; call sys interrupt
