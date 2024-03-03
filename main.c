#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
 

int main(){

    Stack* coffe;
    coffe = create(2);
    push(107, coffe);
    printf("107 added ");
    push(1, coffe);
    printf("1 added ");
    push(7,coffe);
    printf("7 added ");

    

    return 0;
}