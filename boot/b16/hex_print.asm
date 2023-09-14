print_hex:
    pusha
    mov cx,0

print_hex_start:
    cmp cx,4
    je print_hex_done
    mov ax,dx
    and al,0x0f
    add al,0x30
    cmp al,0x39
    jle print_hex_process
    add al,7
    jmp print_hex_process
print_hex_process:
    mov bx,HEX_OUT+5
    sub bx,cx
    mov [bx],al
    add cx,1
    ror dx,4
    jmp print_hex_start

print_hex_done:
    mov bx,HEX_OUT
    call print
    popa
    ret

HEX_OUT:
    db "0x0000",0