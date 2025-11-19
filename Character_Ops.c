/*
contains all operations used for data type character,
which is defined as one byte in this system

list of operations:
setc() ---> assignment
i2a() ---> converts integers to ascii
a2i() ---> converts ascii to integers
cmp() ---> compares two numbers
put_c() ---> prints a single character
put_int() ---> prints a single integer
put_str() ---> prints an entire string
get_c() ---> reads a single character
get_str() ---> reads a string of variable length**supposed too
*/
#include "Integer_Ops.h"
#include "Character_Ops.h"
#include "Command_Calls.h"

#define CHR 1
extern int cmp_value;
extern int modulo;

/*
function setc
sets a character pointed to by LHS to a specified value (RHS)
*/
void setc(char *LHS,char RHS){
    (((*LHS)>>CHR>>CHR>>CHR>>CHR>>CHR>>CHR>>3)&0x1) ? 1 : ({goto poszero_loop;}); // check sign bit
negzero_loop: // set negative number to zero
    *LHS ? 1 : ({goto set;});
    (*LHS)++;
    goto negzero_loop;
// will only go through poszero loop once if already set negative number to zero
poszero_loop: // set positive number to zero
    *LHS ? 1 : ({goto set;});
    (*LHS)--;
    goto poszero_loop;
set:
    ((RHS>>CHR>>CHR>>CHR>>CHR>>CHR>>CHR>>3)&0x1) ? 1 : ({goto posset_loop;});
negset_loop:
    RHS ? 1 : ({goto end;});
    RHS++;
    (*LHS)--;
    goto negset_loop;
posset_loop:
    RHS ? 1 : ({goto end;});
    RHS--;
    (*LHS)++;
    goto posset_loop;
end:
}
/*
function: i2a
converts an integer to an ascii version
*/
void i2a(int integer,char *character){
    int increment;
    setc(character,integer);
    set(&increment,0x30);
positive_inc:
    cmp(increment,0);
    cmp_value ? 1 : ({goto end;});
    (*character)++;
    increment--;
    goto positive_inc;
end: 
}
/*
function: a2i
converts ascii number to int
*/
void a2i(char character,int *integer){
    int increment;
    setc((char *)integer,character);
    set(&increment,0x30);
positive_inc:
    cmp(increment,0);
    cmp_value ? 1 : ({goto end;});
    (*integer)--;
    increment--;
    goto positive_inc;
end: 
}
