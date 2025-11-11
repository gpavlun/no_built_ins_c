#include <stdio.h>

#define INT sizeof(int)



int cmp_value;


void set(int *LHS,int RHS);
void isneg(int value);
void inv(int value,int *result);
void cmp(int A,int B);
void add(int initial,int increment,int *result);
void sub(int initial,int increment,int *result);
void mul(int multiplicand,int multiplier,int *result);



void main(void){
    static int result;
    static int A;
    static int B;

    set(&A, -5);
    set(&B, 5);
    mul(A,B,&result);
    printf("%d\n", result);
}





/*
function: set
The first and most important function, this function
sets the variable on the left to the value on the right.
Same as 'V = #'
*/
void set(int *LHS,int RHS){
    (((*LHS)>>INT>>INT>>INT>>3)&0x1) ? 1 : ({goto poszero_loop;});
negzero_loop:
    *LHS ? 1 : ({goto set;});
    (*LHS)++;
    goto negzero_loop;
poszero_loop:
    *LHS ? 1 : ({goto set;});
    (*LHS)--;
    goto poszero_loop;
set:
    ((RHS>>INT>>INT>>INT>>3)&0x1) ? 1 : ({goto posset_loop;});
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
function: isneg
Checks to see if value is negative, very
useful to avoid the long bitwise string
if it is negatibe, return a 1
if it is positive, return a 0
*/
void isneg(int value){
    ((value>>INT>>INT>>INT>>3)&0x1) ? ({goto negative;}) : ({goto positive;});
positive:
    set(&cmp_value, 0);
    goto end;
negative:
    set(&cmp_value, 1);
    goto end;
end:
}
/*
function: cmp
second most useful function, allows you to
copmare two values and stores the concept in the
cmp_value global variable.

positive return value means A is greater than B,
negative return value means A is lesser than B,
zero return value means A is equal to B
*/
void cmp(int A,int B){
    isneg(B);
    cmp_value ? ({goto negative_B;}) : ({goto positive_B;});
positive_B:
positive_loop:
    B ? ({goto subtract;}) : ({goto end;});
subtract:
    A--;
    B--;
    goto positive_loop;
negative_B:
negative_loop:
    B ? ({goto add;}) : ({goto end;});
add:
    A--;
    B++;
    goto negative_loop;
end:
    set(&cmp_value, A);
}
/*
function: add
this function will simply add two numbers
together. Stores the result in the variable
given in the third term.
*/
void add(int initial,int increment,int *result){
    set(result,initial);
    isneg(increment);
    cmp_value ? ({goto negative_inc;}) : ({goto positive_inc;});
positive_inc:
    cmp(increment,0);
    cmp_value ? 1 : ({goto end;});
    (*result)++;
    increment--;
    goto positive_inc;
negative_inc:
    cmp(increment,0);
    cmp_value ? 1 : ({goto end;});
    (*result)--;
    increment++;
    goto negative_inc;
end: 
}
/*
function: sub
this function will subtract two numbers
stores the result in the given variable
*/
void sub(int initial,int increment,int *result){
    add(~increment, 1, &increment);
    add(initial,increment,result);
}
/*
function:inv
inverts the sign of a number
*/
void inv(int value,int *result){
    add(~value, 1, result);

}
/*
function: mul
multiplies two numbers together and stores
in the given result variable
*/
void mul(int multiplicand,int multiplier,int *result){
    static int negative;
    set(&negative,0);
    set(result, 0);
    cmp(multiplier,0);
    cmp_value ? 1 : ({goto mul_zero;});
    isneg(multiplier);
    cmp_value ? 1 : ({goto mul_loop;});
    inv(multiplier,&multiplier);
    set(&negative,1);
mul_loop:
    cmp(multiplier, 0);
    cmp_value ? 1 : ({goto neg_check;});
    add(*result,multiplicand,result);
    multiplier--;
    goto mul_loop;
neg_check:
    cmp(negative,0);
    cmp_value ? 1 : ({goto end;});
    inv(*result,result);
    goto end;
mul_zero:
    set(result,0);
    goto end;
end:

}