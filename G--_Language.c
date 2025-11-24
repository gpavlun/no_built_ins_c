#include "Command_Calls.h"
#include "Integer_Ops.h"
#include "Character_Ops.h"
#include "Input_Output.h"

#define memblock char

extern int cmp_value;
extern int modulo;

void main(void){    
    put_str("\n=================\n");
    put_str(" welcome to G--! \n");
    put_str("=================\n\n");

    /*
    This code is 10 * 2 using predefined data
    blocks and type casting. this is a proof of
    concept, as I am going to remove the type
    casting from everywhere in the code to
    create to make G-- an untyped language
    where everything is void
    */

    memblock MemoryBlock[100];
    set((int *)&(MemoryBlock[3]),10);
    set((int *)&(MemoryBlock[7]), 2);
    mul((int)MemoryBlock[3],(int)MemoryBlock[7],(int *)&(MemoryBlock[11]));
    put_int((int)(MemoryBlock[11])); 
    // print the result using our integer printing function
}


