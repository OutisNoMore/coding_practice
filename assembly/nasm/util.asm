; libraryr of basic commonly used functions
; for linux 32 bit system using nasm
; include with: %include 'util.asm'

; int strlen(eax = String message)
; Calculates length of string
; String length is stored in eax
strlen:
  push ebx     ; save value of ebx
  mov ebx, eax ; copy msg in eax into ebx

; find mem address of end of string msg in eax
nextchar:
  cmp byte [eax], 0 ; compare each byte of eax to zero - find mem address of end of msg
  jz finished       ; if cmp flag is 0/true then jump to finished
  inc eax           ; increment eax by one
  jmp nextchar      ; go back to nextchar

; use pointer math to calculate length of string msg in eax
finished:
  sub eax, ebx ; eax = eax - ebx 
  pop ebx      ; get original value of ebx
  ret          ; return to where func was called

; void strprint(eax = String message)
; prints string message to stdout
strprint:
  push edx    ; save value of edx - must save so that values from calling program are not lost
  push ecx    ; save value of ecx
  push ebx    ; save value of ebx
  push eax    ; save value of eax
  call strlen ; call strlen to get length of string

  mov edx, eax ; set edx = eax or length of string
  pop eax      ; get original value of eax or msg

  mov ecx, eax ; set ecx to eax or msg
  mov ebx, 1   ; set write to STDOUT
  mov eax, 4   ; set SYS_WRITE
  int 80h      ; invoke sys interrupt

  pop ebx      ; get original value of ebx
  pop ecx      ; get original value of ecx
  pop edx      ; get original value of edx
  ret          ; return to where func was called

; void quit
; call sys_exit to end program
quit:
  mov ebx, 0 ; set error status to 0 - no error
  mov eax, 1 ; call SYS_EXIT
  int 80h    ; invoke sys interrupt
  ret        ; return to where func was called
