#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arbre_huffman.h"
#include "../Libération/Liberation.h"

Node* create_node(int val,char charactere){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    new_node->charactere = charactere;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}


Queue *create_queue_node(Element *l)
{
    Queue *list=NULL;
    Element *temp=l;
    while (temp != NULL)
    {
        Node* n = create_node(temp->data, temp->charactere);
        enqueue(&list, n);
        temp = temp->next;
    }
    return list;
}


Node * arbre_huffman(Element *l)
{
    Queue *q1=create_queue_node(l);
    Queue *q2=NULL;
    Node *n=NULL;
    Node *x1=NULL;
    Node *x2=NULL;
    char c='p';
    int i = 0;
    while (q1!=NULL || q2!=NULL)
    {
        if (q2==NULL)
        {
            x1 = dequeue(&q1);
            x2 = dequeue(&q1);
        }
        else if (q1==NULL)
        {
            x1 = dequeue(&q2);
            x2 = dequeue(&q2);
        }
        else{
                if(q1->no->data<=q2->no->data)
                    x1 = dequeue(&q1);
                else
                    x1 = dequeue(&q2);
             if (q1!=NULL && q2!=NULL)
            {
                if(q1->no->data<=q2->no->data)
                    x2 = dequeue(&q1);
                else
                    x2 = dequeue(&q2);
            }
            else
            {
                if (q1==NULL)
                    x2 = dequeue(&q2);
                else if(q2==NULL)
                    x2 = dequeue(&q1);
            }


        }

        n=create_node(x1->data+x2->data,c);
        n->left=x1;
        n->right=x2;
        if ((q1!=NULL && q2!=NULL)||(q1==NULL && q2!=NULL) || (q1!=NULL && q2==NULL))
        {
            enqueue(&q2,n);
        }

    }
    free_queue(q1);
    free_queue(q2);

    return n;
}
