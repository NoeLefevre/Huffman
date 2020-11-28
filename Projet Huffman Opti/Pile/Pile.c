#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pile.h"

void push(Stack**s, Node* val){
    Stack *nouv = malloc(sizeof(Stack));
    nouv->no = val;
    nouv->next = *s;
    *s = nouv;
}

Node* pop(Stack** s){
    Node * nbr = NULL;
    Stack *temp = *s;
    if (s!=NULL)
        {
            nbr = temp->no;
            *s = temp->next;
            free(temp);
        }
        return nbr;
}
