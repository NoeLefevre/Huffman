#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arbre_huffman.h"

Node* trees_copy_tree(Node* tree){
    Node* tree2 = malloc(sizeof(Node));
    if(tree==NULL)
        return NULL;
    else
        {
            tree2->data = tree->data;
            tree2->charactere = tree->charactere;
            tree2->left = trees_copy_tree(tree->left);
            tree2->right = trees_copy_tree(tree->right);
        }
    return tree2;
}

Node* create_node(int val,char charactere){ //Fonction de création de noeud
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    new_node->charactere = charactere;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}


Queue *create_queue_node(Element *l) //Fonction de création d'une file avec des noeuds
{
    Queue *list=NULL;
    Element *temp=l;
    while (temp!=NULL)
    {
        Node* n = create_node(temp->data,temp->charactere);
        enqueue(&list,n);
        temp = temp->next;
    }
    return list;
}


Node * arbre_huffman(Element *l) 
{
    Queue *q1=create_queue_node(l); //Création d'une file avec la liste d'occurence triée
    Queue *q2=NULL; //Création de la deuxième file
    Node *n=NULL;
    Node *x1; //Minimum 1
    Node *x2; //Minimum 2
    int i=0;
    while (q1!=NULL || q2!=NULL) //Tant qu'il reste un élément dans une des deux files 
    {
        if (q2==NULL) //Si q2 est vide, on prend les deux minimums dans q1
        {
            x1 = dequeue(&q1); 
            x2 = dequeue(&q1);
        }
        else if (q1==NULL) //Cas inverse avec q2
        {
            x1 = dequeue(&q2);
            x2 = dequeue(&q2);
        }
        else{ //Si aucune des deux files n'est vide
                if(q1->no->data<=q2->no->data) //On prend le minimum entre les premiers éléments de chaque file
                    x1 = dequeue(&q1);
                else
                    x1 = dequeue(&q2);
             if (q1!=NULL && q2!=NULL) //On fait la même chose pour prendre un deuxième minimum
            {
                if(q1->no->data<=q2->no->data)
                    x2 = dequeue(&q1);
                else
                    x2 = dequeue(&q2);
            }
            else
            {
                if (q1==NULL) //On refait les mêmes conditions qu'au début car une des deux files a peut-être été vidée entre temps
                    x2 = dequeue(&q2);
                else if(q2==NULL)
                    x2 = dequeue(&q1);
            }


        }
        n=create_node(x1->data+x2->data,"c"); //On créé le noeud avec les minimums de la même façon que dans la partie naïve
        n->left=x1;
        n->right=x2;
        if ((q1!=NULL && q2!=NULL)||(q1==NULL && q2!=NULL) || (q1!=NULL && q2==NULL)) //S'il reste au moins un élément dans une des deux files
        {
            enqueue(&q2,n); //On ajoute notre noeud à q2
        }
    }
    return n;
}
