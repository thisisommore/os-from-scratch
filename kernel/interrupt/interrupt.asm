; declares extern handler(2) and handle label(1) which prepares registers 
; and segment and calls handler(2) defined in C
%macro handle_interrupt_label 2
[extern %2]
%1:
    pusha
    mov ax,ds
    push eax
    mov ax,0x10
    mov ds,ax
    mov es,ax
    mov fs,ax
    mov gs,ax

    call %2
    pop eax
    mov ds,ax
    mov es,ax
    mov fs,ax
    mov gs,ax
    popa
    add sp, 8
    sti
    iret
%endmacro

%include "./kernel/interrupt/isr.asm"
%include "./kernel/interrupt/irq.asm"
