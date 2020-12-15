#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Decompress.h"
#include "../Arbre_huffman/Arbre_huffman.h"
#include "../Conversion/Conversion.h"
Node* create_huff (FILE *dico)
{
    char c;
    char temp_c='p';
    int i=0;
    char* p  = malloc(20*sizeof(char));
    int test = 1;
    Node *tree = create_node(2,temp_c);
    Node *temp = tree;
    while (test==1)
    {
        c = fgetc(dico);//On prend le caractère du fichir dico 
        fseek(dico,1,SEEK_CUR);//On se déplace de 1 pour éviter les :
        if (fgets(p,20,dico)==NULL)//On prend son code
            test = 0;
        if (test==1)
        {
            p[strlen(p)-1] = '\0';
            while (p[i]!= '\0')//Tant qu'on est pas à la fin de lachaine de caractère
            {
                if (p[i+1]=='\0')//Si on est à la fin
                {
                    if (p[i]=='0')//Si '0', on créer une branche à gauche
                    {
                        temp->left = create_node(2,c);//Avec le bon caractère
                        temp = tree;
                    }
                    else //Sinon on créer une branche à gauche
                    {
                        temp->right = create_node(2,c);
                        temp = tree;
                    }
                }
                else
                {
                    //Même prinipe sauf qu'on n'est pas nécessairement à la fin de la chaine de caractère
                    if (p[i]=='1')
                    {
                        if (temp->right==NULL)
                            temp->right = create_node(2,temp_c);//Avec un caractère random
                        temp = temp->right;
                    }
                    else if (p[i]=='0')
                    {
                        if (temp->left==NULL)
                            temp->left = create_node(2,temp_c);
                        temp = temp->left;
                    }
                }
                i++;
            }
            i=0;
        }


    }
    free(p);
    return tree;
}

FILE *decompress(FILE* fichier,Node *tree)
{
    char c;
    Node *temp=tree;
    FILE *trad=NULL;//Création du fichier de traduction
    fopen_s(&trad, "trad.txt", "w+");
    do
    {
        c = fgetc(fichier);//On récupère le caractère du fichier encodage
        if (c!=EOF)
        {
            if (c=='1')
                temp = temp->right;//On se déplace à droite
            else
                temp = temp->left;//On se déplace à gauche
            if (temp->right==NULL && temp->left==NULL)//Si on est sur une feuille et donc un caractère à encoder
            {
                fprintf(trad, "%c", temp->charactere);//On écrit le caractère correspondant dans le fichier de sortie
                temp = tree;//On se replace à la racine pour pouvoir décoder d'autres lettres
            }

        }
    }while (c!=EOF);
    return trad;
}


