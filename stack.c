#include <stdio.h>
#include <stdlib.h>


typedef struct Element
{
    int data;
    Element* next;
    Element* previous;
}Element;

typedef struct Stack
{
    int maxSize;
    int currentSize;
    Element* top;
}Stack;

//create – create stack with number of elements;
void create (Stack *ptrS, int a){
    ptrS->maxSize = a;
    ptrS->currentSize =0;
    ptrS->top = NULL;
}
//push – add element to stack;
void push(int a, Stack* ptrS){
    if( (ptrS->currentSize+1) <= (ptrS->maxSize) ){
        Element* newE = (Element*) calloc (1, sizeof(Element));
        newE->data = a;
        if(ptrS->top != NULL){ //checks if it isn't the first element in the stack
            newE->previous = ptrS->top;
        }else{
            ptrS->top = newE;
            newE->previous = NULL;
        }        
        newE->next = NULL;
        ptrS->currentSize++;
    }
}

