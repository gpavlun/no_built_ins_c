/*
command functions for various applications

command functions:
err() ---> intentionally creates a segfault
*/

#include "Command_Calls.h"

/*
function: err
intentionally create segfault to terminate program
when error is detected
 */
void err(void){
    static int *zero;
    *zero++;
}