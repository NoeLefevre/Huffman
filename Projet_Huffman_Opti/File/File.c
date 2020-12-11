#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "File.h"
void enqueue(Queue** q, Node* val){
    Queue *nouv = malloc(sizeof(Queue));
    nouv->no = val;
    nouv->next = NULL;
    if (*q==NULL)
        *q = nouv;
    else
        {
            Queue *temp = *q;
            while (temp->next !=NULL)
                temp = temp->next;
            temp->next = nouv;
        }
}

Node * dequeue(Queue** q){
    Node *nbr=NULL;
    Queue *temp=*q;
    if (*q!=NULL)
    {
        nbr = temp->no;
        *q = temp->next;
        free(temp);
    }
    return nbr;
}
