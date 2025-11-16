/*
input and output functions for the command line
*/

#include "Character_Ops.h"
#include "Integer_Ops.h"
#include "Input_Output.h"

extern int cmp_value;
extern int modulo;

/*
function put_c
prints a single charcter to the commandline
*/
void put_c(int value){
    char c;
    setc(&c,value);
    asm(
        "mov $1, %%rax\n"
        "mov $1, %%rdi\n"
        "mov %0, %%rsi\n"
        "mov $1, %%rdx\n"
        "syscall\n"
        :
        : "r"(&c)
        : "%rax", "%rdi", "%rsi", "%rdx"
    );
}
/*
function: put_int
writes an entire integer to the command line in hexadecimal
*/
void put_int(int value){
    char integer[8];
    char negative;
    static int index;
    static int shift;
    set(&index,8);
    setc(&negative,0);
    neg(value);
    cmp_value ? 1 : ({goto start;});
    setc(&negative,1);
    inv(value,&value);
    put_c(0x2D);
start:
    put_c('0');
    put_c('x');
loop:
    index--;
    mul(index,4,&shift);
    setc(&(integer[index]),(value>>shift)&0xF);
    i2a(integer[index],&(integer[index]));
    put_c(integer[index]);
    index ? ({goto loop;}) : 1;
}
/*
function: put_int
writes a string to the command line
*/
void put_str(char *string){
loop:
    put_c(*string);
    string++;
    cmp(*string,'\0');
    cmp_value ? ({goto loop;}) : 1;
}  
/*
function: get_c
gets a value from the command line
*/
void get_c(char *dest){
    asm(
        "movq $0, %%rax\n"
        "movq $0, %%rdi\n"
        "movq %0, %%rsi\n"
        "movq $2, %%rdx\n"
        "syscall\n"
        :
        : "r"(dest)
        : "%rax", "%rdi", "%rsi", "%rdx"
    );
    cmp(dest[0],'\n');
    cmp_value ? 1 : ({goto end;});
    cmp(dest[1],'\n');
    cmp_value ? 1 : ({goto end;});    
    err();
    end:
}
/*
function: get_str
reads string from command line
*/
void get_str(char *dest,int size){
        size++;
        asm(
        "movq $0, %%rax\n"
        "movq $0, %%rdi\n"
        "movq %0, %%rsi\n"
        "movq $6, %%rdx\n"
        "syscall\n"
        "movq %%rax, %%rbx\n"
        : "=ri"(dest): "ri"(&size)
        : "%rax", "%rdi", "%rsi", "%rdx"
    );
// loop:
//     cmp(size,0);
//     cmp_value ? 1 : err();
//     size--;
//     cmp(*dest,'\n');
//     dest++;
//     cmp_value ? ({goto loop;}) : 1;

}