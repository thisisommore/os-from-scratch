[org 0x7c00]
KERNAL_OFFSET equ 0x2000

mov bp,0x9000
mov sp,bp
mov bx, BOOTING
call print_ln
call print

mov bx,KERNAL_OFFSET
mov dh,4
call disk_load 
call switch_pm

;16 bit
%include "./boot/b16/_include.asm"
%include "./boot/switch_pm/gdt.asm"

;32 bit
%include "./boot/b32/32_print.asm"
%include "./boot/switch_pm/pm_switch.asm"

[bits 32]
BEGIN_PM:
    ; mov bx,0x1000
    mov ebx, CALL_K
    call print_pm
    call KERNAL_OFFSET
    jmp $

BOOTING: db "Booting", 0
CALL_K: db "Starting Kernel", 0
times 510-($-$$) db 0
dw 0xaa55