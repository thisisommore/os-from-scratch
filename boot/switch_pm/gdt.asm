gdt_start:
    ; null start
    dd 0
    dd 0

gdt_code:
    ; seg len
    dw 0xffff
    ; seg base
    dw 0
    db 0

    ; 1st and type flag
    db 10011010b

    ; 2nd flags and seg limit last
    db 11001111b

    ; seg base last
    db 0

gdt_data:
    ; seg len
    dw 0xffff
    ; seg base
    dw 0
    db 0

    ; 1st and type flag
    db 10010010b

    ; 2nd flags and seg limit last
    db 11001111b

    ; seg base last
    db 0

gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start