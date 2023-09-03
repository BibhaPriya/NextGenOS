#include"kernel.h"
#include"idt/idt.h"
int terminal_row=0;
int terminal_col=0;

uint16_t terminal_make_char(char ch, char colour){
    return (colour<<8) | ch;

}

void terminal_putchar(char ch, int col, int row,   int colour){
        if(ch == '\n'){
            terminal_row += 1;
            terminal_col = 0;
            return;
        }
    uint16_t* videomem = (uint16_t*)VIDEO_MEM;
    videomem[(row)*COLUMNS + col] = terminal_make_char(ch, colour);
}

void terminal_initialize(){
    terminal_row = 0;
    terminal_col =0;
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLUMNS; j++){
            terminal_putchar(' ', j, i, 15);
        }
    }

}

void terminal_writechar(char ch,   int colour){
    terminal_col +=1;
    terminal_putchar(ch,terminal_col, terminal_row, colour);
    
    if (terminal_col>=COLUMNS)
    {
        terminal_col = 0;
        terminal_row +=1;
    }
}

size_t strlen(const char* str){
    int len =0;
    while(str[len]){
        len++;
    }
    return len;
}

void print(const char* str, int colour){
    int length = strlen(str);
    for(int i =0; i<length; i++){

        terminal_writechar(str[i],colour);
    }
}

extern void problem();

void kernel_main(){

    terminal_initialize();
    print("Hello World!\nHello\n", 15);
    print("Hello World!\n", 15);
    //Initialize interup descriptor table
    idt_init();
    problem();

}