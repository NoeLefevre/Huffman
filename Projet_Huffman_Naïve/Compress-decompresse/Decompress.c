#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Decompress.h"
#include "../Binaire/Binaire.h"
#include "../Liberation/Liberation.h"
FILE* decompress(FILE* fichier,Node *tree)
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
                fprintf(trad,"%c",temp->charactere);//On écrit le caractère correspondant dans le fichier de sortie
                temp = tree;//On se replace à la racine pour pouvoir décoder d'autres lettres
            }

        }
    } while (c != EOF);//On s'arrête quand on est à la fin du fichier
    return trad;
}
