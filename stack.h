#ifndef STACK_FUNC
#define STACK_FUNC

typedef struct Element
{
    int data;
    struct Element *next;
    struct Element *previous;
}Element;

typedef struct Stack
{
    int maxSize;
    int currentSize;
    Element *top;
}Stack;

Stack* create (int a);
void push(int a, Stack* ptrS);
void pop(Stack *ptr);


#endif
