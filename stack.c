#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


 
/*
 * Creates a structure (Stack) and sets the maximum number of elements to a 
 * Parameters: 
 *  a - maximum number of elements 
 * Return:
 *  A pointer to the structure (Stack)
*/
Stack* create (int a){
    Stack *ptrS = (Stack*) calloc (1, sizeof(Stack));
    ptrS->maxSize = a;
    ptrS->currentSize =0;
    ptrS->top = NULL;
    return ptrS;
}


/*
 * Adds one element to the stack.
 * Parameters:
 *  a - integer data value of the new element
 *  ptrS - a pointer to the Stack
 * Return:
 *  Doesnt' return anything, it's a void function
*/
void push(int a, Stack* ptrS){
    if( (ptrS->currentSize+1) <= (ptrS->maxSize) ){
        Element *newE = (Element*) calloc (1, sizeof(Element));
        newE->data = a;
        newE->next = NULL;
        newE->previous = NULL;
        //check if it is the first element in the stack
        if(ptrS->top == NULL){ 
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
        //exit if the stack is empty
        return;
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
    //exit if the an empty stack was passed as an argument
    if(ptr->top == NULL){
        printf("*** The Stack is empty ***\n");       
        return;
    }

    //create a copy of ptr     
    Stack *ptrS = (Stack*) calloc(1, sizeof(Stack));
    ptrS->currentSize=ptr->currentSize;
    ptrS->maxSize=ptr->maxSize;
    ptrS->top=ptr->top;
    int a = ptrS->currentSize; 
     
    printf("*** ");
    for(int i=0; i<a; i++){
        printf("%d ",ptrS->top->data);        
        ptrS->top = ptrS->top->previous;        
    }
    printf("***\n");
     
}

