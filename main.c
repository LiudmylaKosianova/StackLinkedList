#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "stack.h"
 

int main(int argc, char *arg[]){

    if( (argc<2)||(strcmp(arg[1], "-h")==0)||(strcmp(arg[1],"--help")==0) ){
        help_user();
        return 0;
    }else if (strcmp(arg[1], "test")==0){

    //create a new stack
    printf("Created a new stack with a maximum size of 3\n");
    Stack* coffe;
    coffe = create(3);
    //check that the maximum size is set correctly and that the stack is empty
    assert(size(coffe)==3);
    assert(capacity(coffe)==0);
    //add elements
    printf("Adding elements...\n");
    push(77, coffe);
    push(10, coffe);
    push(51, coffe);
    //check that it's not possible to add any more elements
    push(101, coffe);
    //print the stack
    printf("There are %d elements in the Stack\n", coffe->currentSize);
    printStack(coffe);
    //resize the stack, so that the new maximum is bigger than the current maximum
    printf("Resizing stack and adding elements...\n");
    resize(coffe, 4);
    push(329, coffe);
    printf("There are %d elements in the Stack\n", coffe->currentSize);
    printStack(coffe);
    //resize the stack, so that the new maximum is smaller than the current maximum
    printf("Reducing the size of the stack...\n");
    resize(coffe, 2);
    assert(size(coffe)==2);
    assert(capacity(coffe)==2);
    printf("There are %d elements in the Stack\n", coffe->currentSize);
    printStack(coffe);
    printf("Popping elements..\n");
    //pop the elements
    pop(coffe);
    pop(coffe);
    assert(size(coffe)==2);
    assert(capacity(coffe)==0);
    printf("There are %d elements in the Stack\n", coffe->currentSize);
    printStack(coffe);
    printf("Trying to pop elements from an empty stack...\n");
    //check that it's not posible to pop from empty stack
    pop(coffe);
    assert(size(coffe)==2);
    assert(capacity(coffe)==0);
    printf("There are %d elements in the Stack\n", coffe->currentSize);
    printStack(coffe);
    printf("Fine\n");
    }   
    

    return 0;
}