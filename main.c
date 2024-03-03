#include <stdio.h>
#include <stdlib.h>

//#include "stack.h"

typedef struct Element{
    int data;
    struct Element *next;
    struct Element *previous;
}Element;

typedef struct Stack{
    int maxSize;
    int currentSize;
    Element *top;
}Stack;


//create – create stack with number of elements;
Stack* create (int a){
    Stack *ptrS;
    ptrS = (Stack*) calloc (1, sizeof(Stack));
    ptrS->maxSize = a;
    ptrS->currentSize =0;
    ptrS->top = NULL;
}
//push – add element to stack;
void push(int a, Stack *ptrS){
    if( (ptrS->currentSize+1) <= (ptrS->maxSize) ){
        Element *newE = (Element*) calloc (1, sizeof(Element));
        newE->data = a;
        if(ptrS->top != NULL){ //checks if it isn't the first element in the stack
            newE->previous = ptrS->top;
        }else{
            ptrS->top = newE;
            newE->previous = NULL;
        }        
        newE->next = NULL;
        ptrS->currentSize++;
    }else{
        printf("Cannot add more elements\n");
    }
}

Element* createElement(int a){
    Element *ptr;
    ptr = (Element*) calloc(1, sizeof(Element));
    ptr->data = a;
    ptr->next = NULL;
    ptr->previous = NULL;
}

int main(){

    Stack* coffe;
    coffe = create(2);
    push(107, coffe);
    printf("107 added ");
    push(1, coffe);
    printf("1 added ");
    push(7,coffe);
    printf("7 added ");

    // Element *coffe = createElement(100);
    // printf("coffe data %d\n", coffe->data);

    return 0;
}