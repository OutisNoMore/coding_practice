 ; Print message of unknown length using functions/subroutines
 ; Compile: nasm -f elf funcCount.asm
 ; link: ld -m elf_i386 funcCount.o -o funcCount
 ; execute: ./funcCount

 SECTION .data
 msg db "Variable String length", 0Ah

 SECTION .text
 global _start

 _start:
  mov eax, msg ; move msg into eax as argument for call to strlen
  call strlen  ; call custom funtion strlen to calculate length of string in eax - jumps to strlen mem location
               ; result is stored in eax register

  mov edx, eax ; move length of string msg into edx register
  mov ecx, msg ; move string msg into ecx register
  mov ebx, 1   ; write to STDOUT
  mov eax, 4   ; call SYS_WRITE
  int 80h      ; Invoke system interrupt

  mov ebx, 0   ; no error flag
  mov eax, 1   ; call SYS_EXIT
  int 80h      ; invoke sys interrupt

; declare strlen function/label
strlen:
  push ebx     ; save mem address of ebx onto stack - so we can go back to it later
  mov ebx, eax ; move address of eax into ebx

; find mem address of last char in string held in eax
nextchar:
  cmp byte [eax], 0
  jz finished
  inc eax
  jmp nextchar

; calculate size of msg held in eax in bytes
finished:
  sub eax, ebx ; eax = eax - ebx
  pop ebx      ; get value of ebx from stack - mem address of msg
  ret          ; return to mem adress where call was originally made ie _start

