section.asm

global idt_load
idt_load:
    pusha
    mov ebp, esp
    mov ebx, [ebp+8]
    lidt [ebx]
    popa
    ret