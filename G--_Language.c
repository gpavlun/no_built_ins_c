#include "Command_Calls.h"
#include "Integer_Ops.h"
#include "Character_Ops.h"
#include "Input_Output.h"

extern int cmp_value;
extern int modulo;

void main(void){
    static int result;
    static int A;
    static int B;
    static char c;
    
    put_str("\n=================\n");
    put_str(" welcome to G--! \n");
    put_str("=================\n\n");

    put_str("please enter a string size(single digit):");
    get_c(&c);
    a2i(c,&A);


    char str[A];
    put_str("please enter a string with size ");
    put_int(A);
    put_c(':');
    get_str(&(str[0]),A);
    put_str(&(str[0]));
    put_c('\n');

    
    
    
/*
    get_c(&cA);
    put_c(cA);
    put_c('\n');
*/
}


