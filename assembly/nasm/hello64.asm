; Hello World using nasm on a 64 bit linux system
; Compile with: nasm -f elf64 hello64.asm
; Link with: ld hello64.o -o hello64
; Execute with: ./hello64

    global _start
    
    section .text

_start:
    mov rax, 1       ; Invoke SYS_WRITE
    mov rdi, 1       ; Write to STDOUT 
    mov rsi, message ; pointer to message
    mov rdx, 13      ; size of string/bytes to write
    syscall          ; System interrupt

    mov rax, 60      ; Invoke SYS_EXIT
    xor rdi, rdi     ; Zero out rdi register - can also mov 0, but less efficient b/c need to use 5 bytes to zero 32 bit 
    syscall          ; System Interrupt

    section .data
message: db "Hello, World", 10

