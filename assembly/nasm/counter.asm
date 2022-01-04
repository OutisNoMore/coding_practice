; Calculates length of string using pointer arithmetic
; Compile: nasm -f elf counter.asm
; Link: ld -m elf_i386 counter.o -o counter
; execute: ./counter

SECTION .data
msg db 'Variable length string!', 0Ah

SECTION .text
global _start

_start:
  mov ebx, msg ; store string msg in ebx
  mov eax, ebx ; eax also points to msg - as argument for nextchar

; iterates through string msg until null byte is reached for end of string
nextchar:
  cmp byte [eax], 0 ; compare each byte in eax/string with null terminator
  jz finished       ; jump if zero - zero indicates true as flag set by cmp
  inc eax           ; increment eax by one byte
  jmp nextchar      ; jump back to top of function

; calculate str length and print msg
finished:
  sub eax, ebx ; subtract ebx from eax - get number of bytes of string msg (eax = eax - ebx)
  mov edx, eax ; move result from sub into edx
  mov ecx, msg ; move msg into ecx
  mov ebx, 1   ; set STDOUT
  mov eax, 4   ; call SYS_WRITE
  int 80h      ; invoke sys interrupt

  mov ebx, 0   ; set error code to 0 
  mov eax, 1   ; call SYS_EXIT
  int 80h      ; invoke sys interrupt
