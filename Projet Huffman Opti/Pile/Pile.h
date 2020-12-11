#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED
#include "../Structure/Structure.h"
typedef struct Stack{
    Node *no;
    struct Stack *next;
}Stack;

void push(Stack**s, Node* val);
Node* pop(Stack** s);

#endif // PILE_H_INCLUDED

