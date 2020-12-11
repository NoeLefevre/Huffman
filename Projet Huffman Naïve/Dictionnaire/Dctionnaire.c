#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dictionnaire.h"
List_node *create_el_node(Node *n) //Permet de créer un élément de type Node
{
    List_node *new_el=malloc(sizeof(List_node));
    new_el->no = n;
    new_el->next = NULL;
    return new_el;
}

int list_size(Element *l) //Permet d'avoir la taille d'une liste chainée
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

int list_position(List_node *l, Node* p){ //Permet de récupérer la position d'un élément dans une liste chainée
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




void dictionnaire(FILE *fichier,Node *tree,Element *l_occurence) //Création du dictionnaire
{
    char *l_code = malloc(1*sizeof(char)//Allocation dynamique de la chaine de caractère qui va contenir le code de chaque caractère
    Stack *p=NULL; //Création de la pile qui va strocké les noeud parcourus qui ne sont pas des feuilles
    Node *temp=tree;
    Node *temp2;
    int compt=0;
    int i=0;
    push(&p,temp);//Ajout de la racine à la pile de noeuds
    while(compt!=list_size(l_occurence))//On parcourt le fichier texte tant qu'on a pas traité tous ses caractères
    {
        if(temp->right == NULL && temp->left==NULL)//Quand on est sur une feuille
        {
            compt++;
            fprintf(fichier,"%c:%s\n",temp->charactere,l_code); //On écrit le caractère suivi de son code dans le fichier dictionnaire
            //free(temp);
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
            if (temp2->right==NULL && temp2->left==NULL) //On vérivie si le parent n'est pas aussi devenue une feuille (dernier de la pile)
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
                push(&p,temp); //Ajoute le noeud à la pile si ce n'est pas une feuille et s'il n'existe pas déjà dans la liste
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
}
