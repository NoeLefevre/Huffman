#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dictionnaire.h"
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

List_node *create_el_node(Node *n)
{
    List_node *new_el=malloc(sizeof(List_node));
    new_el->no = n;
    new_el->next = NULL;
    return new_el;
}

Node *extract(List_node *liste)
{
    List_node *temp = liste;
    Node * tempp;List_node *create_el_node(Node *n)
{
    List_node *new_el=malloc(sizeof(List_node));
    new_el->no = n;
    new_el->next = NULL;
    return new_el;
}
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    tempp = temp->no;
    return tempp;
}

void suppr_fin(List_node **l)
{
    List_node *temp = *l;
    List_node *temp2;
    while (temp->next!=NULL)
    {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = NULL;
    //free(temp);
    temp = NULL;
}

int list_position(List_node *l, Node* p){
    List_node *temp=l;
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
    Node_d* new_node = (Node*)malloc(sizeof(Node));
    new_node->charactere = c;
    new_node->code = code;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
//Fonctions de base pour la création et l'ajout de noeud à un AVL
int depth(Node* tree){
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
//

void dictionnaire(FILE *fichier,Node *tree,Element *l_occurence)
{
    char *l_code = malloc(1*sizeof(char));
    Stack *p=NULL;
    Node *temp=tree;
    Node *temp2;
    int compt=-1;
    int i=0;
    push(&p,temp);
    while(compt!=list_size(l_occurence))
    {
        if(temp->right == NULL && temp->left==NULL)
        {
            compt++;
            fprintf(fichier,"%c:%s\n",temp->charactere,l_code);
            //free(temp);
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
                    pop(&p);
                    temp = p->no;
                    if (temp->right == temp2)
                        temp->right = NULL;
                    else
                        temp->left = NULL;
                    //free(temp2);
                    temp2=NULL;
                    temp2 = temp;
                    //printf("%d ",temp2->data);
                }
            }
            temp = tree;
            i=0;
            l_code = malloc(1*sizeof(char));
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
}

Node *dictionnaire_vrai(Node *tree,Element *l_occurence)
{
    char *l_code = malloc(1*sizeof(char));//Allocation dynamique de la chaine de caractère qui va contenir le code de chaque caractère
    Stack *p=NULL;//Création de la pile qui va strocké les noeud parcourus qui ne sont pas des feuilles
    Node *temp=tree;
    Node *temp2;
    Node_d *dict=NULL;
    Node_d *temp_a;
    int compt=-1;
    int i=0;
    push(&p,temp);//Ajout de la racine à la pile de noeuds
    while(compt!=list_size(l_occurence))//On parcourt le fichier texte tant qu'on a pas traité tous ses caractères
    {
        if(temp->right == NULL && temp->left==NULL)//Quand on est sur une feuille
        {
            compt++;
            temp_a = create_node2(temp->charactere,l_code);
            add_node_AVL(&dict,temp_a);
            temp=NULL;//On supprime la feuille
            temp2 = p->no;
            if (l_code[i-1]=='1')
            {
                temp2->right = NULL;
            }
            else
            {
                temp2->left = NULL;
            }
            if (temp2->right==NULL && temp2->left==NULL)//On vérivie si le parent n'est pas aussi devenue une feuille (dernier de la pile)
            {
                while (compt!=list_size(l_occurence) && temp2->right==NULL && temp2->left==NULL)// S'arrête quand le noeud n'est plus considéré comme une feuille
                {
                    //On supprime les noeuds correspondant
                    pop(&p);
                    temp = p->no;
                    if (temp->right == temp2)
                        temp->right = NULL;
                    else
                        temp->left = NULL;
                    //free(temp2);
                    temp2=NULL;
                    temp2 = temp;
                    //printf("%d ",temp2->data);
                }
            }
            temp = tree;//On se replace à la racine
            i=0;
            l_code = malloc(1*sizeof(char));
        }
        else if(temp->left!=NULL)//On se déplace d'abord à gauche et on vérifie si on peut y accéder
        {
            temp2 = temp;//Permet de sauvegarder le noeud précédent en cas de suppression futur
            temp = temp->left;
            if (list_position(p,temp)==-1 && temp->right!=NULL && temp->left!=NULL)
            {
                push(&p,temp);//Ajoute le noeud à la pile si ce n'est pas une feuille et s'il n'existe pas déjà dans la liste
            }
            l_code = realloc(l_code,i+2);//On réalloue dynamiquement de la mémoire à la chaine de caractère caractère car on ne connait pas sa taille
            l_code[i+1] = '\0';
            l_code[i] = '0';//On lui ajoute de code '0' car on va à gauche
            i++;
        }
        else
        {
            //Sinbn il va à droite, même processus
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
    return dict;
}
