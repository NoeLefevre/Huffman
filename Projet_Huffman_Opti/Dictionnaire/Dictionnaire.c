#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dictionnaire.h"
#include "../Liste_occurence/Liste_occurence.h"
#include "../Libération/Liberation.h"
List_node *create_el_node(Node *n)
{
    List_node *new_el=malloc(sizeof(List_node));
    new_el->no = n;
    new_el->next = NULL;
    return new_el;
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

Node_d* create_node2(char c,char* code){
    Node_d* new_node = (Node_d*)malloc(sizeof(Node_d));
    new_node->charactere = c;
    new_node->code = code;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int depth(Node_d* tree){
    if(tree == NULL){
        return 0;//Attention définition. -1 ou 0
    }
    else{
        int depth_left = depth(tree->left);
        int depth_right = depth(tree->right);
        if(depth_left > depth_right){
            return 1 + depth_left;
        }
        else{
            return 1 + depth_right;
        }
    }
}

void add_node_BST(Node_d** tree, Node_d* node){
    if(*tree == NULL){
        *tree = node;
    }
    else{
        if ((*tree)->charactere > node->charactere){
            add_node_BST(&((*tree)->left) , node);
        }
        else if((*tree)->charactere < node->charactere){
            add_node_BST(&((*tree)->right) , node);
        }
    }
}

int bf(Node_d* tree){
    if(tree == NULL) {
        return 0;
    }
    else{
        return depth(tree->right) - depth(tree->left);
    }
}

void right_rotation(Node_d** tree){
    if (*tree != NULL){
        Node_d* temp = (*tree)->left;
        (*tree)->left = temp->right;
        temp->right = *tree;
        *tree = temp;
    }
}

void left_rotation(Node_d** tree){
    if (*tree != NULL){
        Node_d* temp = (*tree)->right;
        (*tree)->right = temp->left;
        temp->left = *tree;
        *tree = temp;
    }
}

void balance(Node_d** tree){
    if (*tree != NULL){
        balance(&((*tree)->left));// Postfix
        balance(&((*tree)->right));

        int balance_factor = bf(*tree);
        if (balance_factor <= -2){// Cas Gauche - ??
            if(bf((*tree)->left) > 0){// Gauche - Droite
                left_rotation(&((*tree)->left));
            }
            right_rotation(tree);// Gauche - Gauche
        }
        else if (balance_factor >= 2){// Cas Droite - ??
            if(bf((*tree)->right) < 0){// Droite - Gauche
                right_rotation(&((*tree)->right));
            }
            left_rotation(tree);// Droite - Droite
        }
    }
}

void add_node_AVL(Node_d** tree, Node_d* node){
    add_node_BST(tree, node);
    balance(tree);
}



Node_d *dictionnaire_vrai(FILE **fichier,Node **tree,Element *l_occurence)
{
    char *l_code = malloc(1*sizeof(char));
    Stack *p=NULL;
    Node *temp=*tree;
    Node *temp2;
    Node_d *dict=NULL;
    Node_d *temp_a;
    int compt=-1;
    int i=0;
    push(&p,temp);
    while(compt!=list_size(l_occurence))
    {
        if(temp->right == NULL && temp->left==NULL)
        {
            compt++;
            fprintf(*fichier, "%c:%s\n", temp->charactere, l_code);
            temp_a = create_node2(temp->charactere,l_code);
            add_node_AVL(&dict,temp_a);
            free(temp);
            temp=NULL;
            temp2 = p->no;
            if (l_code[i-1]=='1')
            {
                temp2->right = NULL;
            }
            else
            {
                temp2->left = NULL;
            }
            if (temp2->right==NULL && temp2->left==NULL)
            {
                while (compt!=list_size(l_occurence) && temp2->right==NULL && temp2->left==NULL)
                {
                    temp2 = pop(&p);
                    temp = p->no;
                    if (temp->right == temp2)
                        temp->right = NULL;
                    else
                        temp->left = NULL;
                    free(temp2);
                    temp2=NULL;
                    temp2 = temp;
                    //printf("%d ",temp2->data);
                }
            }
            temp = *tree;
            i=0;
            ///free(l_code);
            //l_code = NULL;
            l_code = malloc(1 * sizeof(char));
            //free(l_code);
            //l_code = '\0';
            //l_code = NULL;
            //l_code = realloc(l_code, 1);

        }
        else if(temp->left!=NULL)
        {
            temp2 = temp;
            temp = temp->left;
            if (list_position(p,temp)==-1 && temp->right!=NULL && temp->left!=NULL)
            {
                push(&p,temp);
            }
            l_code = realloc(l_code,i+2);
            l_code[i+1] = '\0';
            l_code[i] = '0';
            i++;
        }
        else
        {
            temp2 = temp;
            temp = temp->right;
            if (list_position(p,temp)==-1 && temp->right!=NULL && temp->left!=NULL)
            {
                push(&p,temp);
            }
            l_code = realloc(l_code,i+2);
            l_code[i+1] = '\0';
            l_code[i] = '1';
            i++;
        }
    }
    free(l_code);
    free_stack(p);
    return dict;
}
