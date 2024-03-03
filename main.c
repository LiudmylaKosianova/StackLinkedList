#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
 

int main(){

    Stack* coffe;
    coffe = create(3);
    push(107, coffe);
    printf("%p coffe->top and %d coffe->top->data\n", coffe->top, coffe->top->data);
    push(1, coffe);
    printf("%p coffe->top and %d coffe->top->data\n", coffe->top, coffe->top->data);
    push(7,coffe);
    printf("%p coffe->top and %d coffe->top->data\n", coffe->top, coffe->top->data);
    printf("\ncoffe current size %d\n", coffe->currentSize);
    pop(coffe);
    printf("coffe current size %d\n", coffe->currentSize);



    

    return 0;
}