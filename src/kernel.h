#ifndef KERNEL_H
#define KERNEL_H
#include<stdint.h>
#include<stddef.h>
void kernel_main();
uint16_t terminal_make_char(char ch, char colour);
void terminal_putchar(char ch, int x, int y,   int colour);
void terminal_initialize();
void print_char(char ch,   int colour);
void print(const char* str, int colour);
#define VIDEO_MEM   0xB8000
#define COLUMNS     80
#define ROWS        25
#define CHAR_COLOR  0xB8001
#endif