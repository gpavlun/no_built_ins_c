#define INT 4
#define CHR 1

int cmp_value;
int modulo;

/*command functions*/
void err(void);//thx James
/*integer operations*/
void set(int *LHS,int RHS);                             //sets a variable to a given value
void neg(int value);                                    //checks if a given value is negative
void inv(int value,int *result);                        //changes the sign of a given value
void cmp(int A,int B);                                  //compares two values
void add(int initial,int increment,int *result);        //adds to values
void sub(int initial,int increment,int *result);        //subtracts two values
void mul(int multiplicand,int multiplier,int *result);  //multiplies two values
void div(int dividend,int divisor,int *result);         //badly divides two values
/*character operations*/
void setc(char *LHS,char RHS);                          //sets a variable to a character
void i2a(int integer,char *character);                 //converts an int to a printatble form
void a2i(char character,int *integer);
void put_c(int value);                                //puts an ascii character on the command line
void put_int(int value);                                
void put_str(char *string);

void get_c(char *dest); 
void get_str(char *dest,int size);



void main(void){
    static int result;
    static int A;
    static int B;
    static char c;
    static char str[6];
    put_str("\n=================\n");
    put_str(" welcome to C--! \n");
    put_str("=================\n\n");

    
    put_str("please enter a string size(single digit):");
    get_c(&c);
    a2i(c,&A);
    put_int(A);
/*
    get_c(&cA);
    put_c(cA);
    put_c('\n');
*/
}





/*
function: set
The first and most important function, this function
sets the variable on the left to the value on the right.
Same as 'V = #'
*/
void set(int *LHS,int RHS){
    (((*LHS)>>INT>>INT>>INT>>INT>>INT>>INT>>3)&0x1) ? 1 : ({goto poszero_loop;});
negzero_loop:
    *LHS ? 1 : ({goto set;});
    (*LHS)++;
    goto negzero_loop;
poszero_loop:
    *LHS ? 1 : ({goto set;});
    (*LHS)--;
    goto poszero_loop;
set:
    ((RHS>>INT>>INT>>INT>>INT>>INT>>INT>>3)&0x1) ? 1 : ({goto posset_loop;});
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
function: neg
Checks to see if value is negative, very
useful to avoid the long bitwise string
if it is negative, return a 1
if it is positive, return a 0
*/
void neg(int value){
    ((value>>INT>>INT>>INT>>INT>>INT>>INT>>3)&0x1) ? ({goto negative;}) : ({goto positive;});
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
* note: "return" value is just the value stored in cmp_value
*/
void cmp(int A,int B){
    neg(B);
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
    neg(increment);
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
    neg(multiplier);
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
/*
function: div
divides two numbers and stores answer in the 
given variable. stores the modulo in the 
global variable "modulo"
*/
void div(int dividend,int divisor,int *result){
    divisor ? 1 : err();
    int negative;
    set(&negative,0);
    neg(dividend);
    cmp_value ? 1 : ({goto neg1;});
    negative++;
    inv(dividend,&dividend);
neg1:
    neg(divisor);
    cmp_value ? 1 : ({goto neg2;});
    negative++;
    inv(divisor,&divisor);
neg2:
    set(result,0);
div_loop:
    neg(dividend);
    cmp_value ? ({goto modulo;}) : 1;
    sub(dividend,divisor,&dividend);
    (*result)++;
    goto div_loop;
modulo:
    (*result)--;
    add(dividend,divisor,&dividend);
    set(&modulo,dividend);
    cmp(negative,1);
    cmp_value ? ({goto end;}) : 1;
    inv(*result,result);
end:
}
/*
function: err
intentionally create segfault to terminate program
when error is detected
 */
void err(void){
    int *zero;
    set(zero,0);
    *zero++;
}
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
function setc
sets a value to a character variable
*/
void setc(char *LHS,char RHS){
    (((*LHS)>>CHR>>CHR>>CHR>>CHR>>CHR>>CHR>>3)&0x1) ? 1 : ({goto poszero_loop;});
negzero_loop:
    *LHS ? 1 : ({goto set;});
    (*LHS)++;
    goto negzero_loop;
poszero_loop:
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
    put_c('\n');
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
        "mov $0, %%rax\n"
        "mov $1, %%rdi\n"
        "mov %0, %%rsi\n"
        "mov $1, %%rdx\n"
        "syscall\n"
        :
        : "r"(dest)
        : "%rax", "%rdi", "%rsi", "%rdx"
    );
}
/*
function: get_str
reads string from command line
*/
void get_str(char *dest,int size){
        asm(
        "mov $0, %%rax\n"
        "mov $1, %%rdi\n"
        "mov %0, %%rsi\n"
        "mov $6, %%rdx\n"
        "syscall\n"
        :
        : "r"(dest),"r"(size)
        : "%rax", "%rdi", "%rsi", "%rdx"
    );
}
/*
function: a2i
converts ascii number to int
*/
void a2i(char character,int *integer){
    int increment;
    setc(integer,character);
    set(&increment,0x30);
positive_inc:
    cmp(increment,0);
    cmp_value ? 1 : ({goto end;});
    (*integer)--;
    increment--;
    goto positive_inc;
end: 
}