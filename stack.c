#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


//create – create stack with number of elements;
Stack* create (int a){
    Stack *ptrS;
    ptrS = (Stack*) calloc (1, sizeof(Stack));
    ptrS->maxSize = a;
    ptrS->currentSize =0;
    ptrS->top = NULL;
    return ptrS;
}

//push – add element to stack;
void push(int a, Stack* ptrS){
    if( (ptrS->currentSize+1) <= (ptrS->maxSize) ){
        Element *newE = (Element*) calloc (1, sizeof(Element));
        newE->data = a;
        newE->next = NULL;
        newE->previous = NULL;
        if(ptrS->top == NULL){ //checks if it is the first element in the stack
            ptrS->top = newE;
        }else{
            newE->previous = ptrS->top;
            ptrS->top->next = newE;
            ptrS->top = newE;

        }        
        
        ptrS->currentSize++;

    } 
}

//pop – get element from stack;
void pop(Stack *ptr){
    if(ptr->top == NULL){
        printf("The Stack is empty, can't pop anything\n");        
    }else if(ptr->top->previous == NULL){
        //pop the last element
        ptr->top = NULL;
        ptr->currentSize--;        
    }else{
        ptr->top = ptr->top->previous;     
        ptr->top->next = NULL;
        ptr->currentSize--;
    }    
    
}

//capacity – get amount of elements in stack;
int capacity(Stack *ptr){
    return ptr->currentSize;
}

//size – maximum amount of elements.
int size(Stack *ptr){
    return ptr->maxSize;
}

//Resize – increase/decrease size of stack.
void resize(Stack *ptr, int a){
    ptr->maxSize = a;
    while( a < ptr->currentSize){
        pop(ptr);
    }
}
 
void printStack(Stack *ptr){
    int a = ptr->currentSize;
    Stack *ptrS = ptr;
    printf("*** ");
    for(int i=0; i<a; i++){
        printf("%d ",ptrS->top->data);
        ptrS->top = ptrS->top->previous;
    }
    printf("***\n");
}

