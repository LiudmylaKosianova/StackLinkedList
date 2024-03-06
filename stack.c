#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void help_user(){
    printf("This stack is based on a linked list implemented as a structure\n");
    printf("Functions: create(),push(),pop(),capacity(),size(),resize(),printStack()\n");
    printf("\n");
    printf("Stack* create(int a) - \tCreates a structure (Stack) and sets the maximum number of elements to int a\n"); 
    printf("\t\t\tParameters: int a - maximum number of elements\n");
    printf("\t\t\tReturn: a pointer to the structure (Stack) \n");
}


 
/*
 * Creates a structure (Stack) and sets the maximum number of elements to int a 
 * Parameters: 
 * int a - maximum number of elements 
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
 * int a - integer data value of the new element
 *  ptrS - a pointer to the Stack
 * Return:
 *  Doesn't return anything, it's a void function
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


/**
 * Deletes (pops) the top element from the stack
 * Parameters:
 *  ptr - a pointer to the stack
 * Return:
 *  Doesn't return anything, it's a void function 
*/
void pop(Stack *ptr){
    if(ptr->top == NULL){
        //exit if the stack is empty
        return;
    }else if(ptr->top->previous == NULL){
        //pop the top element
        ptr->top = NULL;
        ptr->currentSize--;        
    }else{
        ptr->top = ptr->top->previous;     
        ptr->top->next = NULL;
        ptr->currentSize--;
    }    
    
}


/**
 * Gets the current number of elements in the stack
 * Parameters:
 *  ptr - a pointer to the stack
 * Return:
 *  Returns int number of elements in the stack  
*/
int capacity(Stack *ptr){
    return ptr->currentSize;
}


/**
 * Gets the maximum number of elements the stack can hold
 * Parameters:
 *  ptr - a pointer to the stack
 * Return:
 *  Returns int maximum number of elements that the stack can hold * 
*/
int size(Stack *ptr){
    return ptr->maxSize;
}


/**
 * Changes the maximum number of elements that the stack can hold.
 * If the new maximum is less, than the current number of elements in the stack,
 * then the top extra elements will be deleted (poped)
 * Parameters:
 *  ptr - a pointer to the stack
 *  a - integer value of the new maximum size of the stack
 * Return:
 *  Doesn't return anything, it's a void function
*/
void resize(Stack *ptr, int a){
    ptr->maxSize = a;
    while( a < ptr->currentSize){
        pop(ptr);
    }
}
 
/**
 * Prints the int data values of the elements in the stack
 * Parameters:
 *  ptr - a pointer to the stack
 * Return:
 *  Doesn't return anything, it's a void function.
 * */ 
void printStack(Stack *ptr){
    //exit if the an empty stack was passed as an argument
    if(ptr->top == NULL){
        printf("*** The Stack is empty ***\n");       
        return;
    }

    //create a copy of ptr for safe iteration     
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

