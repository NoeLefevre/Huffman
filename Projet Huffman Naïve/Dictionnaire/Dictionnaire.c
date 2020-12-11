#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dictionnaire.h"
#include "../Arbre-huffman/Arbre-huffman.h"
#include "../Liberation/Liberation.h"
List_node *create_el_node(Node *n)
{
    List_node *new_el=malloc(sizeof(List_node));
    new_el->no = n;
    new_el->next = NULL;
    return new_el;
}

int list_size(Element *l)
{
    int i=0;
    Element* temp;
    temp = l;
    while (temp != NULL)
    {
        i = i + 1;
        temp=temp->next;
    }
    return i;
}

int list_position(Stack *l, Node* p){
    Stack *temp=l;
    while (temp!=NULL && temp->no!=p)
    {
        temp = temp->next;
    }
    if (temp == NULL)
        return -1;
    else
        return 1;
}




void dictionnaire(FILE *fichier,Node *tree,Element *l_occurence)
{
    char *l_code = malloc(1*sizeof(char));
    Stack *p=NULL;
    Node *temp=tree;
    Node *temp2;
    int compt=0;
    int i=0;
    push(&p,temp);
    while (compt != list_size(l_occurence))
    {
        if (temp->right == NULL && temp->left == NULL)
        {
            compt++;
            fprintf(fichier, "%c:%s\n", temp->charactere, l_code);
            free(temp);
            temp = NULL;
            temp2 = p->no;
            if (l_code[i - 1] == '1')
            {
                temp2->right = NULL;
            }
            else
            {
                temp2->left = NULL;
            }
            if (temp2->right == NULL && temp2->left == NULL)
            {
                while (compt != list_size(l_occurence) && temp2->right == NULL && temp2->left == NULL)
                {
                    pop(&p);
                    temp = p->no;
                    if (temp->right == temp2)
                        temp->right = NULL;
                    else
                        temp->left = NULL;
                    free(temp2);
                    temp2 = NULL;
                    temp2 = temp;
                    //printf("%d ",temp2->data);
                }
            }
            temp = tree;
            i = 0;
            l_code = malloc(1 * sizeof(char));
        }
        else if (temp->left != NULL)
        {
            temp2 = temp;
            temp = temp->left;
            if (list_position(p, temp) == -1 && temp->right != NULL && temp->left != NULL)
            {
                push(&p, temp);
            }
            l_code = realloc(l_code, i + 2);
            l_code[i + 1] = '\0';
            l_code[i] = '0';
            i++;
        }
        else
        {
            temp2 = temp;
            temp = temp->right;
            if (list_position(p, temp) == -1 && temp->right != NULL && temp->left != NULL)
            {
                push(&p, temp);
            }
            l_code = realloc(l_code, i + 2);
            l_code[i + 1] = '\0';
            l_code[i] = '1';
            i++;
        }
    }
    free(l_code);
    free_stack(p);
}
