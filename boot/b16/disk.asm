disk_load:
    pusha
    push dx

    mov al,dh ; al=no of sectors to read
    mov ah,2 ; read
    mov cl,2 ; cl=starting sector
    mov ch,0 ; ch=cylinder
    ; dl=disk number - set by bios
    mov dh,0 ; dh=head

    int 0x13
    jc edisk
    pop dx
    cmp al,dh
    jne esector
    popa
    ret
esector:
    mov bx, ESECTOR
    call print
    call print_ln

edisk:
    mov bx, EDISK
    call print
    call print_ln

    mov dl,ah
    mov dh,0
    call print_hex
    call print_ln

ESECTOR: db "Failed to read all sectors",0
EDISK: db "Failed to read disk",0