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
    // assert(size(coffe)==3);
    // assert(capacity(coffe)==3);
    // resize(coffe, 4);
    // assert(size(coffe)==4);
    // assert(capacity(coffe)==3);
    // push(329, coffe);
    // assert(size(coffe)==4);
    // assert(capacity(coffe)==4);
    // resize(coffe, 2);
    // assert(size(coffe)==2);
    // assert(capacity(coffe)==2);
    // pop(coffe);
    // pop(coffe);
    // assert(size(coffe)==2);
    // assert(capacity(coffe)==0);
    // pop(coffe);
    // assert(size(coffe)==2);
    // assert(capacity(coffe)==0);
    printf("Fine\n");

    return 0;
}