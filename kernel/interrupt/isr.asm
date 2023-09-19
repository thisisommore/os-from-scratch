handle_interrupt_label isr_handle, isr_handler

; expands to
; global isrx
; isrx:
;     cli
;     ; if no error push 0 to maintain stack
;     push byte 0
;     push byte x
;     jmp isr_handle
;
; params:
; 1 - start isr
; 2 - number isr labels to generate starting from start isr
; 3 - if extra byte for error to be pushed
%macro isr_label 2-3
    %assign i %1
    %rep %2
        global isr %+ i
        isr %+ i:
            cli
            %ifnid %3
            push byte 0
            %endif
            push byte i
            jmp isr_handle
        %assign i i+1
    %endrep
%endmacro

; without error code
isr_label 0, 8
isr_label 9, 1
isr_label 15, 17

; with error code
isr_label 8, 1, 1
isr_label 10, 5, 1
