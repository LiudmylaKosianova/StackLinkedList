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

