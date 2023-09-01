org 0x0
bits 16

_start:
    jmp short start
    nop

    times 33 db 0



start:
    jmp 0x7c0:step2

handle_zero:
    mov ah,0x0e
    mov al, 'A'
    mov bx, 0x0
    int 0x10
    iret
handle_one:
    mov ah, 0x0e
    mov al, 'a'
    mov bx, 0x00
    int 0x10
    iret

step2:
    cli
    mov ax, 0x7c0
    mov ds, ax
    mov es, ax
    mov ax, 0x00
    mov ss, ax
    mov sp, 0x7c00
    sti
    mov word[ss:0x00], handle_zero
    mov word[ss:0x02], 0x7c0
    int 0x0
    mov word[ss:0x04], handle_one
    mov word[ss:0x06], 0x7c0
    int 1 
    mov si, message
    call print
    mov ah, 0x02
    mov al, 0x01
    mov ch, 0x00
    mov cl, 2
    mov dh, 0
    mov bx, buffer
    int 0x13
    jc error
    mov si, buffer
    call print
    cli
    lgdt [gdtr]
    mov eax, cr0
    or al, 1
    mov cr0, eax
    jmp 0x08, PMode
    jmp $

error:
    mov si, err_msg
    call print
    jmp $
print:
    mov bx, 0
.loop:
    lodsb
    cmp al, 0
    je .done
    call print_char
    jmp .loop
.done:
    ret

print_char:
    mov ah, 0x0e
    int 0x10
    ret
err_msg: db "Failed to load Message"
message: db "Hello World", 0
times 510 - ($-$$) db 0
dw 0xaa55
buffer: