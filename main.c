#include <stdio.h>
#include <assert.h>
#include "stack.h"
 

int main(){

    Stack* coffe;
    coffe = create(3);
    assert(size(coffe)==3);
    assert(capacity(coffe)==0);
    push(77, coffe);
    push(10, coffe);
    push(51, coffe);
    push(101, coffe);
    printf("There are %d elements in the Stack\n", coffe->currentSize);
    printStack(coffe);
    resize(coffe, 4);
    push(329, coffe);
    printf("There are %d elements in the Stack\n", coffe->currentSize);
    printStack(coffe);
    resize(coffe, 2);
    assert(size(coffe)==2);
    assert(capacity(coffe)==2);
    printf("There are %d elements in the Stack\n", coffe->currentSize);
    printStack(coffe);
    pop(coffe);
    pop(coffe);
    assert(size(coffe)==2);
    assert(capacity(coffe)==0);
    printf("There are %d elements in the Stack\n", coffe->currentSize);
    printStack(coffe);
    pop(coffe);
    assert(size(coffe)==2);
    assert(capacity(coffe)==0);
    printf("There are %d elements in the Stack\n", coffe->currentSize);
    printStack(coffe);
    printf("Fine\n");

    return 0;
}