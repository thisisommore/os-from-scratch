handle_interrupt_label irq_handle, irq_handler

; expands to
; global irqx
; irqx:
;     cli
;     push byte 0
;     push byte x+32
;     jmp irq_handle
;
%assign i 0
%rep 16
global irq %+ i
irq %+ i:
    cli
    ; TODO: don't push error code
    push byte 0
    push byte i+32
    jmp irq_handle
%assign i i+1
%endrep
