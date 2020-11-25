#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arbre-huffman.h"
Node* create_node(int val,char charactere){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    new_node->charactere = charactere;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void ajouter_ln_fin(List_node** liste, List_node* el){
    List_node* temp = *liste;
    if (*liste == NULL){
        *liste = el;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = el;
    }

}

void list_remove(List_node** l, List_node* el){
    int i=1;
    List_node *temp=*l;
    List_node *temp2=*l;
    if (*l!=NULL)
    {
        while (temp!=NULL)
        {
            if (temp == el && i==1)
            {
                *l = temp->next;
            }
            else
            {
               if (temp == el)
                temp2->next = temp->next;
            }
            temp2 = temp;
            temp = temp->next;
            i++;
        }
    }
}

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
List_node * min_list(List_node *l)
{
    if (l!=NULL)
    {
        List_node * min=l;
        List_node *temp=l->next;
        while (temp!=NULL)
        {
            if (temp->no->data<min->no->data)
                min = temp;
            temp = temp->next;
        }
        return min;
    }
    else
        return NULL;


}



List_node *create_list_node(Element *l)
{
    List_node *list=NULL;
    List_node *temp2;
    Element *temp=l;
    while (temp!=NULL)
    {
        Node* n = create_node(temp->data,temp->charactere);
        temp2 = create_el_node(n);
        ajouter_ln_fin(&list,temp2);
        temp = temp->next;
    }
    return list;
}

Node * arbre_huffman(Element *l)
{
    List_node*l_noeud=create_list_node(l);
    List_node *temp;
    List_node *min1;
    List_node *min2;
    Node *n=NULL;
    while (l_noeud!=NULL)
    {
        min1 = min_list(l_noeud);

        list_remove(&l_noeud,min1);
        min2 = min_list(l_noeud);
        list_remove(&l_noeud,min2);
        n=create_node(min2->no->data+min1->no->data,"c");
        temp = create_el_node(n);
        n->left=min1->no;
        n->right=min2->no;
        if (l_noeud!=NULL)
            ajouter_ln_fin(&l_noeud,temp);
    }
    return n;
}
