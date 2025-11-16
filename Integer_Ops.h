/*
header for integer operations
*/

void set(int *LHS,int RHS);                             //sets a variable to a given value
void neg(int value);                                    //checks if a given value is negative
void inv(int value,int *result);                        //changes the sign of a given value
void cmp(int A,int B);                                  //compares two values
void add(int initial,int increment,int *result);        //adds to values
void sub(int initial,int increment,int *result);        //subtracts two values
void mul(int multiplicand,int multiplier,int *result);  //multiplies two values
void div(int dividend,int divisor,int *result);         //badly divides two values