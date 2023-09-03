#ifndef IDT_H
#define IDT_H
#include<stdint.h>

struct idt_desc
{
    uint16_t offset_1; //offset bits 0-15
    uint16_t selector; //selector described in GDT CODE_SEG and DATA_SEG
    uint8_t zero;//unused set of zero
    uint8_t type_attr; //descryptor type and attribute
    uint16_t offset_2; //offset bits 16-31
}__attribute__((packed));

struct idtr_desc
{
    uint16_t limit; //size of descriptor table
    uint32_t base;//base address of the descriptor table
}__attribute__((packed));



#endif